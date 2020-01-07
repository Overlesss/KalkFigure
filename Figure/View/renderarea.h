#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QBrush>
#include <QPen>
#include <QPixmap>
#include <QWidget>
#include <QScrollBar>
#include <QHBoxLayout>

class RenderArea : public QWidget {
    Q_OBJECT

public:
    enum Shape { Square, Triangle, Rect, Pentagon, Circle, IsoTrap, None };

    RenderArea(QWidget *parent = 0);

    void setSide(double);
    void setHeight(double);
    void setBase(double);
    void setLongBase(double);
    void setShortBase(double);
    void setRadius(double);
    void setApotema(double);
    void setDiagonal(double);
    void setError(QString);
    void clear();

public slots:
    void setShape(Shape shape);
    void setPen(const QPen &pen);
    void setBrush(const QBrush &brush);
    void setCentro(double, double);
    void setValueX(int);
    void setValueY(int);
protected:
    void paintEvent(QPaintEvent *event);

private:
    Shape shape;
    QPen pen;
    QBrush brush;
    QPixmap pixmap;

    double side;
    double h;
    double base;
    double longBase;
    double shortBase;
    double radius;
    double apotema;
    double diagonal;

    QString error;
    double centroX;
    double centroY;
    int x;
    int y;
};

#endif // RENDERAREA_H
