#include <bits/stdc++.h>
using namespace std ;

struct Node {
    int data;
    struct Node* next;
};

struct Node *create(int n)
{
    struct Node *head = NULL , *temp = NULL;
    int val;
    for(int i = 0; i < n ; i++)
    {
        cout << "Enter value of node "<< i+1 <<" : ";
        cin >> val;
        struct Node *p = new Node;
        p->data = val;
        p->next = NULL;

        if(head == NULL)
            head = p;
        else
            temp->next = p;
        temp = p;
    }
    return head;
}

void display(Node *head) {
    if (head == NULL) {
        cout << "List is EMPTY!" << endl;
        return;
    }
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

struct Node *insert(struct Node *head,int pos,int val)
{
    struct Node *n = new Node;
    n->data = val;
    struct Node* temp = head;
    if(pos == 1)
    {
        head = n;
        n->next = temp;
        display(head);
        return head;
    }
    else
    {
        for(int i = 1 ; i < pos - 1 ; i++)
        {
            if (temp == NULL) 
            {
                cout << "Position out of bounds!" << endl;
                delete n;
                return head;
            }
            temp = temp->next;
        }
        n->next = temp->next;
        temp->next = n;
        display(head);
        return head;
    }
}

Node* delete_(Node *head, int pos) {
    if (head == NULL) return NULL;

    if (pos == 1) {
        Node *toDelete = head;
        head = head->next;
        delete toDelete;
        display(head);
        return head;
    }

    Node *temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        cout << "Position out of bounds!" << endl;
        return head;
    }

    Node *toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
    display(head);
    return head;
}

Node* reverse(Node* head) {
    Node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    display(head);
    return head;
}

int main ()
{
    //just some data to test functions
	struct Node *head = create(5);
    head  = insert(head,3,90);
    head = delete_(head,2);
    head = reverse(head);
	return 0;
}