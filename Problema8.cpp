#include <iostream>

using namespace std;

int main()
{
    int a = 0, b = 0, c = 0, suma = 0;


    cout << "Ingrese el numero a: ";
    cin >> a;
    cout << endl;

    cout << "Ingrese el numero b: ";
    cin >> b;
    cout << endl;

    cout << "Ingrese el numero c: ";
    cin >> c;
    cout << endl;

    for (int i = 1; i < c; i++){

        if ((i%a == 0) || (i%b == 0)){

            cout << i;
            if(i<(c-1)){

                cout << " + ";

            }else{

                cout << " = ";

            }

            suma += i;

        }
    }

    cout << suma << endl;

    return 0;

}




