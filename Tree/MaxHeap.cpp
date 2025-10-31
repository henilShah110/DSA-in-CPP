#include <bits/stdc++.h>
using namespace std ;

vector<int> heap;
//max heap tree sorted as array<vector>

void insert(int n){
    heap.push_back(n);
    int i = heap.size()-1;
    int temp;
    while(heap[i]>heap[i/2]){
        temp = heap[i];
        heap[i]=heap[i/2];
        heap[i/2] = temp;
        i/=2;
    }
}

int deleteEl(){ //can only delete first element(greatest)
    int x = heap[0];
    heap[0]=heap[heap.size()-1];
    heap.pop_back();
    int temp;

    int i = 1; //all indices to be used with -1
    while(2*i<=heap.size()-1){
        if(heap[2*i-1]>heap[2*i] && heap[2*i-1]>heap[i-1]){
            temp = heap[i-1];
            heap[i-1]=heap[2*i-1];
            heap[2*i-1]=temp;
            i = 2*i;
        }
        else if(heap[2*i-1]<=heap[2*i] && heap[2*i]>heap[i-1]){
            temp = heap[i-1];
            heap[i-1]=heap[2*i];
            heap[2*i]=temp;
            i = 2*i+1;
        }
        else{
            break;
        }
    }
    return x;
}

int main(){
    insert(2);
    insert(87);
    insert(9);
    insert(3);
    insert(122);
    insert(18);
    insert(34);
    insert(68);
    insert(90);
    insert(23);
    
    cout << deleteEl() << " ";
    cout << deleteEl() << " ";
    cout << deleteEl() << " ";
    cout << deleteEl() << " ";
    cout << deleteEl() << " ";
    cout << deleteEl() << " ";
    cout << deleteEl() << " ";
    cout << deleteEl() << " ";
    cout << deleteEl() << " ";
    cout << deleteEl() << " ";

}