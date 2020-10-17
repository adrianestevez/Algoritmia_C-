#include "cliente.h"

string Cliente::getNombre() const
{
    return nombre;
}

void Cliente::setNombre(const string &value)
{
    nombre = value;
}

int Cliente::getId() const
{
    return id;
}

void Cliente::setId(int value)
{
    id = value;
}

Cliente::Cliente()
{

}
