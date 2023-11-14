#include <iostream>
#include <fstream>

using namespace std;  

void Write_RegistroVentas();
void Read_RegistroVentas(); 

    struct Bebida{
        string nombre_bebida; 
        float precio;
    }; 

    struct Inicio_Sesion{
    string Usuario;
    string Email; 
    int Pin; 
    }Empleado;

int main(){

//cositas detallitos bonitos
    string nombre; 
    int segunda_opcion; 
    Bebida packs[4]; 
    int opcion;  
    
        packs[0].nombre_bebida ="Agua"; 
        packs[0].precio = 6.35; 
        packs[1].nombre_bebida = "Coca Cola"; 
        packs[1].precio = 12.45;
        packs[2].nombre_bebida ="Pepsi"; 
        packs[2].precio = 11.40; 
        packs[3].nombre_bebida = "Frutado"; 
        packs[3].precio = 4.95; 

    //esto creo que no iria aqui xd
    Write_RegistroVentas();
    Read_RegistroVentas(); 

    cout <<endl; 
    cout << "             ------PEPITO'S------"<<endl; 
    cout <<"   ------- DISTRIBUIDORA DE BEBIDAS -------"<<endl; 
    cout <<endl; 
    cout <<"En vez de una, llevate varias"<<endl; 
    cout <<endl; 

//opcion de admi o usuario
    do{
    cout <<"Seleccione la opcion:\n\n1. Opc. Administrador\n2. Opc. Cliente\n3. Salir\n"<<endl; 
    cin >> opcion;

    switch (opcion)
    {
        case 1: 
        cout <<"----- OPCION ADMINISTRADOR ----- "<<endl; 
        cout << endl; 

        cout <<"Ingrese su Usuario: "; 
        cin >>Empleado.Usuario; 
        cout <<"Ingrese su Email: "; 
        cin >>Empleado.Email;  
        cout <<"Ingrese el Pin: "; 
        cin >>Empleado.Pin;  
        cin.ignore();
        cout <<endl;

        if(Empleado.Pin = 123){
            cout <<"Inicio de Sesion correctamente"<<endl; 
            cout <<endl; 
            cout <<"\n1. Buscar informacion\n 2. Modificar inventario\n 3. Eliminar informacion existente"<<endl; 
            cin >>segunda_opcion; 
            switch (segunda_opcion)
            {
                case 1: 
                cout <<"aqui se hace algo para buscar info xd"; 
                break; 
                case 2: 
                for(Bebida bebida : packs){
                cout <<"--"<< bebida.nombre_bebida <<" $"<<bebida.precio<<endl;
                }
                cout <<endl;
                break; 
                case 3: 
                cout <<"aqui se hace algo para eliminar datos"; 
                break; 

            default:
                cout <<"Error al elegir la opcion"<<endl; 
                break;
            } 

        }else{
            cout <<"Pin incorrecto"<<endl;
            cout <<endl;  
        }

        break; 

        case 2: 
        cout << "----- OPCIONES DE COMPRA -----"<<endl; 
        cout <<"Informacion necesaria para la compra"<<endl; 
        cout <<endl; 
        
        cout <<"Ingrese su nombre: "; 
        cin >> nombre; //falta getline
        cout <<endl; 

        cout << "Bebidas disponibles: "<<endl; 
        for(Bebida bebida : packs){
            cout <<"--"<< bebida.nombre_bebida <<" $"<<bebida.precio<<endl; 
        }
        cout <<endl; 
        break; 

        case 3:
        cout <<"Saliendo"<<endl; 
        break; 

    default:
        cout <<"Error al ingresar la opcion"<<endl; 
        break;
    }

    } while (opcion != 3); 

    system("pause"); 
    return 0; 
}

//coso de archivos txt

void Write_RegistroVentas(){
    string fileName = "Bebida_Preferida.txt"; 
    ofstream file; 

    file.open(fileName, fstream::app); 

    if(file.is_open()){
        file << "La bebida preferida del mes es: "<<endl; 
    }else{
        cout <<"Error al abrir el archivo"<<endl; 
        file.close(); 
    }
}

void Read_RegistroVentas(){
    string line;
    string fileName ="Bebida_Preferida.txt"; 
    ifstream file; 

    file.open(fileName); 
    if(file.is_open()){
        while(getline(file, line)){
            cout <<line<<endl; 
        }
    }else{
        cout << "Error al abrir el archivo"<<endl; 
        file.close(); 
    }
}

