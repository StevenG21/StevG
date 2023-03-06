#include <iostream>

using namespace std;

int main(){

    int Dinero = 0, Billete = 0;
    
    cout << "Ingrese el dinero a retirar: ";
    cin >> Dinero;
    cout << endl;
    
    
    
    if(Dinero>=50000){
        
        Billete = Dinero/50000;
        Dinero -= (50000*Billete);
        
        cout << "Billete de $50,000: " << Billete << endl;
        
    }if(Dinero<50000 && Dinero>=20000){
        
        Billete = Dinero/20000;
        Dinero -= (20000*Billete);
        
        cout << "Billete de $20,000: " << Billete << endl;
        
    }if(Dinero<20000 && Dinero>=10000){
        
        Billete = Dinero/10000;
        Dinero -= (10000*Billete);
        
        cout << "Billete de $10,000: " << Billete << endl;
        
    }if(Dinero<10000 && Dinero>=5000){
        
        Billete = Dinero/5000;
        Dinero -= (5000*Billete);
        
        cout << "Billete de $5,000: " << Billete << endl;
        
    }if(Dinero<5000 && Dinero>=2000){
        
        Billete = Dinero/2000;
        Dinero -= (2000*Billete);
        
        cout << "Billete de $2,000: " << Billete << endl;
        
    }if(Dinero<2000 && Dinero>=1000){
        
        Billete = Dinero/1000;
        Dinero -= (1000*Billete);
        
        cout << "Billete de $1,000: " << Billete << endl;
        
    }if(Dinero<1000 && Dinero>=500){
        
        Billete = Dinero/500;
        Dinero -= (500*Billete);
        
        cout << "Moneda de $500: " << Billete << endl;
        
    }if(Dinero<500 && Dinero>=200){
        
        Billete = Dinero/200;
        Dinero -= (200*Billete);
        
        cout << "Moneda de $200: " << Billete << endl;
        
    }if(Dinero<200 && Dinero>=100){
        
        Billete = Dinero/100;
        Dinero -= (100*Billete);
        
        cout << "Moneda de $100: " << Billete << endl;
        
    }if(Dinero<100 && Dinero>=50){
        
        Billete = Dinero/50;
        Dinero -= (50*Billete);
        
        cout << "Moneda de $50: " << Billete << endl;
        
    }else{
        
        cout << "Numero no valido." << endl; 
        
    }
    
    cout << "Dinero faltante: $" << Dinero;
    
    return 0;
}
