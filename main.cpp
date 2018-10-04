#include <iostream>
using namespace std;
#include "tree.h"
int main()
{
	Tree<int> t1;

	t1.AddChild(11);
	t1.AddChild(6);
	t1.AddChild(15);
	t1.Add(6,10);
	t1.Add(6,7);
	t1.Add(15,13);
	t1.PreOrder();
	t1.InOrder();
	cout<<t1.NodeCount()<<endl;
	cout<<t1.HeightTree()<<endl;
	//t1.PostOrder();
	//cout<<t1.Search(4)<<endl;
	return 0;
}