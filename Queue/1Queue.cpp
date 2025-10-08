#include <bits/stdc++.h>
using namespace std ;

struct Node 
{
    int data;
    struct Node* next;
} *front = NULL , *rear = NULL;

void enqueue(int x)
{
    struct Node *p = new Node;
    p->data = x;
    p->next = NULL;
    if(front == NULL)
    {
        front = p;
        rear = p;
        return;
    }

    rear->next = p;
    rear = p;
    return;
}

int dequeue()
{
    if(front == NULL)
    {
        cout << "Queue is EMPTY";
        return -1;
    }
    struct Node *p = front;
    front = front->next;
    int x = p->data;
    delete p;
    return x;
}

void display() 
{
    if(front == NULL)
    {
        cout << "Queue is EMPTY" << endl;
        return;
    }
    struct Node *p = front;
    while(p)
    {
        cout << p->data << " - ";
        p = p->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    //just some data to test functions
    enqueue(10);
    enqueue(5);
    enqueue(3);
    enqueue(7);
    enqueue(11);
    display();
    cout << dequeue() << endl;
    display();
}