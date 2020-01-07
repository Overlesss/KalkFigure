#ifndef KALK2DWIDGET_H
#define KALK2DWIDGET_H

#include "kalkabstract.h"
#include "kalk3dwidget.h"

#include <vector>
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QFont>
#include <QDoubleValidator>
#include <QComboBox>
#include <QPainter>
#include <QPaintEvent>
#include <QInputDialog>

class Kalk2DWidget : public KalkAbstract {
    Q_OBJECT

private:
    QTextEdit* out;
    QLineEdit* lato;
    QLineEdit* baseLunga;
    QLineEdit* baseCorta;
    QLineEdit* base;
    QLineEdit* altezza;
    QLineEdit* raggio;
    QLabel* labelLato;
    QLabel* labelBL;
    QLabel* labelBC;
    QLabel* labelBase;
    QLabel* labelAltezza;
    QLabel* labelRaggio;
    QComboBox* figure;
    QPushButton* piu;
    QPushButton* meno;
    QPushButton* per;
    QPushButton* diviso;
    QPushButton* uguale;
    QPushButton* area;
    QPushButton* perimetro;
    QPushButton* espandi;
    QPushButton* riduci;
    QPushButton* diagonale;
    QPushButton* latoObl;
    QPushButton* raggioOut;
    QPushButton* diametro;
    QPushButton* alt;
    QPushButton* apotema;
    QPushButton* numVertici;
    QPushButton* c;
    QPushButton* ce;
    QPushButton* imposta;

    QPushButton* disegna;
    QPushButton* trasforma;

    char opSalvata;
    Plane* figSalvata;

    void reset();
    Plane* getFigura(int);
    Plane* getFiguraFrom3D(Solid*);
    void stampaInfo(Plane*);
public:
    Kalk2DWidget();
    void setDa3D(Solid*);

public slots:
    void displayInput(int);

    void calcolaArea();
    void calcolaPerimetro();
    void espandiFigura();
    void riduciFigura();
    void calcolaDiagonale();
    void calcolaLatoObl();
    void calcolaRaggioOut();
    void calcolaDiametro();
    void calcolaAltezza();
    void calcolaApotema();
    void printNumVertici();

    void sum();
    void subtraction();
    void multiplication();
    void division();
    void calcola();

    void cancella();
    void cancellaTutto();
    void impostaFigura();

    void draw2D();
    void from2Dto3D();
signals:
    void transformInto3D(Plane*, double);
    void drawFigure(Plane*);
};

#endif // KALK2DWIDGET_H
