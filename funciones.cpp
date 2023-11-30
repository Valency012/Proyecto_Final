#include "funcioness.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <string>

vector<Bebida> packs;
vector<Usuarios> usuario;
vector<Ventas> venta;
vector<Bitacora_usu> bitacora;
vector<Bitacora_prod> bitacoraprod;
vector<Bitacora_ven> bitacoraven;



void InicializarUsuarios() {
    usuario.push_back({"admin123", "123", 1, "system"});
    usuario.push_back({"admin456", "456", 1, "system"});
    usuario.push_back({"admin789", "789", 2, "admin123"});
}
string GetCurrentDate()
{
    time_t t = time(0);
    tm *now = localtime(&t);
    return to_string(now->tm_mday) + "/" + to_string(now->tm_mon + 1) + "/" + to_string(now->tm_year + 1900);
}
void ImprimirBebidas()
{
    for (Bebida bebida : packs)
    {
        cout << endl;
        cout << bebida.nombre_bebida << endl;
        cout << "  Numero de lote: " << bebida.lote << endl;
        cout << "  Tipo de pack: " << bebida.tipo_bebida << endl;
        cout << "  Precio total de compra invertido: $" << bebida.precio << endl;
        cout << "  Cantidad de packs comprados: " << bebida.cantidad << endl;
        cout << "  Precio de venta por pack sera de: $" << bebida.precio_venta << endl;
    }
    cout << "\n\n";
}
void ImprimirVentas()
{
    for (Ventas venta : venta)
    {
        cout << endl;
        cout << GetCurrentDate() << endl;
        cout << " ID de venta: " << venta.identificador << endl;
        cout << " Nombre del Cliente: " << venta.nombre_consumidor << endl;
        cout << " Nombre Bebida: " << venta.nombre_bebida << endl;
        cout << " Cantidad de packs: " << venta.cantidad << endl;
        cout << " Numero de lote: " << venta.lote << endl;
        cout << " Total a pagar: $" << venta.precio_total << endl;
    }
    cout << "\n\n";
}
void ImprimirUsuarios()
{
    cout << " Usuarios existentes: " << endl;
    for (Usuarios imprimir : usuario)
    {
        cout << " > " << imprimir.usuario << endl;
    }
    cout << endl;
}
void ImprimirLotes(string nombre)
{
    for (Bebida bebida : packs)
    {
        if (nombre == bebida.nombre_bebida)
        {
            cout << endl;
            cout << " El numero de lote es: " << bebida.lote << endl
                 << " El tipo de pack es: " << bebida.tipo_bebida << endl
                 << " La cantidad de packs comprados es de: " << bebida.cantidad << endl
                 << " El precio de venta por pack sera de: $" << bebida.precio_venta << endl
                 << " La ganancia por pack sera de: $" << (bebida.precio_venta - (bebida.precio / bebida.cantidad)) << endl;
        }
    }
    cout << "\n\n";
}
void AgregarBebida(Bebida nuevaBebida)
{
    packs.push_back(nuevaBebida);
}
void AgregarVenta(Ventas nuevaVenta)
{
    venta.push_back(nuevaVenta);
}
void AgregarUsuarios(Usuarios nuevoUsuario)
{
    // Variable dentro de la funcion encargada de verificar si existe el usuario y dependiendo del valor retornara 1 si no existe
    for (int i = 0; i < usuario.size(); i++)
    {
        if (nuevoUsuario.usuario == usuario[i].usuario)
        {
            cout << " Usuario ya axistente! Por favor agregue un usuario valido\n";
            cout << endl;
            return;
        }
    }
    usuario.push_back(nuevoUsuario);
    cout << " Usuario agregado existosamente\n";
    cout << endl;
    return;
}
float BuscarPrecioVenta(int lote)
{
    float contadorventa;
    for (Bebida bebida : packs)
    {
        if (lote == bebida.lote)
        {
            contadorventa = bebida.precio_venta;
        }
    }
    return contadorventa;
}
int BuscarBebidaPack(int lote, string nombrebebida)
{
    int contadorpacks = 0;
    for (Bebida bebida : packs)
    {
        if (lote == bebida.lote && nombrebebida == bebida.nombre_bebida)
        {
            contadorpacks = bebida.cantidad;
        }
    }
    return contadorpacks;
}
int BuscarBebidapack6(string nombreBebida)
{
    int contadorpacks6 = 0;
    for (Bebida bebida : packs)
    {
        if (nombreBebida == bebida.nombre_bebida)
        {
            if (bebida.tipo_bebida == 1)
            {
                contadorpacks6 = contadorpacks6 + bebida.cantidad;
            }
        }
    }
    return contadorpacks6;
}
int BuscarBebidapack12(string nombreBebida)
{
    int contadorpacks12 = 0;
    for (Bebida bebida : packs)
    {
        if (nombreBebida == bebida.nombre_bebida)
        {
            if (bebida.tipo_bebida == 2)
            {
                contadorpacks12 = contadorpacks12 + bebida.cantidad;
            }
        }
    }
    return contadorpacks12;
}
int BuscarLote(int identificador) // Funcion que se encarga de buscar al lote del producto usado modficarlo en caso de devolucion
{
    int lote = 0;
    for (Ventas ventas : venta)
    {
        if (identificador == ventas.identificador)
        {
            lote = ventas.lote;
        }
    }
    return lote;
}
int BuscarCantidadVenta(int identificador)
{
    int cantidad = 0;
    for (Ventas ventas : venta)
    {
        if (identificador == ventas.identificador)
        {
            cantidad = ventas.cantidad;
        }
    }
    return cantidad;
}
int BuscarBebidapack24(string nombreBebida)
{

    int contadorpacks24 = 0;
    for (Bebida bebida : packs)
    {
        if (nombreBebida == bebida.nombre_bebida)
        {
            if (bebida.tipo_bebida == 3)
            {
                contadorpacks24 = contadorpacks24 + bebida.cantidad;
            }
        }
    }
    return contadorpacks24;
}
int BuscarUsuario()
{
    int tipo_usu = 0;
    string nombre_usuario;
    string contrasenia;
    do
    {
        system("cls");
        // Encabezado del sistema
        cout << endl;
        cout << "             ------PEPITO'S------" << endl;
        cout << "   ------- DISTRIBUIDORA DE BEBIDAS -------" << endl;
        cout << endl;
        cout << "        En vez de una, llevate varias" << endl;
        cout << endl;

        cout << "*************************************************" << endl;
        cout << "Ingrese su usuario: ";
        cin >> nombre_usuario;
        cout << "Ingrese su clave: ";
        cin >> contrasenia;
        cin.ignore();
        cout << endl;

        for (Usuarios usuarioActual : usuario)
        {
            if (nombre_usuario == usuarioActual.usuario)
            {
                if (usuarioActual.contrasenia == contrasenia)
                {
                    if (usuarioActual.tipo_usuario == 1)
                    {
                        tipo_usu = 1;
                    }
                    else
                    {
                        tipo_usu = 2;
                        break;
                    }
                }
            }
        }
        if (tipo_usu == 0)
        {
            cout << " Credenciales incorrectas!" << endl;
            cout << endl;
            system("pause");
        }

    } while (tipo_usu == 0);
    return tipo_usu;
}
int BuscarUsuario(string nombreusuario, string contrasenia)
{
    int tipo_usu = 0;
    int contador = 0;
    
    for (Usuarios usuario : usuario)
    {
        if (nombreusuario == usuario.usuario)
        {
            if(usuario.contrasenia == contrasenia){
                if(usuario.tipo_usuario == 1){
                    //cout << "Bienvenido usuario administrador" << endl;
                    tipo_usu = 1;
                    return tipo_usu;
                } else {
                    //cout << "Bienvenido empleado" << endl;
                    tipo_usu = 2;
                    return tipo_usu;
                }

            }
        }
    }
    cout << "No se ha encontrado el usuario" << endl;
    system("pause");
    return tipo_usu;
}
void BuscaryModificarBebida(string nombreBebida, int lote)
{
    string nuevoNombre;
    int nuevoTipo;
    float nuevoPrecio;
    int nuevaCantidad;
    float nuevoPrecioVenta;

    for (int i = 0; i < packs.size(); i++)
    {
        cin.ignore();
        if (nombreBebida == packs[i].nombre_bebida && lote == packs[i].lote)
        {
            cout << " Nuevo nombre: ";
            getline(cin, nuevoNombre);
            cout << " Nuevo tipo de pack: ";
            cin >> nuevoTipo;
            cout << " Nueva cantidad: ";
            cin >> nuevaCantidad;
            cout << " Nuevo precio total invertido: $";
            cin >> nuevoPrecio;
            cout << " Nuevo precio de venta: $";
            cin >> nuevoPrecioVenta;

            packs[i].nombre_bebida = nuevoNombre;
            packs[i].tipo_bebida = nuevoTipo;
            packs[i].precio = nuevoPrecio;
            packs[i].cantidad = nuevaCantidad;
            packs[i].precio_venta = nuevoPrecioVenta;

            cout << endl;
            cout << " Bebida modificada exitosamente" << endl;
            return;
        }
    }
    cout << " No se ha encontrado la bebida!" << endl;
}
void ModificarUsuario(string nombreUsuario) // Funcion que se encarga de modificar al usuario
{
    string nuevoNombre;
    string contrasenia;
    int tipo;

    for (int i = 0; i < usuario.size(); i++)
    {
        if (nombreUsuario == usuario[i].usuario)
        {
            cout << endl;
            cout << " Ingrese el nuevo nombre de usuario: ";
            cin >> nuevoNombre;
            cout << " Ingrese la nueva clave: ";
            cin >> contrasenia;
            cout << endl;
            cout << " Ingrese el nuevo tipo de usuario:\n (1) Si es administrador\n (2) Si es empleado\n >";
            cin >> tipo;
            cout << endl;

            usuario[i].usuario = nuevoNombre;
            usuario[i].contrasenia = contrasenia;
            usuario[i].tipo_usuario = tipo;

            cout << " Usuario modificado exitosamente\n";
            cout << endl;
            return;
        }
    }
    cout << " No se ha encontrado el usuario!" << endl;
}
void ModificarStock(int lote, int cantidad)
{
    for (int i = 0; i < packs.size(); i++)
    {
        if (lote == packs[i].lote)
        {
            packs[i].cantidad = packs[i].cantidad - cantidad;
        }
    }
}
void ModificarStockDevolucion(int lote, int cantidad, string nombrebebida)
{
    for (int i = 0; i < packs.size(); i++)
    {
        if (lote == packs[i].lote && nombrebebida == packs[i].nombre_bebida)
        {
            packs[i].cantidad = packs[i].cantidad + cantidad;
        }
    }
}
void EliminarBebida(string nombreBebida, int lote)
{
    for (int i = 0; i < packs.size(); i++)
    {
        if (nombreBebida == packs[i].nombre_bebida && lote == packs[i].lote)
        {
            packs.erase(packs.begin() + i);
            return;
        }
    }
    cout << " No se ha encotrado la bebida! Ingrese bien el nombre o el lote" << endl;
}
void EliminarVenta(string nombreBebida, int identificador)
{
    for (int i = 0; i < venta.size(); i++)
    {
        if (nombreBebida == venta[i].nombre_bebida && identificador == venta[i].identificador)
        {
            venta.erase(venta.begin() + i);
            cout << " Venta eliminada correctamente y stock actualizado" << endl;
            cout << endl;
            return;
        }
    }
    cout << " No se ha encotrado la bebida! Ingresar bien el nombre o el lote" << endl;
}
void EliminarUsuario(string usuarioEliminar)
{
    for (int i = 0; i < usuario.size(); i++)
    {
        if (usuarioEliminar == usuario[i].usuario)
        {
            usuario.erase(usuario.begin() + i);
            cout << " Usuario eliminado correctamente" << endl;
            return;
        }
    }
    cout << "El usuario no existe!" << endl;
}
void RegistrarVenta(Ventas venta)
{
    ofstream file;

    file.open("RegistroVentas.txt", ios::app);

    if (file.is_open())
    {
        file << "-------------------------------------------" << endl;
        file << "  Fecha de realizacion: " << GetCurrentDate() << endl;
        file << "  Nombre del consumidor: " << venta.nombre_consumidor << endl;
        file << "  Nombre de la bebida: " << venta.nombre_bebida << endl;
        file << "  Cantidad de packs: " << venta.cantidad << endl;
        file << "  Numero de lote: " << venta.lote << endl;
        file << "  Costo final: $" << venta.precio_total << endl;
        file.close();
    }
    else
    {
        cout << "Error al registrar la venta!" << endl;
    }
}
void MostrarRegistro(string archivo)
{

    ifstream file(archivo);

    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            cout << line << endl;
        }
        file.close();
    }
    else
    {
        cout << "No hay registros de ventas existentes!" << endl;
    }
}
void AgregarBitacoraUsu(Bitacora_usu nuevabitacora)
{
    bitacora.push_back(nuevabitacora);
}
void AgregarBitacoraProd(Bitacora_prod nuevabitacora)
{
    bitacoraprod.push_back(nuevabitacora);
}
void AgregarBitacoraVen(Bitacora_ven nuevabitacora)
{
    bitacoraven.push_back(nuevabitacora);
}
void ImprimirBitacoraUsu(string nombre)
{
    // for off
    for (Bitacora_usu bitacora : bitacora)
    {
        if (nombre == bitacora.usuario)
        {
            cout << endl;
            cout << "Fecha de realizacion: " << bitacora.fecha << endl << "La accion realizada fue: " << bitacora.accion << endl;
            if (bitacora.accion == "Se agrego un usuario")
            {
                if (bitacora.usuario_afectado == bitacora.usuarios.usuario)
                {
                    cout << "*******************Detalles**********************" << endl;
                    cout << "El usuario ingresado fue el: " << bitacora.usuarios.usuario << endl;
                    if (bitacora.usuarios.tipo_usuario == 1)
                    {
                        cout << "El tipo de usuario ingresado es jefe administrador" << endl;
                    } else
                    {
                        cout << "El tipo de usuario ingresado es empleado administrador" << endl;
                    }
                        
                }
            } else if (bitacora.accion == "Se modifico un usuario")
            {
                
                if (bitacora.usuario_afectado == bitacora.usuarios.usuario)
                {
                    cout << "*******************Detalles**********************" << endl;
                    cout << "El usuario modificado fue: " << bitacora.usuarios.usuario << endl;
                    if (bitacora.usuarios.tipo_usuario == 1)
                    {
                        cout << "El tipo de usuario es jefe administrador" << endl;
                    } else
                    {
                        cout << "El tipo de usuario es empleado administrador" << endl;
                    }
                        
                }
            } else
            {
                if (bitacora.usuario_afectado == bitacora.usuarios.usuario)
                {
                    cout << "*******************Detalles**********************" << endl;
                    cout << "El usuario eliminado fue: " << bitacora.usuarios.usuario << endl;
                    if (bitacora.usuarios.tipo_usuario == 1)
                    {
                        cout << "El tipo de usuario era jefe administrador" << endl;
                    } else
                    {
                        cout << "El tipo de usuario era empleado administrador" << endl;
                    }
                        
                }
            }   
        }
    }
    cout << "\n\n" << endl;
}
void ImprimirBitacoraPro(string nombre)
{
    // for off
    for (Bitacora_prod bitacora : bitacoraprod)
    {
        if (nombre == bitacora.usuario)
        {
            cout << endl;
            cout << "Fecha de realizacion: " << bitacora.fecha << endl << "La accion realizada fue: " << bitacora.accion << endl;
            if (bitacora.accion == "Se agrego un producto")
            {
                if (bitacora.producto_afectado == bitacora.bebida.nombre_bebida)
                {
                    cout << "*******************Detalles**********************" << endl;
                    cout << "El producto ingresado fue el: " << bitacora.producto_afectado << endl;
                    cout << "El numero de lote correspondiente es: " << bitacora.bebida.lote << endl;
                    cout << "La cantidad adquirida fue de: " << bitacora.bebida.cantidad << endl;
                    cout << "El precio de venta sera de: " << bitacora.bebida.precio_venta << endl;
                    if (bitacora.bebida.tipo_bebida == 1)
                    {
                        cout << "El tipo de pack es de 6 botellas" << endl;
                    } else if (bitacora.bebida.tipo_bebida == 2)
                    {
                        cout << "El tipo de pack es de 12 botellas" << endl;
                    } else if (bitacora.bebida.tipo_bebida == 3)
                    {
                        cout << "El tipo de pack es de 24 botellas" << endl;
                    }
                        
                }
            } else if (bitacora.accion == "Se modifico un producto")
            {
                
                if (bitacora.producto_afectado == bitacora.bebida.nombre_bebida)
                {
                    cout << "*******************Detalles**********************" << endl;
                    cout << "El producto modificado fue el: " << bitacora.producto_afectado << endl;
                    cout << "El numero de lote correspondiente es: " << bitacora.bebida.lote << endl;
                    cout << "La cantidad adquirida fue de: " << bitacora.bebida.cantidad << endl;
                    cout << "El precio de venta sera de: " << bitacora.bebida.precio_venta << endl;
                    if (bitacora.bebida.tipo_bebida == 1)
                    {
                        cout << "El tipo de pack es de 6 botellas" << endl;
                    } else if (bitacora.bebida.tipo_bebida == 2)
                    {
                        cout << "El tipo de pack es de 12 botellas" << endl;
                    } else if (bitacora.bebida.tipo_bebida == 3)
                    {
                        cout << "El tipo de pack es de 24 botellas" << endl;
                    }
                        
                }
            } else
            {
                if (bitacora.producto_afectado == bitacora.bebida.nombre_bebida)
                {
                    cout << "*******************Detalles**********************" << endl;
                    cout << "El producto eliminado fue el: " << bitacora.producto_afectado << endl;
                    cout << "El numero de lote correspondiente fue: " << bitacora.bebida.lote << endl;
                    cout << "La cantidad adquirida fue de: " << bitacora.bebida.cantidad << endl;
                    cout << "El precio de venta fue de: " << bitacora.bebida.precio_venta << endl;
                    if (bitacora.bebida.tipo_bebida == 1)
                    {
                        cout << "El tipo de pack es de 6 botellas" << endl;
                    } else if (bitacora.bebida.tipo_bebida == 2)
                    {
                        cout << "El tipo de pack es de 12 botellas" << endl;
                    } else if (bitacora.bebida.tipo_bebida == 3)
                    {
                        cout << "El tipo de pack es de 24 botellas" << endl;
                    }
                        
                }
            }   
        }
    }
    cout << "\n\n" << endl;
}
void ImprimirBitacoraVen(string nombre)
{
    // for off
    for (Bitacora_ven bitacora : bitacoraven)
    {
        if (nombre == bitacora.usuario)
        {
            cout << endl;
            cout << "Fecha de realizacion: " << bitacora.fecha << endl << "La accion realizada fue: " << bitacora.accion << endl;
            if (bitacora.accion == "Se agrego una venta")
            {
                if (bitacora.venta_afectada == bitacora.ventas.nombre_bebida)
                {
                    cout << "*******************Detalles**********************" << endl;
                    cout << "El numero de venta es: $" << bitacora.ventas.identificador << endl;
                    cout << "El nombre del consumidor es: $" << bitacora.ventas.nombre_consumidor << endl;
                    cout << "El producto vendido fue el: " << bitacora.venta_afectada << endl;
                    cout << "El numero de lote utilizado fue: " << bitacora.ventas.lote << endl;
                    cout << "La cantidad vendida fue de: " << bitacora.ventas.cantidad << endl;
                    cout << "El precio final fue de: $" << bitacora.ventas.precio_total << endl;
                    
                        
                }
            }  else
            {
                if (bitacora.venta_afectada == bitacora.ventas.nombre_bebida)
                {
                    cout << "*******************Detalles**********************" << endl;
                    cout << "El numero de venta fue: $" << bitacora.ventas.identificador << endl;
                    cout << "El nombre del consumidor fue: $" << bitacora.ventas.nombre_consumidor << endl;
                    cout << "El producto vendido fue el: " << bitacora.venta_afectada << endl;
                    cout << "El numero de lote utilizado fue: " << bitacora.ventas.lote << endl;
                    cout << "La cantidad vendida fue de: " << bitacora.ventas.cantidad << endl;
                    cout << "El precio final fue de: $" << bitacora.ventas.precio_total << endl;
                        
                }
            }   
        }
    }
    cout << "\n\n" << endl;
}
