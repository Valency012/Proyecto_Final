#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <string>

#include <string>  // Asegúrate de incluir <string> aquí

using namespace std;

// Declaraciones de estructuras a utilizar
struct Bebida
{
    string nombre_bebida;
    int tipo_bebida;
    float precio;
    int cantidad;
    float precio_venta;
    int lote;
};
struct Ventas
{
    string nombre_bebida;
    int lote;
    int cantidad;
    string nombre_consumidor;
    float precio_total;
    int identificador;
    string fecha;
};
struct Usuarios
{
    string usuario;
    string contrasenia;
    int tipo_usuario;
    string usuario_creacion;
};
struct Bitacora_usu{
    string usuario;
    string accion;
    string fecha;
    string usuario_afectado;
    Usuarios usuarios;
};
struct Bitacora_prod{
    string usuario;
    string accion;
    string fecha;
    string producto_afectado;
    Bebida bebida;
};
struct Bitacora_ven{
    string usuario;
    string accion;
    string fecha;
    string venta_afectada;
    Ventas ventas;
};


// Declaracion de las funciones a utilizar
void InicializarUsuarios();
void ImprimirBebidas();
void ImprimirVentas();
void ImprimirLotes(string);
void BuscaryModificarBebida(string, int);
void ModificarStock(int, int);
float BuscarPrecioVenta(int);
int BuscarBebidaPack(int, string);
int BuscarBebidapack6(string);
int BuscarBebidapack12(string);
int BuscarBebidapack24(string);
void EliminarBebida(string, int);
void AgregarBebida(Bebida);
void AgregarVenta(Ventas);
void AgregarUsuarios(Usuarios);
int BuscarUsuario();
void ModificarUsuario(string);
void EliminarVenta(string, int);
void ModificarStockDevolucion(int, int, string);
int BuscarLote(int);
int BuscarCantidadVenta(int);
void ImprimirUsuarios();
void EliminarUsuario(string);
string GetCurrentDate();
void RegistrarVenta(Ventas venta);    // Registro ventas
void MostrarRegistro(string archivo); // Mostrar el archivo
void AgregarBitacoraUsu(Bitacora_usu); //Agregar Bitacora
void AgregarBitacoraProd(Bitacora_prod);
void AgregarBitacoraVen(Bitacora_ven);
void ImprimirBitacoraUsu(string);
void ImprimirBitacoraPro(string);
void ImprimirBitacoraVen(string);
int BuscarUsuario(string, string);     //Imprimir valores de la Bitacora



#endif // FUNCIONES_H