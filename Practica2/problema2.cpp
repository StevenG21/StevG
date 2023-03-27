#include <iostream>

using namespace std;



int main()

{
    int sum=0;
    char* ABC = new char[26]; //Letras del alfabeto sin Ñ
    for(int i=0;i<=26;i++){
        ABC[i] = 65+i;
    }
   
    int n = 200; //Tamaño del arreglo
    
    char* a = new char[n];
    for (int i=0;i<n;i++){
        a[i] = rand() % 26 + 65;
        
      
    }
    for(int i=0; i<n; i++) {
      cout << a[i];
   }
   cout <<endl;
   for(int i=0; i<26; i++){
       for(int j=0;j<n;j++){
           if(ABC[i]==a[j]){
               sum+=1;
           }
           
       }
       
       cout<<ABC[i]<<": "<<sum<<endl;
       sum=0;
   }

   delete[] a; // Liberar la memoria asignada al arreglo
   delete[] ABC; 
    
   
}