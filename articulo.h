#ifndef ARTICULO_H
#define ARTICULO_H
#include <iostream>

using namespace std;

class Articulo
{
    int id;
    float costo, venta;
    string nombre;
public:
    Articulo();
    int getId() const;
    void setId(int value);
    float getCosto() const;
    void setCosto(float value);
    float getVenta() const;
    void setVenta(float value);
    string getNombre() const;
    void setNombre(const string &value);
};

#endif // ARTICULO_H
