#include <bits/stdc++.h>
using namespace std;

void printNameNTimes(int i, int n)
{
    if (i == n)
        return;
    cout << "hi burhaan" << endl;
    printNameNTimes(i + 1, n);
}

void print1ToN(int i, int n)
{
    if (i > n)
        return;
    cout << i << " ";
    print1ToN(i + 1, n);
}

void printNTo1(int n)
{
    if (n < 1)
        return;
    cout << n << " ";
    printNTo1(n - 1);
}

void print1ToNBacktrack(int n)
{
    if (n < 1)
        return;
    print1ToNBacktrack(n - 1);
    cout << n << " ";
}

void reverseArray(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    reverseArray(arr, start + 1, end - 1);
}

bool checkStringAsPalindrome(string str, int i, int n)
{

    if (i >= n / 2)
        return true;
    if (str.at(i) != str.at(n - i - 1))
    {
        return false;
    }
    return checkStringAsPalindrome(str, i + 1, n);
}
int main()
{
    // printNameNTimes(0, 4);
    // print1ToN(1, 4);
    // printNTo1(4);
    // print1ToNBacktrack(4);
    // int arr[] = {1, 2, 3, 4};
    // int length = sizeof(arr) / sizeof(arr[0]);
    // reverseArray(arr, 0, length - 1);
    // for (int val : arr)
    // {
    //     cout << val << " ";
    // }

    cout << checkStringAsPalindrome("madam", 0, 5);
    return 0;
}