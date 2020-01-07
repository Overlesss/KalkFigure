#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "kalk2dwidget.h"
#include "kalk3dwidget.h"
#include "kalkdraw2d.h"

#include <QDialog>
#include <QDialogButtonBox>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QWidget>

class MainWindow : public QDialog {
    Q_OBJECT

private:
    QTabWidget* tab;
    Kalk2DWidget* dueD;
    Kalk3DWidget* treD;
    KalkDraw2D* drawTab;

public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();
public slots:
    void imposta3D(Plane*, double);
    void imposta2D(Solid*);
    void impostaDraw(Plane*);
};

#endif // MAINWINDOW_H
