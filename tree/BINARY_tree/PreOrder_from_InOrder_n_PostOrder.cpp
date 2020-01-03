/// RESOURCE 01: https://www.geeksforgeeks.org/preorder-from-inorder-and-postorder-traversals/
/// Time Complexity : O(n)

#include<bits/stdc++.h>
using namespace std;

struct node
{
    char data;
    node *left,*right;
    node(char ch)
    {
        data = ch;
        left = right = NULL;
    }
};

int postIndex;
stack<char>pre;

void find_pre_Helper(char in[],char post[],map<char,int>& m,int inStart,int inEnd)
{
    if(inStart>inEnd) /// needed for imbalanced binary tree only
        return;

    char ch = post[postIndex--];

    if(inStart != inEnd)
    {
        int inIndex = m[ch];

        find_pre_Helper(in,post,m,inIndex+1,inEnd);
        find_pre_Helper(in,post,m,inStart,inIndex-1);
    }
    pre.push(ch);
}

void find_pre(char in[],char post[],int length)
{
    postIndex = length -1;
    map<char,int>m;
    for(int i=0; i<length; i++)
        m[in[i]]=i;

    find_pre_Helper(in,post,m,0,length-1);
}

void print_PreOrder()
{
    while(!pre.empty())
    {
        cout<<pre.top()<<" ";
        pre.pop();
    }
}
int main()
{
    cout<<"Enter the number of nodes: ";
    int length;
    cin>>length;

    char in[length];
    cout<<"Enter the InOrder Traversal of the tree : ";
    for(int i=0; i<length; i++)
        cin>>in[i];

    char post[length];
    cout<<"Enter the PostOrder Traversal of the tree : ";
    for(int i=0; i<length; i++)
        cin>>post[i];

    find_pre(in,post,length);

    cout<<endl<<"Resultant PreOrder of the Tree : ";
    print_PreOrder();

    return 0;
}

/*
input:
number of nodes :  7
in : 4 2 5 1 6 3 7
post: 4 5 2 6 7 3 1
resultant pre : 1 2 4 5 3 6 7
*/

