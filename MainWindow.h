//
// Created by oreste on 19/12/24.
//

#ifndef APPROXIMAGEALGOADAPTATIF_MAINWINDOW_H
#define APPROXIMAGEALGOADAPTATIF_MAINWINDOW_H


#include <QMainWindow>
#include <QPushButton>
#include "CustomGraphicsView.h"
#include "ImageProcessor.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
            void startVoronoiAlgorithm();

private:
    CustomGraphicsView *graphicsView;
    ImageProcessor *imageProcessor;
    QPushButton *startButton;
};


#endif //APPROXIMAGEALGOADAPTATIF_MAINWINDOW_H
