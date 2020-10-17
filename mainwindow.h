#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "admin.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Agregar_clicked();

    void on_actionGuardar_triggered();

    void on_actionAbrir_triggered();

    void on_pushButton_Mostrar_Clientes_clicked();

    void on_pushButton_Mostrar_Articulos_clicked();

    void on_pushButton_Mostrar_Ventas_clicked();

    void on_pushButton_Mostarr_Encuestas_clicked();

    void on_pushButton_Clientes_clicked();

    void on_pushButton_Articulos_clicked();

    void on_pushButton_Ventas_clicked();

    void on_pushButton_Encuestas_clicked();

    void on_actionCliente_triggered();

    void on_actionCosto_triggered();

    void on_actionVenta_triggered();

    void on_actionSatisfaccion_triggered();

private:
    Ui::MainWindow *ui;
    Admin admin;

    void mostrar_tabla_clientes(vector<Cliente> &clients);
    void mostrar_tabla_articulos(vector<Articulo> &arti);
    void mostrar_tabla_ventas(vector<Ventas> &ven);
    void mostrar_tabla_encuestas(vector<Encuesta> &enc);

};
#endif // MAINWINDOW_H
