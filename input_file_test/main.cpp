#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  ifstream input_file;
  input_file.open("123.txt");

  int a;

  int b;

  input_file >> a;

  input_file >> b;

  cout << a << b;

}
