#include<iostream>
#include<cstdlib>
#include<string>
#include"bintree.h"
using namespace std;


int main()
{
  BinarySearchTree animal;
  //animal.tree_node *root_of_bintree = nullptr;
  animal.create_animal_tree();
  cout << "Ok, the binary tree has been loaded, lets play the game." << endl << endl;
  animal.start_to_play();
}


