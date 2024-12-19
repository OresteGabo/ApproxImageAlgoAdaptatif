//
// Created by oreste on 19/12/24.
//

#ifndef APPROXIMAGEALGOADAPTATIF_IMAGEPROCESSOR_H
#define APPROXIMAGEALGOADAPTATIF_IMAGEPROCESSOR_H


#include <QImage>
#include <vector>
#include "CustomGraphicsView.h"

class ImageProcessor {
public:
    void applyVoronoi(CustomGraphicsView *view);

private:
    void generateRandomPoints(std::vector<QPointF> &points, int count, const QSize &size);
};

#endif //APPROXIMAGEALGOADAPTATIF_IMAGEPROCESSOR_H
