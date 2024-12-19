#include "ImageProcessor.h"
#include <random>
#include <iostream>

void ImageProcessor::applyVoronoi(CustomGraphicsView *view) {
    // Charger une image de test
    QImage image("kigali.png");
    if (image.isNull()) {
        std::cerr << "Erreur : Impossible de charger l'image." << std::endl;
        return;
    }

    // Afficher l'image dans la vue
    view->displayImage(image);

    // Générer des points aléatoires
    std::vector<QPointF> points;
    int pointCount = image.width() * image.height() * 0.002; // 0.2% des pixels
    generateRandomPoints(points, pointCount, image.size());

    std::cout << "Nombre de points générés : " << points.size() << std::endl;

    // Dessiner les points comme germes du diagramme Voronoï
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
