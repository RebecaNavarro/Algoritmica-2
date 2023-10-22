#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std; 

bool es_valido(int tablero[][],int fila,int columna) {
    // Comprobamos que no exista reinas en la misma fila 
    for(int col = 0; col < 4; col++) {
        if(tablero[fila][col] == 1){
            return false;
        }
    }
    // comprobamos diagonales izq superior
    int row = fila, col = columna;
    while(row> 0 && col > 0) {
        if(tablero[row][col] == 1){
            return false;
        }
        row--;
        col--;
    }
    // comprobamos diagonal izq inferior
    row = fila, col = columna;
    while(row < 4 && col > 0) { 
        //si no encontre la reina en la matriz
        if(tablero[row][col] == 1){
            return false;
        }
        row++;
        col--;
    }
    return true;
}

//backtracking necesita la columna y fila
void solve_queen(int columna, int tablero[][]){   // f(pos, tablero)
//matriz vacía
    if( columna >= 4 ) { // ya puso todas las reinas  // CASO BASE
        print_solucion(tablero);
    }//la solucion

    for (int row = 0; row < 4; row++) { //tablero vacío
    // avanzamos columna por columna, 
    // por eso no es necesario preguntar las filas
        if(es_valido(tablero,row,columna)){  // PODA
            tablero[row][columna] = 1; //coloca la reina si es valido
            solve_queen(columna+1,tablero);
            tablero[row][columna] = 0; //si ya teniamos una reina pero 
                                    //que al final no nos funcino
        }
    }
}

//sin matriz: ponemos la
// posicion en la que esta en un array de las columnas

void print_solucion(int tablero[][]){
    for(int fila = 0; fila < 4; fila++){
        for(int col = 0; col < 4; col++){
            printf("[%d]",tablero[fila][col]);
        }
        printf("\n");
    }
}
int main(){

}