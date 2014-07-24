#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "isingtab.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setGeometry(20,300,600,200);
    QTimer *timer = new QTimer(this);
    timer->setInterval(1000/24);
    timer->start(1000/24);

    windowLayout = new QHBoxLayout;

    myIsingTab = new IsingTab;


    //IsingTab *myIsing = new IsingTab;
    QTabWidget *tabs = new QTabWidget;
    tabs->setMinimumSize(400,200);
    tabs->addTab(myIsingTab, "so ising");
    //TIMER RAND TAB ISING
    QObject::connect(timer,SIGNAL(timeout()),
                     myIsingTab,SLOT(initIsingImage()));


    this->setCentralWidget(tabs);
    this->setWindowTitle("YOLO");


}

MainWindow::~MainWindow()
{
    delete ui;
}

