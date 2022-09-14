#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "binary_node_tree.h"

using namespace std;

int main()
{
     int value_1;
     string question;
     string dummy;
     ifstream input_file;
     input_file.open("animals.txt");
     while(input_file >> value_1)
     {
       getline(input_file,dummy);
       getline(input_file,question);
     }
     BinarySearchTree animals_tree;
}

vector convert_to_binary(int value)
{
  int n = 13;
  int a;
  vector<int> binary_vector;
  while(n != 0)
  {
    a = n % 2;
    binary_vector.push_back(a);
    n = n / 2;
  }
  reverse(binary_vector.begin(),binary_vector.end());
  return binary_vector;
}



