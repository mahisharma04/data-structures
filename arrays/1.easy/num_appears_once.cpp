#include <iostream>
using namespace std;

int main()
{

    int array[9] = {1,1,2,2,4,4,7,6,6};
    //task is to find the number that is not appearing twice which in this case is 4.

    //first thought that comes to mind is to use hashing.

    //max number is 5 so we need that in the hash array so we will create a hash array of 5+1
    // int hash[6] = {0}; //initialize it to 0.

    // for(int i = 0; i<9; i++)
    // {
    //     hash[array[i]]++;
    // }

    // for(int i = 0; i<6; i++)
    // {
    //     if(hash[i] == 1) cout << i << endl;
    // }

    //time complexity -> O(2N) space complexity -> O()
    //One thing to NOTE about hash method is that you probably cannot hash if there are negatives involved and also if the numbers are too big such as 10^12 or so then you cannot hash, alternative solution is to use map c++ STL with long long keys.

    //optimal solution is to use xor! (condition is that every other element must appear in pairs and target element should be one only.)

    int xor1=0;
    for(int i = 0; i<9; i++)
    {
        xor1 = xor1 ^ array[i];
    }
    cout << xor1;
    return 0;
}