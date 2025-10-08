#include <bits/stdc++.h>
using namespace std ;

struct Node 
{
    int data;
    struct Node* next;
} *top = NULL;

void push(int x)
{
    struct Node *p = new Node;

    if(p == NULL)
    {
        cout << "stack is FULL";
        return;
    }

    p->data = x;
    p->next = top;
    top = p;
}

int pop()
{
    if(top == NULL)
    {
        cout << "Stack is Empty";
        return 0;
    }

    struct Node *top2 = top;
    top = top->next;
    int x = top2->data;
    delete top2;
    return x;
}

void display() {
    if (top == NULL) {
        cout << "List is EMPTY!" << endl;
        return;
    }
    Node *temp = top;
    while (temp != NULL) {
        cout << temp->data << " / ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main ()
{
    //just some data to test functions
	push(10);
    push(12);
    push(8);
    push(7);
    push(9);
    display();
    pop();
    display();
    push(14);
    display();
	return 0;
}