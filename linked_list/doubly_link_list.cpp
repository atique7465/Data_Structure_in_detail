#include<bits/stdc++.h>
using namespace std;

struct node
{
    int value;
    node *next, *prev;
};

node *head=NULL;
node *tail=NULL;

void append_at_tail(int value)
{
    node *newnode=new node();
    if(head==NULL) ///if the list is empty
    {
        newnode->value=value;
        newnode->next=NULL;
        newnode->prev=NULL;
        head=newnode;
        tail=newnode;
    }
    else
    {
        newnode->value=value;
        tail->next=newnode;
        newnode->prev=tail;
        newnode->next=NULL;
        tail=newnode;
    }
}

void append_at_head(int value)
{
    node *newnode=new node();
    if(head==NULL) ///if the list is empty
    {
        newnode->value=value;
        newnode->next=NULL;
        newnode->prev=NULL;
        head=newnode;
        tail=newnode;
    }
    else
    {
        head->prev=newnode;
        newnode->next=head;
        newnode->prev=NULL;
        head=newnode;
    }
}

void append_at_middle(int value, int position)
{
    node *newnode=new node();

    if(position==0 || head==NULL)
    {
        newnode->value=value;
        newnode->next=NULL;
        newnode->prev=NULL;
        head=newnode;
        tail=newnode;
    }
    else
    {
        node *current_node=head;
        int i=1;
        ///find the immediate previous node of desired position
        while((i<position-1) && current_node!=NULL)
        {
            current_node=current_node->next;
            i++;
        }
        ///assigning the new node value, next and prev
        newnode->value=value;
        newnode->next=current_node->next;
        newnode->prev=current_node;

        ///linking new node in the list
        current_node->next->prev=newnode;
        current_node->next=newnode;
    }
}

void delete_node(int value)
{
    node *current_node=head;
    int i=1;
    ///find the position of our value
    while(current_node->value!=value)
    {
        current_node=current_node->next;
    }
    if(current_node==head)
    {
        node *temp=head;
        head=current_node->next;
        current_node->next->prev=NULL;
        delete(temp);
        delete(current_node);
    }
    else if(current_node==tail)
    {
        node *temp=tail;
        tail=current_node->prev;
        current_node->prev->next=NULL;
        delete(temp);
        delete(current_node);
    }
    else
    {
        ///linking the list at deleted position
        current_node->prev->next=current_node->next;
        current_node->next->prev=current_node->prev;
        delete(current_node);
    }
}


void PrintForward()
{
    cout<<"The linked list in Forward order: "<<endl;
    node *list=head;
    while(1)
    {
        if(head==NULL || tail==NULL)
            break;
        cout<<list->value<<" ";
        if(list==tail)
            break;
        list=list->next;
    }
    cout<<endl;
}

void PrintReverse()
{
    cout<<"The linked list in Reverse order: "<<endl;
    node *list=tail;
    while(1)
    {
        if(head==NULL || tail==NULL)
            break;
        cout<<list->value<<" ";
        if(list==head)
            break;
        list=list->prev;
    }
    cout<<endl;
}

int main()
{
    append_at_head(1);
    append_at_tail(8);
    append_at_tail(10);
    append_at_middle(5,2);
    append_at_middle(7,3);
    PrintForward();
    PrintReverse();
    delete_node(8);
    PrintForward();
    PrintReverse();
    return 0;
}
