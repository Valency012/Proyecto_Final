#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Bebida
{
    string nombre_bebida;
    float precio;
};

void Write_RegistroVentas();
void Read_RegistroVentas();
void ImprimirBebidas();
void BuscaryModificarBebida(string);
void BuscarBebida(string);
void EliminarBebida(string);
void AgregarBebida(Bebida);

vector<Bebida> packs;

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
    int opcion_agregar;
    string bebidaEncontrar, bebidaModificar, bebidaEliminar;
    string nombre;
    int segunda_opcion;
    int opcion;

    packs.push_back({"Agua", 6.35});
    packs.push_back({"Coca Cola", 12.45});
    packs.push_back({"Pepsi", 9.35});
    packs.push_back({"Leche", 10.99});
    packs.push_back({"Seven up", 12.20});
    packs.push_back({"Fanta", 7.35});

    // esto creo que no iria aqui xd
    Read_RegistroVentas();
    Write_RegistroVentas();

    cout << endl;
    cout << "             ------PEPITO'S------" << endl;
    cout << "   ------- DISTRIBUIDORA DE BEBIDAS -------" << endl;
    cout << endl;
    cout << "        En vez de una, llevate varias" << endl;
    cout << endl;

    // opcion de admi o usuario
    do
    {
        cout << "Seleccione la opcion:\n\n1. Opc. Administrador\n2. Opc. Cliente\n3. Salir\n"
             << endl;
        cin >> opcion;
        cin.ignore();

        switch (opcion)
        {
        case 1:
            cout << "----- OPCION ADMINISTRADOR ----- " << endl;
            cout << endl;

            cout << "Ingrese su Usuario: ";
            cin >> Empleado.Usuario;
            cout << "Ingrese su Email: ";
            cin >> Empleado.Email;
            cout << "Ingrese el Pin: ";
            cin >> Empleado.Pin;
            cin.ignore();
            cout << endl;

            if (Empleado.Pin = 123)
            {
                cout << "Inicio de Sesion correctamente" << endl;
                cout << endl;
                cout << "--INVENTARIO DE BEBIDAS--" << endl
                     << endl;
                ImprimirBebidas();
                cout << endl;
                cout << "Ingrese la opcion que desea: " << endl;
                cout << "\n 1. Buscar informacion\n 2. Modificar inventario\n 3. Eliminar informacion existente" << endl;
                cin >> segunda_opcion;
                switch (segunda_opcion)
                {
                // Encontrar bebida
                case 1:
                    cout << ">> Buscar Informacion" << endl;
                    cout << "Ingrese la bebida que desea buscar: ";
                    cin >> bebidaEncontrar;

                    BuscarBebida(bebidaEncontrar);

                    break;

                case 2:
                    // falta opcion de agregar bebida
                    cout << ">> Modificar inventario" << endl;
                    cout << "Ingrese la bebida que desea modificar: ";
                    cin >> bebidaModificar;

                    BuscaryModificarBebida(bebidaModificar);

                    ImprimirBebidas();

                    cout << "Desea agregar una nueva bebida?\n 1.Si\n 2.No";
                    cin >> opcion_agregar;
                    switch (opcion_agregar)
                    {
                    case 1:
                        cout << "Ingrese nombre de la bebida: ";
                        cin >> bebida.nombre_bebida;

                        cout << "Ingrese el precio de la bebida: ";
                        cin >> bebida.precio;

                        AgregarBebida(bebida);
                        ImprimirBebidas();
                        break;
                    // regresar al menu
                    case 2:
                        cout << "Saliendo" << endl;
                        break;

                    default:
                        cout << "Error al ingresar datos" << endl;
                        break;
                    }
                    break;

                case 3:
                    cout << ">>Eliminar informacion existente" << endl;
                    cout << "Ingrese la bebida que desea eliminar: ";
                    cin >> bebidaEliminar;

                    EliminarBebida(bebidaEliminar);

                    ImprimirBebidas();
                    break;

                default:
                    cout << "Error al elegir la opcion" << endl;
                    break;
                }
            }
            else
            {
                cout << "Pin incorrecto, intente de nuevo" << endl;
                cout << endl;
            }

            break;

        case 2:
            cout << "----- OPCIONES DE COMPRA -----" << endl;
            cout << "Informacion necesaria para la compra" << endl;
            cout << endl;

            cout << "Ingrese su nombre: ";
            getline(cin, nombre);
            // cin >> nombre;
            cout << endl;

            cout << "Bebidas disponibles: " << endl;
            ImprimirBebidas();
            cout << endl;
            break;

        case 3:
            cout << "Saliendo" << endl;
            break;

        default:
            cout << "Error al ingresar la opcion" << endl;
            break;
        }

    } while (opcion != 3);

    system("pause");
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
        cout << bebida.nombre_bebida << " $" << bebida.precio << endl;
    }
    cout << "\n\n";
}

void AgregarBebida(Bebida nuevaBebida)
{
    packs.push_back(nuevaBebida);
}

void BuscarBebida(string nombreBebida)
{
    for (Bebida bebida : packs)
    {
        if (nombreBebida == bebida.nombre_bebida)
        {
            cout << "Bebida encontrada\n Precio $" << bebida.precio << endl;
            return;
        }
    }
    cout << "No se ha encontrado la bebida" << endl;
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
