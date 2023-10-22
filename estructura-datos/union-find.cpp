#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

int v[10000]; //valores origianles
int parent[10000];
int cont[10000]; //cuantos elementos hay en el grupo
int rango[10000]; //rango del arbol

int n;
void init() { 
    for(int i=0;  i<= n; i++) {
        parent[i] = i; // al iniciar solo se conocen a si mismos
        rango[i] = 0; //como se conocen solo a sí mimsos tienen rango 0
        cont[i] = 1; //solo hay un elemento que osn ellos mismos
    }
}

int find(int x) {
    if(x == parent[x]) { //legar al padre padre si x es x
        return x;
    }
    else {
        parent[x] = find(parent[x]); //no es el padre, 
                        //por lo que hay que ir subiendo y 
                        //ahora preguntamos por el padre del 
                        //padre que teniamos inicialmente
        
        return parent[x];
    }
}

void unionRango(int x,int y) {  
    int xRaiz = find(x); //hay que ir al padre padre
    int yRaiz = find(y);
    if(rango[xRaiz] > rango[yRaiz]) {
        parent[yRaiz] = xRaiz;
        cont[yRaiz] += cont[xRaiz];
//no aumenta el rango porque va al mayor
    } else { //union por la derecha
        parent[xRaiz] = yRaiz; 
        cont[xRaiz] += cont[yRaiz];
        if(rango[xRaiz] == rango[yRaiz]) { //si son del mismo rango aumenta
            rango[yRaiz]++;
        }
    }
}

int main() {
    input;
    cin>>n;
    init();
    int nrounionRangoes; 
    cin>>nrounionRangoes;
    while(nrounionRangoes--) {
        int x,y;
        cin>>x>>y; 
        unionRango(x,y);
    }
    for(int i=0;i<=n;i++){ 
        cout<<"["<<i<<"] ";
    }
    cout<<endl;
    for(int i=0;i<=n;i++){ 
        cout<<"[" <<parent[i]<<"] ";
    }
    cout<<endl;
    for(int i=0;i<=n;i++){ 
        cout<<"[" <<rango[i]<<"] ";
    }
    cout<<endl;
    int sol = -1;
    for(int i=0;i<=n;i++){
        if(i == parent[i]) {
            sol = max(sol,cont[i]);
        }
    }
    cout<<sol<<endl;

    return 0;
}