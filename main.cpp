#include <iostream>
#include<fstream>
#include<math.h>
using namespace std;

///Variables globales

fstream archivo_escritura,archivo_lectura;
int unosant=0;
int cerosant=0;
bool first=1;
int seed=0;
string texto="";



///Prototipos de funciones
void decodificacion_1();



char valor_ascii(string a);
void convertir_a_caracter();
string implementacion_decodificacion2(string a, string b);



///Cuerpo de la funcion
int main()
{
    cout<<"                     BIENVENIDO AL DECODIFICADOR.\n"<<endl;
    string nombre;

    int opcion=0;

    cout<<"Ingrese el nombre del archivo que desea abrir:  ";cin>>nombre;
    archivo_lectura.open(nombre+".txt",ios::in);
    if(archivo_lectura.is_open()){

        cout<<" ->El archivo '"<<nombre<<".txt' ha sido cargado correctamente."<<endl<<endl; //Muestra el archivo cargado
        while (!(archivo_lectura.eof())) {
                  getline(archivo_lectura,texto);



        }


        //Contenido del archivo abierto:
        cout<<"Contenido: ";
        cout<<texto;
        cout <<endl;

        archivo_lectura.close();

       }else{
        cout<<" ->Lo siento, el archivo '"<<nombre<<".txt' no se pudo abrir."<<endl;
    }
    // Selector

      do{cout<<"    OPCIONES               "<<endl<<"1. Decodificacion 1"<<endl<<"2. Decodificacion 2"<<endl
           <<"0. Para finalizar."<<endl<<endl;
          cout<<"Ingrese la opcion deseada: ";cin>>opcion;
          switch (opcion) {
          case 0:
              break;
          case 1:
              system("clear");
              cout<<"->Decodificacion 1 seleccionada."<<endl;
              decodificacion_1();
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

///Cuerpo de las funciones


void contador(string a){
    unosant=0;
    cerosant=0;
    for(unsigned i=0;i<a.length();i++){ //Cuenta unos y ceros
        if(a[i]=='0')cerosant++;
        else unosant++;
    }

}


string codificador1(string a){ //Recibe un string y retorna un string






    if((unosant==cerosant) && first !=1){ //Invierte todos los bits
        for(unsigned i=0;i<a.length();i++){
            if(a[i]=='0') a[i]='1';
            else a[i]='0';
        }
    }
    else if((unosant < cerosant) && first !=1){ // invierte cada dos bits
        for(unsigned i=1;i<a.length();i+=2){
            if(a[i]=='1') a[i]='0';
            else a[i]='1';

        }
    }
    else if((unosant > cerosant) && first !=1){
        for(unsigned i=2;i<a.length();i+=2){
            if(a[i]=='1') a[i]='0';
            else a[i]='1';

        }
    }
    if(first == 1){
        for(unsigned i=0;i<a.length();i++){
            if(a[i]=='0') a[i]='1';
            else a[i]='0';
        }
        first = 0;

    }
    contador(a);
    return a;
    a="";
}

char valor_ascii (string a){ //Recibe binario y devuelve un caracter

    for (unsigned k=0;k<a.length();k+=8){
        char ascii=0;
        string aux = a.substr(k,8);
        for (int i=0,j=7; i<8; i++, j--){
            ascii+=(((int)aux[i])-48)*(pow(2,j));
    }
        archivo_escritura <<  ascii;
    }
    return false;
}



void decodificacion_1(){
    string bincode,nombre;
    int tam;

    cout<<"Ingrese un nombre para el archivo codificado: ";cin>>nombre;
    cout<<"Ingrese el valor de la semilla: ";cin>> seed;



        tam =texto.length();
        archivo_escritura.open(nombre+".txt",ios::out);

        for(int i=0; i<tam;i+=seed){

          string  bloque = texto.substr(i,seed);

           bincode = bincode + codificador1(bloque);

        }
        valor_ascii(bincode);
        //archivo_escritura << bincode;
        cout<<" ->El archivo '"<<nombre<<".txt' ha sido decodificado correctamente."<<endl<<endl;
        archivo_escritura.close();
        archivo_lectura.close();



}







string implementacion_decodificacion2(string a, string b){
    int tam=a.length();
    for (int i=0,j=0; i<tam; i++){
        if(i==0){
            b[tam-1]=a[i];
        }
        else{
            b[j]=a[i];
            j++;
        }

    }
    return b;
}
