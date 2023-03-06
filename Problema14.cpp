#include <iostream>

using namespace std;
int num_inv(int num){

    int inv = 0;

    while(num > 0){

        inv = (inv * 10 + (num % 10));
        num = (num / 10);

    }

    return inv;

}

int main()
{
    int num = 0,copia_num = 0,copia_mul_1 = 0,copia_mul_2 = 0, evalua = 0;

        cout << "Ingrese un numero de tres digitos: ";
        cin >> evalua;

        for (int mul_1 = 1; mul_1 <= evalua; mul_1++){

            for (int mul_2 = 1; mul_2 <= evalua; mul_2++){

                num = (mul_1 * mul_2);

                if (num == num_inv(num)){

                    if (num > copia_num){

                        copia_num = num;
                        copia_mul_1 = mul_1;
                        copia_mul_2 = mul_2;

                    }
                }
            }
        }

        cout << copia_mul_1 << "*" << copia_mul_2 << " = " << copia_num << endl;

        return 0;
  
}
