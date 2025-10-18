#include <bits/stdc++.h>
using namespace std ;

struct Node 
{
    struct Node* lchild;
    int data;
    struct Node* rchild;
} *root = NULL;

struct Node * insert(struct Node *p , int x){
    if(p == NULL){
        Node *t = new Node;
        t->data = x;
        t->lchild = NULL;
        t->rchild = NULL;
        return t;
    }
    if(x < p->data){
        p->lchild = insert(p->lchild , x);
    }
    else if(x > p->data){
        p->rchild = insert(p->rchild ,x);
    }
    return p;
}

void inorder(struct Node *p)
{
    if(p)
    {
        inorder(p->lchild);
        cout << p->data << " ";
        inorder(p->rchild);
    }
}

int main(){
    root = insert(root,10);
    root = insert(root,12);
    root = insert(root,20);
    root = insert(root,3);
    root = insert(root,5);
    root = insert(root,56);
    root = insert(root,18);
    root = insert(root,4);
    inorder(root);

    return 0;
}