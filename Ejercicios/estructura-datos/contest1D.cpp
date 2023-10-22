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
    cin>>N>>M;
    n = N;
    init();
    for(int i=0; i<M; i++){
        char car;
        int v1;
        int v2;
        cin>>car>>v1>>v2;
        if (car == '?'){
            if(find(v1)==find(v2)){
                cout<<"yes\n";
            } else{
            cout<<"no\n";
            }
        } else {
            unionRango(v1,v2);
        }
    }
}