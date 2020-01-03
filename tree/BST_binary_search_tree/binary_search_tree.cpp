#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left,*right;
};

node* get_newnode(int data)
{
    node* newnode=new node();
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}

node* insert(node* root,int data)
{
    if(root==NULL)
        root=get_newnode(data);

    else if(data <= root->data)
        root->left=insert(root->left,data);

    else
        root->right=insert(root->right,data);

    return root;
}

bool search(node *root,int data) ///search a specific value
{
    if(root==NULL)
        return false;
    else if(root->data==data)
        return true;
    else if(data <= root->data)
        return search(root->left,data);
    else
        return search(root->right,data);
}

node* Find(node* root, int data) ///Find a Specific data address.
{
    if(root==NULL)
        return NULL;
    else if(root->data==data)
        return root;
    else if(data <= root->data)
        return Find(root->left,data);
    else
        return Find(root->right,data);
}

int find_min(node* root)
{
    if(root==NULL)
    {
        cout<<"error: the tree is empty"<<endl;
        return -1;
    }
    else if(root->left==NULL)
        return root->data;

    return find_min(root->left);
}

node* min_node(node* root) ///return min valued node.
{
    if(root==NULL)
    {
        root=NULL;
        return root;
    }
    else if(root->left==NULL)
        return root;

    return min_node(root->left);
}

int find_max(node* root)
{
    if(root==NULL)
    {
        cout<<"error: the tree is empty"<<endl;
        return -1;
    }
    else if(root->right==NULL)
        return root->data;

    return find_max(root->right);
}

int find_height(node* root) ///complexity O(n).
{
    if(root==NULL)
        return -1;
    return max(find_height(root->left),find_height(root->right))+1;
}

void level_order_traverse(node* root) ///Breath First Traverse
{
    if(root==NULL)
        return;
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        node* cur=q.front();
        cout<<cur->data<<" ";
        if(cur->left!=NULL)
            q.push(cur->left);
        if(cur->right!=NULL)
            q.push(cur->right);
        q.pop();
    }
}

void preorder(node* root) ///Depth First Traverse
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node* root) ///Depth First Traverse
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(node* root) ///Depth First Traverse
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

bool BST(node* root,int min_value,int max_value)
{
    if(root==NULL)
        return true;
    if((root->data > min_value) && (root->data <= max_value) && BST(root->left,min_value,root->data) && BST(root->right,root->data,max_value))
        return true;
    else
        return false;
}

bool IsBST(node* root)
{
    return BST(root,INT_MIN,INT_MAX);
}

///BST checking by in order traversal.
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

node* delete_node(node* root, int data)
{
    if(root==NULL)
        return root;
    else if(data < root->data)
        root->left=delete_node(root->left,data);
    else if(data > root->data)
        root->right=delete_node(root->right,data);
    else /// wohoo, i found you.now ready to be deleted ... haha....
    {
        ///case 1: node has no child
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            root=NULL;
        }
        ///case 2: node has one child
        else if(root->left==NULL)
        {
            node* temp=root;
            root=root->right;
            delete temp;
        }
        else if(root->right==NULL)
        {
            node* temp=root;
            root=root->left;
            delete temp;
        }
        ///case 3: node has two child
        else
        {
            node* temp=min_node(root->right);
            root->data=temp->data;
            root->right=delete_node(root->right,temp->data);
        }
    }
    return root;
}

int Find_Inorder_Successor(node* root, int data)
{
    node* current=Find(root,data);
    if(current==NULL)
        return NULL;

    ///case 01: if the data has right subtree.
    if(current->right != NULL)
    {
        return find_min(current->right);
    }

    ///case 02: if data has no right subtree.
    else
    {
        node* ancestor=root;
        node* successor=NULL;
        while(ancestor != current)
        {
            if(current->data < ancestor->data)
            {
                successor=ancestor;
                ancestor=ancestor->left;
            }
            else
                ancestor=ancestor->right;
        }
        return successor->data;
    }
}

void top_view(node* root)
{
    if(root==NULL)
        return;
    map<int, int > m;
    queue<pair<node*, int> > q;

    q.push(make_pair(root,0));
    while(!q.empty())
    {
        pair<node*,int>p=q.front();
        node* n=p.first;
        int val=p.second;
        q.pop();
        if(m.find(val)==m.end())
        {
            m.insert(make_pair(val,n->data));
            //m[val]=n->data; ///i can also use it.
            //cout<<val<<" "<<n->data<<endl;
            // v.push_back(n->data);
        }
        if(n->left!=NULL)
            q.push(make_pair(n->left,val-1));
        if(n->right!=NULL)
            q.push(make_pair(n->right,val+1));
    }
    for (auto const& pair: m)
    {
        //std::cout << "{" << pair.first << ": " << pair.second << "}\n";
        std::cout <<pair.second <<" ";
    }
}

int lca(node *root, int v1,int v2)
{
    // Write your code here.
    if(root==NULL)
        return NULL;

    else if(root->data > v1 && root->data > v2)
        return lca(root->left,v1,v2);

    else if(root->data < v1 && root->data < v2)
        return lca(root->right,v1,v2);

    return root->data;
}


void vertical_order_traversing(node* root)
{
    if(root==NULL)
        return;
    map<int, vector<int> > m;
    queue<pair<node*, int> > q;

    q.push(make_pair(root,0));
    while(!q.empty())
    {
        pair<node*,int>p=q.front();
        node* n=p.first;
        int val=p.second;
        q.pop();
        m[val].push_back(n->data);

        if(n->left!=NULL)
            q.push(make_pair(n->left,val-1));
        if(n->right!=NULL)
            q.push(make_pair(n->right,val+1));
    }
    map< int,vector<int> > :: iterator it;
    for (it=m.begin(); it!=m.end(); it++)
    {
        for (int i=0; i<it->second.size(); ++i)
            cout << it->second[i] << " ";
        cout << endl;
    }
}

int main()
{
    node *root=NULL;
    root=insert(root,15);
    //111 root=insert(root,10);
    root=insert(root,20);
    root=insert(root,25);
    root=insert(root,10);
    root=insert(root,10);
    root=insert(root,8);
    root=insert(root,12);
    root=insert(root,19);

    cout<<"search a number: ";
    int nm;
    cin>>nm;
    if(search(root,nm))
        cout<<"found"<<endl;
    else
        cout<<"not found"<<endl;
    cout<<"the minimum value is :"<<endl;
    int x=find_min(root);
    cout<<x<<endl;
    cout<<"the maximum value is :"<<endl;
    int y=find_max(root);
    cout<<y<<endl;
    cout<<"height of the tree :"<<endl;
    int h=find_height(root);
    cout<<h<<endl;
    cout<<"level order traverse :"<<endl;
    level_order_traverse(root);
    cout<<endl;
    cout<<"PreOrder Traverse :"<<endl;
    preorder(root);
    cout<<endl;
    cout<<"InOrder Traverse :"<<endl;
    inorder(root);
    cout<<endl;
    cout<<"postOrder Traverse :"<<endl;
    postorder(root);
    cout<<endl;
    cout<<"Binary Search Tree ! :";
    if(IsBST(root))
        cout<<"YES"<<endl;
    else
        cout<<"NOT"<<endl;
    cout<<"Delete 15."<<endl;
    delete_node(root,15);
    cout<<"InOrder Traverse :"<<endl;
    inorder(root);
    cout<<endl;
    //cout<<"Find the successor of 20 -> ";
    //cout<<Find_Inorder_Successor(root,20)<<endl;
    cout<<"The TOP VIEW of the tree :"<<endl;
    //top_view(root);
    cout<<"Vertical Order Traversing of the tree :"<<endl;
    vertical_order_traversing(root);
    cout<<"the lca of 8 and 12 is :"<<endl;
    cout<<lca(root,8,12)<<endl;
    return 0;
}
