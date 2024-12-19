//
// Created by oreste on 19/12/24.
//

#include "WorkerVoronoi.h"
#include <cmath>
#include <limits>

WorkerVoronoi::WorkerVoronoi(const std::vector<QPointF> &points, const QSize &size, QObject *parent)
        : QObject(parent), points(points), size(size) {}

void WorkerVoronoi::computeVoronoi() {
    QImage result = computeVoronoiDiagram();
    emit voronoiComputed(result); // Envoyer le résultat à l'interface utilisateur
    emit finished(); // Indiquer que le calcul est terminé
}

QImage WorkerVoronoi::computeVoronoiDiagram() {
    QImage image(size, QImage::Format_RGB32);
    image.fill(Qt::white);

    // Calcul intensif : Voronoi par force brute
    for (int y = 0; y < size.height(); ++y) {
        for (int x = 0; x < size.width(); ++x) {
            double minDistance = std::numeric_limits<double>::max();
            int nearestPointIndex = -1;

            // Trouver le point le plus proche
            for (size_t i = 0; i < points.size(); ++i) {
                double distance = std::hypot(points[i].x() - x, points[i].y() - y);
                if (distance < minDistance) {
                    minDistance = distance;
                    nearestPointIndex = i;
                }
            }

            // Colorer selon l'indice du point
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

