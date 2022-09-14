#include<vector>
#include<string>

class BinarySearchTree
{
private:
	struct tree_node
	{
		tree_node* left_node;
		tree_node* right_node;
		std::string question;
		int number;
	};
	tree_node* root;

public:
	BinarySearchTree()
	{
		root = nullptr;
	}
	void create_animal_tree();
	tree_node*create_tree_node(int number, std::string question);
	void connector(tree_node*&tem_tree_node, tree_node *&new_tree_node);
  void root_checker(tree_node *&new_tree_node);
  void tree_display(tree_node*&tem_tree_node);
  void choice(tree_node*& next_node, tree_node*& previews_node, int &loop_guard);
  int get_answer();
  void start_to_play();
  void add_node(tree_node *previous_node);
  void read_in_file(tree_node *tem_tree_node, std::fstream &out_file);
};
