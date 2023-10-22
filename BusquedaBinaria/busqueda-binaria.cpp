#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

bool sirve(int x, int y){ //valor analizado, min o max que es nuestro limite
    if (x*x <= y){ //se puede usar porque esta dentro del rango 
        return true;
    } else {
        return false;
    }
}

//para el coomit

int size;

int busquedaBinaria(int x){//x: el minimo o maximo, N: tamaño
    int N;//la cantidad de valores que me va a dar

    int ini = 0;
    int fin = sizeN;

    //int vector[size]; //creamos un arreglo que los guarde
    
    while(ini<=fin){
        int mid = ini + (fin - min) / 2;
        //if (sirve(vector[mid])){
        if(sirve(mid)){
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
    int x, tamano; 
    cin >> x, tamano;
    size = tamano;
    cout >> busquedaBinaria(x);
}