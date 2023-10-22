//librerias
#include <vector>
#include <limits>
using namespace std;


class Grafo {
public:
    Grafo(int nodos);//inicializa el grafo
    vector<vector<int>> prim();//crea el vector para todos
                                //con el prim 

private:
    const int INF = numeric_limits<int>::max();//infinito
    int cantidadNodos;//nodos
    vector<vector<int>> adyacencia;//distancias o valores de 
                        //las aristas del grafo
};

Grafo::Grafo(int nodos) {//constructor
    cantidadNodos = nodos;//inicializa el valor de la 
    //cantidad de nodos
    adyacencia = vector<vector<int>>(cantidadNodos, vector<int>(cantidadNodos, INF));
    //matriz de adyacencia con las distancias inicialmente como INF
    //porque todavía no elegimos las aristas que nos serviran
    //se mantienen con INF si no hay una arista entre esos nodos 
    //y es 0 si es el mismo nodo
}

vector<vector<int>> Grafo::prim() {//aca se construye el arbol
//devuelve una matriz que será nuestro árbol

    vector<vector<int>> arbol(cantidadNodos, vector<int>(cantidadNodos, INF));
    //matriz con la informacion del arbol con todos los nodos del grafo 
    //para las columnas y filas para ir llenando con los valores 
    //de las aristas que nos sirven para que sea minimo

    vector<bool> marcado(cantidadNodos, false);
    //vector con los nodos que ya visitamos

    marcado[0] = true; //con el nodo que empezaremos, en este caso el nodo 0,
    //lo marcamos como true en el vector marcado ya que ya está
    //visitado y esto impide que lo volvamos a visitar

    for (int k = 1; k < cantidadNodos; k++) {//construccion
    //desde 1 a cantidad de nodos porque anteriormente
    //ya marcamos como visitado el primero (0)

        int menorDistancia = INF;//guardamos de un nodo
        // cual es su arista con menor peso

        int padre, hijo;// nodos con menor valor en su arista

        for (int i = 0; i < cantidadNodos; i++) {
            // vamos a hacer que vea a todos los marcados 
            //que llegarian a ser todos los nodos

            if (marcado[i]) { //para cada nodo que veamos marcado 
                for (int j = 0; j < cantidadNodos; j++) { //buscamos 
            //un nodo que comparta arista y vemos cual nodo será el 
            //que tenga la arits minima
                    if (!marcado[j] && adyacencia[i][j] < menorDistancia) {
                        //la busqueda se hará con la matriz de adyacencia que tiene 
                        //la informacion de las aristas
                        //si hay una arista menor con j actualizamos 
                        //la menor distancia con la que obtenemos de la matriz 
                        //de adyacenciay la j como el hijo que es el que ahora 
                        //tenemos que buscar su hijo e i que ahora es el padre
                        menorDistancia = adyacencia[i][j];
                        padre = i;
                        hijo = j;
                        //esto para luego marcar como visitados a estos valores y 
                        //buscar a los nodos que faltan
                    }
                }
            }
        }
        //aca lo ponemos como visitado al hijo y ahora buscamos
        // sus propios hijos
        marcado[hijo] = true;

        //ponemos en el arbol la menor distancia y unimos esos nodos
        arbol[padre][hijo] = menorDistancia;
        arbol[hijo][padre] = menorDistancia;
    }

    return arbol;//retorna el arbol minimo que 
                //se fue guardando anteriormente
}
