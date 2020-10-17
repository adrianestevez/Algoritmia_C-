#include "ventas.h"

int Ventas::getId() const
{
    return id;
}

void Ventas::setId(int value)
{
    id = value;
}

int Ventas::getId_cliente() const
{
    return id_cliente;
}

void Ventas::setId_cliente(int value)
{
    id_cliente = value;
}

int Ventas::getId_articulo() const
{
    return id_articulo;
}

void Ventas::setId_articulo(int value)
{
    id_articulo = value;
}

float Ventas::getCosto() const
{
    return costo;
}

void Ventas::setCosto(float value)
{
    costo = value;
}

float Ventas::getVenta() const
{
    return venta;
}

void Ventas::setVenta(float value)
{
    venta = value;
}

string Ventas::getFecha() const
{
    return fecha;
}

void Ventas::setFecha(const string &value)
{
    fecha = value;
}

Ventas::Ventas()
{

}
