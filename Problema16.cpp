#include <iostream>

using namespace std;

int main()
{


    int numerok=0 , contador=1 , numeroI=0;

    cout << "Ingrese un numero: ";cin >> numerok;
    cout << endl;
    numeroI=numerok;

   cout<<"Para la semilla "<<numerok<<": "<<numerok<<", ";
   do {                                                 //Instrucciones que se leeran antes del ciclo while


        if (numerok%2==0){                              //Condicional que se ejecuta si numerok es par
            numerok= numerok/2;                         //La variable numerok se divide entre 2

            if (numerok==1){                            //Condicional que se ejecuta si numerok es igual a 1
                cout << numerok;
                contador++;                             //La variable contador se incrementa en 1, cuenta los elementos de la secuencia
                break;}                                 //Termina el programa

            cout << numerok << ", ";
            contador++;                                 //La variable contador se incrementa en 1, cuenta los elementos de la secuencia
        }

        else {                                          //Condicional que se ejecuta si numerok es impar
            numerok= (3*numerok)+1;                     //La variable numerok se le multiplica por 3 y se le suma 1
            cout << numerok << ", ";
            contador++;                                 //La variable contador se incrementa en 1, cuenta los elementos de la secuencia
        }
    }

    while (numerok!=1);                                 //Ciclo que se ejecutara mientras numerok sea diferente de 1
    cout << endl << endl;
    cout << "Esta es la serie mas larga con la semilla: "<< numeroI << ", teniendo "<< contador <<" terminos." << endl << endl;
    return 0;
}
