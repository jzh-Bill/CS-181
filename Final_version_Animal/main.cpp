#include<iostream>
#include<cstdlib>
#include<string>
#include"bintree.h"
#include"useful.h"
using namespace std;

void ask_and_move(binary_tree_node<string>*& current_ptr);
binary_tree_node<string>* beginning_tree();
void instruct();
void learn(binary_tree_node<string>*& leaf_ptr);
void play(binary_tree_node<string>* current_ptr);

int main() {
	binary_tree_node<string>* animal_root_ptr;
	instruct();
	animal_root_ptr = beginning_tree();
	do
		play(animal_root_ptr);
	while (inquire("Do u wants  to play again?"));
	cout << "Welcome to play next time." << endl;
	return EXIT_SUCCESS;
	while (1);
}
void instruct() {
	cout << "lets start the game." << endl;
	cout << "Let me guess the animal." << endl;
}
void ask_and_move(binary_tree_node<string>*& current_ptr) {
	cout << current_ptr->data();//输出问题
	if (inquire("Plz answer it:")) {
		current_ptr = current_ptr->left();
	}
	else
		current_ptr = current_ptr->right();
}
//创建二叉树
binary_tree_node<string>* beginning_tree(){
	binary_tree_node<string>* root_ptr;//头节点指针
	binary_tree_node<string>* child_ptr;//孩子节点指针
	const string root_question("Are you a mammal");
	const string left_question("Bigger than cat, right?");
	const string right_question("Is it living in water?");
	const string animal_1("kangaroo?");
	const string animal_2("mouse");
	const string animal_3("Tilapia");
	const string animal_4("Magpie");

	//根节点
	root_ptr = new binary_tree_node<string>(root_question);//头节点指针指向新创建的节点问题

	//左子树
	child_ptr = new binary_tree_node<string>(left_question);//左孩子问题
	child_ptr->set_left(new binary_tree_node<string>(animal_1));
	child_ptr->set_right(new binary_tree_node<string>(animal_2));

	root_ptr->set_left(child_ptr);//将根节点的左节点设置为子节点的左节点

	//右子树
	child_ptr = new binary_tree_node<string>(right_question);
	child_ptr->set_left(new binary_tree_node<string>(animal_3));
	child_ptr->set_right(new binary_tree_node<string>(animal_4));

	root_ptr->set_right(child_ptr);//将根节点的右节点设置为子节点的右节点
	return root_ptr;
}
void learn(binary_tree_node<string>*& leaf_ptr) {
	string guess_animal;
	string correct_animal;
	string new_question;
	guess_animal = leaf_ptr->data();
	cout << "Ok, I don't know what it is, or do you tell me? "<< endl;
	getline(cin, correct_animal);
	cout << "Now please enter a new question to distinguish.";
	cout <<'['<<correct_animal<<']'<< " and " << '['<<guess_animal<<']' << endl;
	getline(cin, new_question);
	leaf_ptr->set_data(new_question);
	cout<<correct_animal << "," << new_question << endl;
	if (inquire("Plz answer it")) {//如果回答的是正确的则做节点
		leaf_ptr->set_left(new binary_tree_node<string>(correct_animal));
		leaf_ptr->set_right(new binary_tree_node<string>(guess_animal));
	}
	else {
		leaf_ptr->set_left(new binary_tree_node<string>(guess_animal));
		leaf_ptr->set_right(new binary_tree_node<string>(correct_animal));
	}
}
void play(binary_tree_node<string>* current_ptr) {
	cout << "You imagine an animal in your mind, think about it and press Enter.";
	eat_line();//等待，直到按下回车
	while (!current_ptr->is_leaf())//如果不是叶子节点就执行ask_and_remove（）函数，因为是叶子节点就直接输出最后猜测的结果
		ask_and_move(current_ptr);
	cout << ("Is it" + current_ptr->data()+"?");
	if (!inquire(",am I right?"))//询问是否猜对，否，将该动物添加到二叉树中
		learn(current_ptr);
	else
		cout << "Nice,gg" << endl;

}
