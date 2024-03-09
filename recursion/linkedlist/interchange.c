//Design algorithm/develop pseudocode/write C code which interchanges the Kth and (K+1)st elements
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
void inter(struct node *ptr)
{
    int k;
    printf("\nenter the index k:");
    scanf("%d",&k);
    int i=0;
    while(i!=k && ptr->next!=NULL)
    {
        ptr=ptr->next;
        i++;
    }
    if(ptr->next==NULL)
    {
        printf("invalid input!");
        return;
    }
    int temp=ptr->info;
    ptr->info=ptr->next->info;
    ptr->next->info=temp;
}
int main()
{
    create();
    printf("the original list is:\n");
    traverse();
    inter(head);
    printf("\nthe updated list is:\n");
    traverse();
}