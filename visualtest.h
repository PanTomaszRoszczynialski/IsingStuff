#ifndef VISUALTEST_H
#define VISUALTEST_H

#include <QWidget>
#include <QtDataVisualization/Q3DScatter>

using namespace QtDataVisualization;


class visualTest : public QWidget
{
    Q_OBJECT
public:
    explicit visualTest(QWidget *parent = 0);

private:
    Q3DScatter scatter;
    QScatter3DSeries *series;
    QScatterDataArray data;

signals:

public slots:

};

#endif // VISUALTEST_H
