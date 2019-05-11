#include<bits/stdc++.h>
using namespace std;

struct node
{
    int value;
    node *next,*prev;
};

node *head=NULL;
node *tail=NULL;

void insert_at_head(int value)
{
    node *newnode= new node();
    newnode->value=value;
    newnode->next=newnode;
    newnode->prev=newnode;

    if(head==NULL)
    {
        head=newnode;
        tail=newnode;
    }
    else
    {
        head->prev=newnode;
        newnode->next=head;
        newnode->prev=tail;
        tail->next=newnode;
        head=newnode;
    }
}

void insert_at_tail(int value)
{
    node *newnode= new node();
    newnode->value=value;
    newnode->next=newnode;
    newnode->prev=newnode;

    if(head==NULL)
    {
        head=newnode;
        tail=newnode;
    }
    else
    {
        tail->next=newnode;
        newnode->next=head;
        newnode->prev=tail;
        head->prev=newnode;
        tail=newnode;
    }
}

void insert_at_middle(int value,int position)
{
    if(position==1)
    {
        insert_at_head(value);
        return;
    }
    else if(position>1 && head!=NULL)
    {
        node *current=head;
        int i=1;
        while((i<position-1) && current->next!=head)
        {
            current=current->next;
            i++;
        }
        if(current->next==head)
        {
            insert_at_tail(value);
            return;
        }
        else
        {
            node *newnode=new node();
            newnode->value=value;
            newnode->next=current->next;
            newnode->prev=current;
            current->next->prev=newnode;
            current->next=newnode;
            return;
        }
    }
}

void delete_head()
{
    if(head==NULL)
        return;

    node *temp = head;
    tail->next = head->next;
    head = head->next;
    head->prev = tail;

    delete(temp);
}

void delete_tail()
{
    if(head==NULL)
        return;

    node *temp = head;
    node *current = head;

    while(current->next != head)
    {
        temp = current;
        current = current->next;
    }

    temp->next = head;
    tail = temp;
    head->prev = tail;
    delete(current);
}

void delete_at_middle(int position)
{
    if(head==NULL)
        return;
    else if(position==1)
    {
        delete_head();
        return;
    }
    else if(position>1 && head!=NULL)
    {
        node *current=head;
        int i=1;
        while((i<=position-1) && current->next!=head)
        {
            current=current->next;
            i++;
        }
        if(current->next==head)
        {
            delete_tail();
            return;
        }
        else
        {
            current->prev->next=current->next;
            current->next->prev=current->prev;
            delete(current);
            return;
        }
    }
}

int getListLength()
{
    if(head==NULL)
        return 0;

    int count = 0;
    node *current = head;

    do
    {
        count++;
        current = current->next;
    }
    while(current != head);

    return count;
}

void print_forward_order()
{
    if(head==NULL)
        return;

    node *current = head;

    do
    {
        printf("%d ", current->value);
        current = current->next;
    }
    while(current != head);

    printf("\nList Length: %d\n", getListLength());
}

void print_reverse_order()
{
    if(head==NULL)
        return;

    node *current = tail;

    do
    {
        printf("%d ", current->value);
        current = current->prev;
    }
    while(current != tail);

    printf("\nList Length: %d\n", getListLength());
    puts("\n");
}

void print_list()
{
    printf("FORWARD order print:\n");
    print_forward_order();

    printf("REVERSE order print:\n");
    print_reverse_order();
}

int main()
{
    int a = 5, b = 15, c = 43, d = 23, e = 12, f = 66, g = 99, h =65, i = 20, j = 8;
    int pos = 2, insertMidValue = 500, deletePos = 5;

    printf("Insert at head: %d\n", a);
    insert_at_head(a);
    print_list();

    printf("Insert at tail: %d, %d, %d\n", b, c, d);
    insert_at_tail(b);
    insert_at_tail(c);
    insert_at_tail(d);
    print_list();

    printf("Delete HEAD\n");
    delete_head();
    print_list();

    printf("Insert at head: %d\n", e);
    insert_at_head(e);
    print_list();

    printf("Insert at POSITION: %d, VALUE: %d\n", pos, insertMidValue);
    insert_at_middle(insertMidValue, pos);
    print_list();

    printf("Delete TAIL\n");
    delete_tail();
    print_list();

    printf("Insert at tail: %d, %d, %d\n", f, g, h);
    insert_at_tail(f);
    insert_at_tail(g);
    insert_at_tail(h);
    print_list();

    printf("Delete from POSITION: %d\n", deletePos);
    delete_at_middle(deletePos);
    print_list();

    return 0;
}







