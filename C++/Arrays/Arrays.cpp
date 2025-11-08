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

vector<int> runningSumOf1DArray(int arr[], int len)
{
    vector<int> vec(len);
    vec[0] = arr[0];
    for (int i = 1; i < len; i++)
    {
        vec[i] = vec[i - 1] + arr[i];
    }

    return vec;
}

vector<int> intersectionOfTwoArrays(int arr1[], int arr2[], int m, int n)
{
    int i = 0, j = 0;
    vector<int> vec;
    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
            i++;
        else if (arr1[i] > arr2[j])
            j++;
        else
        {
            vec.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    return vec;
}

list<int> addTwoArrays(int arr1[], int arr2[], int m, int n)
{
    int carry = 0;
    list<int> ls;
    int i = m - 1, j = n - 1;

    while (i >= 0 || j >= 0)
    {
        int sum = 0;
        if (i >= 0)
            sum += arr1[i];
        if (j >= 0)
            sum += arr2[j];
        sum += carry;
        int rem = sum % 10;
        carry = sum / 10;
        ls.emplace_front(rem);
        i--;
        j--;
    }
    if (carry > 0)
    {
        ls.emplace_front(carry);
    }
    return ls;
}

int main()
{
    int arr1[] = {1, 2, 3};
    int arr2[] = {9, 9, 3, 7};
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
    list<int> res = addTwoArrays(arr1, arr2, m, n);

    for (auto val : res)
    {
        cout << val << " ";
    }
    return 0;
}