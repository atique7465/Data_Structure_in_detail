#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left,*right;
    node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

class BST
{
public:
    node *root = NULL;

    node* insert(node *r, int value);
    bool search(node *r, int key);
    node* remove(node *r, int key);
    node* find_min_node(node* r);
    node* find_max_node(node* r);
    int find_height(node* r);
    bool IsBST(node* r);
    bool IsBST_util(node* r, int min_value, int max_value);
    int LCA_BST(node* r, int key_1, int key_2);
    int Find_Inorder_Successor(node* r, int key);
    node* find_node(node* r, int key);
    void InOrder_Traversal(node *r);
};

node* BST::insert(node* r, int value)
{
    if(r == NULL)
        r = new node(value);

    else if(value <= r->data)
        r->left = insert(r->left, value);
    else
        r->right = insert(r->right, value);

    return r;
}

bool BST::search(node* r, int key)
{
    if(r == NULL)
        return false;
    if(r->data == key)
        return true;

    if(key < r->data)
        return search(r->left,key);
    else
        return search(r->right,key);
}

node* BST::remove(node *r, int key)
{
    if(r == NULL)
        return r;

    if(key < r->data)
        r->left = remove(r->left, key);

    else if(key > r->data)
        r->right = remove(r->right, key);

    else  /// value detected. so initiate delete operation.
    {
        /// case 01: the node ha no child.
        if(r->left == NULL && r->right == NULL)
        {
            delete r;
            r = NULL;
        }

        /// case 02: the node has one child.
        else if(r->left == NULL)
        {
            node* tmp = r;
            r = r->right;
            delete tmp;
        }

        else if(r->right == NULL)
        {
            node* tmp = r;
            r = r->left;
            delete tmp;
        }

        /// case 03: the node has two child.
        else
        {
            r->data = find_min_node(r->right)->data;
            r->right = remove(r->right, r->data);
        }
    }
    return r;
}

node* BST::find_min_node(node* r)
{
    if(r == NULL)
        return r;
    else if(r->left == NULL)
        return r;
    return find_min_node(r->left);
}

node* BST::find_max_node(node* r)
{
    if(r == NULL)
        return r;
    else if(r->right == NULL)
        return r;
    return find_max_node(r->right);
}

int BST::find_height(node* r) ///complexity O(n).
{
    if(r == NULL)
        return -1;
    return max(find_height(r->left),find_height(r->right))+1;
}

bool BST::IsBST_util(node* r, int min_value, int max_value)
{
    if(r == NULL)
        return true;

    if(r->data > min_value && r->data <= max_value && IsBST_util(r->left,min_value,r->data) && IsBST_util(r->right, r->data, max_value))
        return true;
    else
        return false;
}

bool BST::IsBST(node* r)
{
    return IsBST_util(r,INT_MIN,INT_MAX);
}

///BST checking by in order traversal. good one.
/*int s=0;
bool IsBST(node* root)
{
    if(root==NULL)
        return true;
    IsBST(root->left);
    if(root->data >= s)
        s=root->data;
    else
        return false;
    IsBST(root->right);
}*/

int BST::LCA_BST(node* r, int key_1, int key_2)
{
    if(r == NULL)
        return NULL;

    if(r->data > key_1 && r->data > key_2)
        return LCA_BST(r->left, key_1, key_2);

    if(r->data < key_1 && r->data < key_2)
        return LCA_BST(r->right, key_1, key_2);

    return r->data;
}

node* BST::find_node(node* r, int key) ///Find a Specific data address.
{
    if(r == NULL)
        return NULL;
    else if(r->data == key)
        return r;
    else if(key <= r->data)
        return find_node(r->left,key);
    else
        return find_node(r->right,key);
}

int BST::Find_Inorder_Successor(node* r, int key)
{
    node* current = find_node(r,key);
    if(current == NULL)
        return NULL;

    ///case 01: if the data has right subtree.
    if(current->right != NULL)
    {
        return find_min_node(current->right)->data;
    }

    ///case 02: if data has no right subtree.
    else
    {
        node* ancestor = root;
        node* successor = NULL;
        while(ancestor != current)
        {
            if(current->data < ancestor->data)
            {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
                ancestor = ancestor->right;
        }
        return successor->data;
    }
}

void BST::InOrder_Traversal(node* r) ///DFS . Complexity O(n).
{
    if(r == NULL)
        return;
    InOrder_Traversal(r->left);
    cout<<r->data<<" ";
    InOrder_Traversal(r->right);
}

int main()
{
    BST tree;
    tree.root = tree.insert(tree.root,15);
    tree.root = tree.insert(tree.root,20);
    tree.root = tree.insert(tree.root,25);
    tree.root = tree.insert(tree.root,10);
    tree.root = tree.insert(tree.root,10);
    tree.root = tree.insert(tree.root,8);
    tree.root = tree.insert(tree.root,12);
    tree.root = tree.insert(tree.root,19);
    tree.root = tree.insert(tree.root,14);
    tree.root = tree.insert(tree.root,16);
    tree.root = tree.insert(tree.root,23);
    tree.root = tree.insert(tree.root,26);

    if(tree.IsBST(tree.root))
        cout<<"This Tree is a BST."<<endl;
    else
        cout<<"This Tree is not a BST."<<endl;

    cout<<"search a number: ";
    int nm;
    cin>>nm;
    if(tree.search(tree.root,nm))
        cout<<"found"<<endl;
    else
        cout<<"not found"<<endl;

    cout<<"Height of the BST is: "<<tree.find_height(tree.root)<<endl;

    cout<<"Max value in the BST is : "<<tree.find_max_node(tree.root)->data<<endl;

    cout<<"Min value in the BST is : "<<tree.find_min_node(tree.root)->data<<endl;

    cout<<"LCA of 10 & 12 is : "<<tree.LCA_BST(tree.root,10,12)<<endl;
    cout<<"LCA of 9 & 12 is : "<<tree.LCA_BST(tree.root,9,12)<<endl;
    cout<<"LCA of 16 & 26 is : "<<tree.LCA_BST(tree.root,16,26)<<endl;

    cout<<"InOrder Successor of 14 is : "<<tree.Find_Inorder_Successor(tree.root,14)<<endl;

    cout<<"InOrder Traversal : ";
    tree.InOrder_Traversal(tree.root);
    cout<<endl;

    tree.remove(tree.root,12);
    cout<<"InOrder Traversal after removing 12 : ";
    tree.InOrder_Traversal(tree.root);
    cout<<endl;

    tree.remove(tree.root,8);
    cout<<"InOrder Traversal after removing 8 : ";
    tree.InOrder_Traversal(tree.root);
    cout<<endl;

    tree.remove(tree.root,20);
    cout<<"InOrder Traversal after removing 20 : ";
    tree.InOrder_Traversal(tree.root);
    cout<<endl;

    return 0;
}

/* -----------------------------------------------
INPUT TREE LOOKS:

                15
             /      \
           10        20
          /  \     /    \
         10  12   19     25
        /     \   /     /  \
       8      14 16    23   26
-------------------------------------------------*/
