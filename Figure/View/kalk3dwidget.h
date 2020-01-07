#ifndef KALK3DWIDGET_H
#define KALK3DWIDGET_H

#include "kalkabstract.h"
#include "kalk2dwidget.h"

#include <QWidget>
#include <QComboBox>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPainter>
#include <QPaintEvent>
#include <QTextEdit>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QInputDialog>

class Kalk3DWidget : public KalkAbstract {
    Q_OBJECT

private:
    QTextEdit* out;
    QLineEdit* base;
    QLineEdit* altezza;
    QLineEdit* lato;
    QLineEdit* baseLunga;
    QLineEdit* baseCorta;
    QLineEdit* lunghezza;
    QLabel* labelBase;
    QLabel* labelAltezza;
    QLabel* labelLato;
    QLabel* labelBL;
    QLabel* labelBC;
    QLabel* labelLung;
    QComboBox* figure;
    QPushButton* c;
    QPushButton* ce;
    QPushButton* imposta;
    QPushButton* piu;
    QPushButton* meno;
    QPushButton* per;
    QPushButton* diviso;
    QPushButton* uguale;
    QPushButton* volume;
    QPushButton* supLaterale;
    QPushButton* superficie;
    QPushButton* diagonaleSpaziale;
    QPushButton* raggio;
    QPushButton* alt;
    QPushButton* espandi;
    QPushButton* riduci;

    QPushButton* numFacce;
    QPushButton* numVertici;
    QPushButton* numSpigoli;
    QPushButton* schlafli;
    QPushButton* inRaggio;
    QPushButton* outRaggio;

    QPushButton* trasforma;

    Solid* figSalvata;
    char opSalvata;

    void reset();
    Solid* getFigura(int);
    Solid* getFiguraFrom2D(Plane*, double);
    void stampaInfo(Solid*);
public:
    Kalk3DWidget();
    void setDa2D(Plane*, double);
public slots:
    void displayInput(int);
    void calcolaVolume();
    void calcolaSuperficie();
    void calcolaSupLaterale();
    void calcolaDSpaziale();
    void calcolaAltezza();
    void calcolaRaggio();
    void espandiFigura();
    void riduciFigura();
    void sum();
    void subtraction();
    void multiplication();
    void division();
    void calcola();
    void cancella();
    void cancellaTutto();
    void impostaFigura();

    void printNumFacce();
    void printNumVertici();
    void printNumSpigoli();
    void printSchlafli();
    void printRaggioIn();
    void printRaggioOut();

    void from3Dto2D();

signals:
    void transformInto2D(Solid*);
};

#endif // KALK3DWIDGET_H
