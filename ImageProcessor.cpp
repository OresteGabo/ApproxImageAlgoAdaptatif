#include "ImageProcessor.h"
#include "WorkerVoronoi.h"
#include <QThread>
#include <random>
#include <iostream>
#include <QFileDialog>
ImageProcessor::ImageProcessor(QObject *parent) : QObject(parent), workerThread(nullptr) {}

void ImageProcessor::applyVoronoi(CustomGraphicsView *view) {
    this->view = view;

    // Open a file dialog to select an image
    QString fileName = QFileDialog::getOpenFileName(nullptr, "Open Image", "", "Images (*.png *.jpg *.jpeg *.bmp)");
    if (fileName.isEmpty()) {
        std::cerr << "No image selected." << std::endl;
        return;
    }

    // Load the selected image
    QImage image(fileName);
    if (image.isNull()) {
        std::cerr << "Failed to load the image: " << fileName.toStdString() << std::endl;
        return;
    }

    // Display the loaded image in the view
    view->displayImage(image);

    // Use the image size for generating random points
    QSize size = image.size();
    std::vector<QPointF> points;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> disX(0, size.width());
    std::uniform_real_distribution<> disY(0, size.height());

    for (int i = 0; i < size.width() * size.height() * 0.002; ++i) {
        points.emplace_back(disX(gen), disY(gen));
    }

    // Create the thread and the worker
    workerThread = new QThread;
    auto worker = new WorkerVoronoi(points, size);

    worker->moveToThread(workerThread);

    // Connect signals and slots between the thread and the interface
    connect(workerThread, &QThread::started, worker, &WorkerVoronoi::computeVoronoi);
    connect(worker, &WorkerVoronoi::voronoiComputed, this, &ImageProcessor::handleVoronoiResult);
    connect(worker, &WorkerVoronoi::finished, this, &ImageProcessor::threadFinished);
    connect(worker, &WorkerVoronoi::finished, worker, &QObject::deleteLater);
    connect(workerThread, &QThread::finished, workerThread, &QObject::deleteLater);

    // Start the thread
    workerThread->start();
}


void ImageProcessor::handleVoronoiResult(const QImage &image) {
    // Afficher le résultat dans la vue
    if (view) {
        view->displayImage(image);
    }
}

void ImageProcessor::threadFinished() {
    if (workerThread) {
        workerThread->quit();
        workerThread = nullptr;
    }
    std::cout << "Calcul terminé." << std::endl;
}
