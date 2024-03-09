//Design algorithm/develop pseudocode/write C code to create a linked list from a given linked
//list. The new linked list must contain every alternate element of the existing linked list.
#include<stdio.h>
#include<stdlib.H>
struct node
{
    struct node *next;
    int info;
};
struct node *head1=NULL;
struct node *head2=NULL;
void create()
{
    struct node *newnode;
    struct node *ptr=head1;
    int n;
    printf("enter number of nodes of original list:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        /*if(newnode->next==NULL)
        {
            printf("overflow");
            return;
        }*/
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter info of newnode:");
        scanf("%d",&newnode->info);
        newnode->next=NULL;
        if(head1==NULL)
        {
            head1=newnode;
            ptr=newnode;
        }
        else
        {
            ptr->next=newnode;
            ptr=newnode;
        }
    }
}
struct node* create_new(struct node *head)
{
    struct node *p=head;
    struct node *ptr=head2;
    struct node *newnode;
    while(p!=NULL)
    {
        newnode =(struct node*)malloc(sizeof(struct node));
        newnode->info=p->info;
        newnode->next=NULL;
        if(head2==NULL)
        {
            head2=newnode;
            ptr=newnode;
        }
        else
        {
            ptr->next=newnode;
            ptr=newnode;
        }
        if(p->next==NULL)
        {
            break;
        }
        p=p->next->next;
    }
    return head2;
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
int main()
{
    create();
    printf("the original linked list is:\n");
    traverse(head1);
    create_new(head1);
    printf("\n the new linked list containing alternate elements is:\n");
    traverse(head2);
}