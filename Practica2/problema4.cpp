#include <iostream>

using namespace std;
int convert(char* c){
    int num = 0;
    
    while(*c != 0){ //Mientras que no sea el caracter nulo
        num = num*10 + (*c - 48);  // Cero: 48 en ascii
        c++;
    }
    return num;
}


int main()
{
    int n;
    char* cadena = new char;
    cout<<"Ingrese una cadena de numeros: ";
    cin.getline(cadena,100);
n= convert(cadena);
cout << n;
    return 0;
}

