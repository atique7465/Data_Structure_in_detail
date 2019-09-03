/// RESOURCE 01: https://www.geeksforgeeks.org/construct-tree-from-given-inorder-and-preorder-traversal/
/// RESOURCE 02: https://www.youtube.com/watch?v=PoBGyrIWisE

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

node* Built_Tree_Helper(char in[],char pre[],map<char,int>& m,int inStart,int inEnd)
{
    if(inStart>inEnd)
        return NULL;

    node *RootNode = new node(pre[preIndex++]);

    if(inStart == inEnd)
        return RootNode;

    int inIndex = m[RootNode->data];

    RootNode->left =  Built_Tree_Helper(in,pre,m,inStart,inIndex-1);
    RootNode->right =  Built_Tree_Helper(in,pre,m,inIndex+1,inEnd);

    return RootNode;
}

node* BuiltTree(char in[],char pre[],char length)
{
    map<char,int>m;
    for(int i=0; i<length; i++)
        m[in[i]]=i;

    return Built_Tree_Helper(in,pre,m,0,length-1);
}

void print_InOrder(node *root)
{
    if(root == NULL)
        return;
    print_InOrder(root->left);
    cout<<root->data<<" ";
    print_InOrder(root->right);
}

void print_PreOrder(node *root)
{
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    print_PreOrder(root->left);
    print_PreOrder(root->right);
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

    node *root = BuiltTree(in,pre,length);

    cout<<endl<<"Resultant InOrder of the Tree : ";
    print_InOrder(root);
    cout<<endl<<"Resultant PreOrder of the Tree : ";
    print_PreOrder(root);

    return 0;
}
