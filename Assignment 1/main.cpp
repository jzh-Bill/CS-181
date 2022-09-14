//Zhihao Jin
// Mergesort assignment
// This file lacks the mergesort function.
// It will build an array of integers of any desired length for testing
// using values obtained from the user.
// This uses the basic (flawed) random function, with NO SEED SETTING!
#include <iostream>

using namespace std;

// This struct is an "improved" array, carrying both an array and the
// length in one unit.  The array contains ints; the length is size_t.
struct array_with_length
{
  size_t length;
  int * data;
};

// This function generates and returns an improved array struct
// The array will be filled with the specified number (parameter length)
// random values between lower_bound and upper_bound, inclusive of both extrema.
// The length requested will be in the returned struct.
//  parameters:  length is a size_t, the count of random numbers in the array
//               lower_bound is an int, the minimum possible value
//               upper_bound is an int, the maximum possible value
//  returns:  a struct of type array_with_length containing the information.
array_with_length generate_array (size_t length, int lower_bound,
                                  int upper_bound);

void mergsort (int low, int high, int *numbers_1);
void merg (int low, int middle, int high, int *numbers);

int main()
{
  const unsigned start_from_0 = 0;
  const unsigned first_index = 0;
  const unsigned one = 1;
  cout << "Hello!" << endl;
  cout << "I will generate an array of random int values and sort it." <<
       endl;
  cout << "How many elements do you want in your array?  " ;
  size_t array_length;
  cin >> array_length;
  cout << "\nWhat is the minimum possible value for the array elements?  ";
  int minimum_value;
  cin >> minimum_value;
  cout << "\nWhat is the maximum possible value for the array elements?  ";
  int maximum_value;
  cin >> maximum_value;
  array_with_length nicer_array = generate_array (array_length,
                                  minimum_value,
                                  maximum_value);
  cout << "\nHere is the array, before sorting:" << endl;
  for (size_t i = start_from_0; i < nicer_array.length; i++)
  {
    cout << nicer_array.data[i] << "  ";
  }
  cout << endl;
  mergsort (first_index, array_length - one, nicer_array.data);
  cout << "This is the array after being sort in ascending order." << endl;
  for (size_t i = start_from_0; i < nicer_array.length; i++)
  {
    cout << nicer_array.data[i] << "  ";
  }
  cout << endl;
  delete nicer_array.data;
  return 0;
}

array_with_length generate_array (size_t length, int lower_bound,
                                  int upper_bound)
{
  const unsigned int start_from_0 = 0;
  //Due to the seed setting, can't change it to unsigned
  const int one_more = 1;
  array_with_length nicer_array ;
  nicer_array.data = new int[length];
  nicer_array.length = length;
  unsigned range_length = static_cast<unsigned> (upper_bound - lower_bound
                          + one_more);
  for (size_t i = start_from_0; i < length; i++)
  {
    nicer_array.data[i] = rand() % static_cast<int>
                          (range_length) + lower_bound;
  }
  return nicer_array;
}

//split up the number in half to the end.
void mergsort (int low, int high, int *numbers_1)
{
  const int divide_two = 2;
  if ( low < high )
  {
    int middle = low + (high - low) / divide_two;
    mergsort (low, middle, numbers_1);
    mergsort (middle + 1, high, numbers_1);
    merg (low, middle, high, numbers_1);
  }
}

//sort the numbers in ascending order, then change the original array.
void merg (int low, int middle, int high, int *numbers)
{
  const int one_more = 1;
  int *helper_array = nullptr;
  helper_array  = new int [high + one_more];

  for (int i = low; i <= high; i++)
  {
    helper_array[i] =
      numbers[i]; //copy the the mergsorting part to helper array to sort.
  }
  int left_index = low;
  int right_index = middle + one_more;
  int k = low;
  while (left_index <= middle
         && right_index <= high)
  {
    if (helper_array[left_index] <= helper_array[right_index])
    {
      numbers[k] = helper_array[left_index];
      left_index++;
    }
    else
    {
      numbers[k] = helper_array[right_index];
      right_index++;
    }
    k++;
  }
  while ( left_index <= middle)
  {
    numbers[k] = helper_array[left_index];
    k++;
    left_index++;
  }
}

