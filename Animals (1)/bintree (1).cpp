  #include "bintree.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

void BinarySearchTree::create_animal_tree()
{
     BinarySearchTree::tree_node *tem_tree_node = nullptr;
     int value;
     string question;
     string dummy;
     ifstream input_file;
     input_file.open("animals.txt");
     while(input_file >> value)
     {
       getline(input_file,dummy);
       getline(input_file,question);
       tem_tree_node = create_tree_node(value, question);
       root_checker(tem_tree_node);
       connector(root,tem_tree_node);
     }
     // tree_display(root);
     input_file.close();
}

BinarySearchTree::tree_node* BinarySearchTree::create_tree_node(int number, string question)
{
  tree_node *newnode = nullptr;
  newnode = new tree_node;
  newnode->number = number;
  newnode->question = question;
  newnode->left_node = nullptr;
  newnode->right_node = nullptr;
  return newnode;
}

void BinarySearchTree::connector(tree_node*&tem_tree_node, tree_node *&new_tree_node)
{
  const int TWO = 2;
  const int ONE = 1;

  if(tem_tree_node != nullptr)
  {
    if(TWO*(tem_tree_node->number) ==  new_tree_node->number)
    {
      tem_tree_node->left_node = new_tree_node;

      return;
    }
    if(TWO*(tem_tree_node->number) + ONE ==  new_tree_node->number)
    {
      tem_tree_node->right_node = new_tree_node;
      return;
    }
    if(TWO*(tem_tree_node->number) + ONE != new_tree_node->number )
    {
      connector(tem_tree_node->right_node,new_tree_node);
    }
    if(TWO*(tem_tree_node->number) !=  new_tree_node->number )
    {
      connector(tem_tree_node->left_node ,new_tree_node);
    }
  }
}

void BinarySearchTree::root_checker(tree_node *&new_tree_node)
{
  if(root == nullptr)
  {
    root = new_tree_node;
  }
}

void BinarySearchTree::tree_display(tree_node*&tem_tree_node)
{
  if(tem_tree_node)
  {
    cout << "The number is "<< tem_tree_node->number << " and the question is "<< tem_tree_node->question << endl;
    tree_display(tem_tree_node->left_node);
    tree_display(tem_tree_node->right_node);
  }
}

void BinarySearchTree::start_to_play()
{
  const int ONE = 1;
  tree_node *dummy_node = nullptr;
  int loop_guard = 1;
  do
  {
      cout << endl;
      choice(root,dummy_node,loop_guard);

  }while(loop_guard == ONE);

  fstream out_put_file;
  out_put_file.open("animals.txt");
  read_in_file(root, out_put_file);
  cout << "The animals binary tree has been saved in your original file. Have a good day!" << endl;
}

void BinarySearchTree::choice(tree_node*& next_node, tree_node*& previews_node, int &loop_guard)
{
  const unsigned ONE = 1;
  const unsigned ZERO = 0;
  previews_node = next_node;
  int user_choice;
  if(next_node->right_node == nullptr && next_node->left_node == nullptr)
  {
    cout << next_node->question << endl;
    cout << "Your answer: ";
    user_choice = get_answer();
    if(user_choice == ONE)
    {
      cout << "Nice, I got right answer!!!!!" << endl;
      cout << "Do you want to play again?" << endl;
      loop_guard = get_answer();
    }
    else if(user_choice == ZERO)
    {
      cout << "Ok, fine, I can't figure out what your animal is." << endl;
      add_node(previews_node);
      cout << "Do you want to play again?" << endl;
      loop_guard = get_answer();
    }
  }
  else
    {
      cout << "Question: " << next_node->question << endl;
      cout << "Your answer: ";
      user_choice = get_answer();
      if(user_choice == 0) // NO -> no_ans
        {
          choice(next_node->left_node, previews_node,loop_guard);
        }
      if(user_choice == 1) // YES -> yes_ans
        {
          choice(next_node->right_node, previews_node,loop_guard);
        }
    }
}

int BinarySearchTree::get_answer()
{
  const int ONE = 1;
  const int ZERO = 0;

    int number;
    string answer;
    cin.clear();
    getline(cin,answer);
    if(answer == "yes" || answer == "YES" || answer == "Yes")
    {
        return ONE;
    }
    else
    {
        if(answer == "No" || answer == "NO" || answer == "no")
        {
            return ZERO;
        }
        else
        {
            cout << "Please enter the valid answer, only yes or no!!!" << endl;
            return number = get_answer();
        }
    }
}

void BinarySearchTree::add_node(tree_node *previous_node)
{
  const int ONE = 1;
  const int TWO = 2;
  string is_it = "Is it ";
  string question_mark = "?";
  string new_a;
  string new_q;
  cout << "What is your animal in your mind? " << endl;
  getline(cin, new_a);
  cin.clear();
  cout << "OK. Help my by adding a question! Type a question to distinguish these two animals." << endl;
  getline(cin,new_q);
  cin.clear();

  tree_node *new_right_tree_node = new tree_node;
  new_right_tree_node->question = is_it + new_a + question_mark;
  new_right_tree_node->number = (previous_node->number)*TWO + ONE;
  new_right_tree_node->right_node = nullptr;
  new_right_tree_node->left_node = nullptr;

  tree_node *new_left_tree_node = new tree_node;
  new_left_tree_node->question = previous_node->question;
  new_left_tree_node->number = (previous_node->number)*TWO;
  new_left_tree_node->right_node = nullptr;
  new_left_tree_node->left_node = nullptr;

  previous_node->question = new_q;
  previous_node->right_node = new_right_tree_node;
  previous_node->left_node = new_left_tree_node;

  return;
}

void BinarySearchTree::read_in_file(tree_node *tem_tree_node, fstream &out_file)
{
  if(tem_tree_node == nullptr)
  {
    return;
  }
  else
  {
    out_file << tem_tree_node->number << endl;
    out_file << tem_tree_node->question << endl;
    read_in_file(tem_tree_node->left_node, out_file);
    read_in_file(tem_tree_node->right_node, out_file);

    return;
  }
}


