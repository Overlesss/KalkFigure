#ifndef KALKABSTRACT_H
#define KALKABSTRACT_H

#include <QWidget>
#include "Eccezioni/kalkexception.h"
#include "./Model/shape.h"
#include "./Model/factory.h"
#include "./Model/pentagonalprism.h"
#include "./Model/cube.h"
#include "./Model/rightcircularcylinder.h"
#include "./Model/tetrahedron.h"
#include "./Model/trapezoidalprism.h"
#include "./Model/rectangularparallelepiped.h"

class KalkAbstract : public QWidget {
    Q_OBJECT

public:
    KalkAbstract(QWidget *parent = 0);
public slots:
    virtual void cancella() = 0;
    virtual void cancellaTutto() = 0;
};

#endif // KALKABSTRACT_H
