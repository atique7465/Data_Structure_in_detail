/// RESOURCE 01: https://www.geeksforgeeks.org/print-postorder-from-given-inorder-and-preorder-traversals/
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

int preIndex = 0;
vector<char>post;

void find_post_Helper(char in[],char pre[],map<char,int>& m,int inStart,int inEnd)
{
    if(inStart>inEnd) /// needed for imbalanced binary tree only
        return;

    char ch = pre[preIndex++];

    if(inStart != inEnd)
    {
        int inIndex = m[ch];

        find_post_Helper(in,pre,m,inStart,inIndex-1);
        find_post_Helper(in,pre,m,inIndex+1,inEnd);
    }
    post.push_back(ch);
}

void find_post(char in[],char pre[],int length)
{
    map<char,int>m;
    for(int i=0; i<length; i++)
        m[in[i]]=i;

    find_post_Helper(in,pre,m,0,length-1);
}

void print_post()
{
    for(int i=0; i<post.size(); i++)
        cout<<post[i]<<" ";
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

    char pre[length];
    cout<<"Enter the PreOrder Traversal of the tree : ";
    for(int i=0; i<length; i++)
        cin>>pre[i];

    find_post(in,pre,length);

    cout<<endl<<"Resultant PostOrder of the Tree : ";
    print_post();

    return 0;
}

/*
input:
number of nodes :  7
in : 4 2 5 1 6 3 7
pre : 1 2 4 5 3 6 7
result post: 4 5 2 6 7 3 1
*/

