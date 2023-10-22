#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

int v[1000000]; 
int parent[1000000];
int rango[1000000]; 

int n;
void init() { 
    for(int i=0;  i<= n; i++) {
        parent[i] = i; 
        rango[i] = 0; 
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
    if(rango[xRaiz] > rango[yRaiz]) {
        parent[yRaiz] = xRaiz;
    } else { 
        parent[xRaiz] = yRaiz; 
        if(rango[xRaiz] == rango[yRaiz]) { 
            rango[yRaiz]++;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    int caso = 0;
    set<int> religiones;
    while(cin>>N>>M){
        if(N==0 && M==0){
            break;
        }

        caso ++;
        n = N;
        init();
        
        for(int x=0; x<M; x++){
            int i, j;
            cin>>i>>j;
            unionRango(i,j);
        }

        religiones.clear();

        for (int y = 1; y <= N; y++) {
            religiones.insert(find(y));
        }
        
        cout << "Case " << caso << ": " << religiones.size() << endl;
    }
    
    return 0;
    
}
