#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_connectBtn_clicked()
{
    if(usbmanager.openDevice(0x2d95, 0x6002))
    {
        qDebug() << "Device connected.";
    }
    else
    {
        qDebug() << "Failed to connected to device";
    }
}


void MainWindow::on_readBtn_clicked()
{

}


void MainWindow::on_writeBtn_clicked()
{

}


void MainWindow::on_disconnectBtn_clicked()
{
    usbmanager.disconnectDevice();
}

