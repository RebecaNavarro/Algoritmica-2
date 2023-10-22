#include <bits/stdc++.h>
using namespace std; 

struct node {
    char currentCharacter;       
    bool isWord;
    int contadorPrefijos;
   //  int priority = 0;            
    struct node *children[27];  // [null,null,null,......,null]
    node() {
        isWord = false;
        contadorPrefijos = 0;
    }
    
}*trie; 

// Inicializar 

void init() {
    trie = new node();  // Instanciar el objeto trie
}

void insertWord(string word) {    
    node *currentNode =  trie;  
    for (int i = 0; i< word.length(); i++) { 
        int character = word[i] - 'a';       
        if(currentNode->children[character] == NULL ) {
            currentNode->children[character] = new node();
        }
        currentNode = currentNode->children[character];
        currentNode->currentCharacter = word[i];
        currentNode->contadorPrefijos = currentNode->contadorPrefijos+1;
    }
    currentNode->isWord = true;
    
}

bool searchWord(string word) {   // alto 
    node *currentNode =  trie;  
    for (int i = 0; i< word.length(); i++) {
        int character = word[i] - 'a';       // i = 0 'a'-'a' = 0
        if(currentNode->children[character] == NULL ) {
           return false;
        }
        currentNode = currentNode->children[character];
    }
    cout<<currentNode->currentCharacter<<endl;
    return currentNode->isWord;
}

bool searcByPrefix(string prefijo) {   // alto 
    node *currentNode =  trie;  
    for (int i = 0; i< prefijo.length(); i++) {
        int character = prefijo[i] - 'a';      
        if(currentNode->children[character] == NULL ) {
           return false;
        }
        currentNode = currentNode->children[character];
    }
    cout<<currentNode->currentCharacter<<endl;
    return currentNode->contadorPrefijos;
}

// Función auxiliar para verificar si un nodo tiene hijos no nulos
bool hasChildren(node *currentNode) {
    for (int i = 0; i < 27; i++) {
        if (currentNode->children[i] != NULL) {
            return true;
        }
    }
    return false;
}

// Función auxiliar para eliminar una palabra
// bcd
bool deleteWord(node *currentNode, string word, int index) {
    // Caso base: Se ha recorrido toda la ruta
    if (index == word.length()) {
        // Si el nodo actual representa el fin de una ruta, lo marcamos como no fin de palabra
        if (currentNode->endOfWord) {
            currentNode->endOfWord = false;
            // Si el nodo actual no tiene otros hijos, se puede eliminar
            return !hasChildren(currentNode);
        }
        return false;
    }

    int character = word[index] - 'a';
    // b - a = 98-97 = 1  
    if (currentNode->children[character] == NULL) {
        // La ruta no existe en el Trie, no hay nada que eliminar
        return false;
    }

    // Llamada recursiva para eliminar la ruta restante
    bool shouldDeleteChild = deleteWord(currentNode->children[character], word, index + 1);

    if (shouldDeleteChild) {
        // Si el nodo hijo debe eliminarse, eliminamos la referencia al hijo y verificamos si el nodo actual también es candidato para eliminarse
        delete currentNode->children[character];
        currentNode->children[character] = NULL;
        return !hasChildren(currentNode) && !currentNode->endOfWord;
    }

    return false;
}

// Función pública para eliminar una ruta de teleférico
void deleteWord(string word) {
    // bcd
    // deleteRoute(trie, "bcd", "b")
    deleteWord(trie, word, 0);
}

void findWordsWithPrefix(node *currentNode, string prefix, vector<string> result){
    //busca las palabras que tienen dicho prefijo

    if(currentNode->isWord) {
        result.push_back(prefix);
    }
    //si un nodo es el final de la palabra, 
    //se añade a la lista la palabra entera
    //que también es un prefijo

    if(!hasChildren(currentNode)){
        return;
    }
    //si el nodo no tiene hijos termina
    
    for (int i = 0; i < 27; i++){ //27 tamaño del alfabeto=matriz
    //recorre todos los hijos de un nodo
        if (currentNode->children[i] != NULL){
            //el elemento i de la matriz not null por lo tanto hay un hijo con el valor
            //si no es null tiene un hijo con i
            char nextChar = 'a' + i; 
            //ve cual es la letra del alfabeto
            string newPrefix = prefix + nextChar;
            //se hace un aumenta al prefijo el char
            findWordsWithPrefix(currentNode->children[i], newPrefix, result);
            //recursividad
            //explora el arbol de nextchar y seguir buscando con ese prefijo
        }

    }
    //debería ver según el prefijo todas las palabras 
    //posibles que se pueden formar con todas las letras
    //si no hay la letra se debería pasar al siguiente
}

int main() {

    // Inicializar Trie
    init();  
    string word = "auto";
    insertWord(word);
    isThereWord(word);
    word = "automovil";   
    insertWord(word);
    isThereWord("auto");
    isThereWord(word);
    return 0;
}