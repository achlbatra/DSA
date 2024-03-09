//Design algorithm/develop pseudocode/write C code to reverse the nodes in a linked list.
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
void reverse()
{
    struct node *p1, *p2, *p3;
    p1=head;
    p2=p1->next;
    p3=p2->next;
    p1->next=NULL;
    while(p2!=NULL)
    {
        p2->next=p1;
        p1=p2;
        p2=p3;
        if(p3!=NULL)
        {
            p3=p3->next;
        }
    }
    head=p1;
}
int main()
{
    create();
    printf("original:\n");
    traverse();
    reverse();
    printf("\nafter reverse:\n");
    traverse();

}