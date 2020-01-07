#include "kalk3dwidget.h"

Kalk3DWidget::Kalk3DWidget() {
    QDoubleValidator* validazione = new QDoubleValidator;
    validazione->setNotation(QDoubleValidator::StandardNotation);
    validazione->setBottom(0);

    // Label e lideedit
    base = new QLineEdit;
    base->setValidator(validazione);
    labelBase = new QLabel(tr("&Base:"));
    labelBase->setBuddy(base);

    altezza = new QLineEdit;
    altezza->setValidator(validazione);
    labelAltezza = new QLabel(tr("&Altezza figura piana:"));
    labelAltezza->setBuddy(altezza);

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

    lunghezza = new QLineEdit;
    lunghezza->setValidator(validazione);
    labelLung = new QLabel(tr("&Altezza figura solida:"));
    labelLung->setBuddy(lunghezza);

    // Dropdown menu
    figure = new QComboBox;
    figure->addItem(tr("-- Seleziona figura --"));
    for(std::vector<std::string>::const_iterator it = Factory::nomiFigure3D.begin(); it != Factory::nomiFigure3D.end(); ++it){
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

    volume = new QPushButton(tr("Volume"));
    superficie = new QPushButton(tr("Superficie"));
    supLaterale = new QPushButton(tr("Superficie Laterale"));
    espandi = new QPushButton(tr("Espandi"));
    riduci = new QPushButton(tr("Riduci"));
    raggio = new QPushButton(tr("Raggio"));
    diagonaleSpaziale = new QPushButton(tr("Diagonale spaziale"));
    alt = new QPushButton(tr("Altezza"));

    connect(volume, SIGNAL(clicked()), this, SLOT(calcolaVolume())); // volume
    connect(superficie, SIGNAL(clicked()), this, SLOT(calcolaSuperficie())); // superficie
    connect(supLaterale, SIGNAL(clicked()), this, SLOT(calcolaSupLaterale())); // superficie laterale
    connect(espandi, SIGNAL(clicked()), this, SLOT(espandiFigura())); // espandi
    connect(riduci, SIGNAL(clicked()), this, SLOT(riduciFigura())); // riduci
    connect(raggio, SIGNAL(clicked()), this, SLOT(calcolaRaggio())); // diagonale spaziale
    connect(diagonaleSpaziale, SIGNAL(clicked()), this, SLOT(calcolaDSpaziale())); // diagonale spaziale
    connect(alt, SIGNAL(clicked()), this, SLOT(calcolaAltezza())); // altezza

    trasforma = new QPushButton(tr("Trasforma in 2D"));
    connect(trasforma, SIGNAL(clicked()), this, SLOT(from3Dto2D()));

    numFacce = new QPushButton(tr("Numero facce"));
    numVertici = new QPushButton(tr("Numero vertici"));
    numSpigoli = new QPushButton(tr("Numero spigoli"));
    schlafli = new QPushButton(tr("Notazione di Schläfli"));
    inRaggio = new QPushButton(tr("Raggio cerchio inscritto"));
    outRaggio = new QPushButton(tr("Raggio cerchio circoscritto"));

    connect(numFacce, SIGNAL(clicked()), this, SLOT(printNumFacce())); // numero facce
    connect(numVertici, SIGNAL(clicked()), this, SLOT(printNumVertici())); // numero vertici
    connect(numSpigoli, SIGNAL(clicked()), this, SLOT(printNumSpigoli())); // numero spigoli
    connect(schlafli, SIGNAL(clicked()), this, SLOT(printSchlafli())); // notazione di Schlafli
    connect(inRaggio, SIGNAL(clicked()), this, SLOT(printRaggioIn())); // raggio circonferenza inscritta
    connect(outRaggio, SIGNAL(clicked()), this, SLOT(printRaggioOut())); // raggio circonferenza circoscritta

    reset();

    // Layout
    QHBoxLayout* bottoni = new QHBoxLayout;
    bottoni->addWidget(c);
    bottoni->addWidget(ce);
    bottoni->addWidget(imposta);

    QGridLayout* dati = new QGridLayout;
    dati->addWidget(figure, 0, 0, 1, 2);
    dati->addWidget(labelBase, 1, 0);
    dati->addWidget(base, 1, 1);
    dati->addWidget(labelLato, 2, 0);
    dati->addWidget(lato, 2, 1);
    dati->addWidget(labelBL, 3, 0);
    dati->addWidget(baseLunga, 3, 1);
    dati->addWidget(labelBC, 4, 0);
    dati->addWidget(baseCorta, 4, 1);
    dati->addWidget(labelAltezza, 5, 0);
    dati->addWidget(altezza, 5, 1);
    dati->addWidget(labelLung, 6, 0);
    dati->addWidget(lunghezza, 6, 1);
    dati->addLayout(bottoni, 7, 0, 1, 2);

    QVBoxLayout* opUnarie = new QVBoxLayout;
    opUnarie->addWidget(volume);
    opUnarie->addWidget(superficie);
    opUnarie->addWidget(raggio);
    opUnarie->addWidget(supLaterale);
    opUnarie->addWidget(diagonaleSpaziale);
    opUnarie->addWidget(alt);
    opUnarie->addWidget(espandi);
    opUnarie->addWidget(riduci);

    QVBoxLayout* opStatiche = new QVBoxLayout;
    opStatiche->addWidget(numFacce);
    opStatiche->addWidget(numVertici);
    opStatiche->addWidget(numSpigoli);
    opStatiche->addWidget(schlafli);
    opStatiche->addWidget(inRaggio);
    opStatiche->addWidget(outRaggio);

    QVBoxLayout* opBinarie = new QVBoxLayout;
    opBinarie->addWidget(piu);
    opBinarie->addWidget(meno);
    opBinarie->addWidget(per);
    opBinarie->addWidget(diviso);
    opBinarie->addWidget(uguale);

    QHBoxLayout* body = new QHBoxLayout;
    body->addLayout(dati);
    body->addLayout(opUnarie);
    body->addLayout(opStatiche);
    body->addLayout(opBinarie);

    out = new QTextEdit;
    out->setVisible(false);
    out->setReadOnly(true);
    out->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    out->setFont(QFont("Times", 20));

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(body);
    mainLayout->addWidget(out);
    mainLayout->addWidget(trasforma);
    setLayout(mainLayout);
}

// CONTROLLER

// imposta la situazione iniziale con tutto nascosto tranne il dropdown menu
void Kalk3DWidget::reset() {
    figure->setCurrentIndex(0);
    labelBase->setVisible(false);
    base->setVisible(false);
    labelAltezza->setVisible(false);
    altezza->setVisible(false);
    labelLato->setVisible(false);
    lato->setVisible(false);
    labelBL->setVisible(false);
    baseLunga->setVisible(false);
    labelBC->setVisible(false);
    baseCorta->setVisible(false);
    labelLung->setVisible(false);
    lunghezza->setVisible(false);
    figSalvata = nullptr;

    // nascondi bottoni
    piu->setVisible(false);
    meno->setVisible(false);
    per->setVisible(false);
    diviso->setVisible(false);
    uguale->setVisible(false);
    volume->setVisible(false);
    superficie->setVisible(false);
    raggio->setVisible(false);
    supLaterale->setVisible(false);
    espandi->setVisible(false);
    riduci->setVisible(false);
    c->setVisible(false);
    ce->setVisible(false);
    imposta->setVisible(false);
    diagonaleSpaziale->setVisible(false);
    alt->setVisible(false);
    trasforma->setVisible(false);

    numFacce->setVisible(false);
    numVertici->setVisible(false);
    numSpigoli->setVisible(false);
    schlafli->setVisible(false);
    inRaggio->setVisible(false);
    outRaggio->setVisible(false);
}

// in base a quale sia l'indice del menu mostra gli input adeguati
void Kalk3DWidget::displayInput(int f) {
    piu->setVisible(true);
    meno->setVisible(true);
    per->setVisible(true);
    diviso->setVisible(true);
    uguale->setVisible(true);
    volume->setVisible(true);
    superficie->setVisible(true);
    supLaterale->setVisible(true);
    espandi->setVisible(true);
    riduci->setVisible(true);
    out->setVisible(true);
    c->setVisible(true);
    ce->setVisible(true);
    trasforma->setVisible(true);

    switch (f) {
        case 1: // Cilindro
            labelBase->setVisible(true);
            base->setVisible(true);
            labelLung->setVisible(true);
            lunghezza->setVisible(true);
            raggio->setVisible(true);

            labelLato->setVisible(false);
            lato->setVisible(false);
            labelBL->setVisible(false);
            baseLunga->setVisible(false);
            labelBC->setVisible(false);
            baseCorta->setVisible(false);
            labelAltezza->setVisible(false);
            altezza->setVisible(false);
            diagonaleSpaziale->setVisible(false);
            numFacce->setVisible(false);
            numSpigoli->setVisible(false);
            schlafli->setVisible(false);
            inRaggio->setVisible(false);
            outRaggio->setVisible(false);
            numVertici->setVisible(false);
        break;

        case 2: // Cubo
            labelLato->setVisible(true);
            lato->setVisible(true);
            diagonaleSpaziale->setVisible(true);
            numFacce->setVisible(true);
            numVertici->setVisible(true);
            numSpigoli->setVisible(true);
            schlafli->setVisible(true);
            inRaggio->setVisible(true);
            outRaggio->setVisible(true);

            labelBase->setVisible(false);
            base->setVisible(false);
            labelAltezza->setVisible(false);
            altezza->setVisible(false);
            labelBL->setVisible(false);
            baseLunga->setVisible(false);
            labelBC->setVisible(false);
            baseCorta->setVisible(false);
            labelLung->setVisible(false);
            lunghezza->setVisible(false);
            alt->setVisible(false);
            raggio->setVisible(false);
        break;

        case 3: // Tetraedro
            labelLato->setVisible(true);
            lato->setVisible(true);
            alt->setVisible(true);
            numFacce->setVisible(true);
            numVertici->setVisible(true);
            numSpigoli->setVisible(true);
            schlafli->setVisible(true);
            inRaggio->setVisible(true);
            outRaggio->setVisible(true);

            labelBase->setVisible(false);
            base->setVisible(false);
            labelAltezza->setVisible(false);
            altezza->setVisible(false);
            labelBL->setVisible(false);
            baseLunga->setVisible(false);
            labelBC->setVisible(false);
            baseCorta->setVisible(false);
            labelLung->setVisible(false);
            lunghezza->setVisible(false);
            diagonaleSpaziale->setVisible(false);
            raggio->setVisible(false);
        break;

        case 4: // Prisma trapezoide
            labelBL->setVisible(true);
            baseLunga->setVisible(true);
            labelBC->setVisible(true);
            baseCorta->setVisible(true);
            labelAltezza->setVisible(true);
            altezza->setVisible(true);
            labelLung->setVisible(true);
            lunghezza->setVisible(true);
            numFacce->setVisible(true);
            numVertici->setVisible(true);
            numSpigoli->setVisible(true);

            labelLato->setVisible(false);
            lato->setVisible(false);
            labelBase->setVisible(false);
            base->setVisible(false);
            diagonaleSpaziale->setVisible(false);
            alt->setVisible(false);
            schlafli->setVisible(false);
            inRaggio->setVisible(false);
            outRaggio->setVisible(false);
            raggio->setVisible(false);
        break;

        case 5: // Prisma pentagonale
            labelLato->setVisible(true);
            lato->setVisible(true);
            labelLung->setVisible(true);
            lunghezza->setVisible(true);
            numFacce->setVisible(true);
            numVertici->setVisible(true);
            numSpigoli->setVisible(true);

            labelBase->setVisible(false);
            base->setVisible(false);
            labelBL->setVisible(false);
            baseLunga->setVisible(false);
            labelBC->setVisible(false);
            baseCorta->setVisible(false);
            labelAltezza->setVisible(false);
            altezza->setVisible(false);
            diagonaleSpaziale->setVisible(false);
            alt->setVisible(false);
            schlafli->setVisible(false);
            inRaggio->setVisible(false);
            outRaggio->setVisible(false);
            raggio->setVisible(false);
        break;

        case 6: // Parallelepipedo rettangolo
            labelBase->setVisible(true);
            base->setVisible(true);
            labelAltezza->setVisible(true);
            altezza->setVisible(true);
            labelLung->setVisible(true);
            lunghezza->setVisible(true);
            numFacce->setVisible(true);
            numVertici->setVisible(true);
            numSpigoli->setVisible(true);

            labelLato->setVisible(false);
            lato->setVisible(false);
            labelBL->setVisible(false);
            baseLunga->setVisible(false);
            labelBC->setVisible(false);
            baseCorta->setVisible(false);
            diagonaleSpaziale->setVisible(false);
            alt->setVisible(false);
            schlafli->setVisible(false);
            inRaggio->setVisible(false);
            outRaggio->setVisible(false);
            raggio->setVisible(false);
        break;

        default:
            reset();
            out->setVisible(false);
        break;
    }
    imposta->setVisible(false);
    out->clear();
    cancella();
}

// ritorna la figura con i dati inseriti, se i campi son vuoti ritorna la figura costruita di default
Solid* Kalk3DWidget::getFigura(int f) {
    try{
        switch (f) {
            case 1: // Cilindro
                if(base->text().isEmpty() && lunghezza->text().isEmpty()) return new RightCircularCylinder;
                return new RightCircularCylinder(base->text().toDouble(), lunghezza->text().toDouble());
            break;

            case 2: // Cubo
                if(lato->text().isEmpty()) return new Cube;
                return new Cube(lato->text().toDouble());
            break;

            case 3: // Tetraedro
                if(lato->text().isEmpty()) return new Tetrahedron;
                return new Tetrahedron(lato->text().toDouble());
            break;

            case 4: // Prisma trapezoide
                if(baseLunga->text().isEmpty() && baseCorta->text().isEmpty() && altezza->text().isEmpty() && lunghezza->text().isEmpty()) return new TrapezoidalPrism;
                return new TrapezoidalPrism(baseLunga->text().toDouble(), baseCorta->text().toDouble(), altezza->text().toDouble(), lunghezza->text().toDouble());
            break;

            case 5: // Prisma pentagonale
                if(lato->text().isEmpty() && lunghezza->text().isEmpty()) return new PentagonalPrism;
                return new PentagonalPrism(lato->text().toDouble(), lunghezza->text().toDouble());
            break;

            case 6: // Parallelepipedo rettangolo
                if(base->text().isEmpty() && altezza->text().isEmpty() && lunghezza->text().isEmpty()) return new RectangularParallelepiped;
                return new RectangularParallelepiped(base->text().toDouble(), altezza->text().toDouble(), lunghezza->text().toDouble());
            break;

            default:
                return nullptr;
            break;
        }
    }
    catch(NonPositiveValues e) { out->setText(QString::fromStdString(e.getError())); opSalvata=0; return nullptr; }
    catch(UnsuitableValues e) { out->setText(QString::fromStdString(e.getError())); opSalvata=0; return nullptr; }
}

// stampa il numero di facce della figura 3D
void Kalk3DWidget::printNumFacce() {
    out->clear();
    Solid* s = getFigura(figure->currentIndex());

    if(dynamic_cast<Polyhedron*>(s)) {
        out->append(QString::fromStdString(s->getName()));
        out->append("Ha " + QString::number(dynamic_cast<Polyhedron*>(s)->faceCount()) + " facce.");
    }
}

// stampa il numero di vertici della figura
void Kalk3DWidget::printNumVertici() {
    out->clear();
    Solid* s = getFigura(figure->currentIndex());

    if(dynamic_cast<Polyhedron*>(s)) {
        out->append(QString::fromStdString(s->getName()));
        out->append("Ha " + QString::number(dynamic_cast<Polyhedron*>(s)->vertexCount()) + " vertici.");
    }
}

// stampa il numero di spigoli della figura
void Kalk3DWidget::printNumSpigoli() {
    out->clear();
    Solid* s = getFigura(figure->currentIndex());

    if(dynamic_cast<Polyhedron*>(s)) {
        out->append(QString::fromStdString(s->getName()));
        out->append("Ha " + QString::number(dynamic_cast<Polyhedron*>(s)->edgeCount()) + " spigoli.");
    }
}

// stampa la notazione di Schlafli
void Kalk3DWidget::printSchlafli() {
    out->clear();
    Solid* s = getFigura(figure->currentIndex());

    if(dynamic_cast<PlatonicSolid*>(s)) {
        out->append(QString::fromStdString(s->getName()));
        out->append("Notazione di Schläfli: " + QString::fromStdString(dynamic_cast<PlatonicSolid*>(s)->schlafliSymbol()));
    }
}

// stampa il raggio della circonferenza inscritta
void Kalk3DWidget::printRaggioIn() {
    out->clear();
    Solid* s = getFigura(figure->currentIndex());

    if(dynamic_cast<PlatonicSolid*>(s)) {
        out->append(QString::fromStdString(s->getName()));
        out->append("Raggio circonferenza inscritta: " + QString::number(dynamic_cast<PlatonicSolid*>(s)->inRadius()));
    }
}

// stampa il raggio della circonferenza circoscritta
void Kalk3DWidget::printRaggioOut() {
    out->clear();
    Solid* s = getFigura(figure->currentIndex());

    if(dynamic_cast<PlatonicSolid*>(s)) {
        out->append(QString::fromStdString(s->getName()));
        out->append("Raggio circonferenza circoscritta: " + QString::number(dynamic_cast<PlatonicSolid*>(s)->circumRadius()));
    }
}

// calcola il volume della figura solida
void Kalk3DWidget::calcolaVolume() {
    out->clear();
    Solid* s = getFigura(figure->currentIndex());
    if(s) {
        out->append(QString::fromStdString(s->getName()));
        out->append("Volume: " + QString::number(s->volume()));
    }
}

// calcola la superficie della figura solida
void Kalk3DWidget::calcolaSuperficie() {
    out->clear();
    Solid* s = getFigura(figure->currentIndex());
    if(s) {
        out->append(QString::fromStdString(s->getName()));
        out->append("Superficie: " + QString::number(s->surface()));
    }
}

// calcola la superficie laterale
void Kalk3DWidget::calcolaSupLaterale() {
    out->clear();
    Solid* s = getFigura(figure->currentIndex());
    if(s) {
        out->append(QString::fromStdString(s->getName()));
        out->append("Superficie laterale: " + QString::number(s->lateralSurface()));
    }
}

// calcola il raggio della figura base del cilindro
void Kalk3DWidget::calcolaRaggio() {
    out->clear();
    RightCircularCylinder* s = dynamic_cast<RightCircularCylinder*>(getFigura(figure->currentIndex()));
    if(s) {
        out->append(QString::fromStdString(s->getName()));
        out->append("Raggio: " + QString::number(s->radius()));
    }
}

// calcola la diagonale spaziale solo del cubo
void Kalk3DWidget::calcolaDSpaziale() {
    out->clear();
    Cube* s = dynamic_cast<Cube*>(getFigura(figure->currentIndex()));
    if(s) {
        out->append(QString::fromStdString(s->getName()));
        out->append("Diagonale spaziale: " + QString::number(s->spaceDiagonal()));
    }
}

// calcola l'altezza del tetraedro
void Kalk3DWidget::calcolaAltezza() {
    out->clear();
    Tetrahedron* s = dynamic_cast<Tetrahedron*>(getFigura(figure->currentIndex()));
    if(s) {
        out->append(QString::fromStdString(s->getName()));
        out->append("Altezza: " + QString::number(s->height(s->edge())));
    }
}

// espande la figura (in percentuale)
void Kalk3DWidget::espandiFigura() {
    try{
        bool ok;
        double e = QInputDialog::getDouble(this, tr("Espandi"), tr("Di quanto espandere? (percentuale)"), 0, 0, 100, 2, &ok);

        Solid* s = getFigura(figure->currentIndex());

        if(ok && s) {
            out->clear();
            s->expand(e);
            out->append(QString::fromStdString(s->getName()) + " espanso del " + QString::number(e) + "%");

            figSalvata = s;
            impostaFigura();
        }
    }catch(NegativeValue e) { out->setText(QString::fromStdString(e.getError())); }
}

// riduce la figura (in percentuale)
void Kalk3DWidget::riduciFigura() {
    try{
        bool ok;
        double r = QInputDialog::getDouble(this, tr("Espandi"), tr("Di quanto espandere? (percentuale)"), 0, 0, 100, 2, &ok);

        Solid* s = getFigura(figure->currentIndex());

        if(ok && s) {
            out->clear();
            s->reduce(r);
            out->append(QString::fromStdString(s->getName()) + " ridotto del " + QString::number(r) + "%");

            figSalvata = s;
            impostaFigura();
        }
    }catch(ValueOutOfRange e) { out->setText(QString::fromStdString(e.getError())); }
}

// stampa i dati della figura
void Kalk3DWidget::stampaInfo(Solid* s) {
    if(s) {
        RightCircularCylinder* rcc = dynamic_cast<RightCircularCylinder*>(s);
        if(rcc) {
            out->append(QString::fromStdString(s->getName()) + " con base " + QString::number((rcc->baseShape())->diameter())
                        + " e lungo " + QString::number(rcc->height()));
        }

        if(dynamic_cast<Cube*>(s)){
            out->append(QString::fromStdString(s->getName()) + " con lato " + QString::number(dynamic_cast<Cube*>(s)->edge()));
        }

        Tetrahedron* t = dynamic_cast<Tetrahedron*>(s);
        if(t){
            out->append(QString::fromStdString(s->getName()) + " con lato " + QString::number(t->edge()));
        }

        TrapezoidalPrism* tp = dynamic_cast<TrapezoidalPrism*>(s);
        if(tp) {
            out->append(QString::fromStdString(s->getName()) + " con base lunga " + QString::number((tp->baseShape())->longBase())
                        + ", base corta " + QString::number((tp->baseShape())->shortBase())
                        + ", altezza " + QString::number((tp->baseShape())->height())
                        + " e lungo " + QString::number(tp->height()));
        }

        PentagonalPrism* pp = dynamic_cast<PentagonalPrism*>(s);
        if(pp) {
            out->append(QString::fromStdString(s->getName()) + " con lato " + QString::number(pp->baseShape()->side())
                        + " e lungo " + QString::number(pp->height()));
        }

        RectangularParallelepiped* rp = dynamic_cast<RectangularParallelepiped*>(s);
        if(rp){
            out->append(QString::fromStdString(s->getName()) + " con base " + QString::number(rp->baseShape()->base())
                        + ", altezza " + QString::number(rp->baseShape()->height()) +
                        + " e lungo " + QString::number(rp->height()));
        }

        cancella();
    }
}

// somma collegata al bottone 'piu'
void Kalk3DWidget::sum() {
    figSalvata = getFigura(figure->currentIndex());

    if(figSalvata && opSalvata!='+') {
        out->clear();
        stampaInfo(figSalvata);
        opSalvata = '+';
        out->append("+");
    }
}

// sottrazione collegata al bottone 'meno'
void Kalk3DWidget::subtraction() {
    figSalvata = getFigura(figure->currentIndex());

    if(figSalvata && opSalvata!='-') {
        out->clear();
        stampaInfo(figSalvata);
        opSalvata = '-';
        out->append("-");
    }
}

// moltiplicazione collegata al bottone 'per'
void Kalk3DWidget::multiplication() {
    figSalvata = getFigura(figure->currentIndex());

    if(figSalvata && opSalvata!='x') {
        out->clear();
        stampaInfo(figSalvata);
        opSalvata = 'x';
        out->append("x");
    }
}

// divisione collegata al bottone 'diviso'
void Kalk3DWidget::division() {
    figSalvata = getFigura(figure->currentIndex());

    if(figSalvata && opSalvata!=':') {
        out->clear();
        stampaInfo(figSalvata);
        opSalvata = ':';
        out->append(":");
    }
}

// slot collegato al pulsante 'uguale'
void Kalk3DWidget::calcola() {
    Solid* ora = getFigura(figure->currentIndex());
    if(ora){
        if(!opSalvata) out->clear();
        stampaInfo(ora);
        if(opSalvata) {

            out->append("=");

            // calcolo
            Solid* result;
            try{
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
                out->append("Superficie: " + QString::number(result->surface()));
                out->append("Volume: " + QString::number(result->volume()));
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
void Kalk3DWidget::cancella() {
    lato->clear();
    base->clear();
    altezza->clear();
    baseLunga->clear();
    baseCorta->clear();
    lunghezza->clear();
}

// cancella e resetta tutto
void Kalk3DWidget::cancellaTutto() {
    out->clear();
    cancella();
    figSalvata = nullptr;
    imposta->setVisible(false);
    opSalvata = 0;
}

// imposta gli input della figura salvata
void Kalk3DWidget::impostaFigura() {
    RightCircularCylinder* rcc = dynamic_cast<RightCircularCylinder*>(figSalvata);
    if(rcc) {
        base->setText(QString::number((rcc->baseShape())->diameter()));
        lunghezza->setText(QString::number(rcc->height()));
    }

    Cube* c = dynamic_cast<Cube*>(figSalvata);
    if(c){
        lato->setText(QString::number(c->edge()));
    }

    Tetrahedron* t = dynamic_cast<Tetrahedron*>(figSalvata);
    if(t){
        lato->setText(QString::number(t->edge()));
    }

    TrapezoidalPrism* tp = dynamic_cast<TrapezoidalPrism*>(figSalvata);
    if(tp) {
        baseLunga->setText(QString::number(tp->baseShape()->longBase()));
        baseCorta->setText(QString::number(tp->baseShape()->shortBase()));
        altezza->setText(QString::number(tp->baseShape()->height()));
        lunghezza->setText(QString::number(tp->height()));
    }

    PentagonalPrism* pp = dynamic_cast<PentagonalPrism*>(figSalvata);
    if(pp) {
        lato->setText(QString::number(pp->baseShape()->side()));
        lunghezza->setText(QString::number(pp->height()));
    }

    RectangularParallelepiped* rp = dynamic_cast<RectangularParallelepiped*>(figSalvata);
    if(rp){
        base->setText(QString::number(rp->baseShape()->base()));
        altezza->setText(QString::number(rp->baseShape()->height()));
        lunghezza->setText(QString::number(rp->height()));
    }
}

// TRASFORMAZIONE 3D -> 2D

Solid* Kalk3DWidget::getFiguraFrom2D(Plane* p, double h) {
    if(dynamic_cast<Circle*>(p)) return new RightCircularCylinder(dynamic_cast<Circle*>(p), h);
    if(dynamic_cast<Square*>(p)) return new Cube(dynamic_cast<Square*>(p));
    if(dynamic_cast<Rectangle*>(p)) return new RectangularParallelepiped(dynamic_cast<Rectangle*>(p), h);
    if(dynamic_cast<EquilateralTriangle*>(p)) return new Tetrahedron(dynamic_cast<EquilateralTriangle*>(p));
    if(dynamic_cast<RegularPentagon*>(p)) return new PentagonalPrism(dynamic_cast<RegularPentagon*>(p), h);
    if(dynamic_cast<IsoscelesTrapezoid*>(p)) return new TrapezoidalPrism(dynamic_cast<IsoscelesTrapezoid*>(p), h);

    return nullptr;
}

void Kalk3DWidget::setDa2D(Plane* p, double h) {
    figSalvata = getFiguraFrom2D(p, h);
    if(dynamic_cast<RightCircularCylinder*>(figSalvata)) figure->setCurrentIndex(1);
    if(dynamic_cast<Cube*>(figSalvata)) figure->setCurrentIndex(2);
    if(dynamic_cast<Tetrahedron*>(figSalvata)) figure->setCurrentIndex(3);
    if(dynamic_cast<TrapezoidalPrism*>(figSalvata)) figure->setCurrentIndex(4);
    if(dynamic_cast<PentagonalPrism*>(figSalvata)) figure->setCurrentIndex(5);
    if(dynamic_cast<RectangularParallelepiped*>(figSalvata)) figure->setCurrentIndex(6);
    impostaFigura();
    imposta->setVisible(false);
}

// TRASFORMAZIONE 3D -> 2D

void Kalk3DWidget::from3Dto2D() {
    Solid* ora = getFigura(figure->currentIndex());
    if(ora) {
        out->clear();
        emit transformInto2D(ora);
    }
}
