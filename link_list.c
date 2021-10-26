#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *nd;
void new()
{
    char ch;
    struct node *newnode,*temp;
    nd=0;
    do
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter data :: ");
        scanf("%d",&newnode->data);
        if(nd==0)
        {   
            nd=temp=newnode;
            newnode=NULL;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
        printf("If you want to enter an another vakue into linklist. Press Y\t");
        scanf("%c",ch);
    }while(ch=='Y'||ch=='y');
}
void disp()
{
    struct node *temp;
    temp=nd;
    //newnode->next=
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
}
int main()
{
    new();
    disp();
    return 0;
}
