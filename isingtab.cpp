#include "isingtab.h"
//#include "ui_isingtab.h"

#define DZIELNIK 10

IsingTab::IsingTab(QWidget *parent) :
    QLabel(parent)
{
    J = 1.0;
    T = 3.0;
    H = 10;

    // + Rozdzielczosc IMG z isingiem
    w = int(420);
    h = int(420);

    // Nie wiem gdzie to dac
    std::vector<double> tmp(5);
    pstwaPreLoad = tmp;

    //isingImage = QImage(w,h,QImage::Format_Mono);
    isingImage = QImage(w,h,QImage::Format_RGB16);
    spiny = MatrixXd(h,w);
    neighBors = MatrixXd(h,w);
    initSpiny();
    initNeighBors();
    initProbs();

    // KOLORY
    //valA = QRgb;
    //valB = QRgb;
    valA = qRgb(133,22,97);
    valB = qRgb(44,144,44);


    isingLayout = new QHBoxLayout;
    isingGroup = new QGroupBox;
    isingGroup->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    initIsingGroup();
    imageLabel = new QLabel;
    initIsingImage();
    //imageLabel->setFixedSize(w,h);
    imageLabel->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    imageLabel->setScaledContents(true);
  /*
    QString g = QString::number(pstwaPreLoad[0]);
    for(int i = 1; i < 5; ++i){
        g.append("\n");
        g.append(QString::number( pstwaPreLoad[i] ));
    }
    debugIt(g);
    */
    imageLabel->setPixmap(QPixmap::fromImage(isingImage));
    isingGroup->setTitle("same opcje");
    this->setLayout(isingLayout);
    isingLayout->addWidget(imageLabel);
    isingLayout->addWidget(isingGroup);


}

void IsingTab::initIsingImage()
{
 //   int w2 = isingImage.width();
 //   int h2 = isingImage.height();
 //   int r1;
 //   QRgb val;
    for(int i=0; i<w; ++i){
        for(int j=0; j<h; ++j){
//            r1 = 255*(spiny(j,i));
//            val = qRgb(r1%50,120-r1%100,r1%200);
//            r1 = spiny(j,i);
//            isingImage.setPixel(i,j,r1);
            spiny(j,i) ? isingImage.setPixel(i,j,valB) : isingImage.setPixel(i,j,valA);
            //isingImage.setPixel(i,j,val);

        }
    }
    imageLabel->setPixmap(QPixmap::fromImage(isingImage));
    initFlipMaybe();
}

void IsingTab::initSpiny()
{
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            spiny(i,j) = (rand()%100>50);
        }
    }
}

void IsingTab::initNeighBors()
{
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            int iNext = i==h-1 ? 0 : i+1;
            int iPrev = i==0 ? h-1 : i-1;
            int jNext = j==w-1 ? 0 : j+1;
            int jPrev = j==0 ? w-1 : j-1;
            neighBors(i,j) = 2*(spiny(i,j)-0.5)*2*(spiny(iNext,j)+
                                spiny(iPrev,j)+
                                spiny(i,jNext)+ //troloo
                                spiny(i,jPrev)-2)/2+2;
        }
    }

}

void IsingTab::initFlipMaybe()
{
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            //spiny(i,j) = spiny(i,j) ? 1-(rand()%100>50) : 0+(rand()%100>22);
            spiny(i,j) = (pstwaPreLoad[neighBors(i,j)] > (rand()%400)*0.01) ?
                        abs(spiny(i,j)-1) : spiny(i,j) ;
        }
    }
    initNeighBors();
}

void IsingTab::initIsingGroup()
{
    isingGroupLayout = new QFormLayout(isingGroup);
    debugPlace = new QTextEdit;
    tempSlider = new QScrollBar;
    couplingSlider = new QScrollBar;
    resetIsingButton = new QPushButton;

    // BUTTON
    resetIsingButton->setText("ISING\nREBOOT");
    QObject::connect(resetIsingButton,SIGNAL(clicked()),
                     this,SLOT(initSpiny()));


    // SLIDER COUPLING
    couplingSlider->setMinimum(-10);
    couplingSlider->setMaximum(30);
    couplingSlider->setSliderPosition(10);
    couplingSlider->setOrientation(Qt::Horizontal);
    QObject::connect(couplingSlider,SIGNAL(valueChanged(int)),
                     this,SLOT(changeCoupling(int)));
    // SLIDER TEMPERATURE
    tempSlider->setMinimum(5);
    tempSlider->setMaximum(80);
    tempSlider->setOrientation(Qt::Horizontal);
    QObject::connect(tempSlider,SIGNAL(valueChanged(int)),
                     this,SLOT(changeTemp(int)));


    //LAYOUT
    isingGroupLayout->addRow(debugPlace);
    isingGroupLayout->addRow("T: ",tempSlider);
    isingGroupLayout->addRow("J: ",couplingSlider);
    isingGroupLayout->addRow(resetIsingButton);
    debugPlace->setText("YOOYOYOY");
    QObject::connect(this,SIGNAL(debugIt(QString)),
                     this->debugPlace,SLOT(setText(QString)) );

}

void IsingTab::initProbs()
{
    // WSPOLCZYNNIKI BOLTZMANA DO UZYTKU
    double k;
    for(int i = 0; i < 5; ++i){
        k = exp( -4*( J*(i-2)/T ) );
        pstwaPreLoad[i] = k ;
    }
}

void IsingTab::recalcBoltzman()
{
    QString bug = QString("T: ");
    bug.append(QString::number(T));
    bug.append("\nJ: ");
    bug.append(QString::number(J));
    debugIt(bug);
    initProbs();
}

IsingTab::~IsingTab()
{
}
