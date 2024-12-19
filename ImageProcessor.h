//
// Created by oreste on 19/12/24.
//

#ifndef APPROXIMAGEALGOADAPTATIF_IMAGEPROCESSOR_H
#define APPROXIMAGEALGOADAPTATIF_IMAGEPROCESSOR_H


#include <QImage>
#include <vector>
#include <QPointF>
#include "CustomGraphicsView.h"

class ImageProcessor : public QObject {
Q_OBJECT

public:
    ImageProcessor(QObject *parent = nullptr);
    void applyVoronoi(CustomGraphicsView *view);

private slots:
    void handleVoronoiResult(const QImage &image); // Gérer le résultat du thread
    void threadFinished(); // Nettoyer après le thread

private:
    CustomGraphicsView *view;
    QThread *workerThread;
};

#endif //APPROXIMAGEALGOADAPTATIF_IMAGEPROCESSOR_H
