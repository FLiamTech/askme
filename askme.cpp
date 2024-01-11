#include "askme.h"
#include "ui_askme.h"

Askme::Askme(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Askme)
{
    ui->setupUi(this);
    cargarDatos();
}

Askme::~Askme()
{
    delete ui;
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


void Askme::on_actionNuevo_triggered()
{
    ApunteForm *w = new ApunteForm(this);
    w->setAsignaturas(m_asignaturas);
    w->cargarAsignaturas();

    cargarSubVentana(w);
}

