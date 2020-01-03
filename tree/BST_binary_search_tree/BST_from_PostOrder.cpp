/// RESOURCE 01: https://www.geeksforgeeks.org/construct-a-binary-search-tree-from-given-postorder/
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

int postIndex;

node* Built_Tree_Helper(int post[],int key,int vmin,int vmax)
{
    if(postIndex<0)
        return NULL;

    node *RootNode = NULL;

    if(key>vmin && key<=vmax)
    {
        RootNode = new node(key);
        postIndex--;
        if(postIndex>=0)
        {
            RootNode->right =  Built_Tree_Helper(post,post[postIndex],key,vmax);
            RootNode->left =  Built_Tree_Helper(post,post[postIndex],vmin,key);
        }
    }
    return RootNode;
}

node* BuiltTree(int post[],int length)
{
    postIndex = length -1;
    return Built_Tree_Helper(post,post[postIndex],INT_MIN,INT_MAX);
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

    int post[length];
    cout<<"Enter the PostOrder Traversal of the tree : ";
    for(int i=0; i<length; i++)
        cin>>post[i];

    node *root = BuiltTree(post,length);

    cout<<endl<<"Resultant InOrder of the Tree : ";
    print_InOrder(root);
    cout<<endl<<"Resultant PostOrder of the Tree : ";
    print_PostOrder(root);

    return 0;
}

/*
input:
number of nodes :  6
post : 1 5 7 50 40 10
*/

