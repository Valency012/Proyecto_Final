#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

//Declaraciones de estructuras a utilizar
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
};
struct Usuarios
{
    string usuario;
    string contrasenia;
    int tipo_usuario;
};

//Declaracion de las funciones a utilizar
void Write_RegistroVentas();
void Read_RegistroVentas();
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
int BuscarUsuario(string, string);
void ModificarUsuario(string);
void EliminarVenta(string, int);
void ModificarStockDevolucion(int, int, string);
int BuscarLote(int);
int BuscarCantidadVenta(int);
void ImprimirUsuarios();
void EliminarUsuario(string);
void RegistrarVenta(Ventas venta);//registro ventas//
void MostrarRegistro(string archivo);


//Definicion de vectores
vector<Bebida> packs;
vector<Usuarios> usuario;
vector<Ventas> venta;

int main()
{

    //Declaracion de variables y estructuras

    Bebida bebida; //Declaracion estructura
    Usuarios usuarios; //Declaracion estructura
    Ventas ventas; //Declaracion estructura
    int opcion; //Variable encargada de evaluar la opcion ingresada por el cliente
    string nombre_usuario; //Variable que captura el nombre de usuario
    string contrasenia; //Variable que captura la contraseña
    int tipo_usuario; //Variable encargada de capturar el tipo de usuario
    int sesion = 0; //Variable que se encarga de cerrar sesion o mantenerla
    int contador = 0; //Variable para la navegabilidad del sistema
    int regresar = 0; //Variable para la navegabilidad del sistema
    int regresarmenupro = 0;//Variable para la navegabilidad del sistema en el menu productos
    int regresarmenuusu = 0;//Variable para la navegabilidad del sistema en el menu usuarios
    int regresarmenuven = 0;//Variable para la navegabilidad del sistema en el menu ventas
    int opcion1;//Variable encargada de evaluar la opcion ingresada por el cliente
    int lote = 0;//Variable que sirve como identificador para cada producto, generada automaticamente
    int identificador = 0;//Variable que sirve como identificador unico para cada venta


    //insertar datos vector usuarios, administrador
    usuario.push_back({"admin123", "123", 1});
    usuario.push_back({"admin456", "456", 1});
    usuario.push_back({"admin789", "789", 2});

    do
    {
        //Encabezado del sistema
        cout << endl;
        cout << "             ------PEPITO'S------" << endl;
        cout << "   ------- DISTRIBUIDORA DE BEBIDAS -------" << endl;
        cout << endl;
        cout << "        En vez de una, llevate varias" << endl;
        cout << endl;

        cout <<"*************************************************"<< endl;
        cout << "Ingrese su usuario: ";
        cin >> nombre_usuario;
        cout << "Ingrese su contrasenia: ";
        cin >> contrasenia;
        cin.ignore();
        cout << endl;

        //Llamamiento a la funcion de buscar usuario, encargada de verificar si es admin o empleado
        tipo_usuario = BuscarUsuario(nombre_usuario, contrasenia);
        do { //do while para el funcionamiento de regresar a menus anteriores
            switch (tipo_usuario)
            {
                case 1:
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
                    do {
                        switch(opcion){
                            case 1:
                            cout << "----- MANEJO DE USUARIOS ----- " << endl;
                            cout << endl;
                            cout << "Presione (1) para agregar usuarios" << endl;
                            cout << "Presione (2) para mostrar usuarios existentes" << endl;
                            cout << "Presione (3) para modificar usuarios" << endl;
                            cout << "Presione (4) para eliminar usuarios" << endl;
                            cout << "Presione (5) para regresar al menu anterior" << endl;
                            cin >> opcion1;

                                do {
                                switch(opcion1){
                                    case 1:
                                        cout << "Ingrese el nombre de usuario: ";
                                        cin >> usuarios.usuario;
                                        cout << "Ingrese una contrasenia: ";
                                        cin >> usuarios.contrasenia;
                                        cout << "Ingrese el tipo de usuario, presione (1) si es administrador y (2) si es empleado" << endl;
                                        cin >> usuarios.tipo_usuario;

                                        if(usuarios.tipo_usuario != 1 && usuarios.tipo_usuario != 2){
                                            cout << "Tipo de usuario no valido" << endl;
                                            regresarmenuusu = 1;
                                            regresar = 0;
                                        } else {
                                            AgregarUsuarios(usuarios);
                                            regresarmenuusu = 1;
                                            regresar = 0;
                                        }
                                    break;
                                    case 2:
                                        //variable para regresar
                                        int regresoUsu;
                                        ImprimirUsuarios();
                                        cout << "Presione 1 para volver al menu anterior" << endl;
                                        cin >> regresoUsu;
                                        if(regresoUsu == 1){
                                            regresarmenuusu = 1;
                                            regresar = 0;
                                        } else{
                                            cout << "Opcion no valida, volviendo al menu anterior..." << endl;
                                            regresarmenuusu = 1;
                                            regresar = 0;
                                        }
                                    break;
                                    case 3:
                                        ImprimirUsuarios();
                                        cout << "Ingrese el nombre del usuario a modificar: ";
                                        cin >> usuarios.usuario;

                                        ModificarUsuario(usuarios.usuario);
                                        regresarmenuusu = 1;
                                        regresar = 0;
                                        cout << endl;

                                    break;
                                    case 4:
                                        ImprimirUsuarios();
                                        cout << "Ingrese de el usuario a eliminar: ";
                                        cin >> usuarios.usuario;
                            
                                        EliminarUsuario(usuarios.usuario);
                                        cout << "Usuario eliminado correctamente" << endl;
                                        cout << endl;
                                        //regresando al menu principal
                                        regresarmenuusu = 1;
                                        regresar = 0;
                                    break;
                                    case 5:
                                        regresarmenuusu = 1;
                                        regresar = 1;
                                        contador = 0;
                                    break;
                                    default:
                                        cout << "Opcion no valida, regresando..." << endl;
                                        cout << endl;
                                        regresarmenuusu = 1;
                                        regresar = 1;
                                    break;
                                }
                                } while(regresarmenuusu == 0);
                            break;
                            case 2:
                            cout << "----- MANEJO DE PRODUCTOS ----- " << endl;
                            cout << endl;
                            cout << "Presione (1) para agregar productos" << endl;
                            cout << "Presione (2) para mostrar productos existentes" << endl;
                            cout << "Presione (3) para modificar productos existentes" << endl;
                            cout << "Presione (4) para eliminar productos existentes" << endl;
                            cout << "Presione (5) para regresar al menu anterior" << endl;
                            cin >> opcion1;

                                do {
                                    switch(opcion1){
                                        case 1:
                                        //lote es el campo oculto que se llenara automaticamente sin pedir ingreso
                                            cout << "Ingrese el nombre de la bebida: ";
                                            cin >> bebida.nombre_bebida;
                                            cout << "Tipos de pack" << endl;
                                            cout << "1 = Pack de 6 botellas" << endl;
                                            cout << "2 = Pack de 12 botellas" << endl;
                                            cout << "3 = Pack de 24 botellas" << endl;
                                            cout << "Ingrese el tipo de pack a comprar: ";
                                            cin >> bebida.tipo_bebida;
                                            //Verificar si el tipo pack es diferente a 1, 2 o 3, si lo es, requerir un valor valido
                                            if(bebida.tipo_bebida != 1 && bebida.tipo_bebida != 2 && bebida.tipo_bebida != 3){
                                                cout << "El tipo de pack no es correcto, ingrese una opcion valida" << endl;
                                                cout << endl;
                                                regresarmenupro = 1;
                                                regresar = 0;
                                            } else {
                                                cout << "Ingrese el precio total de su compra: ";
                                                cin >> bebida.precio;
                                                cout << "Ingrese la cantidad de packs: ";
                                                cin >> bebida.cantidad;
                                                cout << endl;
                                                cout << "El precio por pack es de $" << (bebida.precio/bebida.cantidad) << " le sugerimos ingresar un monto mayor para generar ganancia."<< endl;
                                                cout << "Ingrese el costo de venta por pack: ";
                                                cin >> bebida.precio_venta;
                                                cout << endl;
                                                lote = lote + 1;
                                                bebida.lote = lote;
                                                AgregarBebida(bebida);
                                                cout << "Producto ingresado exitosamente" << endl;
                                                cout << endl;
                                                regresarmenupro = 1;
                                                regresar = 0;
                                            }
                                        break;
                                        case 2:
                                            //variable para regresar
                                            int regreso;
                                            ImprimirBebidas();
                                            cout << "Presione 1 para volver al menu anterior" << endl;
                                            cin >> regreso;
                                            if(regreso == 1){
                                                regresarmenupro = 1;
                                                regresar = 0;
                                            } else{
                                                cout << "Opcion no valida, volviendo al menu anterior...";
                                                regresarmenupro = 1;
                                                regresar = 0;
                                            }
                                        break;
                                        case 3:
                                            ImprimirBebidas();
                                            cout << "Ingrese el nombre de la bebida: ";
                                            cin >> bebida.nombre_bebida;
                                            cout << "Ingrese el numero de lote: ";
                                            cin >> bebida.lote;

                                            BuscaryModificarBebida(bebida.nombre_bebida, bebida.lote);
                                            cout << endl;
                                            regresar = 0;
                                        break;
                                        case 4:
                                            ImprimirBebidas();
                                            cout << "Ingrese el nombre de la bebida a eliminar: ";
                                            cin >> bebida.nombre_bebida;

                                            cout << "Ingrese el numero de lote: ";
                                            cin >> bebida.lote;
                            
                                            EliminarBebida(bebida.nombre_bebida, bebida.lote);
                                            cout << "Bebida eliminada correctamente" << endl;
                                            cout << endl;
                                            //regresando al menu principal
                                            regresarmenupro = 1;
                                            regresar = 0;
                                        break;
                                        case 5:
                                            regresarmenupro = 1;
                                            regresar = 1;
                                            contador = 0;
                                        break;
                                        default:
                                            cout << "Opcion no valida, regresando..." << endl;
                                            cout << endl;
                                            regresarmenupro = 1;
                                            regresar = 0;
                                        break;
                                    }
                                } while(regresarmenupro == 0);
                    
                            break;
                            case 3:

                            MostrarRegistro("RegistroVentas.txt");//imprime el registro//
                                
                            break;
                            case 4:
                            cout << "De verdad desea cerrar sesion? Si = 0, No = 1" << endl;
                            cin >> sesion;
                                if (sesion == 0){
                                    cout << "Ha cerrado sesion" << endl;
                                    cout << endl;
                                    contador = 1;
                                    regresar = 1;
                                } else if (sesion == 1){
                                    cout << "Sesion manetenida" << endl;
                                    cout << endl;
                                    contador = 0;
                                    regresar = 1;
                                }
                                else {
                                    sesion = 0;
                                    cout << "Opcion no valida, cerrando sesion..." << endl;
                                    cout << "Ha cerrado sesion" << endl;
                                    cout << endl;
                                    contador = 1;
                                    regresar = 1;
                                }
                            break;
                            default :
                                cout << "Ingrese una opcion valida" << endl;
                                cout << endl;
                                regresar = 1;
                                contador = 0;
                            break;
                        }
                    } while(regresar == 0);
                break;

                case 2:
                cout <<endl; 
                cout <<"***************************************"<<endl; 
                cout << "  ----- EMPLEADO ADMINISTRADOR -----" << endl;
                cout <<"***************************************"<<endl; 
                cout << endl;
                cout << "Presione (1) para el manejo de productos" << endl;
                cout << "Presione (2) para el manejo de ventas" << endl;
                cout << "Presione (3) para cerrar sesion" << endl;
                cin >> opcion;
                    do {
                        switch(opcion){
                            case 1:
                            cout << "----- MANEJO DE PRODUCTOS ----- " << endl;
                            cout << endl;
                            cout << "Presione (1) para agregar productos" << endl;
                            cout << "Presione (2) para mostrar productos existentes" << endl;
                            cout << "Presione (3) para modificar productos existentes" << endl;
                            cout << "Presione (4) para eliminar productos existentes" << endl;
                            cout << "Presione (5) para regresar al menu anterior" << endl;
                            cin >> opcion1;

                                do {
                                    switch(opcion1){
                                        case 1:
                                        //lote es el campo oculto que se llenara automaticamente sin pedir ingreso
                                            cout << "Ingrese el nombre de la bebida: ";
                                            cin >> bebida.nombre_bebida;
                                            cout << "Tipos de pack" << endl;
                                            cout << "1 = Pack de 6 botellas" << endl;
                                            cout << "2 = Pack de 12 botellas" << endl;
                                            cout << "3 = Pack de 24 botellas" << endl;
                                            cout << "Ingrese el tipo de pack a comprar: ";
                                            cin >> bebida.tipo_bebida;
                                            //Verificar si el tipo pack es diferente a 1, 2 o 3, si lo es, requerir un valor valido
                                            if(bebida.tipo_bebida != 1 && bebida.tipo_bebida != 2 && bebida.tipo_bebida != 3){
                                                cout << "El tipo de pack no es correcto, ingrese una opcion valida" << endl;
                                                cout << endl;
                                                regresarmenupro = 1;
                                                regresar = 0;
                                            } else {
                                                cout << "Ingrese el precio total de su compra: ";
                                                cin >> bebida.precio;
                                                cout << "Ingrese la cantidad de packs: ";
                                                cin >> bebida.cantidad;
                                                cout << endl;
                                                cout << "El precio por pack es de $" << (bebida.precio/bebida.cantidad) << " le sugerimos ingresar un monto mayor para generar ganancia."<< endl;
                                                cout << "Ingrese el costo de venta por pack: ";
                                                cin >> bebida.precio_venta;
                                                cout << endl;
                                                lote = lote + 1;
                                                bebida.lote = lote;
                                                AgregarBebida(bebida);
                                                cout << "Producto ingresado exitosamente" << endl;
                                                cout << endl;
                                                regresarmenupro = 1;
                                                regresar = 0;
                                            }
                                        break;
                                        case 2:
                                            //variable para regresar
                                            int regreso;
                                            ImprimirBebidas();
                                            cout << "Presione 1 para volver al menu anterior" << endl;
                                            cin >> regreso;
                                            if(regreso == 1){
                                                regresarmenupro = 1;
                                                regresar = 0;
                                            } else{
                                                cout << "Opcion no valida, volviendo al menu anterior...";
                                                regresarmenupro = 1;
                                                regresar = 0;
                                            }
                                        break;
                                        case 3:
                                            ImprimirBebidas();
                                            cout << "Ingrese el nombre de la bebida: ";
                                            cin >> bebida.nombre_bebida;
                                            cout << "Ingrese el numero de lote: ";
                                            cin >> bebida.lote;

                                            BuscaryModificarBebida(bebida.nombre_bebida, bebida.lote);
                                            cout << endl;
                                            regresar = 0;
                                        break;
                                        case 4:
                                            ImprimirBebidas();
                                            cout << "Ingrese el nombre de la bebida a eliminar: ";
                                            cin >> bebida.nombre_bebida;

                                            cout << "Ingrese el numero de lote: ";
                                            cin >> bebida.lote;
                            
                                            EliminarBebida(bebida.nombre_bebida, bebida.lote);
                                            cout << "Bebida eliminada correctamente" << endl;
                                            cout << endl;
                                            //regresando al menu principal
                                            regresarmenupro = 1;
                                            regresar = 0;
                                        break;
                                        case 5:
                                            regresarmenupro = 1;
                                            regresar = 1;
                                            contador = 0;
                                        break;
                                        default:
                                            cout << "Opcion no valida, regresando..." << endl;
                                            cout << endl;
                                            regresarmenupro = 1;
                                            regresar = 0;
                                        break;
                                    }
                                } while(regresarmenupro == 0);
                    
                            break;
                            case 2:
                            cout << "----- MANEJO DE VENTAS ----- " << endl;
                            cout << endl;
                            cout << "Presione (1) para agregar venta" << endl;
                            cout << "Presione (2) para eliminar una venta" << endl;
                            cout << "Presione (3) para regresar al menu anterior" << endl;
                            cin >> opcion1;

                                do {
                                    switch(opcion1){
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

                                            int packs;
                                            float preciofinal;

                                            cout << "Ingrese el numero de lote: ";
                                            cin >> ventas.lote;

                                            packs = BuscarBebidaPack(ventas.lote, ventas.nombre_bebida);
                                            preciofinal = BuscarPrecioVenta(ventas.lote);

                                            if(packs == 0) {
                                                cout << "Ingrese un numero de lote existente" << endl;
                                                regresarmenuven = 1;
                                                regresar = 0;
                                            } else {
                                                cout << "Ingrese la cantidad de packs: ";
                                                cin >> ventas.cantidad;


                                                if(packs < ventas.cantidad){
                                                    cout << "No tiene esa cantidad en el stock" << endl;
                                                } else {
                                                    cout << "Ingrese el nombre de el consumidor: ";
                                                    cin >> ventas.nombre_consumidor;
                                                    cout << endl;
                            
                                                    cout << "El costo final de su venta sera de: $" << (preciofinal * ventas.cantidad);
                                                    ventas.precio_total = (preciofinal  * ventas.cantidad);

                                                    identificador = identificador + 1;
                                                    ventas.identificador = identificador;

                                                    AgregarVenta(ventas);
                                                    ImprimirVentas();
                                                    ModificarStock(ventas.lote, ventas.cantidad);
                                                    ImprimirBebidas();
                                                    RegistrarVenta(ventas);//crea el archivo//
                                                    regresarmenuven = 1;
                                                    regresar = 0;
                                                }
                                            }
                                        break;
                                        case 2:
                                            ImprimirVentas();
                                            int cantidad;
                                            int lote_producto;
                                            cout << "Ingrese el nombre de la bebida: ";
                                            cin >> ventas.nombre_bebida;

                                            cout << "Ingrese el numero de id de la venta: ";
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
                                            cout << "Opcion no valida";
                                            regresarmenuven = 1;
                                            regresar = 0;
                                        break;
                                    }
                                } while(regresarmenuven == 0);


                            break;
                            case 3:
                            cout << "De verdad desea cerrar sesion? Si = 0, No = 1" << endl;
                            cin >> sesion;
                                if (sesion == 0){
                                    cout << "Ha cerrado sesion" << endl;
                                    cout << endl;
                                    contador = 1;
                                    regresar = 1;
                                } else if (sesion == 1){
                                    cout << "Sesion manetenida" << endl;
                                    cout << endl;
                                    contador = 0;
                                    regresar = 1;
                                }
                                else {
                                    sesion = 0;
                                    cout << "Opcion no valida, cerrando sesion..." << endl;
                                    cout << "Ha cerrado sesion" << endl;
                                    cout << endl;
                                    contador = 1;
                                    regresar = 1;
                                }
                            break;
                            default :
                                cout << "Ingrese una opcion valida" << endl;
                                cout << endl;
                                regresar = 1;
                                contador = 0;
                            break;
                        }
                    } while(regresar == 0);

                break;
                default:
                break;
            }
        } while(contador == 0);
    } while (sesion == 0);
    return 0;
}

//FUNCIONES

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
        cout << bebida.nombre_bebida <<endl << "El numero de lote es: " << bebida.lote << endl << "El tipo de pack es: " << bebida.tipo_bebida << endl << "El precio total de la compra es de: $" << bebida.precio << endl << "La cantidad de packs comprados es de: " << bebida.cantidad << endl << "El precio de venta por pack sera de: $" << bebida.precio_venta << endl;
    }
    cout << "\n\n";
}
void ImprimirVentas()
{
    // for off
    for (Ventas venta : venta)
    {
        cout << endl;
        cout << "El id de la venta es: " << venta.identificador << endl << "El nombre del consumidor es: " << venta.nombre_consumidor << endl << "El precio total de la compra es de: $" << venta.precio_total << endl << "La cantidad de packs comprados es de: " << venta.cantidad << endl << "El numero de lote utilizado fue el: " << venta.lote << endl;
    }
    cout << "\n\n";
}
void ImprimirUsuarios()
{
    cout << "Usuarios existentes: " << endl;
    for (Usuarios imprimir : usuario)
    {
        cout << "\t* " << imprimir.usuario << endl;
    }
}
void ImprimirLotes(string nombre)
{
    // for off
    for (Bebida bebida : packs)
    {
        if(nombre == bebida.nombre_bebida) {
            cout << endl;
            cout << " El numero de lote es: " << bebida.lote << endl << " el tipo de pack es: " << bebida.tipo_bebida << endl << " la cantidad de packs comprados es de: " << bebida.cantidad << endl << " el precio de venta por pack sera de: $" << bebida.precio_venta << endl << " la ganancia por pack sera de: $" << (bebida.precio_venta - (bebida.precio/bebida.cantidad)) << endl;
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
     //variable dentro de la funcion encargada de verificar si existe el usuario y dependiendo del valor retornara 1 si no existe
    for (int i = 0; i < usuario.size(); i++)
    {
        if (nuevoUsuario.usuario == usuario[i].usuario)
        {
            cout << "El usuario ya existe, porfavor elija un nombre de usuario diferente" << endl;
            return;
        }
    }
    usuario.push_back(nuevoUsuario);
    cout << "Usuario añadido existosamente" << endl;
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
    //cout << "No se ha encontrado la bebida" << endl;
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
    //cout << "No se ha encontrado la bebida" << endl;
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
            if(bebida.tipo_bebida == 1){
                contadorpacks6 = contadorpacks6 + bebida.cantidad;
            } else{
                //cout << "No disponibles";
            }
        } 
    }
    //cout << "No se ha encontrado la bebida" << endl;
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
            if(bebida.tipo_bebida == 2){
                contadorpacks12 = contadorpacks12 + bebida.cantidad;
            } else{
                //cout << "No disponibles";
            }
        } 
    }
    //cout << "No se ha encontrado la bebida" << endl;
    return contadorpacks12;
}
int BuscarLote(int identificador) //funcion que se encarga de buscar al lote del producto usado para modficarlo en caso de devolucion
{
    int lote = 0;
    for (Ventas ventas : venta)
    {
        if (identificador == ventas.identificador)
        {
            lote = ventas.lote;
        } 
    }
    //cout << "No se ha encontrado la venta" << endl;
    return lote;
}
int BuscarCantidadVenta(int identificador){
    int cantidad = 0;
    for (Ventas ventas : venta)
    {
        if (identificador == ventas.identificador)
        {
            cantidad = ventas.cantidad;
        } 
    }
    //cout << "No se ha encontrado la venta" << endl;
    return cantidad;
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
            if(bebida.tipo_bebida == 3){
                contadorpacks24 = contadorpacks24 + bebida.cantidad;
            } else{
                //cout << "No disponibles";
            }
        } 
    }
    //cout << "No se ha encontrado la bebida" << endl;
    return contadorpacks24;
}
int BuscarUsuario(string nombreusuario, string contrasenia)
{
    int tipo_usu;
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

            } else {
                cout << "Credenciales no validas" << endl;
                return tipo_usu;
            }
        }
    }
    cout << "No se ha encontrado el usuario" << endl;
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
        if (nombreBebida == packs[i].nombre_bebida && lote == packs[i].lote)
        {
            cout << "Ingrese el nuevo nombre: ";
            cin >> nuevoNombre;
            cout << "Ingrese el nuevo tipo de pack: ";
            cin >> nuevoTipo;
            cout << "Ingrese el nuevo precio total: ";
            cin >> nuevoPrecio;
            cout << "Ingrese la nueva cantidad: ";
            cin >> nuevaCantidad;
            cout << "Ingrese el nuevo precio de venta: ";
            cin >> nuevoPrecioVenta;

            packs[i].nombre_bebida = nuevoNombre;
            packs[i].tipo_bebida = nuevoTipo;
            packs[i].precio = nuevoPrecio;
            packs[i].cantidad = nuevaCantidad;
            packs[i].precio_venta = nuevoPrecioVenta;

            cout << "Bebida modificada exitosamente" << endl;
            return;
        }
    }
    cout << "No se ha encontrado la bebida" << endl;
}
void ModificarUsuario(string nombreUsuario) //Funcion que se encarga de modificar al usuario
{
    string nuevoNombre;
    string contrasenia;
    int tipo;


    for (int i = 0; i < usuario.size(); i++)
    {
        if (nombreUsuario == usuario[i].usuario)
        {
            cout << "Ingrese el nuevo nombre de usuario: ";
            cin >> nuevoNombre;
            cout << "Ingrese la nueva contraseña: ";
            cin >> contrasenia;
            cout << "Ingrese el nuevo tipo de usuario:, 1 = si es administrador o 2 = si es empleado";
            cin >> tipo;


            usuario[i].usuario = nuevoNombre;
            usuario[i].contrasenia = contrasenia;
            usuario[i].tipo_usuario = tipo;

            cout << "Usuario modificado exitosamente" << endl;
            return;
        }
    }
    cout << "No se ha encontrado la bebida" << endl;
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
            //cout << "Bebida eliminada" << endl;
            return;
        }
    }
    cout << "No se ha encotrado la bebida, ingresar bien el nombre o el lote" << endl;
}
void EliminarVenta(string nombreBebida, int identificador)
{
    for (int i = 0; i < venta.size(); i++)
    {
        if (nombreBebida == venta[i].nombre_bebida && identificador == venta[i].identificador)
        {
            venta.erase(venta.begin() + i);
            cout << "Venta eliminada correctamente y stock actualizado" << endl;
            cout << endl;
            return;
        }
    }
    cout << "No se ha encotrado la bebida, ingresar bien el nombre o el lote" << endl;
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

void RegistrarVenta(Ventas venta)
{
    ofstream file;

    file.open("RegistroVentas.txt", ios::app); 

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
        cout << "No se pudo abrir el archivo" << endl;
    }
}

void MostrarRegistro(string archivo){

    ifstream file(archivo);

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout<<line<<endl;
        }
        file.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}
