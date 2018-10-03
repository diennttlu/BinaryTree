#include <iostream>
using namespace std;
#include "tree.h"
int main()
{
	Tree<int> t1;

	t1.AddChild(4);
	t1.AddChild(2);
	t1.AddChild(1);
	t1.AddChild(3);
	t1.AddChild(6);
	t1.AddChild(5);
	t1.AddChild(8);

	t1.PreOrder();
	t1.InOrder();

	cout<<t1.Search(4)<<endl;
	return 0;
}