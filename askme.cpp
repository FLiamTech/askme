#include "askme.h"
#include "ui_askme.h"

Askme::Askme(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Askme)
{
    ui->setupUi(this);
    cargarDatos();
    connect(ui->actionCargar, SIGNAL(released()), this, SLOT(on_actionCargar_triggered()));
}

Askme::~Askme()
{
    delete ui;
}

void Askme::on_apunteTomado(Apunte *apunte)
{
    foreach(Asignatura *a, m_asignaturas)
    {
        qDebug().noquote() << a->toString();
    }
    guardar();
}

void Askme::cargarSubVentana(QWidget *ventana)
{
    auto sub = ui->mdiArea->addSubWindow(ventana);
    sub->show();
}

void Askme::cargarDatos()
{
    Tema *t1 = new Tema("Electromagnetismo");
    t1->agregarApunte(new Apunte("Carga electrica", "Son cargas electricas que sirven para la electricidad"));
    t1->agregarApunte(new Apunte("Campo electrico", "Recion del espacio alrededor de una esfera"));
    t1->agregarApunte(new Apunte("Ley de Faraday", "Recion del espacio alrededor de una esfera"));
    t1->agregarApunte(new Apunte("Coulomb", "Recion del espacio alrededor de una esfera"));
    t1->agregarApunte(new Apunte("Ley de ampere", "Relacion matematica que describe la circulacion de un campo magnetico a"));

    Tema *t2 = new Tema("Optica");
    t2->agregarApunte(new Apunte("Luz", "Luz que hace ver bien"));
    t2->agregarApunte(new Apunte("Refreccion", "Cambio de direccion del un rayo de luz"));
    t2->agregarApunte(new Apunte("Jordan", "Jos joras son mu buenos"));
    t2->agregarApunte(new Apunte("Prisma", "Objeto optico que sirve para ver la luz"));
    t2->agregarApunte(new Apunte("Dispersion", "Separacion entre lo esto y lo estiotro"));

    Asignatura *a1 = new Asignatura("Fisica");
    a1->agregarTema(t1);
    a1->agregarTema(t2);

    t1 = new Tema("Ecologia");
    t1->agregarApunte(new Apunte("Ecosistema", "Sistema ambiental de la naturaleza"));
    t1->agregarApunte(new Apunte("Biodiversidad", "Entorno fisico entre el ser humano y la naturaleza"));
    t1->agregarApunte(new Apunte("Cadena alimentaria", "Serie de organismos en una piramide alimenticia"));
    t1->agregarApunte(new Apunte("Ciclo del agua", "Proceso continuo de circulacion del agua entre esto y eso"));
    t1->agregarApunte(new Apunte("Bioma", "Gran area geografica con caracteristicas climaticas similares a"));

    t2 = new Tema("Genetica");
    t2->agregarApunte(new Apunte("ADN", "Acido disoxido Ribonucleico"));
    t2->agregarApunte(new Apunte("Gen", "Unidades de informacion hereditaria"));
    t2->agregarApunte(new Apunte("Cromosomas", "Estructura compuesta por adn y proteinas"));
    t2->agregarApunte(new Apunte("Mutacion", "Cambio en la secuencia de ADN que puede dar lugar a"));
    t2->agregarApunte(new Apunte("Herencia", "Tramsisiones de caracteristicas geneticas de padres a descendientes"));

    Asignatura *a2 = new Asignatura("Ciencias naturales");
    a2->agregarTema(t1);
    a2->agregarTema(t2);

    m_asignaturas.append(a1);
    m_asignaturas.append(a2);
}

void Askme::guardar()
{
    QFile file(ARCHIVO);
    qDebug() << "Intentando abrir el archivo para escribir...";
    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Archivo abierto correctamente.";
        QTextStream salida(&file);
        salida << "Asignatura\tTema\tTermino\tConcepto\n";
        foreach(Asignatura *a, m_asignaturas)
        {
            QString nombreAsignatura = a->nombre();
            foreach(Tema *t, a->temas())
            {
                QString nombreTema = t->nombre();
                foreach (Apunte *ap, t->apuntes())  // Cambié el nombre a 'ap'
                {
                    QString termino = ap->termino();  // Cambié el nombre a 'ap'
                    QString concepto = ap->concepto();  // Cambié el nombre a 'ap'

                    salida << nombreAsignatura << "\t" << nombreTema << "\t" << termino << "\t" << concepto << "\n";
                }
            }
        }
        file.close();
        qDebug() << "Archivo cerrado correctamente.";
    }
    else
    {
        QMessageBox::critical(this, "Agregar apunte", "No se pudieron guardar los datos");
        qDebug() << "Error al abrir el archivo para escribir.";
    }
}

void Askme::cargar()
{
    QFile file(ARCHIVO);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream entrada(&file);
        entrada.readLine();
        while(!entrada.atEnd())
        {
            QString linea = entrada.readLine();
            QStringList datos = linea.split("\t");
            QString nombreAsignatura = datos[0];
            QString nombreTema = datos[1];
            QString termino = datos[2];
            QString concepto = datos[3];

            Asignatura *asignatura = nullptr;
            Tema *tema = nullptr;

            foreach(Asignatura *a, m_asignaturas)
            {
                if(a->nombre() == nombreAsignatura)
                {
                    asignatura = a;
                    foreach(Tema *t, a->temas())
                    {
                        if(t->nombre() == nombreTema)
                        {
                            tema = t;
                            break;
                        }
                    }
                    break;
                }
            }
            if(asignatura && tema)
            {
                Apunte *apunte = new Apunte(termino, concepto);
                tema->agregarApunte(apunte);
            }
        }
        file.close();
    }
    else
    {
        QMessageBox::critical(this, "Cargar datos", "No se pudieron cargar los datos");
    }
}

void Askme::agregarApuntes(Asignatura *a, Tema *t, Apunte *ap)
{
    if(a && t)
    {
        t->agregarApunte(ap);
    }
}

void Askme::on_actionNuevo_triggered()
{
    ApunteForm *w = new ApunteForm(this);
    w->setAsignaturas(m_asignaturas);
    w->cargarAsignaturas();
    connect(w, SIGNAL(apunteTomado(Apunte*)), this, SLOT(agregarApunte(Asignatura *, Tema *, Apunte *)));
    cargarSubVentana(w);
    guardar();
}


void Askme::on_actionCargar_triggered()
{
        cargar();
        QMessageBox::information(this, "Cargar datos", "Datos cargados correctamente.");
}


void Askme::on_actionLista_triggered()
{
        listaForm *w = new listaForm(this);
        cargarSubVentana(w);
        w->show();

}

