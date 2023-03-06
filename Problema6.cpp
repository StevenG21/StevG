

#include <iostream>

using namespace std;




int factorial(int numero){
    int numerofactorial = numero;
    if (numerofactorial > 1){
        numerofactorial *= factorial(numero-1);
        return numerofactorial;
    }
    else {return 1;}
}



int main()
{
    int numero = 0;
    float euler = 0, cociente = 0;

    cout << "Ingrese un numero: ";
    cin >> numero;
    cout << endl;

    for (int i = 0; i < numero; i++){

        cociente = factorial(i);
        euler += 1/cociente;

    }

    cout << "El valor aproximado de euler es: " << euler << endl;

    return 0;

}




