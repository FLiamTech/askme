#include "cuestionario.h"

Cuestionario::Cuestionario()
{

}

Cuestionario::Cuestionario(Tema *tema) : m_tema(tema)
{
    foreach(Apunte *a, m_tema->apuntes())
    {
        m_preguntas.append(new Pregunta(a));
        m_terminos.append(a->termino());
    }
}

Pregunta *Cuestionario::siguiente()
{
    foreach(Pregunta *p, m_preguntas)
    {
        if(!p->respuesta())
        {
            return p;
        }
    }
    return nullptr;
}

const QStringList &Cuestionario::terminos() const
{
    return m_terminos;
}
