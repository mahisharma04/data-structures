#include <iostream>
using namespace std;

int main ()
{

    //task is to find the maximum number of consecutive ones.
    //for example -> {1,1,0,0,[1,1,1],0,1,1,} , 3 ones are the most consecutive.

    int array[10] = {1,1,0,0,1,1,0,1,1,1};
    int counter=0; int max_counter=0;

    for(int i = 0 ; i < 10 ; i++)
    {
        if(array[i] == 1)
        {
            counter++;
        }
        else
        {
            if(counter > max_counter)
            {
                max_counter = counter;
            }
            counter = 0;
        }
    }
    //checking last segment
    if(counter > max_counter)
    {
        max_counter = counter;
    }

    cout << "count of maximum consecutive ones is: " << max_counter;

    return 0;
}