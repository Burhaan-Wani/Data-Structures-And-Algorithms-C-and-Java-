#include <bits/stdc++.h>
using namespace std;

int largestElement()
{
    int arr[] = {1, 3, 4, 2, 5, 7, 6};
    int len = sizeof(arr) / sizeof(arr[0]);
    int largest = arr[0];
    for (int i = 1; i < len; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }

    return largest;
}

int smallestElement()
{
    int arr[] = {1, 3, 4, 2, 5, 7, 6};
    int len = sizeof(arr) / sizeof(arr[0]);
    int smallest = arr[0];
    for (int i = 1; i < len; i++)
    {
        if (arr[i] < smallest)
        {
            smallest = arr[i];
        }
    }
    return smallest;
}

void swapTwoArrayElements()
{
    int arr[] = {1, 3, 4, 2, 5, 7, 6};
    int len = sizeof(arr) / sizeof(arr[0]);
    int i = 0;
    int j = len - 1;

    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void reverseAnArray()
{
    int arr[] = {1, 3, 4, 2, 5, 7, 6};
    int len = sizeof(arr) / sizeof(arr[0]);

    int i = 0, j = len - 1;
    while (i <= j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void rotateArrayKTimes()
{
    vector<int> vec = {1, 2, 3, 4};
    int k = 4;

    k = k % vec.size();
    if (k < 0)
        k += vec.size();

    for (int i = 0; i < k; i++)
    {
        int lastEl = vec[vec.size() - 1];
        for (int j = vec.size() - 1; j >= 1; j--)
        {
            vec[j] = vec[j - 1];
        }
        vec[0] = lastEl;
    }
    for (auto val : vec)
    {
        cout << val << " ";
    }
}

void secondLargestElementInArray()
{
    // unsorted array
    vector<int> v = {1, 3, 2, 4, 5, 7, 6};
    int n = v.size();
    int largest = v[0];
    int secondLargest = INT_MIN;

    for (int i = 1; i < n; i++)
    {
        if (v[i] > largest)
        {
            secondLargest = largest;
            largest = v[i];
        }
        else if (v[i] < largest && v[i] > secondLargest)
        {
            secondLargest = v[i];
        }
    }
    cout << largest << " " << secondLargest;
}

void checkArrayIsSortedOrNot()
{
    int arr[] = {1, 2, 2, 3, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int sorted = true;
    for (int i = 0; i <= n - 2; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            sorted = false;
            break;
        }
    }

    if (sorted)
    {
        cout << "Array is sorted";
    }
    else
    {
        cout << "Array is not sorted";
    }
}

int removeDuplicatesFromSortedArray()
{
    int arr[] = {0, 1, 1, 1, 1, 2, 2, 3, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int idx = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] != arr[i])
        {
            arr[idx] = arr[i];
            idx++;
        }
    }
    return idx;
}

int main()
{
    checkArrayIsSortedOrNot();
    return 0;
}