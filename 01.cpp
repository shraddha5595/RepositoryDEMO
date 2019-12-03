/*1. Insert Binary search tree using linked list and implement following functions
Insert a node
**Display ( Inorder, postorder, preorder ) using recursion
Display ( Inorder, postorder, preorder ) without using recursion. ( Create your own stack and make use of that )
**Delete a terminal node
**Delete a non terminal node
Search a node*/


#include<iostream>
using namespace std;

struct Node
{	
	Node *left;
	int data;
	Node *right;
};
class BinarySearchTree
{
	Node *root;
	public:
		BinarySearchTree();
		void insert(int);
		int remove();
		void inorder();
		void inorder(Node*);
		void preorder();
		void preorder(Node*);
		void postorder();
		void postorder(Node*);
		int remove(int);
};
BinarySearchTree::BinarySearchTree()
{
	root=NULL;
}

void BinarySearchTree::insert(int data)
{
	Node* newnode=new Node;
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	
	if(root==NULL)
	{
		root=newnode;
	}
	else
	{
		Node*trav=root;
		while(true)
		{
			if(newnode->data < trav->data)
			{
				if(trav->left==NULL)
				{
					trav->left=newnode;
					break;
				}
				else
					trav = trav->left;
			 }
			else if(newnode->data > trav->data)
			{
				if(trav->right==NULL)
				{
					trav->right=newnode;
					break;
				}
				else
					trav=trav->right;
			}
		}
	}
		

}
void BinarySearchTree::inorder()
{
	inorder(root);
}
void BinarySearchTree::inorder(Node *temp)
{
	
	if(temp!=NULL)
	{
		
		inorder(temp->left);
		cout<<temp->data<<" ";
		inorder(temp->right);
	}
	
	
}


void BinarySearchTree::preorder()
{
	preorder(root);
}
void BinarySearchTree::preorder(Node *temp)
{
	if(temp!=NULL)
	{
		cout<<temp->data<<" ";
		preorder(temp->left);		
		preorder(temp->right);
	}
}

void BinarySearchTree::postorder()
{
	postorder(root);
}
void BinarySearchTree::postorder(Node *temp)
{
	if(temp!=NULL)
	{
		postorder(temp->left);		
		postorder(temp->right);
		cout<<temp->data<<" ";
	}
}

int BinarySearchTree::remove(int data)
{
	
	int t;
	Node *parent =root, *temp=root, *trav=root;
	while(temp!=NULL)
	{
		if(temp->data==data)
		{
			t=temp->data;
			break;
		}
		else if(data<temp->data)
		{
			parent=temp;
			temp=temp->left;
		}
		else if(data>temp->data)
		{
			parent=temp;
			temp=temp->right;
		}
	}
	if(temp->left!=NULL && temp->right!=NULL)
	{
		trav=temp->right;
		parent=temp;
		while(trav->left!=NULL)
		{
			parent=trav;
			trav=trav->left;
		}
		temp->data=trav->data;
		temp=trav;
	}
	if(temp->left!=NULL && temp->right==NULL)
	{
		if(temp==parent->left)
		{
			parent->left=temp->left;
		}
		else if(temp==parent->right)
		{
			parent->right=temp->left;
		}
		delete temp;
	}
	else if(temp->left==NULL && temp->right!=NULL)
	{
		if(temp==parent->left)
		{
			parent->left=temp->right;
			
		}
		else if(temp==parent->right)
		{
			parent->right=temp->right;
		}
	}
	else if(temp->left==NULL && temp->right==NULL)
	{
		if(temp==parent->left)
		   parent->left=NULL;
		else if(temp==parent->right)
		    parent->right=NULL;
		delete temp;
	}
	return t;
}

int main()

{	int ch, data,n;
	BinarySearchTree bst;
	while(true)
	{
		cout<<"\n1.Insert\n2.Inorder\n3.Preorder\n4.Postorder\n5.Exit"<<endl;
		cout<<"Enter your choice:"<<endl;
		cin>>ch;
		
	switch(ch)
	{
		case 1:
			cout<<"Enter Numbers:"<<endl;
			cin>>n;
			bst.insert(n);
			break;
		case 2:
			 bst.inorder();
			 break;
		case 3:
			bst.preorder();
			break;
		case 4:
			bst.postorder();
			break;
		case 5:
			bst.remove(n);
		case 6:
			exit(0);
	}
  }
}
	
	
	
	
	

