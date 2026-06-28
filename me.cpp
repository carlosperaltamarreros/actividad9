 #include <iostream>
using namespace std;

void escaleras(int n){
    if (n < 0) return; 
    //programacion dinamica en heap
    int* dp = new int[n+1];
    // inicialización de la tabla dp
    dp[0] = 1; 
    if (n >= 1) {//si hay al menos un escalón entonces inicializamos el primer escalón
        dp[1] = 1; // 1 escalon 
    }
    for(int i = 2; i <= n; i++){// Calcula el numero de formas posibles para cada escalón
        dp[i] = dp[i-1] + dp[i-2]; // 1primer escalon + 2do escalon
    }
//imprimir
    cout << "formas posibles: " << dp[n] << endl;
    cout << "tabla dp: [";
    for(int i = 0; i <= n; i++){ // 
        cout << dp[i];
        if(i < n) cout << ", ";
    }
    cout << "]" << endl;

    //delete 
    delete[] dp;
}

int main(){
    int n;
    cout << "numero de escalones: ";
    cin >> n;
    escaleras(n);
 
    return 0;
}
