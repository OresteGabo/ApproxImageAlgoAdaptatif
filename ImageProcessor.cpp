#include "ImageProcessor.h"
#include <cmath>
#include <random>
#include <iostream>

void ImageProcessor::applyVoronoi(CustomGraphicsView *view) {
    QImage image("fruits.png");
    if (image.isNull()) {
        std::cerr << "Erreur : Impossible de charger l'image." << std::endl;
        return;
    }

    std::vector<QPointF> points;
    generateRandomPoints(points, image.width() * image.height() * 0.002, image.size());

    // Calculer le diagramme de Voronoï
    QImage voronoiImage = computeVoronoiDiagram(points, image.size());

    // Afficher l'image Voronoï
    view->displayImage(voronoiImage);
    view->drawVoronoi(points);
}

void ImageProcessor::generateRandomPoints(std::vector<QPointF> &points, int count, const QSize &size) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> disX(0, size.width());
    std::uniform_real_distribution<> disY(0, size.height());

    for (int i = 0; i < count; ++i) {
        points.emplace_back(disX(gen), disY(gen));
    }
}

QImage ImageProcessor::computeVoronoiDiagram(const std::vector<QPointF> &points, const QSize &size) {
    QImage image(size, QImage::Format_RGB32);
    image.fill(Qt::white);

    // Pour chaque pixel de l'image
    for (int y = 0; y < size.height(); ++y) {
        for (int x = 0; x < size.width(); ++x) {
            double minDistance = std::numeric_limits<double>::max();
            int nearestPointIndex = -1;

            // Trouver le point le plus proche (force brute)
            for (size_t i = 0; i < points.size(); ++i) {
                double distance = std::hypot(points[i].x() - x, points[i].y() - y);
                if (distance < minDistance) {
                    minDistance = distance;
                    nearestPointIndex = i;
                }
            }

            // Colorer le pixel selon l'index du point le plus proche
            if (nearestPointIndex != -1) {
                int r = (nearestPointIndex * 50) % 256;
                int g = (nearestPointIndex * 100) % 256;
                int b = (nearestPointIndex * 150) % 256;
                image.setPixel(x, y, qRgb(r, g, b));
            }
        }
    }

    return image;
}
