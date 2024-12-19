//
// Created by oreste on 19/12/24.
//

#ifndef APPROXIMAGEALGOADAPTATIF_CUSTOMGRAPHICSVIEW_H
#define APPROXIMAGEALGOADAPTATIF_CUSTOMGRAPHICSVIEW_H


#include <QGraphicsView>
#include <QGraphicsScene>

class CustomGraphicsView : public QGraphicsView {
Q_OBJECT

public:
    CustomGraphicsView(QWidget *parent = nullptr);
    void displayImage(const QImage &image);
    void drawVoronoi(const std::vector<QPointF> &points);

private:
    QGraphicsScene *scene;
};


#endif //APPROXIMAGEALGOADAPTATIF_CUSTOMGRAPHICSVIEW_H
