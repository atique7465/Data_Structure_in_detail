/// RESOURCE 01: https://www.geeksforgeeks.org/construct-bst-from-given-preorder-traversa/
/// Time Complexity : O(n)


#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left,*right;
    node(int ch)
    {
        data = ch;
        left = right = NULL;
    }
};

int preIndex;
int length;

node* Built_Tree_Helper(int pre[],int key,int vmin,int vmax)
{
    if(preIndex>length-1)
        return NULL;

    node *RootNode = NULL;

    if(key>vmin && key<=vmax)
    {
        RootNode = new node(key);
        preIndex++;
        if(preIndex<=length-1)
        {
            RootNode->left =  Built_Tree_Helper(pre,pre[preIndex],vmin,key);
            RootNode->right =  Built_Tree_Helper(pre,pre[preIndex],key,vmax);
        }
    }
    return RootNode;
}

node* BuiltTree(int pre[])
{
    preIndex = 0;
    return Built_Tree_Helper(pre,pre[preIndex],INT_MIN,INT_MAX);
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
    cin>>length;

    int pre[length];
    cout<<"Enter the PreOrder Traversal of the tree : ";
    for(int i=0; i<length; i++)
        cin>>pre[i];

    node *root = BuiltTree(pre);

    cout<<endl<<"Resultant InOrder of the Tree : ";
    print_InOrder(root);
    cout<<endl<<"Resultant PretOrder of the Tree : ";
    print_PreOrder(root);

    return 0;
}

/*
input:
number of nodes :  6
pre : 10 5 1 7 40 50
*/


