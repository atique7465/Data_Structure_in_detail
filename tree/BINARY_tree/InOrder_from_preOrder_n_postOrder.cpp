#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left, *right;
    node(int v)
    {
        data = v;
        left = right = NULL;
    }
};

int preIndex;
vector<int>inorder;

void Find_InOrder_Helper(int pre[], int post[], map<int,int>m, int start, int finish)
{
    if(start > finish)
        return;

    int value = pre[preIndex++];

    if(start != finish)
    {
        int postIndex = m[pre[preIndex]];
        Find_InOrder_Helper(pre, post, m, start, postIndex);
        inorder.push_back(value);
        Find_InOrder_Helper(pre, post, m, postIndex + 1, finish - 1);
    }
    else
        inorder.push_back(value);
}

void Find_InOrder(int pre[], int post[], int start, int finish)
{
    map<int,int>m;
    for(int i=0; i<=finish; i++)
        m[post[i]] = i;
    preIndex = 0;
    return Find_InOrder_Helper(pre,post,m,start,finish);
}

void Print_InOrder()
{
    for(int i=0; i<inorder.size(); i++)
        cout<<inorder[i]<<" ";
}

int main()
{
    int n;
    cin>>n;
    int pre[n];
    for(int i=0; i<n; i++)
        cin>>pre[i];

    int post[n];
    for(int i=0; i<n; i++)
        cin>>post[i];

    Find_InOrder(pre,post,0,n-1);

    cout<<"InOrder : ";
    Print_InOrder();

    return 0;
}

/*
input:
number of nodes :  7
pre : 1 2 4 5 3 6 7
post: 4 5 2 6 7 3 1
InOrder : 4 2 5 1 6 3 7
*/
