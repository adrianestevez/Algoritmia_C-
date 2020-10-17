#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>

using namespace std;

class Cliente
{
    int id;
    string nombre;
public:
    Cliente();
    string getNombre() const;
    void setNombre(const string &value);
    int getId() const;
    void setId(int value);
};

#endif // CLIENTE_H
