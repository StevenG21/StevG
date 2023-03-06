#include <iostream>

using namespace std;

int main()
{
   int num = 0, mf_prim = 1;
    bool es_primo = false;

    cout<<"Ingresa un numero: ";
    cin >> num;


    for (int i = 2; i<=num; i++){

        if (num%i == 0){

            for (int j=2; j<=i; j++){

                if (i%j == 0){

                    if (i == j){

                        es_primo = true;

                    }
                    else{

                        es_primo = false;

                    break;
                    }
                }
                else{

                    es_primo = false;

                }

            }

        }

        else {

            es_primo = false;

        }

        if (es_primo == true){

            mf_prim = i;

        }

    }

    cout<< "El mayor factor primo de "<<num<<" es: "<<mf_prim<<endl;

    return 0;

}

