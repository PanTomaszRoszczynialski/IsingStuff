#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "visualtest.h"
#include "isingtab.h"
#include <QSlider>
#include <QLabel>
#include <QTimer>
#include <QDebug>
#include <cstdlib>
#include <QGroupBox>
#include <QTabWidget>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QMainWindow>
#include <QPushButton>


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

    QTabWidget *tabs;
    IsingTab *myIsingTab;
    visualTest *leVisualTest;
    QHBoxLayout *windowLayout;

};

#endif // MAINWINDOW_H
