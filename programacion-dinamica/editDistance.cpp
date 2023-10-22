#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

int main()
{

    string wordA,wordB;

    int n = wordA.length();//filas
    int m = wordB.length();//columnas

    int dp[n+1][m+1]; //matriz que guarda

    for (int i = n ; i>=0 ; i--){
        dp[n-i][m] = i;
    }

    for (int i = m ; i>=0 ; i--){
        dp[n][m-i] = i;
    }

    for(int i = n-1 ; i>=0 ; i--){ //i es el valor de la fila
    //de la palabra original
        for(int j = m-1 ; j>=0 ; j--){ //j es el valor de la 
        //columna de la palabra objetivo
            if(wordA[i]==wordB[j]){
                dp[i][j]=dp[i+1][j+1];
            } else {
                dp[i][j]= min(dp[i+1][j+1], min(dp[i+1][j], dp[i][j+1])) + 1;
                //falta que funcione
            }
        }
    }

    wordA = "AEO";
    wordB = "AC";
    


    return dp[0][0];
}