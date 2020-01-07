#include "renderarea.h"

#include <QPainter>

RenderArea::RenderArea(QWidget *parent) : QWidget(parent) {
    x = 0;
    y = 0;
    setShape(None);
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}

void RenderArea::setShape(Shape shape) {
    this->shape = shape;
    update();
}

void RenderArea::setPen(const QPen &pen) {
    this->pen = pen;
    update();
}

void RenderArea::setBrush(const QBrush &brush) {
    this->brush = brush;
    update();
}

void RenderArea::setSide(double s) { side = s; }
void RenderArea::setHeight(double he) { h = he; }
void RenderArea::setBase(double b) { base = b; }
void RenderArea::setRadius(double r) { radius = r; }
void RenderArea::setLongBase(double lb) { longBase = lb; }
void RenderArea::setShortBase(double sb) { shortBase = sb; }
void RenderArea::setApotema(double a) { apotema = a; }
void RenderArea::setDiagonal(double d) { diagonal = d; }
void RenderArea::setError(QString e) { error = e; }

void RenderArea::setValueX(int v) { x = v; }
void RenderArea::setValueY(int v) { y = v; }

void RenderArea::setCentro(double xc, double yc) { centroX = xc; centroY = yc; }

void RenderArea::paintEvent(QPaintEvent * ) {
    int spazioUp = 10 - x;
    int spazioSx = 20 - y;
    bool ok = true;

    QPointF pTriangle[3] = {
        QPointF(spazioUp + side/2, spazioSx),
        QPointF(spazioUp, spazioSx + h),
        QPointF(spazioUp + side, spazioSx + h)
    };

    QPointF pTrap[4] = {
        QPointF(spazioUp, spazioSx + h),
        QPointF(spazioUp + (longBase - shortBase)/2, spazioSx),
        QPointF(spazioUp + longBase - (longBase - shortBase)/2, spazioSx),
        QPointF(spazioUp + longBase, spazioSx + h)
    };

    double aux = radius - side/2;
    QPointF pPent[5] = {
        QPointF(spazioUp + diagonal/2, spazioSx),
        QPointF(spazioUp + diagonal, spazioSx + sqrt(pow(side, 2) - pow(diagonal/2, 2))),
        QPointF(spazioUp + aux + side, spazioSx + h),
        QPointF(spazioUp + aux, spazioSx + h),
        QPointF(spazioUp, spazioSx + sqrt(pow(side, 2) - pow(diagonal/2, 2)))
    };

    QRect rect(spazioUp, spazioSx, base, h);
    QRect sq(spazioUp, spazioSx, side, side);

    QPainter painter(this);
    painter.setPen(pen);
    painter.setBrush(brush);

    painter.save();

    if(!error.isNull()){ painter.drawText(10, 20, error); error = nullptr; }
    else{
        switch (shape) {
            case Square:
                painter.drawRect(sq);
            break;

            case Triangle:
                painter.drawPolygon(pTriangle, 3);
                centroY  = apotema*2;
            break;
            case Pentagon:
                painter.drawPolygon(pPent, 5);
                centroY = radius;
            break;

            case Circle:
                painter.drawEllipse(spazioUp, spazioSx, radius*2, radius*2);
            break;

            case Rect:
                painter.drawRect(rect);
            break;
            case IsoTrap:
                painter.drawPolygon(pTrap, 4);
            break;

            case None:
                ok = false;
            break;

            default:
                ok = false;
            break;

            painter.restore();
        }
    }

    QPainter centroSimmetria(this);
    QPen punto;
    if(ok == false) punto.setWidth(0);
    else punto.setWidth(3);
    centroSimmetria.setPen(punto);
    centroSimmetria.drawPoint(centroX + spazioUp, centroY + spazioSx);

    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.setPen(palette().dark().color());
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(QRect(0, 0, width() - 1, height() - 1));
}

void RenderArea::clear() {
    QPainter painter(this);
    painter.drawText(10, 20, "");
}
