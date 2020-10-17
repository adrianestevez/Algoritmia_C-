#ifndef VENTAS_H
#define VENTAS_H
#include <iostream>

using namespace std;

class Ventas
{
    int id,id_cliente,id_articulo;
    float costo,venta;
    string fecha;
public:
    Ventas();
    int getId() const;
    void setId(int value);
    int getId_cliente() const;
    void setId_cliente(int value);
    int getId_articulo() const;
    void setId_articulo(int value);
    float getCosto() const;
    void setCosto(float value);
    float getVenta() const;
    void setVenta(float value);
    string getFecha() const;
    void setFecha(const string &value);
};

#endif // VENTAS_H
