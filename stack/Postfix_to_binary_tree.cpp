/// resource 01: https://www.geeksforgeeks.org/expression-tree/

#include<bits/stdc++.h>
using namespace std;

struct node
{
    string data;
    node *left,*right;
    node(string s)
    {
        data = s;
        left = right = NULL;
    }
};

bool isOperator(char ch)
{
    return ch=='+' || ch=='-' || ch=='*' || ch=='/';
}

node* built_tree(string postfix)
{
    stack<node*>s;
    for(int i=0; i<postfix.size(); i++)
    {
        if(postfix[i]==' '|| postfix[i]=='_')
            continue;

        else if(isOperator(postfix[i]))
        {
            string help = "";
            help+=postfix[i];
            node *root_node = new node(help);
            root_node->right = s.top();
            s.pop();
            root_node->left = s.top();
            s.pop();
            s.push(root_node);
        }
        else
        {
            string operand = "";
            while(i<postfix.size() && postfix[i]!='_')
            {
                operand+=postfix[i];
                i++;
            }
            i--;
            node *cur = new node(operand);
            s.push(cur);
        }
    }
    return s.top();
}

void print_infix(node* root)
{
    if(root==NULL)
        return;
    print_infix(root->left);
    cout<<root->data<<" ";
    print_infix(root->right);
}

void print_postfix(node* root)
{
    if(root==NULL)
        return;
    print_postfix(root->left);
    print_postfix(root->right);
    cout<<root->data<<" ";
}

int main()
{
    string postfix;
    cout<<"Enter the postfix expression : ";
    cin>>postfix;

    node *root = built_tree(postfix);

    cout<<endl<<"Resultant Infix : ";
    print_infix(root);
    cout<<endl<<"Resultant PostFix : ";
    print_postfix(root);

    return 0;
}

/*
input1: 31_52_9.3_+_2.5_*_+
Resultant Infix : 31 + 52 + 9.3 * 2.5
Resultant PostFix : 31 52 9.3 + 2.5 * +

input2: 3_5_9_+_2_*_+
Resultant Infix : 3 + 5 + 9 * 2
Resultant PostFix : 3 5 9 + 2 * +

input2: 1_2_3_*_+_4_5_*_+
Resultant Infix : 1 + 2 * 3 + 4 * 5
Resultant PostFix : 1 2 3 * + 4 5 * +
*/

