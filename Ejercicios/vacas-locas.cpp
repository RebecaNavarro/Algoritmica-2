#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

int n;
int establos[100000];

bool sirve(int vac, int est, int mid) {
    int ultimoE = establos[0];
    for(int i = 1 ; i < n ; i++){
        if(establos[i] - ultimoE >= mid){
            ultimoE = establos[i];
            int vaca++;
            if (vac == vaca){
                
            }
        } else {
            return false;
        }
    }
}


int busquedaBinaria(int v, int e) {
    int ini = 0;
    int fin = e;

    //int vector[size]; //creamos un arreglo que los guarde
    
    while(ini <= fin){
        int mid = ini + (fin - min) / 2;
        if(sirve(v, e, mid)){
            ini = mid + 1;        
        } else {
            fin = mid - 1;
        }
    }

    if (vector[fin] <= x){
        return fin;
    } else if (vector[ini] <= x){
        return ini;
    } else {
        return "-1";
    }

}

int main(){
    int casos, stalls, vacas; 
    cin >> casos;
    cin >> stalls, vacas;
    n = stalls + 1;
    for (int i = 0 ; i < stalls ; i++){
        cin >> establos.add[i];
    }
    sort(establos, establos + n);
    for (int j = 0 ; j < casos ; j++){
        cout << busquedaBinaria(vacas, stalls);
    }
}