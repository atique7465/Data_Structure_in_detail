/// RESOURCE 01: https://www.geeksforgeeks.org/construct-a-binary-tree-from-postorder-and-inorder/
/// RESOURCE 02: https://www.youtube.com/watch?v=s5XRtcud35E
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

node* Built_Tree_Helper(char in[],char post[],map<char,int>& m,int inStart,int inEnd)
{
    if(inStart>inEnd)
        return NULL;

    node *RootNode = new node(post[postIndex--]);

    if(inStart == inEnd)
        return RootNode;

    int inIndex = m[RootNode->data];

    RootNode->right =  Built_Tree_Helper(in,post,m,inIndex+1,inEnd);
    RootNode->left =  Built_Tree_Helper(in,post,m,inStart,inIndex-1);

    return RootNode;
}

node* BuiltTree(char in[],char post[],char length)
{
    postIndex = length -1;
    map<char,int>m;
    for(int i=0; i<length; i++)
        m[in[i]]=i;

    return Built_Tree_Helper(in,post,m,0,length-1);
}

void print_InOrder(node *root)
{
    if(root == NULL)
        return;
    print_InOrder(root->left);
    cout<<root->data<<" ";
    print_InOrder(root->right);
}

void print_PostOrder(node *root)
{
    if(root == NULL)
        return;
    print_PostOrder(root->left);
    print_PostOrder(root->right);
    cout<<root->data<<" ";
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

    node *root = BuiltTree(in,post,length);

    cout<<endl<<"Resultant InOrder of the Tree : ";
    print_InOrder(root);
    cout<<endl<<"Resultant PostOrder of the Tree : ";
    print_PostOrder(root);

    return 0;
}

/*
input:
number of nodes :  8
in : 4 8 2 5 1 6 3 7
post : 8 4 5 2 6 7 3 1
*/
