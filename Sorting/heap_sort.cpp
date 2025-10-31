#include <bits/stdc++.h>
using namespace std;

vector<int> heap;

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

void display(vector<int> arr){
    for(int i = 0 ; i < 10 ; i++){
        cout << arr[i] << " ";
    }
}

void sortingEl1(vector<int> arr,int len){ 
    int x = arr[0];
    arr[0]=arr[len];
    len-=1;
    int temp;

    int i = 1; //all indices to be used with -1
    while(2*i<=len-1){
        if(arr[2*i-1]>arr[2*i] && arr[2*i-1]>arr[i-1]){
            temp = arr[i-1];
            arr[i-1]=arr[2*i-1];
            arr[2*i-1]=temp;
            i = 2*i;
        }
        else if(arr[2*i-1]<=arr[2*i] && arr[2*i]>arr[i-1]){
            temp = arr[i-1];
            arr[i-1]=arr[2*i];
            arr[2*i]=temp;
            i = 2*i+1;
        }
        else{
            break;
        }
    }
    arr[arr.size()-1] = x;
}


void heapSort(vector<int> arr){
    int len = arr.size();
    for(int i = 0 ; i < arr.size() ; i++){
        insert(arr[i]);
    }

    for(int i = 0 ; i < heap.size();i++){
        sortingEl1(heap,len-1);
    }
    display(heap);
} 

int main()
{
    vector<int> arr = {2 , 87 , 9 , 3 , 122 , 18 , 34 , 68 , 90 , 23};
    heapSort(arr);
}