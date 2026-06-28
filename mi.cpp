/*
Cambio mínimo de monedas 
Una máquina expendedora debe entregar una cantidad exacta de dinero utilizando la menor cantidad posible de monedas. Se dispone de un conjunto de denominaciones y una cantidad objetivo.
El objetivo es determinar el número mínimo de monedas necesarias para formar dicha cantidad.
Requisitos específicos
El programa debe:
Recibir un arreglo de monedas.
Recibir una cantidad objetivo.
Implementar Programación Dinámica.
Mostrar:
Cantidad mínima de monedas.
Tabla DP generada.
Una combinación válida de monedas utilizada.

Ejemplos guía

Ejemplo 1:
Monedas: [1,3,4]
Cantidad: 6 
Posible salida
Cantidad mínima de monedas: 2
Combinación: 3 + 3
Tabla DP: 
[0,1,2,1,1,2,2] 

*/

#include <iostream>
using namespace std;
void canminmonedas(int* monedas, int n, int cantidad){
    int* dp = new int[cantidad + 1];
    dp[0] = 0;
    for(int i=1; i<=cantidad; i++){
        dp[i] = INT_MAX; // Inicializar con un valor grande
        for(int j=0; j<n; j++){
            if(monedas[j] <= i){
                int sub_res = dp[i - monedas[j]];
                if(sub_res != INT_MAX && sub_res + 1 < dp[i]){
                    dp[i] = sub_res + 1;
                }
            }
        }
    }
    
    if(dp[cantidad] == INT_MAX){
        cout << "No es posible formar la cantidad con las monedas dadas." << endl;
    } else {
        cout << "Cantidad mínima de monedas: " << dp[cantidad] << endl;
        cout << "Tabla DP: [";
        for(int i=0; i<=cantidad; i++){
            cout << dp[i];
            if(i < cantidad) cout << ",";
        }
        cout << "]" << endl;

        // Mostrar combinación de monedas utilizada
        cout << "Combinación: ";
        int temp_cantidad = cantidad;
        while(temp_cantidad > 0){
            for(int j=0; j<n; j++){
                if(monedas[j] <= temp_cantidad && dp[temp_cantidad - monedas[j]] == dp[temp_cantidad] - 1){
                    cout << monedas[j] << " ";
                    temp_cantidad -= monedas[j];
                    break;
                }
            }
        }
        cout << endl;
    }

    delete[] dp;
}




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
    
    canminmonedas(monedas, n, cantidad);
    delete[] monedas;

}