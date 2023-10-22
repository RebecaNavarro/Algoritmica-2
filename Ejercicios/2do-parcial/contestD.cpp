#include <bits/stdc++.h> 
using namespace std;

bool lower(char c){
    if(c >= 'a' && c <= 'z'){
        return true;
    } else {
        return false;
    }
}

int solve(string word){

    //aBcD = 0123 impares M par m
    int contLowers = 0;
    for(int i = 0 ; i < word.length() ; i++){
        if(i%2 == 0 && !lower(word[i])){ //par y mayuscula
            contLowers ++;
        } else if(i%2 != 0 && lower(word[i])){ //es impar y es minuscula
            contLowers ++;
        }
    }

    //AbCd = 0123 impar m par M
    int contUppers = 0;
    for(int i = 0 ; i < word.length() ; i++){
        if(i%2 == 0 && lower(word[i])){ //par y minuscula
            contUppers ++;
        } else if (i%2 != 0 && !lower(word[i])){ //es impar y es minuscula
            contUppers ++;
        }
    }

    int minimo = min(contLowers,contUppers);

    return minimo;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string word;
    while(cin>>word){
        cout<<solve(word)<<endl;
    }
    return 0;
}