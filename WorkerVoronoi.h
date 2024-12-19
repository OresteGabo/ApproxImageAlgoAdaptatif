//
// Created by oreste on 19/12/24.
//

#ifndef APPROXIMAGEALGOADAPTATIF_WORKERVORONOI_H
#define APPROXIMAGEALGOADAPTATIF_WORKERVORONOI_H


#include <QObject>
#include <QImage>
#include <vector>
#include <QPointF>

class WorkerVoronoi : public QObject {
Q_OBJECT

public:
    WorkerVoronoi(const std::vector<QPointF> &points, const QSize &size, QObject *parent = nullptr);

signals:
    void voronoiComputed(const QImage &result); // Signal pour envoyer le résultat
    void finished(); // Signal de fin du travail

public slots:
    void computeVoronoi();

private:
    std::vector<QPointF> points;
    QSize size;

    QImage computeVoronoiDiagram();
};

#endif //APPROXIMAGEALGOADAPTATIF_WORKERVORONOI_H
