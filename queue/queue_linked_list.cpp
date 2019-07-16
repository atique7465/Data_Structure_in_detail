//---------------------------------------------------------------------
/// what pushed first poped first. FIFO.
/// queue implementation using linked list technique.
/// implemented operations : push(), pop(), front(), isempty(), show() etc.
/// complexity of all operation is O(1).
//---------------------------------------------------------------------

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

struct node
{
    ll data;
    node *next;
};

class Queue
{
private:
    node *frnt,*rear;
public:
    Queue();
    void push(ll v);
    void pop();
    ll Front();
    void show();
    bool isempty();
};

Queue::Queue()
{
    frnt=rear=NULL;
}

void Queue::push(ll v)
{
    node *newnode=new node;
    newnode->data=v;
    newnode->next=NULL;
    if(frnt==NULL && rear==NULL)
        frnt=rear=newnode;
    else
    {
        rear->next=newnode;
        rear=rear->next;
    }
}

void Queue::pop()
{
    if(frnt==NULL && rear==NULL)
        cout<<"Nothing to pop cause queue is empty"<<endl;
    else if(frnt==rear)
        frnt=rear=NULL;
    else
    {
        node *tmp=frnt;
        frnt=frnt->next;
        delete(tmp);
    }
}

ll Queue::Front()
{
    if(frnt==NULL)
    {
        cout<<"returned a gurbase value cause queue is empty : ";
        return -9999999;
    }
    else
        return frnt->data;
}

bool Queue::isempty()
{
    if(frnt==NULL && rear==NULL)
        return true;
    else
        return false;
}

void Queue::show()
{
    if(frnt==NULL && rear==NULL)
        cout<<"Nothing to show cause queue is empty"<<endl;
    else
    {
        node *curr=frnt;
        while(curr!=NULL)
        {
            cout<<curr->data<<" ";
            curr=curr->next;
        }
        cout<<endl;
    }
}

int main()
{
    Queue s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.show();
    cout<<s.Front()<<endl;
    s.pop();
    s.pop();
    cout<<s.Front()<<endl;
    if(s.isempty())
        cout<<"the stack is empty"<<endl;
    else
        cout<<"the stack is not empty"<<endl;
    s.show();
    s.push(10);
    s.push(12);
    s.push(13);
    s.show();
    s.push(14);
    s.show();
    cout<<s.Front()<<endl;
    s.pop();
    cout<<s.Front()<<endl;
    s.pop();
    cout<<s.Front()<<endl;
    s.push(10000);
    s.show();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    cout<<s.Front()<<endl;
    s.pop();
    s.show();
    if(s.isempty())
        cout<<"the stack is empty"<<endl;
    else
        cout<<"the stack is not empty"<<endl;
    s.push(45);
    cout<<s.Front()<<endl;
}
