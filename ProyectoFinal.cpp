#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Bebida
{
    string nombre_bebida;
    int lote; 
    float precio;
    float precio_venta; 
    int cantidad; 
    int tipo_bebida; 
};
struct Ventas
{
    string nombre_bebida;
    int lote;
    int cantidad;
    string nombre_consumidor;
    float precio_total;
};
struct Cajas
{
    string tipo_caja;
    float precio_caja;
};
struct Usuarios
{
    string usuario;
    string contrasenia;
    int tipo_usuario;
};

void ImprimirBebidas();
void ImprimirPreciosCajas();
void BuscaryModificarBebida(string, string);
void ModificarPrecioCaja(int, float);
void BuscarBebida(string);
void EliminarBebida(string);
void AgregarBebida(Bebida);
Bebida ObtenerBebida(string);
bool contieneBebida(string);
int BuscarUsuario(string, string);
void AgregarUsuarios(Usuarios);
void EliminarUsuario(string);
void ImprimirUsuarios();
// void ImprimirLotes(string); 
// float BuscarBebidaPack(int);
// float BuscarBebidapack6(string);
// int BuscarBebidapack12(string);
// int BuscarBebidapack24(string);

vector<Cajas> packs;
vector<Usuarios> usuario;
vector<Bebida> drinks;

int main()
{
    Ventas ventas; 
    Bebida bebida;
    Bebida comprarBebida;
    int opcion_caja, option;
    float precioXcaja, nuevoPrecioCaja;
    int cantidad_packs;
    float preciofinal;
    int opcion_agregar;
    string bebidaEncontrar, bebidaModificar, bebidaEliminar;
    string nombre;
    string nuevoNombrebebida;
    int segunda_opcion;
    int opcion, cajaSeleccionada;
    string Producto;
    string contrasenia;
    string nombre_usuario;
    int contador = 0;
    int tipo_usuario;
    int opcion_usuarios;
    Usuarios nuevoUsuario;
    string usuarioEliminar;
    int contador1 = 0;
    int lote = 0; 
    Usuarios nuevaContra; 

    drinks.push_back({"Agua"});
    drinks.push_back({"Coca Cola"});
    drinks.push_back({"Pepsi"});
    drinks.push_back({"Leche"});
    drinks.push_back({"Seven up"});
    drinks.push_back({"Fanta"});

    packs.push_back({"Caja de 6", 4.99});
    packs.push_back({"Caja de 12", 11.99});
    packs.push_back({"Caja de 24", 20.99});

    usuario.push_back({"admin123", "123", 1});
    usuario.push_back({"admin456", "456", 1});
    usuario.push_back({"admin789", "789", 2});

    cout << endl;
    cout << "       ********** PEPITO'S *********" << endl;
    cout << " ********* DISTRIBUIDORA DE BEBIDAS *********" << endl;
    cout <<"*************************************************"<<endl; 
    cout << endl;
    cout << "        * En vez de una, llevate varias *" << endl;
    cout << endl;
    
    cout <<"*************************************************"<<endl; 
    cout << "Ingrese su Usuario: ";
    cin >> nombre_usuario;
    cout << "Ingrese su contrasenia: ";
    cin >> contrasenia;
    cin.ignore();

    tipo_usuario = BuscarUsuario(nombre_usuario, contrasenia);

    do
    {
        switch (tipo_usuario)
        {
        case 1:
            do
            {
                
            cout << endl;
            cout <<"***************************************"<< endl; 
            cout << "   ----- JEFE ADMINISTRADOR ----- " << endl;
            cout <<"***************************************"<< endl;
            cout <<endl; 
            cout << "Presione (1) para el manejo de usuarios" << endl;
            cout << "Presione (2) para el manejo de productos" << endl;
            cout << "Presione (3) para registro de venta diarias" << endl;
            cout << "Presione (4) para cerrar sesion" << endl;
            cin >> opcion;
            cout << endl;

            cin.ignore();
            switch (opcion)
            {
            case 1:
                cout << "******* MANEJO DE USUARIOS *******" << endl
                     << endl;
                ImprimirUsuarios();
                do
                {
                cout << "Presione (1) para agregar usuarios\nPresione (2) para eliminar usuarios\nPresione (3) para regresar al menu\n"
                     << endl;
                cin >> opcion_usuarios;
                switch (opcion_usuarios)
                {
                case 1:
                    cout << "Ingrese el nombre de usuario: ";
                    cin >> nuevoUsuario.usuario;
                    cout << "Ingrese una contrasenia: ";
                    cin >> nuevaContra.contrasenia; 
                    AgregarUsuarios(nuevoUsuario);
                    ImprimirUsuarios();
                    break;
                case 2:
                    cout << "Ingrese el usuario que desea eliminar: ";
                    cin >> usuarioEliminar;
                    EliminarUsuario(usuarioEliminar);
                    ImprimirUsuarios();
                    cout << endl;
                    break;

                default:
                    cout << "Parece que algo salio mal xd" << endl;
                    break;
                }
                } while(contador1 == 3);

            break;

            case 2:
                cout <<endl; 
                cout << "******** MANEJO DE PRODUCTOS ********" << endl;
                cout << "            Packs y bebidas" << endl;
                cout << endl;
                ImprimirBebidas();
                cout << endl;
                cout << "Ingrese la opcion que desea: " << endl;
                do
                {
                    cout << "\n Presione (1) para buscar\n Presione (2) para modificar inventario\n Presione (3) para eliminar informacion existente\n Presione (4) para regresar al menu\n"
                         << endl;
                    cin >> opcion;

                    switch (opcion)
                    {
                    case 1:
                        cout << "  Ingrese la bebida que desea buscar: ";
                        cin >> bebidaEncontrar;
                        cout << endl;

                        BuscarBebida(bebidaEncontrar);
                        break;

                    case 2:
                        cout << "\n Presione (1) para modificar Bebida\n Presione (2) para modificar precio de caja\n";
                        cin >> option;

                        switch (option)
                        {
                        case 1:
                            cout << "Nombre bebida:" << endl;
                            cin >> bebidaEncontrar;
                            if (contieneBebida(bebidaEncontrar))
                            {
                                cout << "Nuevo nombre: ";

                                cin >> nuevoNombrebebida;
                                BuscaryModificarBebida(bebidaEncontrar, nuevoNombrebebida);
                            }
                            else
                            {
                                cout << "Bebida no existente en inventario" << endl;
                            }

                            break;
                        case 2:
                            ImprimirPreciosCajas();
                            cout << "\n Presione (1) caja de 6\n Presione (2) caja de 12\n Presione (3) caja de 24 " << endl;
                            cin >> cajaSeleccionada;

                            if (cajaSeleccionada >= 1 && cajaSeleccionada <= 3)
                            {
                                cout << "Ingrese el nuevo precio de la caja: $";
                                cin >> nuevoPrecioCaja;

                                ModificarPrecioCaja(cajaSeleccionada, nuevoPrecioCaja);

                                cout << "Precios actualizados de las cajas:" << endl;

                                ImprimirPreciosCajas();
                            }
                            else
                            {
                                cout << "Ingrese un número valido (entre 1 y 3)" << endl;
                            }
                            break;

                            ImprimirBebidas();

                            cout << "Desea agregar una nueva bebida?\n 1.Si\n 2.No\n";
                            cin >> opcion_agregar;
                            switch (opcion_agregar)
                            {
                            case 1:
                                cout << "Ingrese nombre de la bebida: ";
                                cin >> bebida.nombre_bebida;

                                AgregarBebida(bebida);
                                ImprimirBebidas();

                                cout << "Saliendo" << endl;
                                break;
                            default:
                                cout << "Error al ingresar datos" << endl;
                                break;
                            }

                        default:
                            cout << "Error" << endl;
                            break;
                        }
                        break;

                    case 3:
                        cout << "Ingrese la bebida que desea eliminar: ";
                        cin >> bebidaEliminar;

                        EliminarBebida(bebidaEliminar);

                        ImprimirBebidas();
                        break;

                    case 4:
                        cout << "Regresar menu anterior" << endl;
                        break;

                    default:
                        cout << "Error al ingresar opcion" << endl;
                        break;
                    }

                break;
                } while (contador1 == 4);

            case 3:
                cout <<endl; 
                // Registro de ventas(parte de Luis dea rchivos) 
                cout << "******** REGISTRO DE VENTAS DIARIAS ********--"<<endl; 
                //funcion de archivo txt; 
                break;

            case 4:
                return 0; 
                break;

            default:
                cout << "Error" << endl;
                break;
            }
            } while(tipo_usuario == 1);

        case 2:
            cout <<endl; 
            cout <<"***************************************"<<endl; 
            cout << "  ----- EMPLEADO ADMINISTRADOR -----" << endl;
            cout <<"***************************************"<<endl; 
            cout << endl;
            cout << "Presione (1) para el manejo de ventas" << endl;
            cout << "Presione (2) para buscar producto en inventario" << endl;
            cout << "Presione (3) para cerrar sesion" << endl;
            cin >> segunda_opcion; 
            cin.ignore();

            switch (segunda_opcion)
            {
                case 1: 
                cout <<"******** MANEJO DE VENTAS ********"<<endl; 
                cout <<endl; 
                cout << "Informacion necesaria para la compra" << endl;
                cout << endl;
                bebida.lote = lote + 1; 
                cout << "Ingrese el nombre del cliente: ";
                getline(cin, ventas.nombre_consumidor);
                cout <<endl; 
                cout << "Bebidas disponibles: " << endl;
                ImprimirBebidas();
                cout << endl;

                do
                {
                cout << "Ingrese el nombre de la bebida: ";
                getline(cin, ventas.nombre_bebida);
                if (contieneBebida(ventas.nombre_bebida))
                {
                    comprarBebida = ObtenerBebida(ventas.nombre_bebida);
                }
                else
                {
                    cout << "La bebida no se encontra, ingrese un nombre valido" << endl;
                }
                } while (!contieneBebida(ventas.nombre_bebida));
                    
                cout << "Seleccione el tipo de packs que desea: " << endl;
                cout << "\n 1. Caja de 6 \n 2. Caja de 12\n 3. Caja de 24\n";
                cin >> opcion_caja;
                cout << "Ingrese el numero de lote: ";
                cin >> ventas.lote;
                // packs = BuscarBebidaPack(ventas.lote);
                cout <<"Ingrese la cantidad de packs que desea llevar: "; 
                cin >> ventas.cantidad; 
                cout <<"Ingrese el precio total de la comprar: $"; 
                cin >>bebida.precio; 
                cout << "El precio por pack es de $" << (bebida.precio/ventas.cantidad) << " le sugerimos ingresar un monto mayor para generar ganancia."<< endl;
                cout << "Ingrese el costo de venta por pack: ";
                cin >> bebida.precio_venta;

                break; 

                case 2: 
                cout <<"Ingrese el nombre de la bebida que desea buscar: "; 
                getline(cin, bebidaEncontrar); 

                BuscarBebida(bebidaEncontrar);
                cout << endl; 
                break; 

                case 3:
                return 0; 
                break; 

            default:
                cout <<"Error al ingresar la opcion"<<endl; 
                break;
            }
            

        case 3:
            cout << "Saliendo" << endl;
            break;

        default:
            cout << "Error al ingresar la opcion" << endl;
            break;
        }

    } while (contador == 0);

    system("pause");
    return 0;
}

void ImprimirBebidas()
{
    cout << ">> Manejo de packs:\n " << endl;
    for (Cajas nose : packs)
    {
        cout << " --" << nose.tipo_caja << " $" << nose.precio_caja << endl;
    }
    cout << "\n";
    // for off
    cout << ">> Lista de bebidas disponibles:\n " << endl;
    for (Bebida bebida : drinks)
    {
        cout << " --" << bebida.nombre_bebida << endl;
    }
    cout << "\n";
}

void ImprimirPreciosCajas()
{
    for (Cajas caja : packs)
    {
        cout << caja.tipo_caja << ": $" << caja.precio_caja << endl;
    }
}

void AgregarBebida(Bebida nuevaBebida)
{
    drinks.push_back(nuevaBebida);
}

Bebida ObtenerBebida(string nombreBebida)
{
    Bebida bebidaEncontrada;
    for (Bebida bebida : drinks)
    {
        if (nombreBebida == bebida.nombre_bebida)
        {
            bebidaEncontrada = bebida;
        }
    }
    return bebidaEncontrada;
}
bool contieneBebida(string nombreBebida)
{
    for (Bebida bebida : drinks)
    {
        if (nombreBebida == bebida.nombre_bebida)
        {
            return true;
        }
    }
    return false;
}

void BuscarBebida(string nombreBebida)
{
    string nuevoNombre;

    for (Bebida bebida : drinks)
    {
        if (nombreBebida == bebida.nombre_bebida)
        {
            cout << "  Bebida disponible" << endl;

            cout << "  Precio por cajas:\n";
            for (Cajas caja : packs)
            {
                cout << " -" << caja.tipo_caja << " $" << caja.precio_caja << endl;
            }
            return;
        }
    }
    cout << "-- Bebida no disponible en packs" << endl;
    cout << endl;
}
void BuscaryModificarBebida(string nombreAnterior, string nuevoNombre)
{
    for (int i = 0; i < drinks.size(); i++)
    {
        if (nombreAnterior == drinks[i].nombre_bebida)
        {
            drinks[i].nombre_bebida = nuevoNombre;
            return;
        }
    }
}

void ModificarPrecioCaja(int indice, float precio)
{

    packs[indice - 1].precio_caja = precio;
}

void EliminarBebida(string nombreBebida)
{
    for (int i = 0; i < drinks.size(); i++)
    {
        if (nombreBebida == drinks[i].nombre_bebida)
        {
            drinks.erase(drinks.begin() + i);
            cout << "Bebida eliminada" << endl;
            return;
        }
    }
    cout << "No se ha encotrado la bebida" << endl;
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
                    cout << endl;
                    cout << "Bienvenido usuario administrador" << endl;
                    tipo_usu = 1;
                    return tipo_usu;
                }
                else
                {
                    cout <<endl; 
                    cout << "Bienvenido usuario empleado" << endl;
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

// USUARIOS

void AgregarUsuarios(Usuarios nuevoUsuario)
{
    usuario.push_back(nuevoUsuario);
}
void ImprimirUsuarios()
{
    cout << "Usuarios existentes: " << endl;
    for (Usuarios imprimir : usuario)
    {
        cout << "\t* " << imprimir.usuario << endl;
    }
}
void EliminarUsuario(string usuarioEliminar)
{
    for (int i = 0; i < usuario.size(); i++)
    {
        if (usuarioEliminar == usuario[i].usuario)
        {
            usuario.erase(usuario.begin() + i);
            cout << "Usuario eliminado" << endl;
            return;
        }
    }
    cout << "El usuario no existe" << endl;
}
// void ImprimirLotes(string nombre){
    //     for (Bebida bebida : drinks)
    // {
    //     if(nombre == bebida.nombre_bebida) {
    //         cout << endl;
    //         cout << " El numero de lote es: " << bebida.lote << endl << " el tipo de pack es: " << bebida.tipo_bebida << endl << " la cantidad de packs comprados es de: " << bebida.cantidad << endl << " el precio de venta por pack sera de: $" << bebida.precio_venta << endl << " la ganancia por pack sera de: $" << (bebida.precio_venta - (bebida.precio/bebida.cantidad)) << endl;
    //     }
    // }   
//     cout << "\n\n";

// }
//  float BuscarBebidaPack(int lote){
    //  int contadorpacks;
    // for (Bebida bebida : drinks)
    // {
    //     if (lote == bebida.lote)
    //     {
    //         contadorpacks = bebida.cantidad;
    //     } 
    // }
    // return contadorpacks;
//}
// float BuscarBebidapack6(string nombreBebida)
//{
    // int contadorpacks6 = 0;
    // for (Bebida bebida : drinks)
    // {
    //     if (nombreBebida == bebida.nombre_bebida)
    //     {
    //         if(bebida.tipo_bebida == 1){
    //             contadorpacks6 = contadorpacks6 + bebida.cantidad;
    //         } else{
    //         }
    //     } 
    // }
    // return contadorpacks6;
//}