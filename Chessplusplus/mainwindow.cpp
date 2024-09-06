#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
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
    centralWidget = new QWidget(this);
    centralWidget->setFixedSize(80*8, 80*8); // Fix expansion as a square



    // Create a grid layout for the container
    QGridLayout *layout = new QGridLayout(this);

    // Add stretchable space to center the widget vertically

    layout->addWidget(centralWidget, 1,1, Qt::AlignCenter);  // Center the widget in the layout
    layout->setRowStretch(0, 1);  // Top spacer
    layout->setRowStretch(2, 1);  // Bottom spacer
    layout->setColumnStretch(0, 1);  // Left spacer
    layout->setColumnStretch(2, 1);  // Right spacer
    setCentralWidget(centralWidget);

    // Make GridLayout
    QGridLayout *gridLayout = new QGridLayout();
    gridLayout->setSpacing(0);

    for (int row = 0; row < 8; row ++){
        for (int col = 0; col < 8; col ++){
            // Make Square
            QLabel *square = new QLabel(this);
            square->setFixedSize(80,80); // Set the size of each square

            // Set alternating colors for the squares
            if ((row + col) % 2 == 0) {
                square->setStyleSheet("background-color: #E4EBF3;padding: 0px;"); // white
            } else {
                square->setStyleSheet("background-color: #92C1CC; padding: 0px;"); // black
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
