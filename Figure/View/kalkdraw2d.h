#ifndef KALKDRAW2D_H
#define KALKDRAW2D_H

#include "kalkabstract.h"
#include "renderarea.h"

#include <QPushButton>
#include <QComboBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>

class KalkDraw2D : public KalkAbstract {
    Q_OBJECT

private:
    QPushButton* draw;
    QPushButton* ce;
    RenderArea* out;
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

    QLabel* penWidthLabel;
    QLabel* penStyleLabel;
    QLabel* penCapLabel;
    QLabel* penJoinLabel;
    QLabel* brushStyleLabel;

    QComboBox* figure;
    QSpinBox* penWidthSpinBox;
    QComboBox* penStyleComboBox;
    QComboBox* penCapComboBox;
    QComboBox* penJoinComboBox;
    QComboBox* brushStyleComboBox;

    QScrollBar* scrollbarRight;
    QScrollBar* scrollbarBot;

    void reset();
public:
    KalkDraw2D();
    void setDraw2D(Plane*);
public slots:
    void displayInput(int);
    void penChanged();
    void brushChanged();
    void disegna();
    void cancella();
    void cancellaTutto();
    Plane* getFigura(int);

    void setValueX(int);
    void setValueY(int);
};

#endif // KALKDRAW2D_H
