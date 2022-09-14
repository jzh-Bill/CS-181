template<class T>
class BinarySearchTree
{
private:
	struct tree_node
	{
	  int number;
		tree_node* left;
		tree_node* right;
		T data;
	};
	tree_node* root;
public:
	BinarySearchTree()
	{
		root = NULL;
	}
	/*bool isEmpty() const { return root==NULL; }
	void print_inorder();
	void inorder(tree_node*);
	void print_preorder();
	void preorder(tree_node*);
	void print_postorder();
	void postorder(tree_node*);
	*/
};

