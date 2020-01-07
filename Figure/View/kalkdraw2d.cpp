#include "kalkdraw2d.h"

KalkDraw2D::KalkDraw2D() {
    out = new RenderArea;

    QDoubleValidator* validazione = new QDoubleValidator;
    validazione->setNotation(QDoubleValidator::StandardNotation);
    validazione->setBottom(0);

    // Label e textedit
    lato = new QLineEdit;
    lato->setValidator(validazione);
    labelLato = new QLabel(tr("&Lato:"));
    labelLato->setBuddy(lato);

    baseLunga = new QLineEdit;
    baseLunga->setValidator(validazione);
    labelBL = new QLabel(tr("&Base Lunga:"));
    labelBL->setBuddy(baseLunga);

    baseCorta = new QLineEdit;
    baseCorta->setValidator(validazione);
    labelBC = new QLabel(tr("&Base Corta:"));
    labelBC->setBuddy(baseCorta);

    base = new QLineEdit;
    base->setValidator(validazione);
    labelBase = new QLabel(tr("&Base:"));
    labelBase->setBuddy(base);

    altezza = new QLineEdit;
    altezza->setValidator(validazione);
    labelAltezza = new QLabel(tr("&Altezza:"));
    labelAltezza->setBuddy(altezza);

    raggio = new QLineEdit;
    raggio->setValidator(validazione);
    labelRaggio = new QLabel(tr("&Raggio:"));
    labelRaggio->setBuddy(raggio);

    figure = new QComboBox;
    figure->addItem(tr("-- Seleziona figura --"));
    for(std::vector<std::string>::const_iterator it = Factory::nomiFigure2D.begin(); it != Factory::nomiFigure2D.end(); ++it){
        figure->addItem(QString::fromStdString(*it));
    }
    connect(figure, SIGNAL(currentIndexChanged(int)), this, SLOT(displayInput(int)));

    penWidthSpinBox = new QSpinBox;
    penWidthSpinBox->setRange(0, 10);
    penWidthSpinBox->setSpecialValueText(tr("0 (cosmetic pen)"));
    penWidthLabel = new QLabel(tr("&Spessore Penna:"));
    penWidthLabel->setBuddy(penWidthSpinBox);

    penStyleComboBox = new QComboBox;
    penStyleComboBox->addItem(tr("Solido"), static_cast<int>(Qt::SolidLine));
    penStyleComboBox->addItem(tr("Linea"), static_cast<int>(Qt::DashLine));
    penStyleComboBox->addItem(tr("Punto"), static_cast<int>(Qt::DotLine));
    penStyleComboBox->addItem(tr("Linea Punto"), static_cast<int>(Qt::DashDotLine));
    penStyleComboBox->addItem(tr("Linea Punto Punto"), static_cast<int>(Qt::DashDotDotLine));
    penStyleComboBox->addItem(tr("None"), static_cast<int>(Qt::NoPen));

    penStyleLabel = new QLabel(tr("&Stile Penna:"));
    penStyleLabel->setBuddy(penStyleComboBox);

    penCapComboBox = new QComboBox;
    penCapComboBox->addItem(tr("Flat"), Qt::FlatCap);
    penCapComboBox->addItem(tr("Quadrata"), Qt::SquareCap);
    penCapComboBox->addItem(tr("Rotonda"), Qt::RoundCap);

    penCapLabel = new QLabel(tr("&Cap Penna:"));
    penCapLabel->setBuddy(penCapComboBox);

    penJoinComboBox = new QComboBox;
    penJoinComboBox->addItem(tr("45 gradi"), Qt::MiterJoin);
    penJoinComboBox->addItem(tr("Smussato"), Qt::BevelJoin);
    penJoinComboBox->addItem(tr("Rotondo"), Qt::RoundJoin);

    penJoinLabel = new QLabel(tr("Tipologia &Angoli:"));
    penJoinLabel->setBuddy(penJoinComboBox);

    brushStyleComboBox = new QComboBox;
    brushStyleComboBox->addItem(tr("None"), static_cast<int>(Qt::NoBrush));
    brushStyleComboBox->addItem(tr("Linear Gradient"), static_cast<int>(Qt::LinearGradientPattern));
    brushStyleComboBox->addItem(tr("Radial Gradient"), static_cast<int>(Qt::RadialGradientPattern));
    brushStyleComboBox->addItem(tr("Conical Gradient"), static_cast<int>(Qt::ConicalGradientPattern));
    brushStyleComboBox->addItem(tr("Solid"), static_cast<int>(Qt::SolidPattern));
    brushStyleComboBox->addItem(tr("Horizontal"), static_cast<int>(Qt::HorPattern));
    brushStyleComboBox->addItem(tr("Vertical"), static_cast<int>(Qt::VerPattern));
    brushStyleComboBox->addItem(tr("Cross"), static_cast<int>(Qt::CrossPattern));
    brushStyleComboBox->addItem(tr("Backward Diagonal"), static_cast<int>(Qt::BDiagPattern));
    brushStyleComboBox->addItem(tr("Forward Diagonal"), static_cast<int>(Qt::FDiagPattern));
    brushStyleComboBox->addItem(tr("Diagonal Cross"), static_cast<int>(Qt::DiagCrossPattern));
    brushStyleComboBox->addItem(tr("Dense 1"), static_cast<int>(Qt::Dense1Pattern));
    brushStyleComboBox->addItem(tr("Dense 2"), static_cast<int>(Qt::Dense2Pattern));
    brushStyleComboBox->addItem(tr("Dense 3"), static_cast<int>(Qt::Dense3Pattern));
    brushStyleComboBox->addItem(tr("Dense 4"), static_cast<int>(Qt::Dense4Pattern));
    brushStyleComboBox->addItem(tr("Dense 5"), static_cast<int>(Qt::Dense5Pattern));
    brushStyleComboBox->addItem(tr("Dense 6"), static_cast<int>(Qt::Dense6Pattern));
    brushStyleComboBox->addItem(tr("Dense 7"), static_cast<int>(Qt::Dense7Pattern));
    brushStyleLabel = new QLabel(tr("&Pennello:"));
    brushStyleLabel->setBuddy(brushStyleComboBox);

    connect(penWidthSpinBox, SIGNAL(valueChanged(int)), this, SLOT(penChanged()));
    connect(penStyleComboBox, SIGNAL(activated(int)), this, SLOT(penChanged()));
    connect(penCapComboBox, SIGNAL(activated(int)), this, SLOT(penChanged()));
    connect(penJoinComboBox, SIGNAL(activated(int)), this, SLOT(penChanged()));
    connect(brushStyleComboBox, SIGNAL(activated(int)), this, SLOT(brushChanged()));

    // bottoni

    draw = new QPushButton(tr("Disegna"));
    connect(draw, SIGNAL(clicked()), this, SLOT(disegna()));
    ce = new QPushButton(tr("Cancella tutto"));
    connect(ce, SIGNAL(clicked()), this, SLOT(cancellaTutto()));

    scrollbarRight = new QScrollBar(Qt::Vertical);
    scrollbarBot = new QScrollBar(Qt::Horizontal);
    scrollbarRight->setMaximum(500);
    scrollbarBot->setMaximum(500);

    connect(scrollbarRight, SIGNAL(valueChanged(int)), this, SLOT(setValueY(int)));
    connect(scrollbarBot, SIGNAL(valueChanged(int)), this, SLOT(setValueX(int)));

    reset();

    QGridLayout* dati = new QGridLayout;
    dati->addWidget(labelLato, 0, 0);
    dati->addWidget(lato, 0, 1);
    dati->addWidget(labelBL, 1, 0);
    dati->addWidget(baseLunga, 1, 1);
    dati->addWidget(labelBC, 2, 0);
    dati->addWidget(baseCorta, 2, 1);
    dati->addWidget(labelBase, 3, 0);
    dati->addWidget(base, 3, 1);
    dati->addWidget(labelAltezza, 4, 0);
    dati->addWidget(altezza, 4, 1);
    dati->addWidget(labelRaggio, 5, 0);
    dati->addWidget(raggio, 5, 1);

    QGridLayout *options = new QGridLayout;
    options->addWidget(penWidthLabel, 0, 0);
    options->addWidget(penWidthSpinBox, 0, 1);
    options->addWidget(penStyleLabel, 1, 0);
    options->addWidget(penStyleComboBox, 1, 1);
    options->addWidget(penCapLabel, 2, 0);
    options->addWidget(penCapComboBox, 2, 1);
    options->addWidget(penJoinLabel, 3, 0);
    options->addWidget(penJoinComboBox, 3, 1);
    options->addWidget(brushStyleLabel, 4, 0);
    options->addWidget(brushStyleComboBox, 4, 1);

    QHBoxLayout* bottoni = new QHBoxLayout;
    bottoni->addWidget(draw);
    bottoni->addWidget(ce);

    QHBoxLayout* out1 = new QHBoxLayout;
    out1->addWidget(out);
    out1->addWidget(scrollbarRight);
    QVBoxLayout* out2 = new QVBoxLayout;
    out2->addLayout(out1);
    out2->addWidget(scrollbarBot);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(out2);
    mainLayout->addWidget(figure);
    mainLayout->addLayout(dati);
    mainLayout->addLayout(options);
    mainLayout->addLayout(bottoni);
    setLayout(mainLayout);
}

// CONTROLLER

void KalkDraw2D::setValueX(int v) { out->setValueX(v); disegna(); }
void KalkDraw2D::setValueY(int v) { out->setValueY(v); disegna(); }

void KalkDraw2D::reset() {
    figure->setCurrentIndex(0);
    labelLato->setVisible(false);
    lato->setVisible(false);
    labelBL->setVisible(false);
    baseLunga->setVisible(false);
    labelBC->setVisible(false);
    baseCorta->setVisible(false);
    labelBase->setVisible(false);
    base->setVisible(false);
    labelAltezza->setVisible(false);
    altezza->setVisible(false);
    labelRaggio->setVisible(false);
    raggio->setVisible(false);

    penWidthLabel->setVisible(false);
    penStyleLabel->setVisible(false);
    penCapLabel->setVisible(false);
    penJoinLabel->setVisible(false);
    brushStyleLabel->setVisible(false);

    penWidthSpinBox->setVisible(false);
    penStyleComboBox->setVisible(false);
    penCapComboBox->setVisible(false);
    penJoinComboBox->setVisible(false);
    brushStyleComboBox->setVisible(false);
}

// in base a quale sia l'indice del menu mostra gli input adeguati
void KalkDraw2D::displayInput(int f) {
    // mostra i pulsanti
    penWidthLabel->setVisible(true);
    penStyleLabel->setVisible(true);
    penCapLabel->setVisible(true);
    penJoinLabel->setVisible(true);
    brushStyleLabel->setVisible(true);

    penWidthSpinBox->setVisible(true);
    penStyleComboBox->setVisible(true);
    penCapComboBox->setVisible(true);
    penJoinComboBox->setVisible(true);
    brushStyleComboBox->setVisible(true);

    draw->setVisible(true);
    ce->setVisible(true);

    switch(f) {
        case 1: // triangolo
            labelLato->setVisible(true);
            lato->setVisible(true);

            labelBL->setVisible(false);
            baseLunga->setVisible(false);
            labelBC->setVisible(false);
            baseCorta->setVisible(false);
            labelBase->setVisible(false);
            base->setVisible(false);
            labelAltezza->setVisible(false);
            altezza->setVisible(false);
            labelRaggio->setVisible(false);
            raggio->setVisible(false);
        break;

        case 2: // quadrato
            labelLato->setVisible(true);
            lato->setVisible(true);

            labelBL->setVisible(false);
            baseLunga->setVisible(false);
            labelBC->setVisible(false);
            baseCorta->setVisible(false);
            labelBase->setVisible(false);
            base->setVisible(false);
            labelAltezza->setVisible(false);
            altezza->setVisible(false);
            labelRaggio->setVisible(false);
            raggio->setVisible(false);
        break;

        case 3: // rettangolo
            labelBase->setVisible(true);
            base->setVisible(true);
            labelAltezza->setVisible(true);
            altezza->setVisible(true);

            labelLato->setVisible(false);
            lato->setVisible(false);
            labelBL->setVisible(false);
            baseLunga->setVisible(false);
            labelBC->setVisible(false);
            baseCorta->setVisible(false);
            labelRaggio->setVisible(false);
            raggio->setVisible(false);
        break;

        case 4: // trapezio
            labelBL->setVisible(true);
            baseLunga->setVisible(true);
            labelBC->setVisible(true);
            baseCorta->setVisible(true);
            labelAltezza->setVisible(true);
            altezza->setVisible(true);

            labelLato->setVisible(false);
            lato->setVisible(false);
            labelBase->setVisible(false);
            base->setVisible(false);
            labelRaggio->setVisible(false);
            raggio->setVisible(false);
        break;

        case 5: // pentagono
            labelLato->setVisible(true);
            lato->setVisible(true);

            labelBL->setVisible(false);
            baseLunga->setVisible(false);
            labelBC->setVisible(false);
            baseCorta->setVisible(false);
            labelBase->setVisible(false);
            base->setVisible(false);
            labelAltezza->setVisible(false);
            altezza->setVisible(false);
            labelRaggio->setVisible(false);
            raggio->setVisible(false);
        break;

        case 6: // cerchio
            labelRaggio->setVisible(true);
            raggio->setVisible(true);

            labelLato->setVisible(false);
            lato->setVisible(false);
            labelBL->setVisible(false);
            baseLunga->setVisible(false);
            labelBC->setVisible(false);
            baseCorta->setVisible(false);
            labelBase->setVisible(false);
            base->setVisible(false);
            labelAltezza->setVisible(false);
            altezza->setVisible(false);
        break;

        default:
            reset();
        break;
    }
}

Plane* KalkDraw2D::getFigura(int f) {
    try{
        switch(f) {
            case 1: // TRIANGOLO
                if(lato->text().isEmpty()) return new EquilateralTriangle;
                return new EquilateralTriangle(lato->text().toDouble());
            break;

            case 2: // QUADRATO
                if(lato->text().isEmpty()) return new Square;
                return new Square(lato->text().toDouble());
            break;

            case 3: // RETTANGOLO
                if(base->text().isEmpty() && altezza->text().isEmpty()) return new Rectangle;
                return new Rectangle(base->text().toDouble(), altezza->text().toDouble());
            break;

            case 4: // TRAPEZIO
                if(baseLunga->text().isEmpty() && baseCorta->text().isEmpty() && altezza->text().isEmpty()) return new IsoscelesTrapezoid;
                return new IsoscelesTrapezoid(baseLunga->text().toDouble(), baseCorta->text().toDouble(), altezza->text().toDouble());
            break;

            case 5: // PENTAGONO
                if(lato->text().isEmpty()) return new RegularPentagon;
                return new RegularPentagon(lato->text().toDouble());
            break;

            case 6: // CERCHIO
                if(raggio->text().isEmpty()) return new Circle;
                return new Circle(raggio->text().toDouble());
            break;

            default:
                return nullptr;
            break;
        }
    }
    catch(NonPositiveValues e) { out->setError(QString::fromStdString(e.getError())); return nullptr; }
    catch(UnsuitableValues e) { out->setError(QString::fromStdString(e.getError())); return nullptr; }
}

// connect

void KalkDraw2D::penChanged() {
    int width = penWidthSpinBox->value();
    Qt::PenStyle style = Qt::PenStyle(penStyleComboBox->itemData(penStyleComboBox->currentIndex()).toInt());
    Qt::PenCapStyle cap = Qt::PenCapStyle(penCapComboBox->itemData(penCapComboBox->currentIndex()).toInt());
    Qt::PenJoinStyle join = Qt::PenJoinStyle(penJoinComboBox->itemData(penJoinComboBox->currentIndex()).toInt());

    out->setPen(QPen(Qt::blue, width, style, cap, join));
}

void KalkDraw2D::brushChanged() {
    Qt::BrushStyle style = Qt::BrushStyle(brushStyleComboBox->itemData(brushStyleComboBox->currentIndex()).toInt());

    if (style == Qt::LinearGradientPattern) {
        QLinearGradient linearGradient(0, 0, 100, 100);
        linearGradient.setColorAt(0.0, Qt::white);
        linearGradient.setColorAt(0.2, Qt::green);
        linearGradient.setColorAt(1.0, Qt::black);
        out->setBrush(linearGradient);
    } else if (style == Qt::RadialGradientPattern) {
        QRadialGradient radialGradient(50, 50, 50, 70, 70);
        radialGradient.setColorAt(0.0, Qt::white);
        radialGradient.setColorAt(0.2, Qt::green);
        radialGradient.setColorAt(1.0, Qt::black);
        out->setBrush(radialGradient);
    } else if (style == Qt::ConicalGradientPattern) {
        QConicalGradient conicalGradient(50, 50, 150);
        conicalGradient.setColorAt(0.0, Qt::white);
        conicalGradient.setColorAt(0.2, Qt::green);
        conicalGradient.setColorAt(1.0, Qt::black);
        out->setBrush(conicalGradient);
    } else {
        out->setBrush(QBrush(Qt::green, style));
    }
}

void KalkDraw2D::disegna() {
    penChanged();
    brushChanged();
    Plane* ora = getFigura(figure->currentIndex());
    if(ora) {
        if(dynamic_cast<Square*>(ora)){
            out->setShape(RenderArea::Square);
            out->setSide(dynamic_cast<Square*>(ora)->side());
        }

        if(dynamic_cast<EquilateralTriangle*>(ora)){
            out->setShape(RenderArea::Triangle);
            out->setSide(dynamic_cast<EquilateralTriangle*>(ora)->side());
            out->setHeight(dynamic_cast<EquilateralTriangle*>(ora)->height(dynamic_cast<EquilateralTriangle*>(ora)->side()));
            out->setApotema(dynamic_cast<EquilateralTriangle*>(ora)->apothem());
        }

        if(dynamic_cast<Rectangle*>(ora)){
            out->setShape(RenderArea::Rect);
            out->setHeight(dynamic_cast<Rectangle*>(ora)->height());
            out->setBase(dynamic_cast<Rectangle*>(ora)->base());
        }

        if(dynamic_cast<RegularPentagon*>(ora)){
            out->setShape(RenderArea::Pentagon);
            out->setSide(dynamic_cast<RegularPentagon*>(ora)->side());
            out->setHeight(dynamic_cast<RegularPentagon*>(ora)->height(dynamic_cast<RegularPentagon*>(ora)->side()));
            out->setRadius(dynamic_cast<RegularPentagon*>(ora)->radius());
            out->setApotema(dynamic_cast<RegularPentagon*>(ora)->apothem());
            out->setDiagonal(dynamic_cast<RegularPentagon*>(ora)->diagonal(dynamic_cast<RegularPentagon*>(ora)->side()));
        }

        if(dynamic_cast<Circle*>(ora)){
            out->setShape(RenderArea::Circle);
            out->setRadius(dynamic_cast<Circle*>(ora)->radius());
        }

        if(dynamic_cast<IsoscelesTrapezoid*>(ora)){
            out->setShape(RenderArea::IsoTrap);
            out->setHeight(dynamic_cast<IsoscelesTrapezoid*>(ora)->height());
            out->setLongBase(dynamic_cast<IsoscelesTrapezoid*>(ora)->longBase());
            out->setShortBase(dynamic_cast<IsoscelesTrapezoid*>(ora)->shortBase());
        }

        out->setCentro(ora->centreOfSymmetry()->getX(), ora->centreOfSymmetry()->getY());
    }
}

void KalkDraw2D::cancella() {
    altezza->clear();
    lato->clear();
    baseLunga->clear();
    baseCorta->clear();
    base->clear();
    raggio->clear();
}

void KalkDraw2D::cancellaTutto() {
    cancella();
    out->setShape(RenderArea::None);
}

void KalkDraw2D::setDraw2D(Plane* p) {
    if(dynamic_cast<EquilateralTriangle*>(p)) {
        lato->setText(QString::number(dynamic_cast<EquilateralTriangle*>(p)->side()));
        figure->setCurrentIndex(1);
    }

    if(dynamic_cast<Square*>(p)) {
        lato->setText(QString::number(dynamic_cast<Square*>(p)->side()));
        figure->setCurrentIndex(2);
    }

    if(dynamic_cast<Rectangle*>(p)) {
        altezza->setText(QString::number(dynamic_cast<Rectangle*>(p)->height()));
        base->setText(QString::number(dynamic_cast<Rectangle*>(p)->base()));
        figure->setCurrentIndex(3);
    }

    if(dynamic_cast<IsoscelesTrapezoid*>(p)) {
        altezza->setText(QString::number(dynamic_cast<IsoscelesTrapezoid*>(p)->height()));
        baseLunga->setText(QString::number(dynamic_cast<IsoscelesTrapezoid*>(p)->longBase()));
        baseCorta->setText(QString::number(dynamic_cast<IsoscelesTrapezoid*>(p)->shortBase()));
        figure->setCurrentIndex(4);
    }

    if(dynamic_cast<RegularPentagon*>(p)) {
        lato->setText(QString::number(dynamic_cast<RegularPentagon*>(p)->side()));
        figure->setCurrentIndex(5);
    }

    if(dynamic_cast<Circle*>(p)) {
        raggio->setText(QString::number(dynamic_cast<Circle*>(p)->radius()));
        figure->setCurrentIndex(6);
    }
}
