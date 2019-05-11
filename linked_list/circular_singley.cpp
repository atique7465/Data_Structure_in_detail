#include<bits/stdc++.h>
using namespace std;

struct node
{
    int value;
    node *next;
};

node *head=NULL;
node *tail=NULL;

void insert_at_head(int value)
{
    node *newnode=new node();
    newnode->value=value;
    newnode->next=newnode;

    if(head==NULL)
    {
        head=newnode;
        tail=newnode;
    }
    else
    {
        newnode->next=head;
        tail->next=newnode;
        head=newnode;
    }
}

void insert_at_tail(int value)
{
    node *newnode=new node();
    newnode->value=value;
    newnode->next=newnode;

    if(head==NULL)
    {
        head=newnode;
        tail=newnode;
    }
    else
    {
        tail->next=newnode;
        newnode->next=head;
        tail=newnode;
    }
}

void insert_at_middle(int value, int position)
{
    if(position==1)
    {
        insert_at_head(value);
        return;
    }
    else
    {
        node *current_node=head;
        int i=1;
        ///find the immediate previous node of desired position
        while((i<position-1) && current_node->next!=head)
        {
            current_node=current_node->next;
            i++;
        }
        if(current_node->next==head)
        {
            insert_at_tail(value);
            return;
        }
        ///assigning the new node value, next and linking in list
        node *newnode=new node();
        newnode->value=value;
        newnode->next=current_node->next;
        current_node->next=newnode;
        delete(current_node);
        return;
    }
    cout<<"position does not exist!"<<endl;
}

void delete_head()
{
    if(head==NULL)
        return;
    else
    {
        node *temp=head;
        tail->next=head->next;
        head=head->next;
        delete(temp);
    }
}

void delete_tail()
{
    if(head==NULL)
        return;
    else
    {
        node *current_node=head;
        node *temp=tail;
        while(current_node->next!=tail)
        {
            current_node=current_node->next;
        }
        current_node->next=head;
        tail=current_node;
        delete(temp);
        delete(current_node);
    }
}

void delete_middle(int position)
{
    if(head==NULL)
        return;
    else if(position==1)
    {
        delete_head();
        return;
    }
    else
    {
        node *current_node=head;
        node *prev=NULL;
        int i=1;
        ///find the immediate previous node of desired position
        while((i<=position-1) && current_node->next!=head)
        {
            prev=current_node;
            current_node=current_node->next;
            i++;
        }
        if(current_node->next==head)
        {
            delete_tail();
            return;
        }
        ///assigning the new node value, next and linking in list

        prev->next=current_node->next;
        delete(current_node);
        return;
    }
    cout<<"position does not exist!"<<endl;
}

int get_length()
{
    if(head==NULL)
        return 0;
    else
    {
        node *current=head;
        int c=1;
        while(current->next!=head)
        {
            c++;
            current=current->next;
        }
        return c;
    }
}

void print_list()
{
    if(head==NULL)
        return;
    else
    {
        node *current=head;
        if(get_length()==1)
            cout<<current->value<<" ";
        while(current->next!=head)
        {
            cout<<current->value<<" ";
            current=current->next;
            if(current==tail)
                cout<<current->value<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int a = 5, b = 15, c = 43, d = 23, e = 12, f = 66, g = 99, h =65, i = 20, j = 8;
    int pos = 2, insertMidValue = 500, deletePos = 5;

    printf("Insert at head: %d\n", a);
    insert_at_head(a);

    printf("\nUpdated Full list:\n");
    print_list();

    printf("\nUpdated list length:\n");
    cout<<get_length()<<endl;

    printf("\nInsert at tail: %d, %d, %d\n", b, c, d);
    insert_at_tail(b);
    insert_at_tail(c);
    insert_at_tail(d);

    printf("\nUpdated list length:\n");
    cout<<get_length()<<endl;

    printf("\nUpdated Full list:\n");
    print_list();

    printf("\nDelete HEAD\n");
    delete_head();

    printf("\nUpdated Full list:\n");
    print_list();

    printf("\nInsert at head: %d\n", e);
    insert_at_head(e);

    printf("\nUpdated Full list:\n");
    print_list();

    printf("\nInsert at POSITION: %d, VALUE: %d\n", pos, insertMidValue);
    insert_at_middle(insertMidValue, pos);

    printf("\nUpdated Full list:\n");
    print_list();

    printf("\nDelete TAIL\n");
    delete_tail();

    printf("\nUpdated Full list:\n");
    print_list();

    printf("\nInsert at tail: %d, %d, %d\n", f, g, h);
    insert_at_tail(f);
    insert_at_tail(g);
    insert_at_tail(h);

    printf("\nUpdated Full list:\n");
    print_list();

    printf("\nDelete from POSITION: %d\n", deletePos);
    delete_middle(deletePos);

    printf("\nUpdated Full list:\n");
    print_list();

    return 0;
}
