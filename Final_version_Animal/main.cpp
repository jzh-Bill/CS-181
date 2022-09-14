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
	cout << current_ptr->data();//�������
	if (inquire("Plz answer it:")) {
		current_ptr = current_ptr->left();
	}
	else
		current_ptr = current_ptr->right();
}
//����������
binary_tree_node<string>* beginning_tree(){
	binary_tree_node<string>* root_ptr;//ͷ�ڵ�ָ��
	binary_tree_node<string>* child_ptr;//���ӽڵ�ָ��
	const string root_question("Are you a mammal");
	const string left_question("Bigger than cat, right?");
	const string right_question("Is it living in water?");
	const string animal_1("kangaroo?");
	const string animal_2("mouse");
	const string animal_3("Tilapia");
	const string animal_4("Magpie");

	//���ڵ�
	root_ptr = new binary_tree_node<string>(root_question);//ͷ�ڵ�ָ��ָ���´����Ľڵ�����

	//������
	child_ptr = new binary_tree_node<string>(left_question);//��������
	child_ptr->set_left(new binary_tree_node<string>(animal_1));
	child_ptr->set_right(new binary_tree_node<string>(animal_2));

	root_ptr->set_left(child_ptr);//�����ڵ����ڵ�����Ϊ�ӽڵ����ڵ�

	//������
	child_ptr = new binary_tree_node<string>(right_question);
	child_ptr->set_left(new binary_tree_node<string>(animal_3));
	child_ptr->set_right(new binary_tree_node<string>(animal_4));

	root_ptr->set_right(child_ptr);//�����ڵ���ҽڵ�����Ϊ�ӽڵ���ҽڵ�
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
	if (inquire("Plz answer it")) {//����ش������ȷ�������ڵ�
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
	eat_line();//�ȴ���ֱ�����»س�
	while (!current_ptr->is_leaf())//�������Ҷ�ӽڵ��ִ��ask_and_remove������������Ϊ��Ҷ�ӽڵ��ֱ��������²�Ľ��
		ask_and_move(current_ptr);
	cout << ("Is it" + current_ptr->data()+"?");
	if (!inquire(",am I right?"))//ѯ���Ƿ�¶ԣ��񣬽��ö�����ӵ���������
		learn(current_ptr);
	else
		cout << "Nice,gg" << endl;

}
