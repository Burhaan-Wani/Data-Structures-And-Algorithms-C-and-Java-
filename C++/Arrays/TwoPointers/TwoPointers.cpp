#include <bits/stdc++.h>
using namespace std;

void sortZeroesAndOnes(vector<int> &arr)
{
    int i = 0, j = arr.size() - 1;
    while (i <= j)
    {
        if (arr[i] == 0)
            i++;
        else
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}

int numRescueBoats(vector<int> &vec, int limit)
{
    sort(vec.begin(), vec.end());
    int i = 0, j = vec.size() - 1;
    int boats = 0;
    while (i <= j)
    {
        boats++;
        if (vec[i] + vec[j] <= limit)
        {
            i++;
        }
        j--;
    }
    return boats;
}

void nextPermutation(vector<int> &nums)
{
    int i = nums.size() - 1;
    while (i >= 1 && nums[i - 1] >= nums[i])
        i--;

    if (i == 0)
    {
        reverse(nums, 0);
        return;
    }
    int k = 0;
    for (int j = i; j < nums.size(); j++)
    {
        if (nums[j] > nums[i - 1])
            k = j;
    }

    swap(nums, i - 1, k);
    reverse(nums, i);
}

vector<int> twoSum(vector<int> &vec, int target)
{
    int i = 0, j = vec.size() - 1;
    while (i <= j)
    {
        if (vec[i] + vec[j] > target)
        {
            j--;
        }
        else if (vec[i] + vec[j] < target)
            i++;
        else
        {
            return {i + 1, j + 1};
        }
    }
    return {-1, -1};
}

void reverse(vector<int> &nums, int i)
{
    int j = nums.size() - 1;
    while (i <= j)
    {
        swap(nums, i, j);
        i++;
        j--;
    }
}

void swap(vector<int> &nums, int i, int j)
{
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

int main()
{
    // vector<int> arr = {0, 1, 0, 0, 1, 1, 0};
    // sortZeroesAndOnes(arr);
    vector<int> people = {3, 2, 2, 1};
    cout << numRescueBoats(people, 3);
    // for (auto val : people)
    // {
    //     cout << val << " ";
    // }
    return 0;
}