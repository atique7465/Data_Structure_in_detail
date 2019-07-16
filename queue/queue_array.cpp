//---------------------------------------------------------------------
/// what pushed first poped first. FIFO.
/// queue implementation using dinamic array technique.
/// implemented operations : push(), pop(), front(), isempty(), show() etc.
/// complexity of all operation is O(1).
//---------------------------------------------------------------------

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class Queue
{
private:
    ll *a;
    ll frnt,rear,sz;
public:
    Queue();
    ~Queue();
    void push(ll v);
    void pop();
    ll Front();
    void show();
    bool isempty();
};

Queue::Queue()
{
    frnt=rear=-1;
    sz=5;
    a=new ll[5];
}

Queue::~Queue()
{
    delete [] a;
}

bool Queue::isempty()
{
    if(frnt==-1 && rear==-1)
        return true;
    else
        return false;
}

void Queue::push(ll v)
{
    if(frnt==-1 && rear==-1)
        frnt=rear=0;
    else if((rear+1)%sz==frnt)
    {   /// circular array technique used here to push new element to reduce memory waste.
        ll *newa=new ll[(rear-frnt+1)*2]; /// make a new array.
        ll i=0;
        ll j=frnt;
        while(j<=rear)
        {
            newa[i]=a[j%sz]; /// copy elements of previous array.
            i++;
            j++;
        }
        delete [] a;
        a=newa;
        frnt=0;
        rear=i;
        sz=2*(rear-frnt+1); /// updadate size, front, rear accordingly.
    }
    else
        rear++;
    a[rear%sz]=v;
}

void Queue::pop()
{
    if(frnt==-1 && rear==-1)
        cout<<"Nothing to pop cause queue is empty"<<endl;
    if(frnt==rear)
        frnt=rear=-1;
    else
        frnt+=1;
}

ll Queue::Front()
{
    if(frnt==-1 && rear==-1)
    {
        cout<<"A gurbage returned cause queue is empty : ";
        return -99999999;
    }
    else
        return a[frnt];
}

void Queue::show()
{
    if(frnt==-1 && rear==-1)
        cout<<"Nothing to show cause queue is empty"<<endl;
    else
    {
        ll i,j;
        i=frnt;
        j=rear;
        while(i<=j)
        {
            cout<<a[i%sz]<<" ";
            i++;
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
