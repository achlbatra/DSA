//count number of occurances of an element in a single ll
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
int count(int ele)
{
    int count=0;
    struct node *ptr=head;
    while(ptr!=NULL)
    {
        if(ptr->info==ele)
        {
            count++;
        }
        ptr=ptr->next;
    }
    return count;
}
int main()
{
    create();
    printf("the linked list is:");
    traverse(head);
    int ele;
    printf("\nenter the element:");
    scanf("%d",&ele);
    printf("\nthe number of occurances of %d is %d.",ele,count(ele));
}