#include <iostream>
#include <vector>

using namespace std;

vector<int> bits; // numero binario
vector<int> parent;
vector<int> cont; // Cuántos elementos hay en el grupo
vector<int> rango; // Rango del árbol

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

//input
int main(){
    //para el tiempo
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;//casos
    cin>>T;

    for(int caso = 1; caso <= T; caso++){//para mostrar los casos

        string numBinario; //num como cadena
        cin>>numBinario;

        n = numBinario.length(); //tamaño del numBinario

        //damos tamaños a los vectores
        bits.resize(500001);
        parent.resize(500001);
        cont.resize(500001);
        rango.resize(500001);

        init();

        for(int i = 0; i < n; i++){ 
            // guardamos los valores del numBinario 1 o 0
            bits[i+1] = numBinario[i] - '0';
        }
        
        int queries;
        cin>>queries;

        cout << "Case " << caso << ":" << endl;

        for(int q = 0; q < queries; q++){
            char iOq;//es I o Q el primer valor
            cin>>iOq;
            int i, j;
            cin>>i>>j;
            if(iOq == 'I'){//invierte en un rango
                for (int k = i; k <= j; k++) { //visita todo el rango
                    bits[k] = 1 - bits[k]; // Invertir el bit
                }
            } else {//Q devuelve el bit i 
                int root = find(i);
                cout << bits[root] << endl;
            }
        }

    }

    return 0;
}