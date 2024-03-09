/*Design algorithm/develop pseudocode/write C code to search an element in a linked
list, if found delete that node and insert that node at beginning. Otherwise display an
appropriate message.*/
#include<stdio.h>
#include<stdlib.H>
struct node
{
    struct node *next;
    int info;
};
struct node *head=NULL;
void create()
{
    struct node *newnode;
    struct node *ptr=head;
    int n;
    printf("enter number of nodes:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        if(newnode==NULL)
        {
            printf("overflow");
            return;
        }
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter info of newnode:");
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
void insert_at_begin(int ele)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->info=ele;
    newnode->next=head;
    head=newnode;
}
void delete(int ele)
{
    struct node *prev, *ptr;
    if(ele==head->info)
    {
        printf("\nalready in the beginning\n");
        return;
    }
    ptr=head;
    while(ptr!=NULL && ptr->info!=ele)
    {
        prev=ptr;
        ptr=ptr->next;
    }
    if(ptr==NULL)
    {
        printf("node not found!\n");
        return;
    }
    prev->next=ptr->next;
    free(ptr);
    insert_at_begin(ele);
}
void traverse()
{
    struct node *ptr=head;
    while(ptr->next!=NULL)
    {
        printf("%d->",ptr->info);
        ptr=ptr->next;
    }
    printf("%d",ptr->info);
}
int main()
{
    int ele;
    create();
    printf("the original list is:\n");
    traverse();
    printf("enter the element:");
    scanf("%d",&ele);
    delete(ele);
    printf("\nthe updated list is:\n");
    traverse();
}
