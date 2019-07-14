//---------------------------------------------------------------------
/// stack implementation using dinamic array technique.
/// implemented operations : push(), pop(), top(), isempty() etc.
/// complexity of all operation is O(1).
//---------------------------------------------------------------------
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class Stack
{
private:
    ll *a;
    ll Top,length;

public:
    Stack(ll sz);
    ~Stack();

    void push(ll v);
    void pop();
    ll top();
    bool isempty();
    void show();
};

Stack::Stack(ll sz)
{
    cout<<"hi"<<endl;
    Top=-1;
    length=sz;
    a = new ll[length];
}

Stack::~Stack()
{
    delete [] a;
}

void Stack::push(ll v)
{
    if(Top == length-1)
    {   /// complexity O(n);
        ll *newa= new ll[length * 2];
        std::memcpy(newa, a, sizeof(ll)*length);
        /// or use a loop to copy element of a upto top to newa;
        /*for(ll i=0; i<=Top; i++)
            newa[i]=a[i];*/
        delete [] a;
        a = newa;
        length*= 2;
    }
    /// complexity O(1) otherwise;
    Top++;
    a[Top]=v;
}

void Stack::pop()
{
    if(Top == -1)
        cout<<"Cant pop cause The stack is empty"<<endl;
    else
        Top--;
}

ll Stack::top()
{
    if(Top == -1)
        return -999999999;
    else
        return a[Top];
}

bool Stack::isempty()
{
    if(Top == -1)
        return true;
    else
        return false;
}

void Stack::show()
{
    if(Top == -1)
        cout<<"the stack is empty"<<endl;
    else
    {
        for(int i = 0; i <= Top; i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }
}

int main()
{
    Stack s(5);
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
        cout<<"the stack is empty"<<endl;
    else
        cout<<"the stack is not empty"<<endl;
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
        cout<<"the stack is empty"<<endl;
    else
        cout<<"the stack is not empty"<<endl;
    s.push(45);
    cout<<s.top()<<endl;
    return 0;
}

