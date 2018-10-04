#include <iostream>
using namespace std;
#include "tree.h"
int main()
{
	Tree<int> t1;
	//Tree<int> t2;

	t1.AddChild(50);
	t1.AddChild(40);
	t1.AddChild(70);
	t1.AddChild(60);
	t1.AddChild(80);
	t1.PreOrder();
	cout<<t1.FindMax()<<endl;
	//t2.PreOrder();
	//t1.DeleteNode(80);
	t1.PreOrder();
	cout<<t1.NodeCount()<<endl;
	cout<<t1.HeightTree()<<endl;
	//t1.PostOrder();
	//cout<<t1.Search(4)<<endl;
	return 0;
}