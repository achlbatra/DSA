//Design algorithm/develop pseudocode/write C code to add, subtract and multiply 2 polynomials.
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    int expo;
    struct node *next;
};
struct node *head=NULL;
struct node *poly1=NULL;
struct node *poly2=NULL;
struct node *res=NULL;
struct node* create(int n, struct node *head)
{
    struct node *newnode, *ptr=head;
    for(int i=0;i<=n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->expo=i;
        printf("enter the coefficient of power %d:",i);
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
    return head;
}
void traverse(struct node *head)
{
    struct node *q=head;

    int i=0;
    while(q->next!=NULL)
    {
        printf("%dx^%d ->",q->info,q->expo);
        q=q->next;
    }
    printf("%dx^%d",q->info, q->expo);
}
struct node *add(struct node *poly1, struct node *poly2)
{
    struct node *newnode,*ptr3=res, *ptr1=poly1, *ptr2=poly2;
    while(ptr1!=NULL && ptr2!=NULL)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->next = NULL;
        if(ptr1->expo<ptr2->expo)
        {
            newnode->info=ptr1->info;
            newnode->expo=ptr1->expo;
            ptr1=ptr1->next;
        }
        else if(ptr1->expo>ptr2->expo)
        {
            newnode->info=ptr2->info;
            newnode->expo=ptr2->expo;
            ptr2=ptr2->next;
        }
        else
        {
            newnode->info=ptr1->info + ptr2->info;
            newnode->expo=ptr1->expo;
            ptr2=ptr2->next;
            ptr1=ptr1->next;
        }
        if(res==NULL)
        {
            res=newnode;
            ptr3=newnode;
        }
        else
        {
            ptr3->next=newnode;
            ptr3=newnode;
        }
    }
    while(ptr1!=NULL)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->next=NULL;
        newnode->info=ptr1->info;
        newnode->expo=ptr1->expo;
        ptr1=ptr1->next;
        if(res==NULL)
        {
            res=newnode;
            ptr3=newnode;
        }
        else
        {
            ptr3->next=newnode;
            ptr3=newnode;
        }
    }
    while(ptr2!=NULL)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->next=NULL;
        newnode->info=ptr2->info;
        newnode->expo=ptr2->expo;
        ptr2=ptr2->next;
        if(res==NULL)
        {
            res=newnode;
            ptr3=newnode;
        }
        else
        {
            ptr3->next=newnode;
            ptr3=newnode;
        }
    }
    return res;
}

struct node *sub(struct node *poly1, struct node *poly2)
{
    struct node *newnode,*ptr3=res, *ptr1=poly1, *ptr2=poly2;
    while(ptr1!=NULL && ptr2!=NULL)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->next = NULL;
        if(ptr1->expo<ptr2->expo)
        {
            newnode->info=ptr1->info;
            newnode->expo=ptr1->expo;
            ptr1=ptr1->next;
        }
        else if(ptr1->expo>ptr2->expo)
        {
            newnode->info= (-ptr2->info);
            newnode->expo=ptr2->expo;
            ptr2=ptr2->next;
        }
        else
        {
            newnode->info=ptr1->info - ptr2->info;
            newnode->expo=ptr1->expo;
            ptr2=ptr2->next;
            ptr1=ptr1->next;
        }
        if(res==NULL)
        {
            res=newnode;
            ptr3=newnode;
        }
        else
        {
            ptr3->next=newnode;
            ptr3=newnode;
        }
    }
    while(ptr1!=NULL)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->next=NULL;
        newnode->info=ptr1->info;
        newnode->expo=ptr1->expo;
        ptr1=ptr1->next;
        if(res==NULL)
        {
            res=newnode;
            ptr3=newnode;
        }
        else
        {
            ptr3->next=newnode;
            ptr3=newnode;
        }
    }
    while(ptr2!=NULL)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->next=NULL;
        newnode->info= (-ptr2->info);
        newnode->expo=ptr2->expo;
        ptr2=ptr2->next;
        if(res==NULL)
        {
            res=newnode;
            ptr3=newnode;
        }
        else
        {
            ptr3->next=newnode;
            ptr3=newnode;
        }
    }
    return res;
}
int main()
{
    int d1,d2;
    printf("enter the degrre of 1st polynomial:");
    scanf("%d",&d1);
    poly1=create(d1, poly1);
    printf("enter the degrre of 1st polynomial:");
    scanf("%d",&d2);
    poly2=create(d2,poly2);
    printf("choose from the following operations:\n1.addition\n2.subtraction\n3.multiplication\n");
    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        res=add(poly1,poly2);
        break;
        case 2:
        res=sub(poly1,poly2);
        break;
        default:
        printf("invalid input");
        break;
    }
    printf("result : \n");
    traverse(res);
}
