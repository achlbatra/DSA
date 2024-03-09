//Design algorithm/develop pseudocode/write C code to swap nodes in a linked list without swapping data.
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
void traverse( struct node *head)
{
    struct node *ptr=head;
    while(ptr->next!=NULL)
    {
        printf("%d->",ptr->info);
        ptr=ptr->next;
    }
    printf("%d",ptr->info);
}
struct node* swap(struct node *h)
{
    int k;
    struct node *prev, *curr, *temp;
    prev=h;
    printf("\nenter the index:");
    scanf("%d",&k);
    if(k==0)
    {
        curr=prev->next;
        temp=curr->next;
        h=prev->next;
        prev->next=temp;
        curr->next=prev;
    }
    else
    {
    curr=prev->next;
    temp=curr->next;
    int i=1;
    while(i!=k && curr->next!=NULL)
    {
        prev=prev->next;
        curr=prev->next;
        temp=curr->next;
        i++;
    }
    if(curr->next==NULL)
    {
        printf("invalid input\n");
        return h;
    }
    prev->next=curr->next;
    curr->next=temp->next;
    temp->next=curr;
    }
    return h;
}
int main()
{
    create();
    printf("the original list is:\n");
    traverse(head);
    struct node *new = swap(head);
    printf("\nafter swapping:\n");
    traverse(new);
}