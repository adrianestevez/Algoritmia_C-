#include "articulo.h"

int Articulo::getId() const
{
    return id;
}

void Articulo::setId(int value)
{
    id = value;
}

float Articulo::getCosto() const
{
    return costo;
}

void Articulo::setCosto(float value)
{
    costo = value;
}

float Articulo::getVenta() const
{
    return venta;
}

void Articulo::setVenta(float value)
{
    venta = value;
}

string Articulo::getNombre() const
{
    return nombre;
}

void Articulo::setNombre(const string &value)
{
    nombre = value;
}

Articulo::Articulo()
{

}
