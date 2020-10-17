#include "admin.h"

Admin::Admin()
{

}

//Clientes
void Admin::agregar_Clientes(Cliente &c)
{
        clientes.push_back(c);
}

void Admin::Respaldar_Clientes()
{
    fstream archivo("Clientes.txt",ios::out);

    if(archivo.is_open()){
        for (unsigned int j = 0; j < clientes.size(); ++j) {
            Cliente &c = clientes[j];

            archivo<<c.getId()<<endl;
            archivo<<c.getNombre()<<endl;

        }
    }
}

void Admin::Recuperar_Clientes()
{
    fstream archivo("Clientes.txt",ios::in);

    if(archivo.is_open()){
        while (!archivo.eof()) {
            Cliente c;
            string s;

            getline(archivo, s);
            if (archivo.eof()) {
                break;
            }
            int id= stoi(s);
            c.setId(id);

            getline(archivo,s);
            c.setNombre(s);

            agregar_Clientes(c);
        }
    }
}


//Articulos
void Admin::agregar_Articulos(Articulo &a)
{
    articulos.push_back(a);

}

void Admin::Respaldar_Articulos()
{
    fstream archivo("Articulos.txt",ios::out);

    if(archivo.is_open()){
        for (unsigned int j = 0; j < articulos.size(); ++j) {
            Articulo &a = articulos[j];

            archivo<<a.getId()<<endl;
            archivo<<a.getNombre()<<endl;
            archivo<<a.getCosto()<<endl;
            archivo<<a.getVenta()<<endl;

        }
    }
}

void Admin::Recuperar_Articulos()
{
    fstream archivo("Articulos.txt",ios::in);

    if(archivo.is_open()){
        while (!archivo.eof()) {
            Articulo a;
            string s;
            float f;

            getline(archivo, s);
            if (archivo.eof()) {
                break;
            }

            int id = stoi(s);
            a.setId(id);

            getline(archivo,s);
            a.setNombre(s);

            getline(archivo,s);
            f = stof(s);
            a.setCosto(f);

            getline(archivo,s);
            f = stof(s);
            a.setVenta(f);

            agregar_Articulos(a);
        }
    }
}


//Encuestas
void Admin::agregar_Encuesta(Encuesta &e)
{
    encuestas.push_back(e);
}

void Admin::Respaldar_Encuestas()
{
    fstream archivo("Encuestas.txt",ios::out);

    if(archivo.is_open()){
        for (unsigned int j = 0; j < encuestas.size(); ++j) {
            Encuesta &e = encuestas[j];

            archivo<<e.getFecha()<<endl;
            archivo<<e.getSatisfaccion()<<endl;
            archivo<<e.getId_ventas()<<endl;

        }
    }
}

void Admin::Recuperar_Encuestas()
{
    fstream archivo("Encuestas.txt",ios::in);
    if(archivo.is_open()){
        while (!archivo.eof()) {
            Encuesta e;
            string s;
            int i;

            getline(archivo, s);
            if (archivo.eof()) {
                break;
            }
            e.setFecha(s);

            getline(archivo,s);
            i = stoi(s);
            e.setSatisfaccion(i);

            getline(archivo,s);
            i = stoi(s);
            e.setId_ventas(i);

            agregar_Encuesta(e);
        }
    }
}


//Ventas
void Admin::agregar_Ventas(Ventas &v)
{
    ventas.push_back(v);
}

void Admin::Respaldar_Ventas()
{
    fstream archivo("Ventas.txt",ios::out);

    if(archivo.is_open()){
        for (unsigned int j = 0; j < ventas.size(); ++j) {
            Ventas &v = ventas[j];

            archivo<<v.getId()<<endl;
            archivo<<v.getId_cliente()<<endl;
            archivo<<v.getId_articulo()<<endl;
            archivo<<v.getCosto()<<endl;
            archivo<<v.getVenta()<<endl;
            archivo<<v.getFecha()<<endl;
        }
    }
}

void Admin::Recuperar_Ventas()
{
    fstream archivo("Ventas.txt",ios::in);

    if(archivo.is_open()){
        while (!archivo.eof()) {
            Ventas v;
            string s;
            float f;
            int i;

            getline(archivo, s);
            if (archivo.eof()) {
                break;
            }

            i = stoi(s);
            v.setId(i);

            getline(archivo,s);
            i = stoi(s);
            v.setId_cliente(i);

            getline(archivo,s);
            i = stoi(s);
            v.setId_articulo(i);

            getline(archivo,s);
            f = stof(s);
            v.setCosto(f);

            getline(archivo,s);
            f = stof(s);
            v.setVenta(f);

            getline(archivo,s);
            v.setFecha(s);

            agregar_Ventas(v);
        }
    }
}

void Admin::Ordenar_Clientes()
{
    ::sort(clientes.begin(), clientes.end(), [](const Cliente &a, const Cliente &b){ return a.getId()<b.getId();});
}

void Admin::Ordenar_Costo()
{
    ::sort(articulos.begin(), articulos.end(), [](const Articulo &a, const Articulo &b){ return a.getCosto()<b.getCosto();});
}

void Admin::Ordenar_Venta()
{
    ::sort(articulos.begin(), articulos.end(), [](const Articulo &a, const Articulo &b){ return a.getVenta()<b.getVenta();});
}

void Admin::Ordena_Satisfaccion()
{
    ::sort(encuestas.begin(), encuestas.end(), [](const Encuesta &a, const Encuesta &b){ return a.getSatisfaccion()<b.getSatisfaccion();});
}





