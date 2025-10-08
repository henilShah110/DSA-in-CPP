#include <bits/stdc++.h>
using namespace std ;

struct Node {
    int data;
    struct Node* next;
};

struct Node create(int n) {
    struct Node *head = NULL , *temp = NULL;
    int value;

    for(int i = 0 ; i < n ; i++){
        cout << "Enter value : ";
        cin >> value;
        p = new Node;
        p->data = value;
        p->next = NULL;

        if(head->next == NULL)
            head = new; 
        else
            temp->next = new;
        temp = new;

    }
    return head;
}

void display(struct Node *head){
    
}


int main ()
{
	
	return 0;
}