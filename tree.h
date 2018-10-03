#ifndef tree_h
#define tree_h
#include "node.h"
template <class T>
class Tree
{
private:
	Node<T> *root;
	void AddChild(T value, Node<T> *root)
	{
		if(value<root->data) // neu phan tu them vao nho hon node goc thi them vao ben trai
		{
			if(root->left != 0)
				AddChild(value, root->left);
			else
			{
				root->left = new Node<T>;
				root->left->data = value;
				root->left->left = 0;
				root->left->right=0;
			}
		}
		else
		{
			if(value>root->data) // neu phan tu them vao lon hon node goc thi them vao ben trai
			{
				if(root->right != 0)
					AddChild(value,root->right);
				else
				{
					root->right = new Node<T>;
					root->right->data = value;
					root->right->left = 0;
					root->right->right = 0;
				}
			}
		}
	};
	void PreOrder(Node<T> *root) const
	{
		if(root != 0)
		{
			PreOrder(root->left);
			cout<<root->data<<"; ";
			PreOrder(root->right);
		}
	};
	void InOrder(Node<T> *root) const
	{
		if(root != 0)
		{
			cout<<root->data<<"; ";
			InOrder(root->left);
			InOrder(root->right);
		}
	};
	bool Search(T value, Node<T> *root)
	{
			if(root == 0)
				return false;
			if(root->data == value)
				return true;
			if(root->data<value)
				return Search(value,root->right);
			if(root->data>value)
				return Search(value,root->left);	
	};
public:
	Tree()
	{
		root = 0;
	};
	void  AddChild(T value)
	{
		if(root == 0)
		{
			Node<T> *n = new Node<T>;
			n->data = value;
			n->left = 0;
			n->right = 0;
			root = n;
		}
		else
		{
			AddChild(value, root);
		}
	};
	void PreOrder() const
	{
		PreOrder(root);
		cout<<endl;
	};
	void InOrder() const
	{
		InOrder(root);
		cout<<endl;
	};
	bool Search(T value)
	{
		return Search(value,root);
	};
};
	
#endif