#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;


int main(){

    string binario, corregido;
    
    cin >> binario;

    for(int i = 0 ; i < binario.length() ; i++){
        if(binario[i] == '1'){
            corregido += "0";
        } else {
            corregido += "1";
        }
    }

    cout << corregido << endl;
    
    return 0;
    
}
