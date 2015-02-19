template <class T>
class BTree
{
	struct Node
	{
		T value;
		Node parent;
		Node *left;
		Node *right;

		Node(T val, Node parent):value(val),left(nullptr),right(nullptr){}
	};
	Node *root;
	Node find(T target);
	int insert(T val);
};
