#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

display(struct node *head)
{
    if(head == NULL)
    {
        printf("NULL\n");
    }
    else
    {
        printf("%d\n", head -> data);
        display(head->next);
    }
}

struct node* front(struct node *head,int value)
{
    struct node *p;
    p=malloc(sizeof(struct node));
    p->data=value;
    p->next=head;
    return (p);
}

end(struct node *head,int value)
{
    struct node *p,*q;
    p=malloc(sizeof(struct node));
    p->data=value;
    p->next=NULL;
    q=head;
    while(q->next!=NULL)
    {
        q = q->next;
    }
    q->next = p;
}
after(struct node *a, int value)
{
    if (a->next != NULL)
    {
        struct node *p;
        p = malloc(sizeof(struct node));
        p->data = value;
        /*
        if initial linked list is
         ___        ___        ___ 
        |   1   |_\ |   3   |_\ |   5   |__\ NULL
        |__|    / |__|    / |___|    / 
        and new node's value is 10
        then the next line will do something like
         ___        ___        ___ 
        |   1   |_\ |   3   |_\ |   5   |__\ NULL
        |__|    / |__|    / |___|    / 
                        / \
                         |
                         |
                      _|_
                     |   10  |
                     |___|
        */
        p->next = a->next;
        a->next = p;
    }
    else
    {
        printf("Use end function to insert at the end\n");
    }
}

