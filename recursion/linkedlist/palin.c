//Design algorithm/develop pseudocode/write C code to check if a singly linked list is palindrome
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
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
bool palindrome(struct node *head)
{
    if(head->next==NULL)
    {
        return true;
    }
    struct node *p1, *p2, *p3, *head2=NULL;
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
    head2=p1;
    p1=head;
    while(p1!=NULL)
    {
        if(p1->info!=head2->info)
        {
            return false;
        }
        p1=p1->next;
        head2=head2->next;
    }
    return true;
}
void main()
{
    create();
    printf("the list is \n");
    traverse(head);
    if(palindrome(head))
    {
        printf("\nyes it is a palindrome");
    }
    else
    {
        printf("\nno it is not a palaindrome");
    }
}