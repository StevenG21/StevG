#include <iostream>

using namespace std;

int main()
{
   int numero = 0, numero_primo = 0, contador = 0, base = 2;

    cout << "Ingrese un numero: ";
    cin >> numero;
    cout << endl;

    while (contador < numero){

        for(int i = 2; i<= base; i++){

            if (i != base && base%i == 0){

                break;

            }else if(i==base){

                numero_primo = base;
                contador++;

            }

        }

        base++;

    }

    cout << "El primo numero " << numero << " es: " << numero_primo << endl;

    return 0;
}

