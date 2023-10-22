#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

int v[500001]; 
int parent[500001];
int cont[500001]; 
int rango[500001]; 

int n;
void init() { 
    for(int i=0;  i<= n; i++) {
        parent[i] = i; 
        rango[i] = 0; 
        cont[i] = 1; 
    }
}

int find(int x) {
    if(x == parent[x]) { 
        return x;
    }
    else {
        parent[x] = find(parent[x]); 
        
        return parent[x];
    }
}

void unionRango(int x,int y) {  
    int xRaiz = find(x); 
    int yRaiz = find(y);
    if(yRaiz == xRaiz){
        return;
    }
    if(rango[xRaiz] > rango[yRaiz]) {
        parent[yRaiz] = xRaiz;
        cont[xRaiz] += cont[yRaiz];
    } else { 
        parent[xRaiz] = yRaiz; 
        cont[yRaiz] += cont[xRaiz];
        if(rango[xRaiz] == rango[yRaiz]) { 
            rango[yRaiz]++;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int recetascreadas = 0; //contador

    int N;
    cin>>N;

    n = 5e5+1;
    init();

    for(int i = 0; i < N; i++){//recibimos cuantas recetas van a haber
        int M;
        cin>>M;

        vector<int> pocion;
        map<int, int> copia;

        bool sepuede = true; //empieza en true porque no hay ningun elemento repetido todavia

        for(int j = 0; j < M; j++){//recibimos cuantos ingredientes van a haber
            int ingred;
            cin>>ingred;
            
            pocion.push_back(ingred); //solo guardamos   

        }

        for(int k = 0; k < pocion.size(); k++){
            copia[find(pocion[k])]=cont[find(pocion[k])];
        }

        for(int l = 0; l < pocion.size(); l++){//cada que usamos un ingred 
                        //lo restamos para ver si lo popdemos usar como conjunto
            copia[find(pocion[l])]--;
        }

        for(auto & v:copia){//v es un par dependiendo del mapa 
            if(v.second != 0){ //restamos pero no estamos usando todo el conjunto
                sepuede=false;
                break;
            }
        }

        if(sepuede){ //si se puede porque los ingredientes estan disponibles
            for (int j = 1; j < M; j++) { // ve los ingredientes y los va añadiendo después 
                                        //de ver que estan disponibles, desde 1 porque el -1 
                                        //hará que añada al primero
                unionRango(pocion[j - 1], pocion[j]); //porque en pocion guardamos os ingredinetes
                //unimos los M elementos si están disponibles 
                //ahora esa receta está disponible para usarse
            }
            recetascreadas++; // se creó con éxito una receta
        }
    }

    cout << recetascreadas << "\n";

    return 0;
    
}