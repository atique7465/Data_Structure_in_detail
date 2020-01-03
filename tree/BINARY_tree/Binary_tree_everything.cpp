/// ----------------------------------------------------------------------------------------------------------------------------------
//  Resource : https://www.youtube.com/watch?v=JCBsWzE6o90&list=PLjhq5EHRYAeLdh0xtn2v7wbQsVc8WAB2e
//  Atiqur Rahman
//  2-1-2020;
/// ----------------------------------------------------------------------------------------------------------------------------------

#include<bits/stdc++.h>
using namespace std;

struct node
{
    int value;
    node *left,*right;
    node(int v)
    {
        value = v;
        left = right = NULL;
    }
};

class binary_tree
{
private:
    queue<pair<node*,int> >last_node;

public:
    node *root;
    void insert(int v);
    void InOrder_recursive(node *r);
    void PreOrder_recursive(node *r);
    void PostOrder_recursive(node *r);
    void InOrder_Iterative();
    void PreOrder_Iterative();
    void PostOrder_Iterative();
    void level_order_traverse();
    void vertical_order_traverse();
    void top_view();
    void bottom_view();
    void right_view();
    void left_view();
    void diagonal_view();
    int height_of_tree(node* r);
    int number_of_nodes(node* r);
    int number_of_leaf_nodes(node* r);
    void leaf_nodes(node* r);
    void left_boundary_traverse(node* r);
    void right_boundary_traverse(node* r);
    void boundary_traverse();
    void spiral_level_order_travesre();
    void create_mirror_tree(node* r);
};

void binary_tree::insert(int v)
{
    node *NewNode = new node(v);
    if(last_node.empty())
        root = NewNode;

    else if(last_node.front().second == 0)
    {
        if(NewNode->value != -1)
            last_node.front().first->left = NewNode;
        last_node.front().second++;
    }

    else
    {
        if(NewNode->value != -1)
            last_node.front().first->right = NewNode;
        last_node.pop();
    }
    if(v != -1)
        last_node.push(make_pair(NewNode,0));
}

void binary_tree::InOrder_recursive(node* r) ///DFS
{
    if(r == NULL)
        return;
    InOrder_recursive(r->left);
    cout<<r->value<<" ";
    InOrder_recursive(r->right);
}

void binary_tree::PreOrder_recursive(node* r) ///DFS
{
    if(r == NULL)
        return;
    cout<<r->value<<" ";
    PreOrder_recursive(r->left);
    PreOrder_recursive(r->right);
}

void binary_tree::PostOrder_recursive(node* r) ///DFS
{
    if(r == NULL)
        return;
    PostOrder_recursive(r->left);
    PostOrder_recursive(r->right);
    cout<<r->value<<" ";
}

void binary_tree::InOrder_Iterative()
{
    if(root == NULL)
        return;

    stack<node*>s;
    node *curr = root;
    while((curr != NULL) || (!s.empty()))
    {
        if(curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        else
        {
            cout<<s.top()->value<<" ";
            curr = s.top()->right;
            s.pop();
        }
    }
}

void binary_tree::PreOrder_Iterative()
{
    if(root == NULL)
        return;

    stack<node*>s;
    node *curr = root;
    while((curr != NULL) || (!s.empty()))
    {
        if(curr != NULL)
        {
            cout<<curr->value<<" ";
            s.push(curr);
            curr = curr->left;
        }
        else
        {
            curr = s.top()->right;
            s.pop();
        }
    }
}

void binary_tree::PostOrder_Iterative()
{
    if(root == NULL)
        return;

    stack<int>res;
    stack<node*>s;
    node *curr = root;
    while((curr != NULL) || (!s.empty()))
    {
        if(curr != NULL)
        {
            res.push(curr->value);
            s.push(curr);
            curr = curr->right;
        }
        else
        {
            curr = s.top()->left;
            s.pop();
        }
    }
    while(!res.empty())
    {
        cout<<res.top()<<" ";
        res.pop();
    }
}

void binary_tree::level_order_traverse() ///BFS
{
    if(root == NULL)
        return;
    queue<node*>Q;
    Q.push(root);
    while(!Q.empty())
    {
        cout<<Q.front()->value<<" ";
        if(Q.front()->left != NULL)
            Q.push(Q.front()->left);
        if(Q.front()->right != NULL)
            Q.push(Q.front()->right);
        Q.pop();
    }
}

void binary_tree::vertical_order_traverse()
{
    if(root == NULL)
        return;

    queue< pair<node*,int> >q;
    map<int, vector<int> >m;
    q.push(make_pair(root,0));

    while(!q.empty())
    {
        pair<node*,int> r = q.front();
        q.pop();
        m[r.second].push_back(r.first->value);
        if(r.first->left != NULL)
            q.push(make_pair(r.first->left, r.second - 1));
        if(r.first->right != NULL)
            q.push(make_pair(r.first->right, r.second + 1));
    }
    map<int, vector<int> >::iterator it;
    for(it = m.begin(); it!=m.end(); it++)
    {
        for(int i = 0; i<it->second.size(); i++)
            cout<<it->second[i]<<" ";
    }
}

void binary_tree::top_view()
{
    if(root == NULL)
        return;

    map<int, int > m;
    queue< pair<node*,int> >q;
    q.push(make_pair(root,0));

    while(!q.empty())
    {
        pair<node*,int> r = q.front();
        q.pop();
        if(!m.count(r.second))
            m[r.second] = r.first->value;
        if(r.first->left != NULL)
            q.push(make_pair(r.first->left, r.second - 1));
        if(r.first->right != NULL)
            q.push(make_pair(r.first->right, r.second + 1));
    }
    map<int, int>::iterator it;
    for(it=m.begin(); it!=m.end(); it++)
        cout<<it->second<<" ";
}

void binary_tree::bottom_view()
{
    if(root == NULL)
        return;

    map<int, int > m;
    queue< pair<node*,int> >q;
    q.push(make_pair(root,0));

    while(!q.empty())
    {
        pair<node*,int> r = q.front();
        q.pop();
        m[r.second] = r.first->value;
        if(r.first->left != NULL)
            q.push(make_pair(r.first->left, r.second - 1));
        if(r.first->right != NULL)
            q.push(make_pair(r.first->right, r.second + 1));
    }
    map<int, int>::iterator it;
    for(it=m.begin(); it!=m.end(); it++)
        cout<<it->second<<" ";
}

void binary_tree::right_view() /// or, i can traverse in level order and print the last one from map of every level like bottom view code.
{
    if(root == NULL)
        return;

    queue<node*>q;
    q.push(root);
    int c;
    while(!q.empty())
    {
        c = q.size();
        while(c>0)
        {
            c--;
            if(c == 0)
                cout<<q.front()->value<<" ";
            if(q.front()->left != NULL)
                q.push(q.front()->left);
            if(q.front()->right != NULL)
                q.push(q.front()->right);
            q.pop();
        }
    }
}

void binary_tree::left_view() /// or, i can traverse in level order and print the first one from map of every level like top view code.
{
    if(root == NULL)
        return;

    queue<node*>q;
    q.push(root);
    int c;
    while(!q.empty())
    {
        c = q.size();
        cout<<q.front()->value<<" ";
        while(c>0)
        {
            c--;
            if(q.front()->left != NULL)
                q.push(q.front()->left);
            if(q.front()->right != NULL)
                q.push(q.front()->right);
            q.pop();
        }
    }
}

void binary_tree::diagonal_view()
{
    if(root == NULL)
        return;

    queue< pair<node*,int> >q;
    map<int, vector<int> >m;
    q.push(make_pair(root,0));

    while(!q.empty())
    {
        pair< node*, int > r = q.front();
        q.pop();
        m[r.second].push_back(r.first->value);
        if(r.first->left != NULL)
            q.push(make_pair(r.first->left,r.second + 1));
        if(r.first->right != NULL)
            q.push(make_pair(r.first->right,r.second));
    }
    map<int, vector<int> >::iterator it;
    for(it=m.begin(); it!=m.end(); it++)
    {
        for(int i=0; i<it->second.size(); i++)
            cout<<it->second[i]<<" ";
        cout<<endl;
    }
}

int binary_tree::height_of_tree(node* r)
{
    if(r == NULL)
        return -1;
    int h1 = height_of_tree(r->left);
    int h2 = height_of_tree(r->right);
    return max(h1,h2) + 1;
}

int binary_tree::number_of_nodes(node* r) /// or, we can implement  in iterative way using level order traversal.
{
    if(r == NULL)
        return 0;
    int n1 = number_of_nodes(r->left);
    int n2 = number_of_nodes(r->right);
    return n1 + n2 + 1;
}

int binary_tree::number_of_leaf_nodes(node* r)
{
    if(r == NULL)
        return 0;
    if(r->left == NULL && r->right == NULL)
        return 1;

    int n1 = number_of_leaf_nodes(r->left);
    int n2 = number_of_leaf_nodes(r->right);
    return n1 + n2;
}

void binary_tree::leaf_nodes(node* r)
{
    if(r == NULL)
        return;
    if(r->left == NULL && r->right == NULL)
    {
        cout<<r->value<<" ";
        return;
    }
    leaf_nodes(r->left);
    leaf_nodes(r->right);
}

void binary_tree::left_boundary_traverse(node* r)
{
    if(r == NULL)
        return;
    if(r->left == NULL && r->right == NULL)
        return;

    cout<<r->value<<" ";
    left_boundary_traverse(r->left);
}

void binary_tree::right_boundary_traverse(node* r)
{
    if(r == NULL)
        return;
    if(r->left == NULL && r->right == NULL)
        return;

    right_boundary_traverse(r->right);
    cout<<r->value<<" ";
}

void binary_tree::boundary_traverse()
{
    left_boundary_traverse(root);
    leaf_nodes(root);
    right_boundary_traverse(root->right);
}

void binary_tree::spiral_level_order_travesre()
{
    if(root == NULL)
        return;

    stack<node*>s1;
    stack<node*>s2;
    s1.push(root);

    while(!s1.empty() || !s2.empty())
    {
        while(!s1.empty())
        {
            cout<<s1.top()->value<<" ";
            if(s1.top()->left != NULL)
                s2.push(s1.top()->left);
            if(s1.top()->right != NULL)
                s2.push(s1.top()->right);
            s1.pop();
        }

        while(!s2.empty())
        {
            cout<<s2.top()->value<<" ";
            if(s2.top()->right != NULL)
                s1.push(s2.top()->right);
            if(s2.top()->left != NULL)
                s1.push(s2.top()->left);
            s2.pop();
        }
    }
}

void binary_tree::create_mirror_tree(node* r)
{
    if(r == NULL)
        return;
    create_mirror_tree(r->left);
    create_mirror_tree(r->right);
    node* tmp = r->left;
    r->left = r->right;
    r->right = tmp;
}

int main()
{
    binary_tree tree;
    int n,v;
    cout<<"Enter The Number of Elements : ";
    cin>>n;
    cout<<endl<<"Enter The Tree Elements : "; /// -1 as NULL
    for(int i=1; i<=n; i++)
    {
        cin>>v;
        tree.insert(v);
    }

    cout<<endl<<"Inorder Recursive : ";
    tree.InOrder_recursive(tree.root);
    cout<<endl;

    cout<<"Inorder Iterative : ";
    tree.InOrder_Iterative();
    cout<<endl<<endl;

    cout<<"Preorder Recursive : ";
    tree.PreOrder_recursive(tree.root);
    cout<<endl;

    cout<<"Preorder Iterative : ";
    tree.PreOrder_Iterative();
    cout<<endl<<endl;

    cout<<"Postorder Recursive : ";
    tree.PostOrder_recursive(tree.root);
    cout<<endl;

    cout<<"Postorder Iterative : ";
    tree.PostOrder_Iterative();
    cout<<endl<<endl;

    cout<<"Level Order Traverse : ";
    tree.level_order_traverse();
    cout<<endl<<endl;

    cout<<"Vertical Order Traverse : ";
    tree.vertical_order_traverse();
    cout<<endl<<endl;

    cout<<"Top View : ";
    tree.top_view();
    cout<<endl<<endl;

    cout<<"Bottom View : ";
    tree.bottom_view();
    cout<<endl<<endl;

    cout<<"Right View : ";
    tree.right_view();
    cout<<endl<<endl;

    cout<<"Left View : ";
    tree.left_view();
    cout<<endl<<endl;

    cout<<"Diagonal View : "<<endl;
    tree.diagonal_view();
    cout<<endl<<endl;

    cout<<"Height of the Tree : "<<tree.height_of_tree(tree.root);
    cout<<endl<<endl;

    cout<<"Number of nodes in the Tree : "<<tree.number_of_nodes(tree.root);
    cout<<endl<<endl;

    cout<<"Number of leaf nodes in the Tree : "<<tree.number_of_leaf_nodes(tree.root)<<endl;
    cout<<"The leaf nodes are : ";
    tree.leaf_nodes(tree.root);
    cout<<endl<<endl;

    cout<<"Boundary Traverse : ";
    tree.boundary_traverse();
    cout<<endl<<endl;

    cout<<"Spiral Level Order Traverse : ";
    tree.spiral_level_order_travesre();
    cout<<endl;

    cout<<endl<<"Inorder Traverse before mirror : ";
    tree.InOrder_recursive(tree.root);
    cout<<endl;
    tree.create_mirror_tree(tree.root);
    cout<<"Inorder Traverse after mirror : ";
    tree.InOrder_recursive(tree.root);
    cout<<endl;
    tree.create_mirror_tree(tree.root);
    cout<<"Inorder Traverse after mirror again: ";
    tree.InOrder_recursive(tree.root);
    cout<<endl;


    return 0;
}

/*
INPUT:
21
1 2 3 4 5 -1 6 -1 -1 9 8 -1 7 10 -1 -1 -1 -1 -1 11 -1
-----------------------------------------------------
The Tree looks:
                   1
                /     \
              2         3
            /   \         \
           4       5         6
                /     \         \
              9         8         7
            /
          10
        /
      11
-----------------------------------------------------

OUTPUT:
Enter The Number of Elements : 21

Enter The Tree Elements : 1 2 3 4 5 -1 6 -1 -1 9 8 -1 7 10 -1 -1 -1 -1 -1 11 -1

Inorder Recursive : 4 2 11 10 9 5 8 1 3 6 7
Inorder Iterative : 4 2 11 10 9 5 8 1 3 6 7

Preorder Recursive : 1 2 4 5 9 10 11 8 3 6 7
Preorder Iterative : 1 2 4 5 9 10 11 8 3 6 7

Postorder Recursive : 4 11 10 9 8 5 2 7 6 3 1
Postorder Iterative : 4 11 10 9 8 5 2 7 6 3 1

Level Order Traverse : 1 2 3 4 5 6 9 8 7 10 11

Vertical Order Traverse : 11 4 10 2 9 1 5 3 8 6 7

Top View : 11 4 2 1 3 6 7

Bottom View : 11 10 9 5 8 6 7

Right View : 1 3 6 7 10 11

Left View : 1 2 4 9 10 11

Diagonal View :
1 3 6 7
2 5 8
4 9
10
11

Height of the Tree : 5

Number of nodes in the Tree : 11

Number of leaf nodes in the Tree : 4
The leaf nodes are : 4 11 8 7

Boundary Traverse : 1 2 4 11 8 7 6 3

Spiral Level Order Traverse : 1 3 2 4 5 6 7 8 9 10 11

Inorder Traverse before mirror : 4 2 11 10 9 5 8 1 3 6 7
Inorder Traverse after mirror : 7 6 3 1 8 5 9 10 11 2 4
Inorder Traverse after mirror again: 4 2 11 10 9 5 8 1 3 6 7
*/
