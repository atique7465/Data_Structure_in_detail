#include<bits/stdc++.h>
using namespace std;

struct node
{
    int roll;
    node *next;
};

int c=0;
node *root=NULL;

void append(int roll)
{
    if(root==NULL) ///if the list is empty
    {
        root=new node(); ///create new node in root
        root->roll=roll;
        root->next=NULL;
    }
    else
    {
        node *current_node=root; ///make a copy of root node
        while(current_node->next!=NULL)///find the last node
        {
            current_node=current_node->next; ///go to next address
        }
        node *newnode=new node(); ///create a new node
        newnode->roll=roll;
        newnode->next=NULL;
        current_node->next=newnode; ///link the last node with new node
    }
}

void append_middle(int roll_1, int roll_2)
{
    node *current_node=root;
	while(current_node->roll!=roll_1) ///Searching node
	{
		current_node=current_node->next;
	}

	node *newnode=new node();
	newnode->roll=roll_2;

	if(current_node==NULL)
    {
        current_node->next=newnode;
        newnode->next=NULL;
    }
    else
    {
        node *temp=current_node->next;
        current_node->next=newnode;
        newnode->next=temp;
        delete(temp);
    }
}

void delete_node(int roll)
{
	node *current_node=root;
	node *previous_node=NULL;
	while(current_node->roll!=roll) ///Searching node
	{
		previous_node=current_node; ///Save the previous node
		current_node=current_node->next;
	}
	if(current_node==root) ///Delete root
	{
		node *temp=root; ///save root in temporary variable
		root=root->next; ///move root forward
		delete(temp); ///free memory
	}
	else ///delete non-root node
	{
		previous_node->next=current_node->next; ///previous node points the current node's next node
		delete(current_node); ///free current node
	}

}

void print(node *root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->roll<<" ";
    print(root->next);
}

void print_reverse(node *root)
{
    if(root==NULL)
    {
        return;
    }
    print(root->next);
    cout<<root->roll<<" ";
}

void reverse(node *p)
{
    if(p->next==NULL)
    {
        if(c==0)
        {
            c=1;
            root=p;
        }
        return;
    }
    reverse(p->next);
    p->next->next=p;
    p->next=NULL;
}

int main(){
	append(1);
	append(2);
	append(6);
	append(5);
	append(10);
	print(root);
	print_reverse(root);
	cout<<endl;
	cout<<"delete 5"<<endl;
	delete_node(5);
	print(root);
	cout<<endl;
	append_middle(2,7);
	cout<<"append 7 after 2"<<endl;
	print(root);
	cout<<endl;
	append_middle(10,12);
	cout<<"append 12 after 10"<<endl;
	print(root);
	cout<<endl;
	delete_node(1);
	cout<<"delete 1"<<endl;
	print(root);
	cout<<endl;
	cout<<"reverse the list"<<endl;
	reverse(root);
	print(root);
    return 0;
}
