#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *create(int n)
{
    struct Node *head = NULL , *temp = NULL , *new = NULL;
    int val;
    for(int i = 0; i < n ; i++)
    {
        printf("Enter value of node %d : ",i+1);
        scanf("%d",&val);
        new = (struct Node*)malloc(sizeof(struct Node));
        new->data = val;
        new->next = NULL;

        if(head == NULL)
            head = new;
        else
            temp->next = new;
        temp = new;
    }
    return head;
}

void display(struct Node *head)
{
    struct Node *temp = head;
    printf("%d ",temp->data);
    while(temp->next != NULL)
    {
        temp = temp->next;
        printf("%d ",temp->data);
    }
}

struct Node *insert(struct Node *head,int pos,int val)
{
    struct Node *new = (struct Node*)malloc(sizeof(struct Node));
    new->data = val;
    struct Node* temp = head;
    if(pos == 1)
    {
        head = new;
        new->next = temp;
        display(head);
        return head;
    }
    else
    {
        for(int i = 1 ; i < pos - 1 ; i++)
        {
            if (temp == NULL) 
            {
                printf("Position out of bounds!\n");
                free(new);
                return head;
            }
            temp = temp->next;
        }
        new->next = temp->next;
        temp->next = new;
        display(head);
        return head;
    }
}

struct Node *delete(struct Node *head , int pos)
{
    struct Node* temp = head;
    for(int i = 0 ; i < pos-1 ; i++)
    {
        temp = temp->next;
    }
    temp->next = temp->next->next;
    display(head);
    return head;
}

struct Node *reverse(struct Node *head)
{
    struct Node *t1 = NULL,*t2 = NULL ,*t3 = head;
    while(t3->next != NULL)
    {
        t1 = t2;
        t2 = t3;
        t3 = t3->next;
        t2->next = t1;
    }
    head = t3;
    t3->next = t2;
    t2->next = t1;
    display(head);
    return head;
}

int main()
{
    struct Node *head = create(5);
    head  = insert(head,3,90);
    head = delete(head,2);
    head = reverse(head);
}

