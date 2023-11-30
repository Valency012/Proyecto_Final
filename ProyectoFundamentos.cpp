#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
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
};

// Declaracion de las funciones a utilizar
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

// Definicion de vectores
vector<Bebida> packs;
vector<Usuarios> usuario;
vector<Ventas> venta;

int main()
{

    // Declaracion de variables y estructuras

    Bebida bebida;           // Declaracion estructura
    Usuarios usuarios;       // Declaracion estructura
    Ventas ventas;           // Declaracion estructura
    int opcion;              // Variable encargada de evaluar la opcion ingresada por el cliente
    string nombre_usuario;   // Variable que captura el nombre de usuario
    string contrasenia;      // Variable que captura la clave
    int tipo_usuario;        // Variable encargada de capturar el tipo de usuario
    int sesion = 0;          // Variable que se encarga de cerrar sesion o mantenerla
    int contador = 0;        // Variable la navegabilidad del sistema
    int regresar = 0;        // Variable la navegabilidad del sistema
    int regresarmenupro = 0; // Variable la navegabilidad del sistema en el menu productos
    int regresarmenuusu = 0; // Variable la navegabilidad del sistema en el menu usuarios
    int regresarmenuven = 0; // Variable la navegabilidad del sistema en el menu ventas
    int opcion1;             // Variable encargada de evaluar la opcion ingresada por el cliente
    int lote = 0;            // Variable que sirve como identificador cada producto, generada automaticamente
    int identificador = 0;   // Variable que sirve como identificador unico cada venta

    // Insertar datos vector usuarios, administrador
    usuario.push_back({"admin123", "123", 1});
    usuario.push_back({"admin456", "456", 1});
    usuario.push_back({"admin789", "789", 2});

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

        // Llamamiento a la funcion de buscar usuario, encargada de verificar si es admin o empleado
        tipo_usuario = BuscarUsuario();

        do
        { // Do while el funcionamiento de regresar a menus anteriores
            system("cls");
            cout << endl;
            switch (tipo_usuario)
            {
            case 1:
                // Menu principal Administrador
                cout << GetCurrentDate() << endl;
                cout << "***************************************" << endl;
                cout << "   ----- JEFE ADMINISTRADOR ----- " << endl;
                cout << "***************************************";
                cout << endl;
                cout << "Opciones: " << endl;
                cout << " (1) Manejo de usuarios" << endl;
                cout << " (2) Manejo de productos" << endl;
                cout << " (3) Registro de ventas diarias" << endl;
                cout << " (4) Mostrar bitacora" << endl;
                cout << " (5) Cerrar sesion\n >";
                cin >> opcion;
                cin.ignore();
                cout << endl;
                do
                {
                    system("cls");
                    cout << endl;
                    switch (opcion)
                    {
                    // Opcion 1 del menu administrador
                    case 1:
                        cout << "------- MANEJO DE USUARIOS ------- " << endl;
                        cout << endl;
                        cout << "Opciones: " << endl;
                        cout << " (1) Agregar usuarios" << endl;
                        cout << " (2) Mostrar usuarios existentes" << endl;
                        cout << " (3) Modificar usuarios existentes" << endl;
                        cout << " (4) Eliminar usuarios existentes" << endl;
                        cout << " (5) Regresar al menu anterior" << endl;
                        cout << " >";
                        cin >> opcion1;
                        cout << endl;

                        do
                        {
                            switch (opcion1)
                            {
                            case 1:
                                cout << " Ingrese el nombre de usuario: ";
                                cin >> usuarios.usuario;
                                cout << " Ingrese una clave: ";
                                cin >> usuarios.contrasenia;
                                cout << endl;
                                cout << " Ingrese el tipo de usuario:\n (1) Si es administrador\n (2) Si es empleado\n >";
                                cin >> usuarios.tipo_usuario;
                                cout << endl;

                                if (usuarios.tipo_usuario != 1 && usuarios.tipo_usuario != 2)
                                {
                                    cout << "Tipo de usuario no valido!" << endl;
                                    regresarmenuusu = 1;
                                    regresar = 0;
                                }
                                else
                                {
                                    AgregarUsuarios(usuarios);
                                    regresarmenuusu = 1;
                                    regresar = 0;
                                }
                                break;
                            case 2:
                                ImprimirUsuarios();
                                regresarmenuusu = 1;
                                regresar = 0;
                                break;
                            case 3:
                                ImprimirUsuarios();
                                cout << " Ingrese el nombre del usuario a modificar: ";
                                cin >> usuarios.usuario;

                                ModificarUsuario(usuarios.usuario);

                                break;
                            case 4:
                                ImprimirUsuarios();
                                cout << " Ingrese el nombre de usuario a eliminar: ";
                                cin >> usuarios.usuario;

                                EliminarUsuario(usuarios.usuario);
                                cout << endl;
                                regresarmenuusu = 1;
                                regresar = 0;
                                break;
                            case 5:
                                regresarmenuusu = 1;
                                regresar = 1;
                                contador = 0;
                                break;
                            default:
                                cout << "Opcion no valida! Regresando..." << endl;
                                cout << endl;
                                regresarmenuusu = 1;
                                regresar = 1;
                                break;
                            }
                            system("pause");

                        } while (regresarmenuusu == 0);
                        break;

                    // Opcion 2 del menu Administrador
                    case 2:
                        cout << "----- MANEJO DE PRODUCTOS ----- " << endl;
                        cout << endl;
                        cout << "Opciones: " << endl;
                        cout << " (1) Agregar productos" << endl;
                        cout << " (2) Mostrar productos existentes" << endl;
                        cout << " (3) Modificar productos existentes" << endl;
                        cout << " (4) Eliminar productos existentes" << endl;
                        cout << " (5) Regresar al menu anterior\n >";
                        cin >> opcion1;
                        cout << endl;

                        do
                        {
                            cin.ignore();
                            switch (opcion1)
                            {
                            case 1:
                                // Lote es el campo oculto que se llenara automaticamente sin pedir ingreso
                                cout << " Ingrese el nombre de la bebida: ";
                                getline(cin, bebida.nombre_bebida);
                                cout << endl;
                                cout << " Tipos de packs: " << endl;
                                cout << "   (1) Pack de 6 botellas" << endl;
                                cout << "   (2) Pack de 12 botellas" << endl;
                                cout << "   (3) Pack de 24 botellas" << endl;
                                cout << endl;
                                cout << "  Ingrese el tipo de pack que ha comprado: ";
                                cin >> bebida.tipo_bebida;

                                // Verificar si el tipo pack es diferente a 1, 2 o 3, si lo es, requerir un valor valido
                                if (bebida.tipo_bebida != 1 && bebida.tipo_bebida != 2 && bebida.tipo_bebida != 3)
                                {
                                    cout << " Ingrese una opcion valida!\n"
                                         << endl;
                                    regresarmenupro = 1;
                                    regresar = 0;
                                }
                                else
                                {
                                    cout << "  Ingrese el precio total de lo invertido en la compra: $";
                                    cin >> bebida.precio;
                                    cout << "  Ingrese la cantidad de packs que se compro: ";
                                    cin >> bebida.cantidad;
                                    cout << endl;
                                    cout << " El precio por pack es de $" << (bebida.precio / bebida.cantidad) << endl;
                                    cout << " Le sugerimos ingresar un monto mayor para generar ganancia." << endl;
                                    cout << " Ingrese el costo de venta por pack: $";
                                    cin >> bebida.precio_venta;
                                    cout << endl;
                                    lote = lote + 1;
                                    bebida.lote = lote;
                                    AgregarBebida(bebida);
                                    cout << " Producto ingresado exitosamente\n";
                                    cout << endl;
                                    regresarmenupro = 1;
                                    regresar = 0;
                                }
                                break;

                            case 2:
                                ImprimirBebidas();
                                break;

                            case 3:
                                ImprimirBebidas();
                                cout << "Ingrese el nombre de la bebida: ";
                                getline(cin, bebida.nombre_bebida);
                                cin.ignore();
                                cout << "Ingrese el numero de lote: ";
                                cin >> bebida.lote;

                                BuscaryModificarBebida(bebida.nombre_bebida, bebida.lote);
                                cout << endl;
                                regresar = 0;
                                break;
                            case 4:
                                ImprimirBebidas();
                                cout << "Ingrese el nombre de la bebida a eliminar: ";
                                getline(cin, bebida.nombre_bebida);
                                cout << "Ingrese el numero de lote: ";
                                cin >> bebida.lote;
                                EliminarBebida(bebida.nombre_bebida, bebida.lote);
                                cout << endl;
                                cout << "Bebida eliminada correctamente" << endl;
                                break;
                            case 5:
                                regresarmenupro = 1;
                                regresar = 1;
                                contador = 0;
                                break;
                            default:
                                cout << "Opcion no valida! Regresando..." << endl;
                                cout << endl;
                                regresarmenupro = 1;
                                regresar = 0;
                                break;
                            }
                            system("pause");
                        } while (regresarmenupro == 0);
                        break;
                    // Opcion 3 del menu Administrador
                    case 3:
                        if (opcion == 3)
                        {
                            cout << endl;
                            cout << "----- REGISTRO DE VENTAS DIARIAS ----- " << endl;
                            MostrarRegistro("RegistroVentas.txt"); // Imprime el registro
                        }
                        else
                        {
                            cout << "El archivo se ha creado aparte" << endl;
                        }
                        system("pause");
                        regresar = 1;
                        break;

                    // Opcion 4 del menu Administrador
                    case 4:
                        // BITACORAAAAAAAAAAAAAAAAAAA
                        // BITACORAAAAAAAAAAAAA
                        cout << "---------- BITACORA ---------- " << endl;
                        system("pause");
                        regresar = 1;
                        break;
                    // Opcion 5 del menu Administrador
                    case 5:
                        cout << "De verdad desea cerrar sesion? Si (0), No (1)  \n > ";
                        cin >> sesion;
                        cout << endl;
                        if (sesion == 0)
                        {
                            cout << " Ha cerrado sesion" << endl;
                            contador = 1;
                            regresar = 1;
                        }
                        else if (sesion == 1)
                        {
                            cout << "  Sesion manetenida" << endl;
                            contador = 0;
                            regresar = 1;
                        }
                        else
                        {
                            sesion = 0;
                            cout << "Opcion no valida! Cerrado sesion..." << endl;
                            contador = 1;
                            regresar = 1;
                        }
                        system("pause");
                        break;
                        system("cls");
                    default:
                        cout << "Ingrese una opcion valida! " << endl;
                        cout << endl;
                        regresar = 1;
                        contador = 0;
                        break;
                    }
                } while (regresar == 0);
                break;

            // Menu principal Usuario Administrador 2
            case 2:
                cout << GetCurrentDate() << endl;
                cout << "***************************************" << endl;
                cout << "  ----- EMPLEADO ADMINISTRADOR -----" << endl;
                cout << "***************************************";
                cout << endl;
                cout << "Opciones: " << endl;
                cout << " (1) Manejo de productos" << endl;
                cout << " (2) Manejo de ventas" << endl;
                cout << " (3) Cerrar sesion\n >";
                cin >> opcion;
                cout << endl;
                do
                {
                    system("cls");
                    switch (opcion)
                    {
                    case 1:
                        // Opcion 1 del menu Usuario Administrador 2
                        cout << endl;
                        cout << "----- MANEJO DE PRODUCTOS ----- " << endl;
                        cout << endl;
                        cout << "Opciones: " << endl;
                        cout << " (1) Agregar productos" << endl;
                        cout << " (2) Mostrar productos existentes" << endl;
                        cout << " (3) Modificar productos existentes" << endl;
                        cout << " (4) Eliminar productos existentes" << endl;
                        cout << " (5) Regresar al menu anterior\n >";
                        cin >> opcion1;
                        cout << endl;

                        do
                        {
                            cin.ignore();
                            switch (opcion1)
                            {
                            case 1:
                                // Lote es el campo oculto que se llenara automaticamente sin pedir ingreso
                                cout << " Ingrese el nombre de la bebida: ";
                                getline(cin, bebida.nombre_bebida);
                                cout << endl;
                                cout << " Tipos de packs: " << endl;
                                cout << "   (1) Pack de 6 botellas" << endl;
                                cout << "   (2) Pack de 12 botellas" << endl;
                                cout << "   (3) Pack de 24 botellas\n";
                                cout << endl;
                                cout << " Ingrese el tipo de pack a comprar: ";
                                cin >> bebida.tipo_bebida;

                                // Verificar si el tipo pack es diferente a 1, 2 o 3, si lo es, requerir un valor valido
                                if (bebida.tipo_bebida != 1 && bebida.tipo_bebida != 2 && bebida.tipo_bebida != 3)
                                {
                                    cout << " El tipo de pack no es correcto, ingrese una opcion valida" << endl;
                                    cout << endl;
                                    regresarmenupro = 1;
                                    regresar = 0;
                                }
                                else
                                {
                                    cout << " Ingrese el precio total de su compra: $";
                                    cin >> bebida.precio;
                                    cout << " Ingrese la cantidad de packs: ";
                                    cin >> bebida.cantidad;
                                    cout << endl;
                                    cout << " El precio por pack es de $" << (bebida.precio / bebida.cantidad) << endl;
                                    cout << " Le sugerimos ingresar un monto mayor generar ganancia." << endl;
                                    cout << " Ingrese el costo de venta por pack: ";
                                    cin >> bebida.precio_venta;
                                    cout << endl;
                                    lote = lote + 1;
                                    bebida.lote = lote;
                                    AgregarBebida(bebida);
                                    cout << " Producto ingresado exitosamente" << endl;
                                    cout << endl;
                                    regresarmenupro = 1;
                                    regresar = 0;
                                }
                                break;
                            case 2:
                                ImprimirBebidas();
                                break;
                            case 3:
                                ImprimirBebidas();
                                cout << " Ingrese el nombre de la bebida: ";
                                getline(cin, bebida.nombre_bebida);
                                cout << " Ingrese el numero de lote: ";
                                cin >> bebida.lote;
                                BuscaryModificarBebida(bebida.nombre_bebida, bebida.lote);
                                cout << endl;
                                regresar = 0;
                                break;
                            case 4:
                                ImprimirBebidas();
                                cout << " Ingrese el nombre de la bebida a eliminar: ";
                                getline(cin, bebida.nombre_bebida);
                                cout << " Ingrese el numero de lote: ";
                                cin >> bebida.lote;

                                EliminarBebida(bebida.nombre_bebida, bebida.lote);
                                cout << " Bebida eliminada correctamente" << endl;
                                cout << endl;
                                regresarmenupro = 1;
                                regresar = 0;
                                break;
                            case 5:
                                regresarmenupro = 1;
                                regresar = 1;
                                contador = 0;
                                break;
                            default:
                                cout << "Opcion no valida! Regresando..." << endl;
                                cout << endl;
                                regresarmenupro = 1;
                                regresar = 0;
                                break;
                            }
                            system("pause");
                        } while (regresarmenupro == 0);

                        break;
                    // Opcion 2 del menu Usuario Administrador 2
                    case 2:
                        cout << endl;
                        cout << "----- MANEJO DE VENTAS ----- " << endl;
                        cout << endl;
                        cout << "Opciones: " << endl;
                        cout << " (1) Agregar venta" << endl;
                        cout << " (2) Eliminar una venta" << endl;
                        cout << " (3) Regresar al menu anterior\n >";
                        cin >> opcion1;

                        do
                        {
                            cin.ignore();
                            switch (opcion1)
                            {
                            case 1:
                                ImprimirBebidas();
                                cout << endl;
                                cout << "      DATOS NECESARIOS DEL CLIENTE  " << endl;
                                cout << "***************************************" << endl;
                                cout << endl;
                                cout << "  Ingrese el nombre de la bebida: ";
                                getline(cin, ventas.nombre_bebida);
                                cout << endl;

                                int packs6, packs12, packs24, lote;

                                packs6 = BuscarBebidapack6(ventas.nombre_bebida);
                                packs12 = BuscarBebidapack12(ventas.nombre_bebida);
                                packs24 = BuscarBebidapack24(ventas.nombre_bebida);
                                cout << endl;

                                cout << "  Tipos de packs disponibles" << endl;
                                cout << "   Disponibles " << packs6 << "  packs de 6 botellas" << endl;
                                cout << "   Disponibles " << packs12 << " packs de 12 botellas" << endl;
                                cout << "   Disponibles " << packs24 << " packs de 24 botellas" << endl;
                                cout << endl;

                                int packs;
                                float preciofinal;

                                cout << "  N. lote: ";
                                cin >> ventas.lote;
                                packs = BuscarBebidaPack(ventas.lote, ventas.nombre_bebida);
                                preciofinal = BuscarPrecioVenta(ventas.lote);

                                if (packs == 0)
                                {
                                    cout << " Ingrese un numero de lote existente! " << endl;
                                    regresarmenuven = 1;
                                    regresar = 0;
                                }
                                else
                                {
                                    cout << "  Cantidad de packs: ";
                                    cin >> ventas.cantidad;

                                    cin.ignore();
                                    if (packs < ventas.cantidad)
                                    {
                                        cout << " No tiene esa cantidad en el stock!" << endl;
                                    }
                                    else
                                    {
                                        cout << "  Nombre de el consumidor: ";
                                        getline(cin, ventas.nombre_consumidor);
                                        cout << endl;
                                        cout << " Total a pagar: $" << (preciofinal * ventas.cantidad) << endl;
                                        ventas.precio_total = (preciofinal * ventas.cantidad);
                                        cout << endl;
                                        system("cls");
                                        cout << endl;
                                        cout << "----------------------- RECIBO DE CLIENTE ---" << endl;
                                        identificador = identificador + 1;
                                        ventas.identificador = identificador;
                                        AgregarVenta(ventas);
                                        ImprimirVentas();
                                        ModificarStock(ventas.lote, ventas.cantidad);
                                        RegistrarVenta(ventas); // Crea el archivo de Registro Ventas
                                        regresarmenuven = 1;
                                        regresar = 0;
                                    }
                                }
                                break;
                            case 2:
                                ImprimirVentas();
                                int cantidad;
                                int lote_producto;
                                cout << " Ingrese el nombre de la bebida: ";
                                getline(cin, ventas.nombre_bebida);
                                cout << " Ingrese el numero de ID de la venta: ";
                                cin >> ventas.identificador;

                                lote_producto = BuscarLote(ventas.identificador);
                                cantidad = BuscarCantidadVenta(ventas.identificador);

                                EliminarVenta(ventas.nombre_bebida, ventas.identificador);

                                ModificarStockDevolucion(lote_producto, cantidad, ventas.nombre_bebida);
                                regresarmenuven = 1;
                                regresar = 0;
                                break;
                            case 3:
                                regresarmenuven = 1;
                                regresar = 1;
                                contador = 0;
                                break;
                            default:
                                cout << "Opcion no valida!";
                                regresarmenuven = 1;
                                regresar = 0;
                                break;
                            }
                            system("pause");
                        } while (regresarmenuven == 0);
                        break;
                    // Opcion 3 del menu Usuario Administrador 2
                    case 3:
                        cout << endl;
                        cout << " De verdad desea cerrar sesion? Si (0), No (1)" << endl;
                        cin >> sesion;
                        if (sesion == 0)
                        {
                            cout << " Ha cerrado sesion" << endl;
                            contador = 1;
                            regresar = 1;
                        }
                        else if (sesion == 1)
                        {
                            cout << " Sesion mantenida" << endl;
                            contador = 0;
                            regresar = 1;
                        }
                        else
                        {
                            sesion = 0;
                            cout << "Opcion no valida! Cerrando sesion..." << endl;
                            cout << endl;
                            contador = 1;
                            regresar = 1;
                        }
                        break;
                    default:
                        cout << " Ingrese una opcion valida!" << endl;
                        cout << endl;
                        regresar = 1;
                        contador = 0;
                        break;
                    }
                } while (regresar == 0);
                break;
            default:

                break;
            }
        } while (contador == 0);
    } while (sesion == 0);
    return 0;
}

// Funciones
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