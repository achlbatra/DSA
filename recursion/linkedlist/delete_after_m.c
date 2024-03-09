//Design algorithm/develop pseudocode/write C code to delete n nodes after m nodes of a linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
};
struct node *head=NULL;
void create()
{
    struct node *newnode, *ptr=head;
    int n;
    printf("enter the number of nodes:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter the info of newnode:");
        scanf("%d",&newnode->info);
        newnode->next=NULL;
        if(head==NULL)
        {
            head=newnode;
            ptr=newnode;
        }
        else
        {
            ptr->next=newnode;
            ptr=newnode;
        }
    }
}
void traverse(struct node *head)
{
    struct node *q=head;
    while(q->next!=NULL)
    {
        printf("%d->",q->info);
        q=q->next;
    }
    printf("%d",q->info);
}
void delete(int pos)
{
    struct node *prev, *ptr=head;
    int i=0;
    while(ptr!=NULL && i!=pos)
    {
        prev=ptr;
        ptr=ptr->next;
        i++;
    }
    prev->next=ptr->next;
    free(ptr);
}
int main()
{
    int m,n;
    create();
    printf("orginal list is:\n");
    traverse(head);
    printf("enter the value of m:");
    scanf("%d",&m);
    printf("enter value of n:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        delete(m);
    }
    printf("\nafter deletion:\n");
    traverse(head);
}