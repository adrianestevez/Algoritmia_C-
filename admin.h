#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
#include "cliente.h"
#include "articulo.h"
#include "encuesta.h"
#include "ventas.h"
#include <vector>
#include <fstream>
#include "algoritmos.h"
#include <algorithm>

using namespace std;

class Admin
{
    vector<Cliente> clientes;
    vector<Articulo> articulos;
    vector<Encuesta> encuestas;
    vector<Ventas> ventas;

public:
    Admin();
    //Clientes
    void agregar_Clientes(Cliente &c);
    void Respaldar_Clientes();
    void Recuperar_Clientes();

    //Articulos
    void agregar_Articulos (Articulo &a);
    void Respaldar_Articulos();
    void Recuperar_Articulos();

    //Encuesta
    void agregar_Encuesta (Encuesta &e);
    void Respaldar_Encuestas();
    void Recuperar_Encuestas();

    //Ventas
    void agregar_Ventas(Ventas &v);
    void Respaldar_Ventas();
    void Recuperar_Ventas();

    size_t size_clientes()
        {
            return clientes.size();
        }
    size_t size_articulos()
        {
            return articulos.size();
        }
    size_t size_ventas()
        {
            return ventas.size();
        }
    size_t size_encuesta()
        {
            return encuestas.size();
        }

    Cliente pos_cliente(size_t pos){
        return clientes[pos];
    }

    Articulo pos_articulos(size_t pos){
        return articulos[pos];
    }

    Encuesta pos_encuestas(size_t pos){
        return encuestas[pos];
    }

    Ventas pos_ventas(size_t pos){
        return ventas[pos];
    }

    //Clientes
    bool mayorId(Cliente* a, Cliente* b){
        return a->getId() > b->getId();
    }
    void Ordenar_Clientes();
    void Ordenar_Costo();
    void Ordenar_Venta();
    void Ordena_Satisfaccion();
};

#endif // ADMIN_H
