#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setGeometry(20,300,600,200);
    QTimer *timer = new QTimer(this);
    timer->start(1000/48);

    windowLayout = new QHBoxLayout;

    myIsingTab = new IsingTab;

    leVisualTest = new visualTest;

    QTabWidget *tabs = new QTabWidget;
    tabs->setMinimumSize(400,200);
    tabs->addTab(myIsingTab, "so ising");
    tabs->addTab(leVisualTest,"very plot");

    // TIMER RAND TAB ISING
    QObject::connect(timer,SIGNAL(timeout()),
                     myIsingTab,SLOT(initIsingImage()));

    this->setCentralWidget(tabs);
    this->setWindowTitle("YOLO");
}

MainWindow::~MainWindow()
{
    delete ui;
}

