#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QPalette>
#include <QColor>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CreateGraphicalBoard();
}

void MainWindow::CreateGraphicalBoard(void)
{
    // Create a central widget
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Make GridLayout
    QGridLayout *gridLayout = new QGridLayout();
    gridLayout->setSpacing(0);

    for (int row = 0; row < 8; row ++){
        for (int col = 0; col < 8; col ++){
            // Make Square
            QLabel *square = new QLabel(this);
            square->setFixedSize(80, 80); // Set the size of each square

            // Set alternating colors for the squares
            if ((row + col) % 2 == 0) {
                square->setStyleSheet("background-color: white;padding: 0px;");
            } else {
                square->setStyleSheet("background-color: black; padding: 0px;");
            }

            gridLayout->addWidget(square, row, col);
        }
    }
    // Set the layout to the central widget
    centralWidget->setLayout(gridLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}
