#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Bebida
{
    int lote;
    string nombre_bebida;
    int tipo_bebida;
    float precio;
    int cantidad;
    float precio_venta;
};

struct Ventas
{
    string nombre_bebida;
    int lote;
    int cantidad;
    string nombre_consumidor;
    float precio_total;
};

struct Usuarios
{
    string usuario;
    string contrasenia;
    int tipo_usuario;
};

void Write_RegistroVentas();
void Read_RegistroVentas();
void ImprimirBebidas();
void ImprimirVentas();
void ImprimirLotes(string);
void BuscaryModificarBebida(string);
float BuscarPrecioVenta(int);
int BuscarBebidaPack(int);
int BuscarBebidapack6(string);
int BuscarBebidapack12(string);
int BuscarBebidapack24(string);
void EliminarBebida(string);
void AgregarBebida(Bebida);
void AgregarVenta(Ventas);
int BuscarUsuario(string, string);
void RegistrarVenta(Ventas venta);

vector<Bebida> packs;
vector<Usuarios> usuario;
vector<Ventas> venta;

struct Inicio_Sesion
{
    string Usuario;
    string Email;
    int Pin;
} Empleado;

int main()
{

    // cositas detallitos bonitos
    Bebida bebida;
    Usuarios usuarios;
    Ventas ventas;
    int opcion_agregar;
    string bebidaEncontrar, bebidaModificar, bebidaEliminar;
    string nombre;
    int segunda_opcion;
    int opcion;
    string nombre_usuario;
    string contrasenia;
    int tipo_usuario;
    int sesion;
    int contador = 0;
    int contador1 = 0;
    int opcion1;
    int lote = 0;

    // insertar datos vector
    /*packs.push_back({1, "Roca", 1, 60.35, 4, 3.00});
    packs.push_back({2, "Pepsi", 2, 80.35, 4,3.00});
    packs.push_back({3, "CocaCola", 1, 90.35, 4, 3.00});
    packs.push_back({4, "SalvaCola", 2, 60.35, 4, 3.00});*/

    // insertar datos vector usuarios, administrador
    usuario.push_back({"admin123", "123", 1});
    usuario.push_back({"admin456", "456", 1});
    usuario.push_back({"admin789", "789", 2});

    // esto creo que no iria aqui xd
    // Read_RegistroVentas();
    // Write_RegistroVentas();

    cout << endl;
    cout << "             ------PEPITO'S------" << endl;
    cout << "   ------- DISTRIBUIDORA DE BEBIDAS -------" << endl;
    cout << endl;
    cout << "        En vez de una, llevate varias" << endl;
    cout << endl;

    // opcion de admi o usuario

    // cout << "Seleccione la opcion:\n\n1. Opc. Administrador\n2. Opc. Cliente\n3. Salir\n"
    //<< endl;
    // cin >> opcion;
    // cin.ignore();

    cout << "Ingrese su Usuario: ";
    cin >> nombre_usuario;
    cout << "Ingrese su contraseña";
    cin >> contrasenia;
    cin.ignore();
    cout << endl;

    tipo_usuario = BuscarUsuario(nombre_usuario, contrasenia);

    do
    {
        switch (tipo_usuario)
        {
        case 1:
            cout << "----- OPCIONES ADMINISTRADOR ----- " << endl;
            cout << endl;
            cout << "Presione (1) para el manejo de usuarios" << endl;
            cout << "Presione (2) para el manejo de productos" << endl;
            cout << "Presione (3) para el manejo de ventas" << endl;
            cout << "Presione (4) para generar archivos" << endl;
            cout << "Presione (5) para cerrar sesion" << endl;
            cout << endl;
            cin >> opcion;

            switch (opcion)
            {
            case 2:
                cout << "----- MANEJO DE PRODUCTOS ----- " << endl;
                cout << endl;
                cout << "Presione (1) para agregar productos" << endl;
                cout << "Presione (2) para mostrar productos existentes" << endl;
                cout << "Presione (3) para regresar al menu anterior" << endl;
                cin >> opcion1;

                do
                {
                    switch (opcion1)
                    {
                    case 1:
                        bebida.lote = lote + 1;
                        cout << "Ingrese el nombre de la bebida: ";
                        cin >> bebida.nombre_bebida;
                        cout << "Tipos de pack" << endl;
                        cout << "1 = Pack de 6 botellas" << endl;
                        cout << "2 = Pack de 12 botellas" << endl;
                        cout << "3 = Pack de 24 botellas" << endl;
                        cout << "Ingrese el tipo de pack a comprar: ";
                        cin >> bebida.tipo_bebida;
                        cout << "Ingrese el precio total de su compra: ";
                        cin >> bebida.precio;
                        cout << "Ingrese la cantidad de packs: ";
                        cin >> bebida.cantidad;
                        cout << endl;
                        cout << "El precio por pack es de $" << (bebida.precio / bebida.cantidad) << " le sugerimos ingresar un monto mayor para generar ganancia." << endl;
                        cout << "Ingrese el costo de venta por pack: ";
                        cin >> bebida.precio_venta;

                        AgregarBebida(bebida);
                        ImprimirBebidas();
                        contador1 = 1;
                        break;
                    case 2:
                        ImprimirBebidas();
                        break;
                    case 3:
                        contador1 = 1;
                        break;
                    default:
                        cout << "Opcion no valida";
                        contador1 = 1;
                        break;
                    }
                } while (contador1 == 0);

                break;
            case 3:
                cout << "----- MANEJO DE VENTAS ----- " << endl;
                cout << endl;
                cout << "Presione (1) para agregar venta" << endl;
                cout << "Presione (2) para eliminar una venta" << endl;
                cout << "Presione (3) para regresar al menu anterior" << endl;
                cin >> opcion1;

                do
                {
                    switch (opcion1)
                    {
                    case 1:
                        ImprimirBebidas();
                        cout << "Ingrese el nombre de la bebida: ";
                        cin >> ventas.nombre_bebida;

                        int packs6, packs12, packs24, lote;

                        packs6 = BuscarBebidapack6(ventas.nombre_bebida);
                        packs12 = BuscarBebidapack12(ventas.nombre_bebida);
                        packs24 = BuscarBebidapack24(ventas.nombre_bebida);

                        cout << "Tipos de packs disponibles" << endl;
                        cout << "Usted tiene " << packs6 << " packs de 6 botellas disponibles" << endl;
                        cout << "Usted tiene " << packs12 << " packs de 12 botellas disponibles" << endl;
                        cout << "Usted tiene " << packs24 << " packs de 24 botellas disponibles" << endl;
                        cout << endl;

                        cout << "Su numero de lotes comprados son los siguientes:" << endl;
                        ImprimirLotes(ventas.nombre_bebida);

                        cout << "Ingrese el numero de lote: ";
                        cin >> ventas.lote;
                        cout << "Ingrese la cantidad de packs: ";
                        cin >> ventas.cantidad;

                        cout << "Ingrese el nombre de el consumidor: ";
                        cin >> ventas.nombre_consumidor;
                        int packs;
                        float preciofinal;

                        packs = BuscarBebidaPack(ventas.lote);
                        preciofinal = BuscarPrecioVenta(ventas.lote);

                        if (packs < ventas.cantidad)
                        {
                            cout << "No tiene esa cantidad en el stock";
                            return 0;
                        }
                        cout << endl;

                        cout << "El costo final de su venta sera de: $" << (preciofinal * ventas.cantidad);
                        ventas.precio_total = (preciofinal * ventas.cantidad);

                        AgregarVenta(ventas);
                        ImprimirVentas();
                        RegistrarVenta(ventas);
                        return 0;
                        break;
                    case 2:
                        ImprimirBebidas();
                        break;
                    case 3:
                        contador1 = 1;
                        break;
                    default:
                        cout << "Opcion no valida";
                        contador1 = 1;
                        break;
                    }
                } while (contador1 == 0);

                break;
            case 4:
                cout << "De verdad desea cerrar sesion? Si = 1, No = 0" << endl;
                cin >> sesion;
                if (sesion == 1)
                {
                    cout << "Ha cerrado sesion" << endl;
                    contador = 1;
                }
                else if (sesion == 0)
                {
                    contador = 0;
                }
                else
                {
                    cout << "Opcion no valida, cerrando sesion..." << endl;
                    cout << "Ha cerrado sesion" << endl;
                    contador = 1;
                }

                break;
            }

            break;

        case 2:
            cout << "----- OPCIONES EMPLEADO -----" << endl;
            cout << endl;
            cout << "Presione (1) para el manejo de ventas" << endl;
            cout << "Presione (2) para generar archivos" << endl;
            cout << "Presione (3) para cerrar sesion" << endl;
            cout << endl;
            cin >> opcion;

            /*cout << "Informacion necesaria para la compra" << endl;
            cout << endl;

            cout << "Ingrese su nombre: ";
                getline(cin, nombre);
                // cin >> nombre;
                cout << endl;

                cout << "Bebidas disponibles: " << endl;
                ImprimirBebidas();
                cout << endl;
                break;*/
            break;

        default:
            break;
        }
    } while (contador == 0);
    return 0;
}

// coso de archivos txt

void Write_RegistroVentas()
{
    string fileName = "Bebida_Preferida.txt";
    ofstream file;

    file.open(fileName, fstream::app);

    if (file.is_open())
    {
        file << "La bebida preferida del mes es: " << endl;
    }
    else
    {
        cout << "Error al abrir el archivo" << endl;
        file.close();
    }
}

void Read_RegistroVentas()
{
    string line;
    string fileName = "Bebida_Preferida.txt";
    ifstream file;

    file.open(fileName);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            cout << line << endl;
        }
    }
    else
    {
        cout << "Error al abrir el archivo" << endl;
        file.close();
    }
}

void ImprimirBebidas()
{
    // for off
    for (Bebida bebida : packs)
    {
        cout << endl;
        cout << bebida.nombre_bebida << endl
             << " el tipo de pack es: " << bebida.tipo_bebida << endl
             << " el precio total de la compra es de: $" << bebida.precio << endl
             << " la cantidad de packs comprados es de: " << bebida.cantidad << endl
             << " el precio de venta por pack sera de: $" << bebida.precio_venta << endl
             << " la ganancia por pack sera de: $" << (bebida.precio_venta - (bebida.precio / bebida.cantidad)) << endl;
    }
    cout << "\n\n";
}

void ImprimirVentas()
{
    // for off
    for (Ventas venta : venta)
    {
        cout << endl;
        cout << " el nombre del consumidor es: " << venta.nombre_consumidor << endl
             << " el precio total de la compra es de: $" << venta.precio_total << endl
             << " la cantidad de packs comprados es de: " << venta.cantidad << endl
             << " el numero de lote utilizado fue el: " << venta.lote << endl;
    }
    cout << "\n\n";
}

void ImprimirLotes(string nombre)
{
    // for off
    for (Bebida bebida : packs)
    {
        if (nombre == bebida.nombre_bebida)
        {
            cout << endl;
            cout << " El numero de lote es: " << bebida.lote << endl
                 << " el tipo de pack es: " << bebida.tipo_bebida << endl
                 << " la cantidad de packs comprados es de: " << bebida.cantidad << endl
                 << " el precio de venta por pack sera de: $" << bebida.precio_venta << endl
                 << " la ganancia por pack sera de: $" << (bebida.precio_venta - (bebida.precio / bebida.cantidad)) << endl;
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
    // cout << "No se ha encontrado la bebida" << endl;
    return contadorventa;
}

int BuscarBebidaPack(int lote)
{
    int contadorpacks;
    for (Bebida bebida : packs)
    {
        if (lote == bebida.lote)
        {
            contadorpacks = bebida.cantidad;
        }
    }
    // cout << "No se ha encontrado la bebida" << endl;
    return contadorpacks;
}
int BuscarBebidapack6(string nombreBebida)
{
    int contadorpacks6 = 0;
    for (Bebida bebida : packs)
    {
        if (nombreBebida == bebida.nombre_bebida)
        {
            /*cout << "Bebida encontrada\n Precio $" << bebida.precio << endl;
            return;*/
            if (bebida.tipo_bebida == 1)
            {
                contadorpacks6 = contadorpacks6 + bebida.cantidad;
            }
            else
            {
                // cout << "No disponibles";
            }
        }
    }
    // cout << "No se ha encontrado la bebida" << endl;
    return contadorpacks6;
}
int BuscarBebidapack12(string nombreBebida)
{
    int contadorpacks12 = 0;
    for (Bebida bebida : packs)
    {
        if (nombreBebida == bebida.nombre_bebida)
        {
            /*cout << "Bebida encontrada\n Precio $" << bebida.precio << endl;
            return;*/
            if (bebida.tipo_bebida == 2)
            {
                contadorpacks12 = contadorpacks12 + bebida.cantidad;
            }
            else
            {
                // cout << "No disponibles";
            }
        }
    }
    // cout << "No se ha encontrado la bebida" << endl;
    return contadorpacks12;
}

int BuscarBebidapack24(string nombreBebida)
{

    int contadorpacks24 = 0;
    for (Bebida bebida : packs)
    {
        if (nombreBebida == bebida.nombre_bebida)
        {
            /*cout << "Bebida encontrada\n Precio $" << bebida.precio << endl;
            return;*/
            if (bebida.tipo_bebida == 3)
            {
                contadorpacks24 = contadorpacks24 + bebida.cantidad;
            }
            else
            {
                // cout << "No disponibles";
            }
        }
    }
    // cout << "No se ha encontrado la bebida" << endl;
    return contadorpacks24;
}

int BuscarUsuario(string nombreusuario, string contrasenia)
{
    int tipo_usu;
    for (Usuarios usuario : usuario)
    {
        if (nombreusuario == usuario.usuario)
        {
            if (usuario.contrasenia == contrasenia)
            {
                if (usuario.tipo_usuario == 1)
                {
                    cout << "Bienvenido usuario administrador" << endl;
                    tipo_usu = 1;
                    return tipo_usu;
                }
                else
                {
                    cout << "Bienvenido empleado" << endl;
                    tipo_usu = 2;
                    return tipo_usu;
                }
            }
            else
            {
                cout << "Credenciales no validas" << endl;
                return tipo_usu;
            }
        }
    }
    cout << "No se ha encontrado el usuario" << endl;
    return tipo_usu;
}

void BuscaryModificarBebida(string nombreBebida)
{
    string nuevoNombre;
    float nuevoPrecio;

    for (int i = 0; i < packs.size(); i++)
    {
        if (nombreBebida == packs[i].nombre_bebida)
        {
            cout << "Ingrese el nuevo nombre: ";
            cin >> nuevoNombre;
            cout << "Ingrese el nuevo precio: ";
            cin >> nuevoPrecio;

            packs[i].nombre_bebida = nuevoNombre;
            packs[i].precio = nuevoPrecio;
            return;
        }
    }
    cout << "No se ha encontrado la bebida" << endl;
}

void EliminarBebida(string nombreBebida)
{
    for (int i = 0; i < packs.size(); i++)
    {
        if (nombreBebida == packs[i].nombre_bebida)
        {
            packs.erase(packs.begin() + i);
            cout << "Bebida eliminada" << endl;
            return;
        }
    }
    cout << "No se ha encotrado la bebida" << endl;
}

void RegistrarVenta(Ventas venta)
{
    ofstream file;

    file.open("RegistroVentas.txt", ios::app); // Abre el archivo en modo append

    if (file.is_open())
    {
        file << "Nombre de la bebida: " << venta.nombre_bebida << endl;
        file << "Número de lote: " << venta.lote << endl;
        file << "Cantidad de packs: " << venta.cantidad << endl;
        file << "Nombre del consumidor: " << venta.nombre_consumidor << endl;
        file << "Costo final: $" << venta.precio_total << endl;
        file << "-------------------------" << endl;
        file.close();
    }
    else
    {
        cout << "No se pudo abrir el archivo para guardar el detalle de la venta." << endl;
    }
}