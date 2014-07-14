#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QLabel>
#include <QGroupBox>
#include <QFormLayout>
#include <QPushButton>
#include <cstdlib>
#include <QTimer>
#include <QDebug>
#include <QTabWidget>
#include <QSlider>
#include "isingtab.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QHBoxLayout *windowLayout;
    IsingTab *myIsingTab;
    QTabWidget *tabs;

};



#endif // MAINWINDOW_H
