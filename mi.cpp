#include <iostream>
using namespace std;



int main(){
    int n;
    cout<<"ingresa cantidad de monedas: ";
    cin>>n;
    int* monedas = new int[n];
    for(int i=0; i<n; i++){
        cout<<"ingruese el valor de la moneda "<<i+1<<": ";
        cin>>monedas[i];
    }
    for(int i=0; i<n; i++){
        cout<<monedas[i]<<" ";
    }
    cout<<"cantidad : ";
    int cantidad;
    cin>>cantidad;


}