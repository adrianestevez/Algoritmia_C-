#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTableWidgetItem>
#include "cliente.h"
#include "articulo.h"
#include "ventas.h"
#include "encuesta.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_Agregar_clicked()
{
    qDebug() <<"Hola" ;
    //Cliente
    QString cliente_id = ui->lineEdit_Cliente_id->text();
    QString cliente_nombre = ui->lineEdit_Cliente_nombre->text();

    //Articulo
    QString articulo_id = ui->lineEdit_Articulo_id->text();
    QString articulo_nombre = ui->lineEdit_Articulo_Nombre->text();
    QString articulo_costo = ui->lineEdit_Articulo_Costo->text();
    QString articulo_venta = ui->lineEdit_Articulo_Costo->text();

    //Ventas
    QString ventas_id = ui->lineEdit_Ventas_id->text();
    QString ventas_fecha = ui->lineEdit_Ventas_Fecha->text();
    QString ventas_costo = ui->lineEdit_Ventas_costo->text();
    QString ventas_ventas = ui->lineEdit_Ventas_venta->text();

    //Encuesta
    QString encuesta_fecha = ui->lineEdit_Encuestas_Fecha->text();
    int encuesta_satisfaccion = ui->spinBox_Encuestas_satisfaccion->value();

    int client_id,arti_id, v_id;
    float arti_costo, arti_venta, v_costo, v_ventas;

    //Ciente
    Cliente c;
    client_id = stoi(cliente_id.toStdString());//Convierto lo sacado del lineEdit a int
    c.setId(client_id);//Id
    c.setNombre(cliente_nombre.toStdString());//Nombre

    admin.agregar_Clientes(c);//Annadimos el cliente que creamos a la lista de clientes controlada por clientes

    //Articulo
    Articulo a;
    arti_id = stoi(articulo_id.toStdString());
    a.setId(arti_id);//Id
    a.setNombre(articulo_nombre.toStdString());//Nombre
    arti_costo = stof(articulo_costo.toStdString());
    a.setCosto(arti_costo);//Costo
    arti_venta = stof(articulo_venta.toStdString());
    a.setVenta(arti_venta);//Venta

    admin.agregar_Articulos(a); //Annadimos el articulo a que creamos a la lista de articulos controlada por admin

    //Ventas
    Ventas v;
    v_id = stoi(ventas_id.toStdString());
    v.setId(v_id);//Id
    v.setFecha(ventas_fecha.toStdString());//Fecha
    v.setId_cliente(client_id); //En este caso como es el id del cliente el que se requiere mando el id del cliente previamente buscado
    v.setId_articulo(arti_id); //En este caso como es el id del articulo el que se requiere mando el id del articulo previamente buscado
    v_costo = stof(ventas_costo.toStdString());
    v.setCosto(v_costo);//Costo
    v_ventas = stof(ventas_ventas.toStdString());
    v.setVenta(v_ventas);//Costo

    admin.agregar_Ventas(v); //Annadimos la venta v que creamos a la lista de ventas controlada por admin


    //Encuesta
    Encuesta e;
    e.setFecha(encuesta_fecha.toStdString());//Fecha
    e.setSatisfaccion(encuesta_satisfaccion);//Satisfaccion
    e.setId_ventas(v_id);

    admin.agregar_Encuesta(e);//Annadimos la encuesta que creamos a la lista de encuestas controlada por admin

}


void MainWindow::on_actionGuardar_triggered()
{
    admin.Respaldar_Clientes();
    admin.Respaldar_Articulos();
    admin.Respaldar_Ventas();
    admin.Respaldar_Encuestas();
}

void MainWindow::on_actionAbrir_triggered()
{
    admin.Recuperar_Clientes();
    admin.Recuperar_Articulos();
    admin.Recuperar_Ventas();
    admin.Recuperar_Encuestas();
}

void MainWindow::on_pushButton_Mostrar_Clientes_clicked()
{
    ui->salida->clear();
    for(size_t i=0;i < admin.size_clientes();i++){
        Cliente c = admin.pos_cliente(i);

        ui->salida->insertPlainText(
                    "------------------------- \n");

        ui->salida->insertPlainText(
                    "Id: "
                    + QString::number(c.getId())
                    +"\n");

        ui->salida->insertPlainText(
                    "Nombre: "
                    + QString::fromStdString(c.getNombre())
                    +"\n");
    }
}


void MainWindow::on_pushButton_Mostrar_Articulos_clicked()
{
    ui->salida->clear();
    for(size_t i=0;i < admin.size_articulos();i++){
        Articulo a = admin.pos_articulos(i);

        ui->salida->insertPlainText(
                    "------------------------- \n");

        ui->salida->insertPlainText(
                    "Id: "
                    + QString::number(a.getId())
                    +"\n");

        ui->salida->insertPlainText(
                    "Nombre: "
                    + QString::fromStdString(a.getNombre())
                    +"\n");

        ui->salida->insertPlainText(
                    "Costo: "
                    + QString::number(a.getCosto())
                    +"\n");

        ui->salida->insertPlainText(
                    "Venta: "
                    + QString::number(a.getVenta())
                    +"\n");
    }
}

void MainWindow::on_pushButton_Mostrar_Ventas_clicked()
{
    ui->salida->clear();
    for(size_t i=0; i < admin.size_ventas();i++){
        Ventas v = admin.pos_ventas(i);

        ui->salida->insertPlainText(
                    "------------------------- \n");

        ui->salida->insertPlainText(
                    "Id Venta: "
                    + QString::number(v.getId())
                    +"\n");

        ui->salida->insertPlainText(
                    "Nombre: "
                    + QString::fromStdString(v.getFecha())
                    +"\n");

        ui->salida->insertPlainText(
                    "Id Cliente: "
                    + QString::number(v.getId_cliente())
                    +"\n");

        ui->salida->insertPlainText(
                    "Id Articulo: "
                    + QString::number(v.getId_articulo())
                    +"\n");

        ui->salida->insertPlainText(
                    "Costo: "
                    + QString::number(v.getCosto())
                    +"\n");

        ui->salida->insertPlainText(
                    "Venta: "
                    + QString::number(v.getVenta())
                    +"\n");
    }
}

void MainWindow::on_pushButton_Mostarr_Encuestas_clicked()
{
    for(size_t i=0; i < admin.size_encuesta();i++){
        Encuesta e = admin.pos_encuestas(i);

        ui->salida->insertPlainText(
                    "------------------------- \n");

        ui->salida->insertPlainText(
                    "Fecha: "
                    +QString::fromStdString(e.getFecha())
                    +"\n");

        ui->salida->insertPlainText(
                    "Id ventas: "
                    +QString::number(e.getId_ventas())
                    +"\n");

        ui->salida->insertPlainText(
                    "Satisfaccion: "
                    +QString::number(e.getSatisfaccion())
                    +"\n");

    }
}

void MainWindow::on_pushButton_Clientes_clicked()
{
    qDebug()<<"Clientes";
    vector<Cliente> clis;
    for(size_t i = 0; i < admin.size_clientes(); i++){
        clis.push_back(admin.pos_cliente(i));
    }
    mostrar_tabla_clientes(clis);

}

void MainWindow::mostrar_tabla_clientes(vector<Cliente> &clients)
{
    ui->tabla->clear();
    ui->tabla->setColumnCount(2);
    ui->tabla->setRowCount(clients.size());


     QStringList headers;
     headers << "Id " <<" Nombre ";

     ui->tabla-> setHorizontalHeaderLabels(headers);

     size_t row = 0;
     for(size_t i=0;i<clients.size();i++){
         Cliente c = admin.pos_cliente(i);

         QString id = QString::number(c.getId());
         QString nombre = QString::fromStdString(c.getNombre());

         ui->tabla->setItem(row, 0, new QTableWidgetItem(id));
         ui->tabla->setItem(row, 1, new QTableWidgetItem(nombre));

         row++;
     }

}

void MainWindow::mostrar_tabla_articulos(vector<Articulo> &arti)
{
    ui->tabla->clear();
    ui->tabla->setColumnCount(4);
    ui->tabla->setRowCount(arti.size());


    QStringList headers;
    headers << "Id " <<" Nombre "<< " Costo "<< " Venta ";

    ui->tabla-> setHorizontalHeaderLabels(headers);

    size_t row = 0;
    for(size_t i=0;i<arti.size();i++){
        Articulo a = admin.pos_articulos(i);

        QString id = QString::number(a.getId());
        QString nombre = QString::fromStdString(a.getNombre());
        QString costo = QString::number(a.getCosto());
        QString venta = QString::number(a.getVenta());


        ui->tabla->setItem(row, 0, new QTableWidgetItem(id));
        ui->tabla->setItem(row, 1, new QTableWidgetItem(nombre));
        ui->tabla->setItem(row, 2, new QTableWidgetItem(costo));
        ui->tabla->setItem(row, 3, new QTableWidgetItem(venta));

        row++;
    }
}

void MainWindow::mostrar_tabla_ventas(vector<Ventas> &ven)
{
    ui->tabla->clear();
    ui->tabla->setColumnCount(6);
    ui->tabla->setRowCount(ven.size());


    QStringList headers;
    headers << "Id " <<" Fecha "<< " Id cliente "<< " Id articulo "<< " Costo "<< " Venta ";

    ui->tabla-> setHorizontalHeaderLabels(headers);

    size_t row = 0;
    for(size_t i=0;i<ven.size();i++){
        Ventas v = admin.pos_ventas(i);

        QString id = QString::number(v.getId());
        QString fecha = QString::fromStdString(v.getFecha());
        QString id_cliente = QString::number(v.getId_cliente());
        QString id_arti = QString::number(v.getId_articulo());
        QString costo = QString::number(v.getCosto());
        QString venta = QString::number(v.getVenta());


        ui->tabla->setItem(row, 0, new QTableWidgetItem(id));
        ui->tabla->setItem(row, 1, new QTableWidgetItem(fecha));
        ui->tabla->setItem(row, 2, new QTableWidgetItem(id_cliente));
        ui->tabla->setItem(row, 3, new QTableWidgetItem(id_arti));
        ui->tabla->setItem(row, 4, new QTableWidgetItem(costo));
        ui->tabla->setItem(row, 5, new QTableWidgetItem(venta));

        row++;
    }
}

void MainWindow::mostrar_tabla_encuestas(vector<Encuesta> &enc)
{
    ui->tabla->clear();
    ui->tabla->setColumnCount(3);
    ui->tabla->setRowCount(enc.size());


    QStringList headers;
    headers << " Id Venta " <<" Fecha "<< " Satisfaccion ";

    ui->tabla-> setHorizontalHeaderLabels(headers);

    size_t row = 0;
    for(size_t i=0;i<enc.size();i++){
        Encuesta e = admin.pos_encuestas(i);

        QString id_ventas = QString::number(e.getId_ventas());
        QString fecha = QString::fromStdString(e.getFecha());
        QString satisfaccion = QString::number(e.getSatisfaccion());

        ui->tabla->setItem(row, 0, new QTableWidgetItem(id_ventas));
        ui->tabla->setItem(row, 1, new QTableWidgetItem(fecha));
        ui->tabla->setItem(row, 2, new QTableWidgetItem(satisfaccion));

        row++;
    }
}

void MainWindow::on_pushButton_Articulos_clicked()
{
    qDebug()<<"Articulos";
    vector<Articulo> art;
    for(size_t i = 0; i < admin.size_articulos(); i++){
        art.push_back(admin.pos_articulos(i));
    }
    mostrar_tabla_articulos(art);

}

void MainWindow::on_pushButton_Ventas_clicked()
{
    qDebug()<<"Ventas";
    vector<Ventas> ve;
    for(size_t i = 0; i < admin.size_ventas(); i++){
        ve.push_back(admin.pos_ventas(i));
    }
    mostrar_tabla_ventas(ve);
}

void MainWindow::on_pushButton_Encuestas_clicked()
{
    qDebug()<<"Encuestas";
    vector<Encuesta> en;
    for(size_t i = 0; i < admin.size_encuesta(); i++){
        en.push_back(admin.pos_encuestas(i));
    }
    mostrar_tabla_encuestas(en);
}

void MainWindow::on_actionCliente_triggered()
{
    //algoritmos<Cliente> al;
   // Cliente *a,*b;
   // vector<Cliente> cli;
    //al.ordenar(cli,al.mayorStockMinimo(a,b));
    admin.Ordenar_Clientes();
}

void MainWindow::on_actionCosto_triggered()
{
    admin.Ordenar_Costo();
}

void MainWindow::on_actionVenta_triggered()
{
    admin.Ordenar_Venta();
}

void MainWindow::on_actionSatisfaccion_triggered()
{
    admin.Ordena_Satisfaccion();
}
