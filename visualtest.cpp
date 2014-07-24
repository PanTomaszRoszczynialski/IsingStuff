#include "visualtest.h"


visualTest::visualTest(QWidget *parent) :
    QWidget(parent)
{

    Q3DScatter scatter;
    scatter.setFlags(scatter.flags() ^ Qt::FramelessWindowHint);
    QScatter3DSeries *series = new QScatter3DSeries;
    QScatterDataArray data;
    data << QVector3D(0.5f, 0.5f, 0.5f) << QVector3D(-0.3f, -0.5f, -0.4f) << QVector3D(0.0f, -0.3f, 0.2f);
    series->dataProxy()->addItems(data);
    scatter.addSeries(series);
    scatter.show();

}
