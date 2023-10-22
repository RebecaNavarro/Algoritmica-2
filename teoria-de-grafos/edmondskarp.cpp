#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std; 
#define MAX_N 101        // Tarea 

int grafo[MAX_N][MAX_N];   // capacidad + flujo  
int path[MAX_N];           // camino b: b <- a     
// path 0->3->2->4    
// [0,-1,3,0,2,-1, 4]
//  0  1 2 3 4, 5, 6
// Edmonds Karp 
// DINIC 

int maxFlow(int s,int t) { 
    // s nodo inicial 
    // t nodo final 
    int maxFlow = 0;
    while(true) { ///  nunca sabemos si no tenemos flujo
        //BFS O(V+E) //mas rapidoo de nodo a nodo// queue
        memset(path, -1, sizeof(path)); // no los estamos visitando
        //path: camino visitado
        queue<int> Q;
        Q.push(s);
        path[s] = s;  // s- 
        while(!Q.empty() && path[t]==-1) {//no llegué a la meta
            int currentNode = Q.front();
            Q.pop();
            for(int i = 0 ; i < MAX_N ; i++) {
                //
                if(grafo[currentNode][i] > 0 && path[i]==-1)  {  // puedo visitar? 
                    path[i] = currentNode;                       // guardar camino 
                    Q.push(i);                                  // agregar a la cola
                }   
            }
        }
       
        if(path[t]==-1) { // si llego a t el path tiene que ser diferente a -1
        //no llega nunca a T / al objetivo 
            break;
        }
        int minFlow = 1e9; // infinito
        for(int from = path[t],to = t; from!=to ; from = path[to = from]) {
            //dos variables: de donde vengo y adonde voy
            //recorre el camino hacia atras
            //to se vuelve from y luego su path lo asigna al from
            //camino mínimo del path = minimo flujo
            minFlow = min(minFlow,grafo[from][to]); // grafo[from][to] capacidades de las aristas 
            //
        }
        

        // V - 1 //  
        // Sumar al grafo residual y restar al grafo de capacidad ese minimo                                            // sumar todos os diferentes a -1 
        for(int from = path[t],to = t; from!=to ; from = path[to = from]) {
            grafo[from][to] -= minFlow; // grafo de capacidad
            grafo[to][from] += minFlow; // grafo residual
        } //resta el minimo y le aumentamos al residuo
        // s = 0 , t = 6
        // 0 -> 1 -> 3 -> 5 -> 6 
        // path[] = {0,0,0,1,0,3,5,0,0,0}
        //           0 1 2 3 4 5 6 7 8 9

        // from = 0
        // to = 0

        //from = path[to = from]
        //from = path[0] 
        maxFlow += minFlow; //se le suma para el total
        // 2V+E-1
    }
    // flujos * 2V+E-1
    // flujos *2V + flujos*E - flujos
    // flujos*E E^2
    return maxFlow;
}



int main() {
input;
int nodes, aristas, nroCases = 1; 
while(cin>>nodes && nodes) {
    int s,t;   // s = fuente o source t = terminal 
    cin>>s>>t>>aristas;
    memset(grafo,0,sizeof(grafo));
     for(int i=0;i<aristas;i++) {
        int from, to, capacity; 
        cin>>from>>to>>capacity;
        grafo[from][to] = capacity;          // camino capacidad
        grafo[to][from] = 0;                //  flujo camino residual 
    }
    cout<<maxFlow(s,t)<<endl;
    }    
}