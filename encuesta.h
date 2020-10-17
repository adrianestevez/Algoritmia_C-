#ifndef ENCUESTA_H
#define ENCUESTA_H
#include <iostream>

using namespace std;

class Encuesta
{
    string fecha;
    int satisfaccion, id_ventas;
public:
    Encuesta();
    string getFecha() const;
    void setFecha(const string &value);
    int getSatisfaccion() const;
    void setSatisfaccion(int value);
    int getId_ventas() const;
    void setId_ventas(int value);
};

#endif // ENCUESTA_H
