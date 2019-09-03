/// RESOURCE 01: https://www.geeksforgeeks.org/full-and-complete-binary-tree-from-given-preorder-and-postorder-traversals/
/// RESOURCE 02: https://www.youtube.com/watch?v=5lWJpTEnyow
/// Time Complexity : O(n)
/// the code will work for both balanced & imbalanced binary tree
/// for balanced tree it will produce unique binary tree
/// for imbalanced tree it will produce ambiguous but valid binary tree

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

int preIndex;

node* Built_Tree_Helper(char pre[],char post[],map<char,int>& m,int postStart,int postEnd)
{
    if(postStart>postEnd) /// needed for imbalanced binary tree only
        return NULL;

    node *RootNode = new node(pre[preIndex++]);

    if(postStart == postEnd)
        return RootNode;

    int postIndex = m[pre[preIndex]]; /// partition based on next preorder value;

    RootNode->left =  Built_Tree_Helper(pre,post,m,postStart,postIndex);
    RootNode->right =  Built_Tree_Helper(pre,post,m,postIndex+1,postEnd-1);

    return RootNode;
}

node* BuiltTree(char pre[],char post[],int length)
{
    preIndex = 0;
    map<char,int>m;
    for(int i=0; i<length; i++)
        m[post[i]]=i;

    return Built_Tree_Helper(pre,post,m,0,length-1);
}

void print_PreOrder(node *root)
{
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    print_PreOrder(root->left);
    print_PreOrder(root->right);
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

    char pre[length];
    cout<<"Enter the PreOrder Traversal of the tree : ";
    for(int i=0; i<length; i++)
        cin>>pre[i];

    char post[length];
    cout<<"Enter the PostOrder Traversal of the tree : ";
    for(int i=0; i<length; i++)
        cin>>post[i];

    node *root = BuiltTree(pre,post,length);

    cout<<endl<<"Resultant PreOrder of the Tree : ";
    print_PreOrder(root);
    cout<<endl<<"Resultant PostOrder of the Tree : ";
    print_PostOrder(root);

    return 0;
}

/*
input: 01 (balanced binary tree)
number of nodes :  9
pre : 1 2 4 8 9 5 3 6 7
post : 8 9 4 5 2 6 7 3 1

input: 02 (not balanced binary tree)
number of nodes :  9
pre : F B A D C E G I H
post : A C E D B H I G F

input: 03 (balanced binary tree)
number of nodes :  11
pre : F B A D C E G I H K J
post : A C E D B H K I J G F
*/
