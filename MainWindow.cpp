//
// Created by oreste on 19/12/24.
//

#include "MainWindow.h"
#include <QVBoxLayout>
#include <QPushButton>

#include <iostream>

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent) {
    // Initialisation des composants
    graphicsView = new CustomGraphicsView(this);
    imageProcessor = new ImageProcessor();

    startButton = new QPushButton("Démarrer l'algorithme", this);
    connect(startButton, &QPushButton::clicked, this, &MainWindow::startVoronoiAlgorithm);

    // Mise en page
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(graphicsView);
    layout->addWidget(startButton);

    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    setWindowTitle("Approximation d'images avec Voronoï");
    resize(800, 600);
}

MainWindow::~MainWindow() {}

void MainWindow::startVoronoiAlgorithm() {
    std::cout << "Bouton cliqué : démarrage de l'algorithme Voronoï." << std::endl;
    imageProcessor->applyVoronoi(graphicsView);
}
