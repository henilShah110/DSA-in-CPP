#include <bits/stdc++.h>
using namespace std ;

//FOR QUADRATIC PROBING : just change i -> i*i
#define SIZE 10

int hash_i(int key) {
    return key%SIZE;
}
int probe(int H[],int key){
    int index = hash_i(key);
    int i = 0;

    while(H[(index+i)%SIZE]) i++;
    return (index+i)%SIZE;
}

void Insert(int H[],int key){
    int index = hash_i(key);
    
    if(H[index]!=0) index = probe(H,key);

    H[index]=key;
}

int search_i(int H[],int key){
    int index = hash_i(key);

    int i = 0;
    while(H[(index+i)%SIZE]!=key)
        i++;
    if(H[(index+i)%SIZE]==key)
        return (index+i)%SIZE;
    return -1; //key not found
}

int main(){
    int HT[10] = {0};

    Insert(HT,12);
    Insert(HT,25);
    Insert(HT,35);
    Insert(HT,26);

    cout << search_i(HT,35) << " " << search_i(HT,15);
    return 0;
}