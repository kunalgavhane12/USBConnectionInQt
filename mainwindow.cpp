#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    startScrcpy();
}

MainWindow::~MainWindow()
{
    if(scrcpyProcess)
    {
        scrcpyProcess->terminate();
        scrcpyProcess = nullptr;
    }
    delete ui;
}

void MainWindow::on_connectBtn_clicked()
{
      startScrcpy();
    // if(usbmanager.openDevice(0x2d95, 0x6002)) // vid //pid
    if(usbmanager.openDevice(0x2d95, 0x6003)) // vid //pid src
    // if(usbmanager.openDevice(0x22d9, 0x2765)) // vid //pid src
    {
        qDebug() << "Device connected.";
    }
    else
    {
        qDebug() << "Failed to connected to device";
    }
}


// void MainWindow::on_readBtn_clicked()
// {

// }


// void MainWindow::on_writeBtn_clicked()
// {

// }


void MainWindow::on_disconnectBtn_clicked()
{
    if(scrcpyProcess)
    {
        scrcpyProcess->terminate();
        scrcpyProcess = nullptr;
    }
    usbmanager.disconnectDevice();
}

void MainWindow::startScrcpy()
{
    if (scrcpyProcess == nullptr)
    {
        scrcpyProcess = new QProcess(this);
        QStringList arguments;
        arguments << "--max-size" << "800" << "--bit-rate" << "2M" << "--stay-awake";

        scrcpyProcess->start("scrcpy", arguments);

        if(!scrcpyProcess->waitForStarted())
        {
            qDebug() << "Failed to start scrcpy.";
        }
        else
        {
            qDebug() << "scrcpy started successfully.";
        }
    }
    else
    {
        qDebug() << "Device Already Connected.";
    }
}

