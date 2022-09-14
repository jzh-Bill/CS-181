#include <iostream>

using namespace std;

void mergsort(int low, int high, int *numbers_1);
void merg(int low, int middle, int high, int *numbers);

int main()
{
    int length = 3;

    //int A[length] = {1,2,5,3,6,2,5,12,9,78};

    int *ptr = nullptr;
    ptr = new int[length];

     for(int i = 0; i < length; i++)
    {
        cin >> ptr[i];
    }

    for(int i = 0; i < length; i++)
    {
        cout << ptr[i] << " ";
    }


    mergsort(0, 9, ptr);

    for ()
}


void mergsort(int low, int high, int *numbers_1)
{
      if(low < high)
        {
			int middle = low + (high - low) / 2;
			mergsort(low, middle, numbers_1);
			mergsort(middle + 1, high, numbers_1);
			merg(low, middle, high, numbers_1);
		}
}

void merg(int low, int middle, int high, int *numbers)
{
    int helper_array[high + 1];
    for(int i = low; i <= high; i++)
        {
			helper_array[i] = numbers[i]; //copy the the mergsorting part to helper array to merg
		}

    int i = low;
    int j = middle + 1;
    int k = low;


    while (i <= middle && j <= high) //begin the mergsort one number wit another number.
    {
        if(helper_array[i] <= helper_array[j])
            {
                numbers[k] = helper_array[i];
                i++;
            }
            else
            {
                numbers[k] = helper_array[j];
                j++;
            }
        k++;
    }
    while( i <= middle)
    {
        numbers[k] = helper_array[i];
        k++;
        i++;
    }
}

