#ifndef tree_h
#define tree_h
#include "node.h"
#include <limits.h>
#include <math.h>
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
	void PostOrder(Node<T> *root) const
	{
		if(root != 0)
		{
			PostOrder(root->right);
			cout<<root->data<<"; ";
			PostOrder(root->left);
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

	void Add(T value1, T value2, Node<T> *root)
	{
		if(root != 0)
		{
			if( Search(value1) )
			{
				if(value1 == root->data)
				{
					/*
					if(root->left != 0)
					{
						root->right = new Node<T>;
						root->right->data = value2;
						root->right->left = 0;
						root->right->right=0;
					}
					else
					{
						if(root->right != 0)
						{
							root->left = new Node<T>;
							root->left->data = value2;
							root->left->left = 0;
							root->left->right=0;
						}
					}*/
					
					Node<T> *n = new Node<T>;
					n->data = value2;
					n->left = 0;
					n->right = 0;

					if(root->left == 0)
					{
						root->left = n;	
					}
					else
					{
						if(root->right == 0)
						{
							root->right = n;
						}
					}
				}
				else
				{
					Add(value1,value2,root->left);
					Add(value1,value2,root->right);
				}
			}
		}
	};
	int Max = INT_MIN; // gan cho max gia tri nho nhat cua int;
	int SearchMax(Node<T> *root)
	{
		if(root != 0)
		{
			if(Max< root->data)
				Max = root->data;
			SearchMax(root->left);
			SearchMax(root->right);
		}
		return Max;
	};
	int NodeCount(Node<T> *root) // dem so node
	{
        if (root == 0)
        	return 0;
        else
        	return 1 + NodeCount(root->left) + NodeCount(root->right);
    }

    int HeightTree(Node<T> *root) // dem so tang
    {
    	if(root == 0)
    		return 0;
    	else
    		return 1 + max(HeightTree(root->left) , HeightTree(root->right));
    }

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
	void PostOrder() const
	{
		PostOrder(root);
		cout<<endl;
	};
	bool Search(T value)
	{
		return Search(value,root);
	};
	void Add(T value1, T value2)
	{
		Add(value1,value2,root);
	};
	int SearchMax()
	{
		return SearchMax(root);
	};
	int NodeCount()
	{
		return NodeCount(root);
	};
	int HeightTree()
	{
		return HeightTree(root);
	}
};
	
#endif