//---------------------------------------------------------------------
/// Stack implementation using dinamic array technique.
/// implemented operations : push(), pop(), Top(), isempty() etc.
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

class Stack
{
private:
    node *Top;
public:
    Stack();
    ~Stack();
    void push(ll v);
    void pop();
    ll top();
    void show();
    bool isempty();
};

Stack::Stack()
{
    Top = NULL;
}

Stack::~Stack()
{
    delete(Top);
}

void Stack::push(ll v)
{
    node *newnode=new node;
    newnode->data=v;
    newnode->next=NULL;
    if(Top!=NULL)
        newnode->next=Top;
    Top=newnode;
}

void Stack::pop()
{
    if(Top != NULL)
    {
        node *tmp = Top;
        Top=Top->next;
        delete(tmp);
    }
    else
        cout<<"Cant pop cause The stack is empty"<<endl;
}

ll Stack::top()
{
    return Top->data;
}

void Stack::show()
{
    if(Top!=NULL)
    {
        node *curr=Top;
        while(curr!=NULL)
        {
            cout<<curr->data<<" ";
            curr=curr->next;
        }
        cout<<endl;
    }
    else
        cout<<"Nothing to show cause The stack is empty"<<endl;
}

bool Stack::isempty()
{
    if(Top==NULL)
        return true;
    else
        return false;
}

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.show();
    cout<<s.top()<<endl;
    s.pop();
    s.pop();
    cout<<s.top()<<endl;
    if(s.isempty())
        cout<<"the Stack is empty"<<endl;
    else
        cout<<"the Stack is not empty"<<endl;
    s.show();
    s.push(10);
    s.push(12);
    s.push(13);
    s.push(14);
    s.show();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.push(10000);
    s.show();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.show();
    if(s.isempty())
        cout<<"the Stack is empty"<<endl;
    else
        cout<<"the Stack is not empty"<<endl;
    s.push(45);
    cout<<s.top()<<endl;
    return 0;
}
