#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "usbmanager.h"
#include <QMainWindow>
#include <QProcess>
#include <QWidget>
#include <QVBoxLayout>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_connectBtn_clicked();

    // void on_readBtn_clicked();

    // void on_writeBtn_clicked();

    void on_disconnectBtn_clicked();

private:
    Ui::MainWindow *ui;
    USBManager usbmanager;
    QProcess *scrcpyProcess;
    void startScrcpy();
};
#endif // MAINWINDOW_H
