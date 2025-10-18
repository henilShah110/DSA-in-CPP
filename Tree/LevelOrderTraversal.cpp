#include <bits/stdc++.h>
using namespace std ;

struct Node 
{
    struct Node* lchild;
    int data;
    struct Node* rchild;
} *root = NULL;

struct Queue 
{
    struct Node *Q;
    struct Queue* next;
} *front = NULL , *rear = NULL; 

void enqueue(struct Node *x)
{
    struct Queue *p = new Queue;
    p->Q = x;
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

struct Node * dequeue()
{
    if(front == NULL)
    {
        cout << "Queue is EMPTY";
        return NULL;
    }
    struct Queue *p = front;
    front = front->next;
    if(front == NULL) rear = NULL;
    struct Node *x = p->Q;
    delete p;
    return x;
}

int isEmpty()
{
    return(front==NULL);
}

void CreateBinaryTree()
{
    struct Node *p , *t;
    int x;
    cout << "Enter root value : ";
    cin >> x;
    root = new Node;
    root->data = x;
    root->lchild = NULL;
    root->rchild = NULL;
    enqueue(root);

    while(!isEmpty())
    {
        p = dequeue();
        cout << "Enter left child of " << p->data << " : ";
        cin >> x;
        if(x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = NULL;
            t->rchild = NULL;
            p->lchild = t;
            enqueue(t);
        }
        cout << "Enter right child of " << p->data << " : ";
        cin >> x;
        if(x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = NULL;
            t->rchild = NULL;
            p->rchild = t;
            enqueue(t);
        }
    }
}

void levelorder(){
    front = NULL;
    rear = NULL;
    enqueue(root);

    struct Node *p;
    while(front){
        p = dequeue();
        cout << p->data << " ";
        if(p->lchild)
            enqueue(p->lchild);
        if(p->rchild)
            enqueue(p->rchild);
    }
}

int main()
{
    CreateBinaryTree();
    levelorder();
}