#include <iostream>
#include <fstream>
#include <sstream>

#include<math.h>
using namespace std;
ifstream archivo_lectura;
ofstream archivo_escritura;
int unosant;
int cerosant;
bool first=1;
int seed=0;

//Funciones
string codificador1(string a); // Utilizada en el metodo 1
string binario(string cadena); //Retorna un string con toda la representacion binaria
void metodo_codificacion1();  //Primer metodo










int main()
{
    cout<<"  ?  ?  ?  ? ENIGMA.txt  ?  ?  ?  ? }"<<endl;
    string nombre, texto;
    int i=0;
    int opcion=0;

    cout<<"Ingrese el nombre del archivo que desea abrir:  ";cin>>nombre;
    archivo_lectura.open(nombre+".txt",ios::in);
    if(archivo_lectura.is_open()){

        cout<<" ->El archivo '"<<nombre<<".txt' ha sido cargado correctamente."<<endl<<endl; //Muestra el archivo cargado
        while (!(archivo_lectura.eof())) {
                  getline(archivo_lectura,texto);


            i++;
        }


        //Contenido del archivo abierto:
        cout<<"Contenido: ";
//        for(int j=0;j<i;j++){
//            cout<<texto[j];
//        }
        cout<<texto;
        cout <<endl;
        archivo_lectura.close();
        archivo_escritura.open("archivo_binario.bin",ios::out | ios::binary);

            string bin = binario(texto);
            archivo_escritura << bin;


        archivo_escritura.close();
      // Selector

        do{cout<<"    OPCIONES               "<<endl<<"1. Metodo de codificacion 1"<<endl<<"2. Metodo de codificacion 2"<<endl
             <<"0. Para finalizar."<<endl<<endl;
            cout<<"Ingrese la opcion deseada: ";cin>>opcion;
            switch (opcion) {
            case 0:
                break;
            case 1:
                system("clear");
                cout<<"->Codificacion 1 seleccionada."<<endl;
                metodo_codificacion1();
                break;
            case 2:
                system("clear");
                cout<<"->Codificacion 2 seleccionada."<<endl;
              //  metodo_codificacion2();
                break;

            default:
                cout<<"Ingrese una opcion valida."<<endl;
                break;
            }

        }while(opcion);

    }
    else{
        cout<<" ->Lo siento, hubo un error al cargar archivo '"<<nombre<<"'"<<endl;
    }



}




// Funciones


string binario(string cadena){   //Me retorna un string con la representacion binaria de un caracter

    string bits;
    for(unsigned j = 0; j < cadena.length();j++){
        for (int i = 7; i >= 0; i--) {
            char b = cadena[j];
               int bit = ((b >> i) & 1); // Obtener el bit correspondiente //Operador de shift
               cout << bit; // Imprimir el bit
               if(bit==0){  // Cadena de caracteres con el paquete binario
                   bits =  bits + '0' ;
               }
               else bits = bits + '1' ;
        }
        //cout << endl;
    }
cout <<"Representacion en binario: "<<cadena<<endl;
    cout<<endl;
    return bits;
}


void metodo_codificacion1(){
    string cadena,bincode,nombre;
    int tam;

    cout<<"Ingrese un nombre para el archivo codificado: ";cin>>nombre;
    cout<<"Ingrese el valor de la semilla: ";cin>> seed;
    archivo_lectura.open("archivo_binario.bin",ios::binary);

    if(archivo_lectura.is_open()){   //Abre el archivo en binario y lo guarda en cadena
        while (!(archivo_lectura.eof())) {
            archivo_lectura>>cadena;
        }
        tam =cadena.length();
        archivo_escritura.open(nombre+".txt",ios::out);

        for(int i=0; i<tam;i+=seed){

          string  bloque = cadena.substr(i,seed);

           bincode = bincode + codificador1(bloque);

        }
        archivo_escritura << bincode;
        cout<<" ->El archivo '"<<nombre<<".txt' ha sido codificado correctamente."<<endl<<endl;
        archivo_escritura.close();
        archivo_lectura.close();

    }

}

string codificador1(string a){ //Recibe un string y retorna un string
    int unos=0;
    int ceros=0;


    for(unsigned i=0;i<a.length();i++){ //Cuenta unos y ceros
        if(a[i]=='0')ceros++;
        else unos++;
    }



    if((unosant==cerosant) && first !=1){ //Invierte todos los bits
        for(unsigned i=0;i<a.length();i++){
            if(a[i]=='0') a[i]='1';
            else a[i]='0';
        }
    }
    else if((unosant < cerosant) && first !=1){ // Mayor cantidad de ceros
        for(unsigned i=0;i<a.length();i++){
            if(a[i+1]=='0') a[i+1]='1';
            else a[i+1]='0';
            i = i+1;
        }
    }
    else if((unosant > cerosant) && first !=1){ // Mayor cantidad de unos
        for(unsigned i=2;i<a.length();i++){
            if(a[i]=='0') a[i]='1';
            else a[i]='0';
            i=i + 2;
        }
    }
    if(first == 1){
        for(unsigned i=0;i<a.length();i++){
            if(a[i]=='0') a[i]='1';
            else a[i]='0';
        }
        first = 0;

    }
    unosant=unos;
    cerosant=ceros;
    return a;
    a="";
}








