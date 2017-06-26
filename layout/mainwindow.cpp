#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->label->setPixmap(QPixmap("://1.png"));
    ui->label->setScaledContents(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}
