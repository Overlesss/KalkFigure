#include "kalk2dwidget.h"

Kalk2DWidget::Kalk2DWidget() {
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

    // Dropdown menu
    figure = new QComboBox;
    figure->addItem(tr("-- Seleziona figura --"));
    for(std::vector<std::string>::const_iterator it = Factory::nomiFigure2D.begin(); it != Factory::nomiFigure2D.end(); ++it){
        figure->addItem(QString::fromStdString(*it));
    }
    connect(figure, SIGNAL(currentIndexChanged(int)), this, SLOT(displayInput(int)));

    // Bottoni
    c = new QPushButton(tr("Cancella"));
    ce = new QPushButton(tr("Cancella tutto"));
    imposta = new QPushButton(tr("Imposta figura"));

    connect(c, SIGNAL(clicked()), this, SLOT(cancella())); // clear
    connect(ce, SIGNAL(clicked()), this, SLOT(cancellaTutto())); // clear everything
    connect(imposta, SIGNAL(clicked()), this, SLOT(impostaFigura())); // ans

    piu = new QPushButton("+");
    meno = new QPushButton("-");
    per = new QPushButton("x");
    diviso = new QPushButton(":");
    uguale = new QPushButton("=");

    connect(piu, SIGNAL(clicked()), this, SLOT(sum())); // SOMMA
    connect(meno, SIGNAL(clicked()), this, SLOT(subtraction())); // SOTTRAZIONE
    connect(per, SIGNAL(clicked()), this, SLOT(multiplication())); // MOLTIPLICAZIONE
    connect(diviso, SIGNAL(clicked()), this, SLOT(division())); // DIVISIONE
    connect(uguale, SIGNAL(clicked()), this, SLOT(calcola())); // UGUALE

    area = new QPushButton(tr("Area"));
    perimetro = new QPushButton(tr("Perimetro"));
    espandi = new QPushButton(tr("Espandi"));
    riduci = new QPushButton(tr("Riduci"));
    latoObl = new QPushButton(tr("Lato obliquo"));
    diagonale = new QPushButton(tr("Diagonale"));
    raggioOut = new QPushButton(tr("Raggio"));
    diametro = new QPushButton(tr("Diametro"));
    alt = new QPushButton(tr("Altezza"));
    apotema = new QPushButton(tr("Apotema"));
    numVertici = new QPushButton(tr("Numero Vertici"));

    connect(area, SIGNAL(clicked()), this, SLOT(calcolaArea())); // area
    connect(perimetro, SIGNAL(clicked()), this, SLOT(calcolaPerimetro())); // perimetro
    connect(espandi, SIGNAL(clicked()), this, SLOT(espandiFigura())); // espandi
    connect(riduci, SIGNAL(clicked()), this, SLOT(riduciFigura())); // riduci
    connect(diagonale, SIGNAL(clicked()), this, SLOT(calcolaDiagonale())); // diagonale
    connect(latoObl, SIGNAL(clicked()), this, SLOT(calcolaLatoObl())); // lato obliquo trapezio
    connect(raggioOut, SIGNAL(clicked()), this, SLOT(calcolaRaggioOut())); // raggio
    connect(diametro, SIGNAL(clicked()), this, SLOT(calcolaDiametro())); // diametro
    connect(alt, SIGNAL(clicked()), this, SLOT(calcolaAltezza())); // altezza
    connect(apotema, SIGNAL(clicked()), this, SLOT(calcolaApotema())); // apotema (raggio interno)
    connect(numVertici, SIGNAL(clicked()), this, SLOT(printNumVertici())); // apotema (raggio interno)

    disegna = new QPushButton(tr("Disegna figura"));
    trasforma = new QPushButton(tr("Trasforma in 3D"));
    connect(disegna, SIGNAL(clicked()), this, SLOT(draw2D())); // disegna
    connect(trasforma, SIGNAL(clicked()), this, SLOT(from2Dto3D())); // trasforma in 3D

    reset();

    // Layout
    QHBoxLayout* bottoni = new QHBoxLayout;
    bottoni->addWidget(c);
    bottoni->addWidget(ce);
    bottoni->addWidget(imposta);

    QGridLayout* dati = new QGridLayout;
    dati->addWidget(figure, 0, 0, 1, 2);
    dati->addWidget(labelLato, 1, 0);
    dati->addWidget(lato, 1, 1);
    dati->addWidget(labelBL, 2, 0);
    dati->addWidget(baseLunga, 2, 1);
    dati->addWidget(labelBC, 3, 0);
    dati->addWidget(baseCorta, 3, 1);
    dati->addWidget(labelBase, 4, 0);
    dati->addWidget(base, 4, 1);
    dati->addWidget(labelAltezza, 5, 0);
    dati->addWidget(altezza, 5, 1);
    dati->addWidget(labelRaggio, 6, 0);
    dati->addWidget(raggio, 6, 1);
    dati->addLayout(bottoni, 7, 0, 1, 2);

    QVBoxLayout* opUnarie = new QVBoxLayout;
    opUnarie->addWidget(area);
    opUnarie->addWidget(perimetro);
    opUnarie->addWidget(diagonale);
    opUnarie->addWidget(latoObl);
    opUnarie->addWidget(raggioOut);
    opUnarie->addWidget(diametro);
    opUnarie->addWidget(alt);
    opUnarie->addWidget(apotema);
    opUnarie->addWidget(numVertici);
    opUnarie->addWidget(espandi);
    opUnarie->addWidget(riduci);

    QVBoxLayout* opBinarie = new QVBoxLayout;
    opBinarie->addWidget(piu);
    opBinarie->addWidget(meno);
    opBinarie->addWidget(per);
    opBinarie->addWidget(diviso);
    opBinarie->addWidget(uguale);

    QHBoxLayout* body = new QHBoxLayout;
    body->addLayout(dati);
    body->addLayout(opUnarie);
    body->addLayout(opBinarie);

    out = new QTextEdit;
    out->setVisible(false);
    out->setReadOnly(true);
    out->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    out->setFont(QFont("Times", 20));

    QHBoxLayout* extra = new QHBoxLayout;
    extra->addWidget(trasforma);
    extra->addWidget(disegna);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(body);
    mainLayout->addWidget(out);
    mainLayout->addLayout(extra);
    setLayout(mainLayout);
}

// CONTROLLER

// imposta la situazione iniziale con tutto nascosto tranne il dropdown menu
void Kalk2DWidget::reset() {
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
    figSalvata = nullptr;

    // nasconde i bottoni
    piu->setVisible(false);
    meno->setVisible(false);
    per->setVisible(false);
    diviso->setVisible(false);
    uguale->setVisible(false);
    area->setVisible(false);
    perimetro->setVisible(false);
    espandi->setVisible(false);
    riduci->setVisible(false);
    diagonale->setVisible(false);
    latoObl->setVisible(false);
    raggioOut->setVisible(false);
    diametro->setVisible(false);
    alt->setVisible(false);
    apotema->setVisible(false);
    numVertici->setVisible(false);
    c->setVisible(false);
    ce->setVisible(false);
    imposta->setVisible(false);
    trasforma->setVisible(false);
    disegna->setVisible(false);
}

// in base a quale sia l'indice del menu mostra gli input adeguati
void Kalk2DWidget::displayInput(int f) {
    // mostra i pulsanti
    piu->setVisible(true);
    meno->setVisible(true);
    per->setVisible(true);
    diviso->setVisible(true);
    uguale->setVisible(true);
    area->setVisible(true);
    perimetro->setVisible(true);
    espandi->setVisible(true);
    riduci->setVisible(true);
    out->setVisible(true);
    c->setVisible(true);
    ce->setVisible(true);
    trasforma->setVisible(true);
    disegna->setVisible(true);

    switch(f) {
        case 1: // triangolo
            labelLato->setVisible(true);
            lato->setVisible(true);
            alt->setVisible(true);
            apotema->setVisible(true);
            raggioOut->setVisible(true);
            numVertici->setVisible(true);

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
            diagonale->setVisible(false);
            diametro->setVisible(false);
            latoObl->setVisible(false);
        break;

        case 2: // quadrato
            labelLato->setVisible(true);
            lato->setVisible(true);
            diagonale->setVisible(true);
            apotema->setVisible(true);
            raggioOut->setVisible(true);
            numVertici->setVisible(true);

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
            diametro->setVisible(false);
            alt->setVisible(false);
            latoObl->setVisible(false);
        break;

        case 3: // rettangolo
            labelBase->setVisible(true);
            base->setVisible(true);
            labelAltezza->setVisible(true);
            altezza->setVisible(true);
            diagonale->setVisible(true);
            raggioOut->setVisible(true);
            numVertici->setVisible(true);

            labelLato->setVisible(false);
            lato->setVisible(false);
            labelBL->setVisible(false);
            baseLunga->setVisible(false);
            labelBC->setVisible(false);
            baseCorta->setVisible(false);
            labelRaggio->setVisible(false);
            raggio->setVisible(false);
            diametro->setVisible(false);
            alt->setVisible(false);
            apotema->setVisible(false);
            latoObl->setVisible(false);
        break;

        case 4: // trapezio
            labelBL->setVisible(true);
            baseLunga->setVisible(true);
            labelBC->setVisible(true);
            baseCorta->setVisible(true);
            labelAltezza->setVisible(true);
            altezza->setVisible(true);
            diagonale->setVisible(true);
            raggioOut->setVisible(true);
            numVertici->setVisible(true);
            latoObl->setVisible(true);

            labelLato->setVisible(false);
            lato->setVisible(false);
            labelBase->setVisible(false);
            base->setVisible(false);
            labelRaggio->setVisible(false);
            raggio->setVisible(false);
            diametro->setVisible(false);
            alt->setVisible(false);
            apotema->setVisible(false);
        break;

        case 5: // pentagono
            labelLato->setVisible(true);
            lato->setVisible(true);
            diagonale->setVisible(true);
            alt->setVisible(true);
            apotema->setVisible(true);
            raggioOut->setVisible(true);
            numVertici->setVisible(true);

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
            diametro->setVisible(false);
            latoObl->setVisible(false);
        break;

        case 6: // cerchio
            labelRaggio->setVisible(true);
            raggio->setVisible(true);
            diametro->setVisible(true);

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
            diagonale->setVisible(false);
            alt->setVisible(false);
            apotema->setVisible(false);
            numVertici->setVisible(false);
            raggioOut->setVisible(false);
            latoObl->setVisible(false);
        break;

        default:
            reset();
            out->setVisible(false);
        break;
    }
    cancella();
    imposta->setVisible(false);
    out->clear();
}

// ritorna la figura con i dati inseriti, se i campi son vuoti ritorna la figura costruita di default
Plane* Kalk2DWidget::getFigura(int f) {
    try {
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
    catch(NonPositiveValues e) { out->setText(QString::fromStdString(e.getError())); opSalvata=0; return nullptr; }
    catch(UnsuitableValues e) { out->setText(QString::fromStdString(e.getError())); opSalvata=0; return nullptr; }
}

// calcola l'area della figura piana
void Kalk2DWidget::calcolaArea() {
    out->clear();
    Plane* p = getFigura(figure->currentIndex());
    if(p) {
        out->append(QString::fromStdString(p->getName()));
        out->append("Area: " + QString::number(p->area()));
    }
}

// calcola il perimetro della figura piana
void Kalk2DWidget::calcolaPerimetro() {
    out->clear();
    Plane* p = getFigura(figure->currentIndex());
    if(p) {
        out->append(QString::fromStdString(p->getName()));
        out->append("Perimetro: " + QString::number(p->perimeter()));
    }
}

// calcola la diagonale ma solo del trapezio isoscele, rettangolo, quadrato e pentagono
void Kalk2DWidget::calcolaDiagonale() {
    out->clear();
    Plane* p = getFigura(figure->currentIndex());
    if(p) {
        out->append(QString::fromStdString(p->getName()));

        IsoscelesTrapezoid* it = dynamic_cast<IsoscelesTrapezoid*>(p);
        Rectangle* r = dynamic_cast<Rectangle*>(p);
        Square* sq = dynamic_cast<Square*>(p);
        RegularPentagon* rp = dynamic_cast<RegularPentagon*>(p);

        if(it) out->append("Diagonale: " + QString::number(it->diagonal()));
        if(r) out->append("Diagonale: " + QString::number(r->diagonal()));
        if(sq) out->append("Diagonale: " + QString::number(sq->diagonal()));
        if(rp) out->append("Diagonale: " + QString::number(rp->diagonal(lato->text().toDouble())));
    }
}

// calcola il lato obliquo del trapezio isoscele
void Kalk2DWidget::calcolaLatoObl() {
    out->clear();
    Plane* p = getFigura(figure->currentIndex());
    if(dynamic_cast<IsoscelesTrapezoid*>(p)) {
        out->append(QString::fromStdString(p->getName()));
        out->append("Lato obliquo: " + QString::number(dynamic_cast<IsoscelesTrapezoid*>(p)->leg()));
    }
}

void Kalk2DWidget::calcolaRaggioOut() {
    out->clear();
    Plane* p = getFigura(figure->currentIndex());

    SimplePolygon* sp = dynamic_cast<SimplePolygon*>(p);
    if(sp) {
        out->append(QString::fromStdString(p->getName()));
        out->append("Raggio circonferenza circoscritta: " + QString::number(sp->radius()));
    }
}

// calcola la diagonale solo del cerchio
void Kalk2DWidget::calcolaDiametro() {
    out->clear();
    Plane* p = getFigura(figure->currentIndex());

    Circle* cerchio = dynamic_cast<Circle*>(p);
    if(cerchio) {
        out->append(QString::fromStdString(p->getName()));
        out->append("Diametro: " + QString::number(cerchio->diameter()));
    }
}

// calcola l'altezza del triangolo e del pentagono
void Kalk2DWidget::calcolaAltezza() {
    out->clear();
    Plane* p = getFigura(figure->currentIndex());
    if(p) {
        out->append(QString::fromStdString(p->getName()));

        EquilateralTriangle* et = dynamic_cast<EquilateralTriangle*>(p);
        RegularPentagon* rp = dynamic_cast<RegularPentagon*>(p);

        if(et) out->append("Altezza: " + QString::number(et->height(lato->text().toDouble())));
        if(rp) out->append("Altezza: " + QString::number(rp->height(lato->text().toDouble())));
    }
}

// calcola l'apotema delle figure regolari (quadrato, triangolo equilatero, pentagono)
void Kalk2DWidget::calcolaApotema() {
    out->clear();
    Plane* p = getFigura(figure->currentIndex());
    if(p) {
        out->append(QString::fromStdString(p->getName()));

        RegularPolygon* rp = dynamic_cast<RegularPolygon*>(p);

        if(rp) out->append("Apotema: " + QString::number(rp->apothem()));
    }
}

// stampa il numero di vertici della figura
void Kalk2DWidget::printNumVertici() {
    out->clear();
    Plane* p = getFigura(figure->currentIndex());
    if(dynamic_cast<SimplePolygon*>(p)) {
        out->append(QString::fromStdString(p->getName()));
        out->append("Ha: " + QString::number(dynamic_cast<SimplePolygon*>(p)->vertexCount()) + " vertici.");
    }
}

// espande la figura (in percentuale)
void Kalk2DWidget::espandiFigura() {
    try{
        bool ok;
        double e = QInputDialog::getDouble(this, tr("Espandi"), tr("Di quanto espandere? (percentuale)"), 0, 0, 100, 2, &ok);

        Plane* p = getFigura(figure->currentIndex());

        if(ok && p) {
            out->clear();
            p->expand(e);
            out->append(QString::fromStdString(p->getName()) + " espanso del " + QString::number(e) + "%");

            figSalvata = p;
            impostaFigura();
        }
    }catch(NegativeValue e) { out->setText(QString::fromStdString(e.getError())); }
}

// riduce la figura (in percentuale)
void Kalk2DWidget::riduciFigura() {
    try{
        bool ok;
        double r = QInputDialog::getDouble(this, tr("Espandi"), tr("Di quanto espandere? (percentuale)"), 0, 0, 100, 2, &ok);

        Plane* p = getFigura(figure->currentIndex());

        if(ok && p) {
            out->clear();
            p->reduce(r);
            out->append(QString::fromStdString(p->getName()) + " ridotto del " + QString::number(r) + "%");

            figSalvata = p;
            impostaFigura();
        }
    }catch(ValueOutOfRange e) { out->setText(QString::fromStdString(e.getError())); }
}

// stampa i dati della figura
void Kalk2DWidget::stampaInfo(Plane* p) {
    if(p) {
        RegularPolygon* r = dynamic_cast<RegularPolygon*>(p);
        if(r && (dynamic_cast<Square*>(r) || dynamic_cast<RegularPentagon*>(r) || dynamic_cast<EquilateralTriangle*>(r))) {
            out->append(QString::fromStdString(p->getName()) + " con lato " + QString::number(r->side()));
        }

        if(dynamic_cast<Circle*>(p)) {
            out->append(QString::fromStdString(p->getName()) + " con raggio " + QString::number(dynamic_cast<Circle*>(p)->radius()));
        }

        if(dynamic_cast<Rectangle*>(p)) {
            out->append(QString::fromStdString(p->getName()) + " con base " + QString::number(dynamic_cast<Rectangle*>(p)->base())
                        + " e altezza " + QString::number(dynamic_cast<Rectangle*>(p)->height()));
        }

        if(dynamic_cast<IsoscelesTrapezoid*>(p)) {
            out->append(QString::fromStdString(p->getName()) + " con base lunga " + QString::number(dynamic_cast<IsoscelesTrapezoid*>(p)->longBase())
                        + ", base corta " + QString::number(dynamic_cast<IsoscelesTrapezoid*>(p)->shortBase())
                        + " e altezza " + QString::number(dynamic_cast<IsoscelesTrapezoid*>(p)->height()));
        }
        cancella();
    }
}

// somma collegata al bottone 'piu'
void Kalk2DWidget::sum() {
    figSalvata = getFigura(figure->currentIndex());

    if(figSalvata && opSalvata!='+') {
        out->clear();
        stampaInfo(figSalvata);
        opSalvata = '+';
        out->append("+");
    }
}

// sottrazione collegata al bottone 'meno'
void Kalk2DWidget::subtraction() {
    figSalvata = getFigura(figure->currentIndex());

    if(figSalvata && opSalvata!='-') {
        out->clear();
        stampaInfo(figSalvata);
        opSalvata = '-';
        out->append("-");
    }
}

// moltiplicazione collegata al bottone 'per'
void Kalk2DWidget::multiplication() {
    figSalvata = getFigura(figure->currentIndex());

    if(figSalvata && opSalvata!='x') {
        out->clear();
        stampaInfo(figSalvata);
        opSalvata = 'x';
        out->append("x");
    }
}

// divisione collegata al bottone 'diviso'
void Kalk2DWidget::division() {
    figSalvata = getFigura(figure->currentIndex());

    if(figSalvata && opSalvata!=':') {
        out->clear();
        stampaInfo(figSalvata);
        opSalvata = ':';
        out->append(":");
    }
}

// slot collegato al pulsante 'uguale'
void Kalk2DWidget::calcola() {
    Plane* ora = getFigura(figure->currentIndex());
    if(ora) {
        if(!opSalvata) out->clear();
        stampaInfo(ora);
        if(opSalvata) {

            out->append("=");

            // calcolo
            try{
                Plane* result;
                switch(opSalvata) {
                    case '+':
                        result = *figSalvata + *ora;
                    break;

                    case '-':
                        result = *figSalvata - *ora;
                    break;

                    case 'x':
                        result = *figSalvata * *ora;
                    break;

                    case ':':
                        result = *figSalvata / *ora;
                    break;
                    default:
                        result = nullptr;
                    break;
                }

                stampaInfo(result);
                out->append("Perimetro: " + QString::number(result->perimeter()));
                out->append("Area: " + QString::number(result->area()));
                figSalvata = result;
                imposta->setVisible(true);
            }
            catch(NonPositiveValues e) { out->setText(QString::fromStdString(e.getError())); figSalvata = nullptr; }
            catch(DifferentShapes e) { out->setText(QString::fromStdString(e.getError())); figSalvata = nullptr; }
            catch(CongruentShapes e) { out->setText(QString::fromStdString(e.getError())); figSalvata = nullptr; }
            catch(BigShape e) { out->setText(QString::fromStdString(e.getError())); figSalvata = nullptr; }
        } else figSalvata = ora;
        opSalvata = 0;
    }
}

// cancella tutti i textedit
void Kalk2DWidget::cancella() {
    altezza->clear();
    lato->clear();
    baseLunga->clear();
    baseCorta->clear();
    base->clear();
    raggio->clear();
}

// cancella e resetta tutto
void Kalk2DWidget::cancellaTutto() {
    out->clear();
    cancella();
    figSalvata = nullptr;
    imposta->setVisible(false);
    opSalvata = 0;
}

// imposta gli input della figura salvata
void Kalk2DWidget::impostaFigura() {
    if(dynamic_cast<RegularPolygon*>(figSalvata)) lato->setText(QString::number(dynamic_cast<RegularPolygon*>(figSalvata)->side()));
    if(dynamic_cast<Circle*>(figSalvata)) raggio->setText(QString::number(dynamic_cast<Circle*>(figSalvata)->radius()));
    if(dynamic_cast<Rectangle*>(figSalvata)){
        base->setText(QString::number(dynamic_cast<Rectangle*>(figSalvata)->base()));
        altezza->setText(QString::number(dynamic_cast<Rectangle*>(figSalvata)->height()));
    }
    if(dynamic_cast<IsoscelesTrapezoid*>(figSalvata)){
        baseLunga->setText(QString::number(dynamic_cast<IsoscelesTrapezoid*>(figSalvata)->longBase()));
        baseCorta->setText(QString::number(dynamic_cast<IsoscelesTrapezoid*>(figSalvata)->shortBase()));
        altezza->setText(QString::number(dynamic_cast<IsoscelesTrapezoid*>(figSalvata)->height()));
    }
}

// TRASFORMAZIONE 2D -> 3D

Plane* Kalk2DWidget::getFiguraFrom3D(Solid* s) {
    try{
        if(dynamic_cast<Cube*>(s)) return dynamic_cast<Cube*>(s)->face();
        if(dynamic_cast<Tetrahedron*>(s)) return dynamic_cast<Tetrahedron*>(s)->face();
        if(dynamic_cast<PentagonalPrism*>(s)) return dynamic_cast<PentagonalPrism*>(s)->baseShape();
        if(dynamic_cast<RectangularParallelepiped*>(s)) return dynamic_cast<RectangularParallelepiped*>(s)->baseShape();
        if(dynamic_cast<RightCircularCylinder*>(s)) return dynamic_cast<RightCircularCylinder*>(s)->baseShape();
        if(dynamic_cast<TrapezoidalPrism*>(s)) return dynamic_cast<TrapezoidalPrism*>(s)->baseShape();
    } catch(NonPositiveValues e) { out->setText(QString::fromStdString(e.getError())); return nullptr; }
    return nullptr;
}

void Kalk2DWidget::from2Dto3D() {
    double h = 1;
    Plane* ora = getFigura(figure->currentIndex());
    if(ora) {
        out->clear();
        bool ok = true;
        if(!dynamic_cast<Square*>(ora) && !dynamic_cast<EquilateralTriangle*>(ora)) {
            h = QInputDialog::getDouble(this, tr("Da 2D a 3D"), tr("Inserisci altezza figura solida:"), 0, 0, 1000, 2, &ok);
            if(h <= 0) ok = false;
        }
        if(ok) emit transformInto3D(ora, h);
        else out->setText("Error!");
    }
}

// IMPOSTA DA 3D a 2D

void Kalk2DWidget::setDa3D(Solid* s) {
    figSalvata = getFiguraFrom3D(s);

    if(dynamic_cast<EquilateralTriangle*>(figSalvata)) figure->setCurrentIndex(1);
    if(dynamic_cast<Square*>(figSalvata)) figure->setCurrentIndex(2);
    if(dynamic_cast<Rectangle*>(figSalvata)) figure->setCurrentIndex(3);
    if(dynamic_cast<IsoscelesTrapezoid*>(figSalvata)) figure->setCurrentIndex(4);
    if(dynamic_cast<RegularPentagon*>(figSalvata)) figure->setCurrentIndex(5);
    if(dynamic_cast<Circle*>(figSalvata)) figure->setCurrentIndex(6);

    imposta->setVisible(false);
    impostaFigura();
}

// DISEGNA

void Kalk2DWidget::draw2D() {
    Plane* ora = getFigura(figure->currentIndex());
    if(ora) {
        out->clear();
        emit drawFigure(ora);
    }
}
