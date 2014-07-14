#ifndef ISINGTAB_H
#define ISINGTAB_H

#include <QWidget>
#include <QLabel>
#include <Eigen/Dense>
#include <QDebug>
#include <math.h>
#include <vector>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QGroupBox>
#include <QTextEdit>
#include <QString>
#include <QSlider>
#include <QPushButton>
#include <QScrollBar>
using Eigen::MatrixXd;

namespace Ui {
class IsingTab;
}

class IsingTab : public QLabel
{
    Q_OBJECT

public:
    explicit IsingTab(QWidget *parent = 0);
    ~IsingTab();

private:
    Ui::IsingTab *ui;
    MatrixXd spiny;
    MatrixXd neighBors;
    QHBoxLayout *isingLayout;
    QLabel *imageLabel;
    QGroupBox *isingGroup;
    QFormLayout *isingGroupLayout;
    QTextEdit *debugPlace;
    QScrollBar *tempSlider;
    QScrollBar *couplingSlider;
    QPushButton *resetIsingButton;


    QImage isingImage;

    std::vector<double> pstwaPreLoad;

    int w, h;
    double J,T,H;
    void initIsingGroup();
    void initProbs();
    void recalcBoltzman();

public slots:
    void initSpiny();
    void initIsingImage();
    void initNeighBors();
    void initFlipMaybe();
    void changeTemp(int T2){
        T = T2*0.1;
        recalcBoltzman();}
    void changeCoupling(int J2){
        J = J2*0.1;
        recalcBoltzman();}

signals:
    void debugIt(const QString);
};

#endif // ISINGTAB_H
