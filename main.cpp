#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <cstdlib>
#include <cstring>
using namespace std;

// Estructura



struct Persona{
    char clave[10]="";
    char cedula[15]="";
    long saldo = 0;

};
Persona getPersona(string ced);
void mostrar2(Persona p);
void retirar(string ced,long cantidad);
void costo(string ced);


void borrar(string c){
    std::ifstream archivo_lectura("datos.dat", std::ios::binary);
        if (!archivo_lectura) {
            std::cout << "No se pudo abrir el archivo de lectura" << std::endl;
            return;
        }

        std::ofstream archivo_temporal("temporal.dat", std::ios::binary);
        if (!archivo_temporal) {
            std::cout << "No se pudo crear el archivo temporal" << std::endl;
            archivo_lectura.close();
            return;
        }

        // Leer los registros del archivo
        Persona aux;
        bool encontrado = false;
        while (archivo_lectura.read((char*)&aux, sizeof(Persona))) {
            // Comparar el nombre del registro actual con el nombre a borrar
            std::string nombre_actual(aux.cedula, strlen(aux.cedula));
            if (nombre_actual == c) {
                encontrado = true;
                continue;
            }

            // Escribir el registro actual en el archivo temporal
            archivo_temporal.write((char*)&aux, sizeof(Persona));
        }

        archivo_lectura.close();
        archivo_temporal.close();

        if (encontrado) {
            // Reemplazar el archivo original con el archivo temporal
            if (std::remove("datos.dat") != 0) {
                std::cout << "No se pudo borrar el archivo original" << std::endl;
                return;
            }
            if (std::rename("temporal.dat","datos.dat" ) !=0){
                std::cout << "No se pudo renombrar el archivo temporal" << std::endl;
                return;
            }
            std::cout << "Registro borrado exitosamente" << std::endl;
        } else {
            std::cout << "No se encontró el registro con el nombre proporcionado" << std::endl;
            std::remove("temporal.bin");
        }

    }






bool buscar(string b){
    bool d=false;
    ifstream archivo("datos.dat",ios::binary);

        if (archivo.is_open()) {
            string contenido((istreambuf_iterator<char>(archivo)), (istreambuf_iterator<char>()));
                archivo.close();


                size_t posicion = contenido.find(b);

                if (posicion != std::string::npos) {
                    //cout << "Bienvenido."<< endl;
                    d=true;
                } else {
                    //cout << "Usuario o clave incorrecto."<< endl;
                    d=false;
                }
        }else cout <<"Error de lectura"<<endl;
return d;
}




void Usuario(){
    int x = 0;
    string cedula;
    string clave;
    bool pass;
    bool pass2;
    cout<<"Ingrese Cedula: ";
    cin >> cedula;
   cout<<endl<<"Ingrese clave: ";
   cin >> clave;
   pass = buscar(clave);
   pass2 = buscar(cedula);
    if(pass == 1 && pass2 == 1){
        Persona User;
        long cantidad=0;

        cout <<"Bienvenido"<<endl;
        do{
        User = getPersona(cedula);
        cout<<"1. Consultar Saldo"<<endl;
        cout<<"2. Retirar"<<endl;
        cout<<"0. Salir"<<endl;
        cin >> x;
        switch (x) {
        case 1:
           costo(User.cedula);
           cout<<"Se han descontado $1000 por transaccion "<<endl;
           mostrar2(User);


            break;
        case 2:
            costo(User.cedula);
            cout<<"Se han descontado $1000 por transaccion "<<endl;
            cout<<"Cuanto desea retirar? ";
            cin >> cantidad;
            retirar(User.cedula,cantidad);


            break;
        case 0:
            break;
        }
        }while(x !=0);
    }else{cout<<"Usuario o clave incorrecto."<<endl;};




}


int users(){
    int x = 0;
    cout<<"1. Admin"<<endl;
    cout<<"2. Usuario"<<endl;
    cout<<"0. Salir"<<endl;
    cin >> x;
    return x;

}

int sudo(){
    int x = 0;

    cout<<"1. Agregar"<<endl;
    cout<<"2. Listar"<<endl;
    cout<<"3. Buscar"<<endl;
    cout<<"4. Borrar"<<endl;
    cout<<"0. Salir"<<endl;
    cin >> x;
    return x;
}

Persona getPersona(string ced){
    Persona aux;
    ifstream archivo("datos.dat", ios::in | ios::binary);

        if (!archivo.is_open()) {
            cout << "No se pudo abrir el archivo." << endl;

        }

        // Leer los registros del archivo binario

        while (archivo.read((char*)&aux, sizeof(Persona))) {
            // Verificar si el registro actual tiene el nombre buscado
            if (string(aux.cedula) == ced) {
                //mostrar2(aux);
                break; // Si se encontró el nombre, se sale del ciclo
            }
        }



        archivo.close();
        return aux;
}



void Registrar(){
    Persona p;
    ofstream fichero;
    fichero.open("datos.dat",ios::out | ios::binary | ios::app);
    if(fichero.is_open()){
       cin.ignore();
       cout<<"Ingrece cedula: ";
       cin.getline(p.cedula,15);

       cout <<endl <<"Ingrese clave: ";
       cin.getline(p.clave,8);

       cout<<endl<<"Ingrese saldo: ";
       cin >> p.saldo;
    Persona aux = getPersona(p.cedula);
    if(aux.cedula == p.cedula){

         cout << "ya existe "<<endl;
    }
        else{fichero.write((char*)&p,sizeof (Persona));
    cout<<"Registro añadido. "<<endl; }



    }else cout<<"No se pudo abrir"<<endl;
}

void mostrar(Persona p){ //Solo para el administrador
    cout<<"Cedula-------: "<<p.cedula<<endl;
    cout<<"Saldo--------: $"<<p.saldo<<endl;
    cout<<"Clave--------: "<<p.clave<<endl;

}
void mostrar2(Persona p){ //Usuarios
    cout<<"Cedula-------: "<<p.cedula<<endl;
    cout<<"Saldo--------: $"<<p.saldo<<endl;


}
void listar(){
    cout << "LISTA DE USUARIOS"<<endl<<endl;
    Persona aux;
    ifstream leer_fichero;
    leer_fichero.open("datos.dat",ios::binary);
    if(leer_fichero.is_open()){

        while(leer_fichero.read((char*)&aux,sizeof (Persona))){
         mostrar(aux);
         cout<< endl<<"------------------------------------"<<endl<<endl;

        }
        leer_fichero.close();

    }else cout<<"El archivo no existe"<<endl;


}


int main()
{
    string f="";
    int x = 0;

    do{

       x = users();
       switch (x){
       case 1:


           break;

       case 2:
           Usuario();
           break;


       }








    }while(x !=0);





}

void costo(string c) {
    Persona aux;
    ifstream archivo_lectura("datos.dat",ios::binary);
    if (!archivo_lectura) {
        cout << "No se pudo abrir el archivo de lectura" <<endl;

    }

    ofstream archivo_temporal("temporal.dat",ios::binary);
    if (!archivo_temporal) {
        cout << "No se pudo crear el archivo temporal" << endl;

    }

    bool encontrado = false;
    while (archivo_lectura.read((char*)&aux, sizeof(Persona))) {
        // Comparar el nombre del registro actual con el nombre a modificar
        string nombre_actual(aux.cedula, strlen(aux.cedula));
        if (nombre_actual == c) {
            encontrado = true;
            long saldo = aux.saldo;
            long nuevo_saldo = saldo - 1000;
            aux.saldo = nuevo_saldo;
        }

        // Escribir el registro actual en el archivo temporal
        archivo_temporal.write((char*)&aux, sizeof(Persona));
    }
    archivo_lectura.close();
    archivo_temporal.close();

    if (encontrado) {
        // Reemplazar el archivo original con el archivo temporal
        if (std::remove("datos.dat") != 0) {
            std::cout << "No se pudo borrar el archivo original" << std::endl;

        }
        if (std::rename("temporal.dat","datos.dat") != 0) {
            std::cout << "No se pudo renombrar el archivo temporal" << std::endl;

        }
        std::cout << "Registro modificado exitosamente" << std::endl;
    } else {
        std::cout << "No se encontró el registro con el nombre proporcionado" << std::endl;
        std::remove("temporal.dat");
    }
}

void retirar(string ced,long cantidad) {
    std::ifstream archivo_lectura("datos.dat", std::ios::binary);
    if (!archivo_lectura) {
        std::cout << "No se pudo abrir el archivo de lectura" << std::endl;

    }

    std::ofstream archivo_temporal("temporal.dat", std::ios::binary);
    if (!archivo_temporal) {
        std::cout << "No se pudo crear el archivo temporal" << std::endl;
        archivo_lectura.close();

    }

    // Leer los registros del archivo
    Persona aux;
    bool encontrado = false;
    while (archivo_lectura.read((char*)&aux, sizeof(Persona))) {
        // Comparar el nombre del registro actual con el nombre a modificar
        std::string nombre_actual(aux.cedula, strlen(aux.cedula));
        if (nombre_actual == ced) {
            encontrado = true;
            long saldo = aux.saldo;
            long nuevo_saldo = saldo - cantidad;
            aux.saldo = nuevo_saldo;
        }

        // Escribir el registro actual en el archivo temporal
        archivo_temporal.write((char*)&aux, sizeof(Persona));
    }

    archivo_lectura.close();
    archivo_temporal.close();

    if (encontrado) {
        // Reemplazar el archivo original con el archivo temporal
        if (std::remove("datos.dat") != 0) {
            std::cout << "No se pudo borrar el archivo original" << std::endl;
            return;
        }
        if (std::rename("temporal.dat","datos.dat") != 0) {
            std::cout << "No se pudo renombrar el archivo temporal" << std::endl;
            return;
        }
        std::cout << "Registro modificado exitosamente" << std::endl;
    } else {
        std::cout << "No se encontró el registro con el nombre proporcionado" << std::endl;
        std::remove("temporal.dat");
    }
}
