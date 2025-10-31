#include <bits/stdc++.h>
using namespace std ;

vector<int> heap;
//max heap tree sorted as array<vector>

void insert(int n){
    heap.push_back(n);
    int i = heap.size()-1;
    int temp;
    while(i>0 && heap[i]>heap[(i-1)/2]){
        temp = heap[i];
        heap[i]=heap[(i-1)/2];
        heap[(i-1)/2] = temp;
        i=(i-1)/2;
    }
}

int deleteEl(){ //can only delete first element(greatest)
    if(heap.size()==0) return -1;
    int x = heap[0];
    heap[0]=heap[heap.size()-1];
    heap.pop_back();
    int temp;

    int i = 0;
    int left,right,largest;

    while(true){
        left = 2*i+1;
        right = 2*i+2;
        largest = i;

        if(left < heap.size() && heap[left] > heap[largest]) largest = left;
        if(right < heap.size() && heap[right] > heap[largest]) largest = right;

        if(largest != i){
            temp = heap[i];
            heap[i] = heap[largest];
            heap[largest] = temp;
            i = largest;
        }
        else break;
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
