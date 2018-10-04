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
				Node<T> *n = new Node<T>;
				n->data = value;
				n->left = 0;
				n->right = 0;
				root->left = n;
				/*
				root->left = new Node<T>;
				root->left->data = value;
				root->left->left = 0;
				root->left->right=0;*/
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
					Node<T> *n = new Node<T>;
					n->data = value;
					n->left = 0;
					n->right = 0;
					root->right = n;
					/*
					root->right = new Node<T>;
					root->right->data = value;
					root->right->left = 0;
					root->right->right = 0;*/
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
	bool Search(T value, Node<T> *root) const
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
	int NodeCount(Node<T> *root) const // dem so node
	{
        if (root == 0)
        	return 0;
        else
        	return 1 + NodeCount(root->left) + NodeCount(root->right);
    };

    int HeightTree(Node<T> *root) const// dem so tang
    {
    	if(root == 0)
    		return 0;
    	else
    		return 1 + max(HeightTree(root->left) , HeightTree(root->right));
    }
    T FindMin(Node<T> *root) // tim thang con nho nhat trong cay: tim ben trai la ra
    {
       	if(root == 0)
    		return INT_MIN;
    	if(root->left != 0)
    		return FindMin(root->left);
    	return root->data;
    };
    T FindMax(Node<T> *root)
    {
    	if(root == 0)
    		return INT_MAX;
    	if(root->right != 0)
    		return FindMax(root->right);
    	return root->data;
    };

    bool DeleteNode(T value, Node<T> *root, Node<T> *p) // p la node tam chuyen vao = 0
    {
    	if(root == 0)
    		return false;
    	if(root->data == value)
    	{
    		if(root -> left == 0 || root ->right ==0)
    		{
    			Node<T>* temp = root ->left;
    			if(root->right != 0)
    				temp == root->right;
    			if(p != 0)
    			{
    				if(p->left == root)// p la parent: cha cua thang can xoa
    				{
    					Node<T>* n = p->left; 
    					p->left = temp; // Truong hop thang ben delete thang ben trai
    					delete n;
    				}
    				else
    				{
    					Node<T>* n = p->right;
    					p->right = temp; //Truong hop thang ben delete thang ben phai
    					delete n;
    				}
    			}
    			else
    			{
    				Node<T>* n = root;
    				root = temp;
    				delete n;
    			}
    		}
    		else
    		{
    			Node<T>* valSub = root ->right; // thang ke nhiem
    			while (valSub ->left) // tim thang be nhat ben phai lam ke nhiem de thoai man left< cha < right;
    			{ 
    				valSub = valSub->left; 
    			}
    			T temp = root -> data;
    			root->data = valSub->data; // hoan vi thang ke nhiem vao node can xoa, node can xoa vao vi tri ke nhiem
    			valSub->data = temp;
    			return DeleteNode(temp,root->right,root); // Xoa node can xoa tai vi tri ke nhiem
    		}
    		//delete root;
    		return true;
    	}
    	return DeleteNode(value,root->left, root) || DeleteNode(value, root->right, root);
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
	void PostOrder() const
	{
		PostOrder(root);
		cout<<endl;
	};
	bool Search(T value) const
	{
		return Search(value,root);
	};
	void Add(T value1, T value2)
	{
		Add(value1,value2,root);
	};
	int SearchMax() const
	{
		return SearchMax(root);
	};
	int NodeCount() const
	{
		return NodeCount(root);
	};
	int HeightTree() const
	{
		return HeightTree(root);
	}
	bool DeleteNode(T value)
	{
		return DeleteNode(value,root, 0);
	};
	T FindMax()
	{
		return FindMax(root);
	};
	T FindMin()
	{
		return FindMin(root);
	};
};
	
#endif