#include<iostream>
using namespace std;

int power(int n, int expo)
{
    //Base Case
    if(expo == 0) return 1;

    //Recursive relation --> 4^4 = 4 * 4^3; f(n) = n * f(n-1) where f(n) = 4^n for example;
    int smallerProblem = power(n, expo-1);
    int biggerProblem = n* smallerProblem;

    return biggerProblem;

}

int main(){

    int n, expo;
    cin >> n >> expo;

    int ans = power(n, expo);

    cout << ans << endl;
    return 0;
}