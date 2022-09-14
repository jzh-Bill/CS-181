#include <iostream>
#include <vector>
#include <deque>
#include <array>
#include <algorithm>

using namespace std;


void square_function(int &n);


int main()
{
    deque<int> numbers_1 = {2,6,3,9,1,8,-2};
    cout << "The numbers that deque contains are ";
    for(auto i: numbers_1)
    {
      cout << i << " ";
    }
    cout << ".";
    sort(numbers_1.begin(),numbers_1.end());
    cout << endl;
    cout << "The numbers after sorting are in deque: ";
    for(auto i: numbers_1)
    {
      cout << i << " ";
    }

    cout << "." << endl << endl;

    vector<int> numbers_2 = {-2,1,2,3,6,8,9};
    cout << "The numbers contained in vector are: ";
    for(auto i: numbers_2)
    {
      cout << i << " ";
    }
    cout << "." << endl;

    sort(numbers_2.begin(),numbers_2.end());

    cout << "The numbers after sorting in vector are : ";
    for(auto i: numbers_2)
    {
      cout << i << " ";
    }
    cout << "." << endl << endl;

    array<int, 14>  arr;

    cout << "The numbers in array are: ";
    merge(numbers_1.begin(),numbers_1.end(), numbers_2.begin(), numbers_2.end(), arr.begin());

    for(auto i: arr)
    {
      cout << i << " ";
    }
  cout << "." <<endl;

  for_each(arr.begin(),arr.end(),square_function);
  cout << "The numbers after square are: ";

   for(auto i: arr)
    {
      cout << i << " ";
    }
    cout << "." << endl;
}

void square_function(int &n)
{
  n = n * n;
}
