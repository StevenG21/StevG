
#include <iostream>

using namespace std;
int deco(int n,bool select){  //0 Horas 1 Minutos
    int d;
    
    if(select==0) {d=n/100; return d;}
    
    else{d=n%100; return d;}
    
}


int main()
{
    int datos[2];
    int horas;
    int minutos;
    bool select;
    cout<<"Ingrese una hora en formato hhmm: ";
    cin>>datos[0];
    while(deco(datos[0],select=0)>24){
        cout<<"Hora invalida."<<endl;
        cout<<"Ingrese una hora en formato hhmm: ";
        cin>>datos[0];
    }
    while(deco(datos[0],select=1)>=60){
        cout<<"Minuto invalido."<<endl;
        cout<<"Ingrese una hora en formato hhmm: ";
        cin>>datos[0];
    }    
    
    
    cout<<"Ingrese un tiempo a sumar en formato hhmm: ";
    cin>>datos[1];
    while(deco(datos[1],select=0)>24){
        cout<<"Hora invalida."<<endl;
        cout<<"Ingrese una hora en formato hhmm: ";
        cin>>datos[1];
    }
    while(deco(datos[1],select=1)>=60){
        cout<<"Minuto invalida."<<endl;
        cout<<"Ingrese una hora en formato hhmm: ";
        cin>>datos[1];
    }    

    
    for(int i=0;i<=1;i++){
        horas += deco(datos[i],select=0);
        minutos += deco(datos[i],select=1);
    }
    if(minutos>=60){
        minutos -=60;
        horas +=1;
   }
    
    cout<<"La suma es: ";
    cout.width(2);
    cout.fill('0');
    cout <<horas<<":";
    cout.width(2);
    cout.fill('0');
    cout <<minutos<<endl;
  
    
  

    return 0;
}