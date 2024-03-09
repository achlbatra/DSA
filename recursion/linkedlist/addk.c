//Design algorithm/develop pseudocode/write C code to add a given value K to each element in
//the LIST.
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
void add_k(struct node *ptr)
{
    int k;
    printf("\nenter the number to add:");
    scanf("%d",&k);
    while(ptr!=NULL)
    {
        ptr->info=ptr->info+k;
        ptr=ptr->next;
    }
}
int main()
{
    create();
    printf("the originial list is:\n");
    traverse();
    add_k(head);
    printf("the updated list is:\n");
    traverse();
}