//
// Created by oreste on 19/12/24.
//
#include "CustomGraphicsView.h"

CustomGraphicsView::CustomGraphicsView(QWidget *parent)
        : QGraphicsView(parent) {
    scene = new QGraphicsScene(this);
    setScene(scene);
}

void CustomGraphicsView::displayImage(const QImage &image) {
    scene->clear(); // Effacer la scène
    scene->addPixmap(QPixmap::fromImage(image));
}

void CustomGraphicsView::drawVoronoi(const std::vector<QPointF> &points) {
    for (const auto &point : points) {
        scene->addEllipse(point.x(), point.y(), 3, 3, QPen(Qt::red), QBrush(Qt::red));
    }
    this->viewport()->update(); // Mise à jour de l'affichage
}
