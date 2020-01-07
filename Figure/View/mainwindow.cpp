#include "mainwindow.h"

MainWindow::~MainWindow() {}

MainWindow::MainWindow(QWidget* parent) : QDialog(parent) {
    QWidget::setWindowTitle(tr("KALK: Figure geometriche")); // imposta titolo finestra
    QWidget::resize(960, 540); // imposta dimensioni

    dueD = new Kalk2DWidget();
    treD = new Kalk3DWidget();
    drawTab = new KalkDraw2D();
    tab = new QTabWidget;
    tab->addTab(dueD, tr("Calcolo 2D")); // aggiunge tab di calcolo 2D
    tab->addTab(treD, tr("Calcolo 3D")); // aggiunge tab di calcolo 3D
    tab->addTab(drawTab, tr("Disegna")); // aggiunge tab di disegno 2D

    connect(dueD, SIGNAL(transformInto3D(Plane*,double)), this, SLOT(imposta3D(Plane*,double)));
    connect(treD, SIGNAL(transformInto2D(Solid*)), this, SLOT(imposta2D(Solid*)));
    connect(dueD, SIGNAL(drawFigure(Plane*)), this, SLOT(impostaDraw(Plane*)));

    QDialogButtonBox* exit = new QDialogButtonBox(QDialogButtonBox::Close);
    connect(exit, &QDialogButtonBox::rejected, this, &QDialog::reject); // bottone che fa uscire

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(tab);
    mainLayout->addWidget(exit);
    setLayout(mainLayout);
}

void MainWindow::imposta3D(Plane* p, double h) {
    treD->setDa2D(p, h);
    tab->setCurrentIndex(1);
}

void MainWindow::imposta2D(Solid* s) {
    dueD->setDa3D(s);
    tab->setCurrentIndex(0);
}

void MainWindow::impostaDraw(Plane* p) {
    drawTab->setDraw2D(p);
    tab->setCurrentIndex(2);
}
