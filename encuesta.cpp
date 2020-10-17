#include "encuesta.h"

string Encuesta::getFecha() const
{
    return fecha;
}

void Encuesta::setFecha(const string &value)
{
    fecha = value;
}

int Encuesta::getSatisfaccion() const
{
    return satisfaccion;
}

void Encuesta::setSatisfaccion(int value)
{
    satisfaccion = value;
}

int Encuesta::getId_ventas() const
{
    return id_ventas;
}

void Encuesta::setId_ventas(int value)
{
    id_ventas = value;
}

Encuesta::Encuesta()
{

}
