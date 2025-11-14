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

void reverseAnArray(vector<int> &vec, int left, int right)
{
    int len = vec.size();

    while (left < right)
    {
        int temp = vec[left];
        vec[left] = vec[right];
        vec[right] = temp;
        left++;
        right--;
    }
}

// Method 1
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

// Method 2 - by reversing array
void rotateArray(vector<int> &nums, int k)
{
    int len = nums.size();
    k = k % len;
    reverseAnArray(nums, 0, len - 1);
    reverseAnArray(nums, 0, k - 1);
    reverseAnArray(nums, k, len - 1);
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

// Method 1
int removeDuplicatesFromSortedArray()
{
    int arr[] = {1, 2, 2, 3, 3, 4, 4};
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

// Method 2
int removeDuplicatesInSortedArray(vector<int> &vec)
{
    int idx = 0;
    for (int j = 1; j < vec.size(); j++)
    {
        if (vec[j] != vec[idx])
        {
            vec[idx + 1] = vec[j];
            idx += 1;
        }
    }
    return idx + 1;
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

vector<int> unionOfTwoArrays(vector<int> &v1, vector<int> &v2)
{
    int n1 = v1.size();
    int n2 = v2.size();
    int i = 0, j = 0;
    vector<int> unionArr;

    while (i < n1 && j < n2)
    {
        if (v1[i] <= v2[j])
        {
            if (unionArr.size() == 0 || unionArr.back() != v1[i])
            {
                unionArr.push_back(v1[i]);
            }
            i++;
        }
        else
        {
            if (unionArr.size() == 0 || unionArr.back() != v2[j])
            {
                unionArr.push_back(v2[j]);
            }
            j++;
        }
    }

    while (i < n1)
    {
        if (unionArr.size() == 0 || unionArr.back() != v1[i])
        {
            unionArr.push_back(v1[i]);
        }
        i++;
    }
    while (j < n2)
    {
        if (unionArr.size() == 0 || unionArr.back() != v2[j])
        {
            unionArr.push_back(v2[j]);
        }
        j++;
    }
    return unionArr;
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

void leftRotateArrayByOnePlace(vector<int> &vec)
{
    int temp = vec[0];
    for (int i = 1; i < vec.size(); i++)
    {
        vec[i - 1] = vec[i];
    }
    vec[vec.size() - 1] = temp;
}

// Method 1 - This method does not maintain the relative order
void putAllZeroesAtTheEnd(vector<int> &vec)
{
    int i = 0, j = vec.size() - 1;
    while (j >= i)
    {
        if (vec[j] == 0)
            j--;
        else
        {
            int temp = vec[j];
            vec[j] = vec[i];
            vec[i] = temp;
        }
        i++;
    }
}

// Method 2 - Shifting array to left by ones, maintain relative order
void moveZeroesToTheEnd(vector<int> &vec)
{
    int i = 0, idx = vec.size() - 1;
    while (i <= idx)
    {
        if (vec[idx] == 0)
            idx--;
        else if (vec[i] == 0)
        {
            int temp = vec[i];
            for (int j = i + 1; j <= idx; j++)
            {
                vec[j - 1] = vec[j];
            }
            vec[idx] = temp;
            idx--;
        }
        else
        {
            i++;
        }
    }
}

// Method 3 - optimized
void moveZeroes(vector<int> &nums)
{
    int j = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            j = i;
            break;
        }
    }

    if (j == -1)
        return;
    for (int i = j + 1; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            j++;
        }
    }
}

// 268. Missing Number
int missingNumber(vector<int> &nums)
{
    int xor1 = 0, xor2 = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        xor2 = xor2 ^ nums[i];
        xor1 = xor1 ^ i;
    }
    xor1 = xor1 ^ nums.size();
    return xor1 ^ xor2;
}

// 485. Max Consecutive Ones
int findMaxConsecutiveOnes(vector<int> &nums)
{
    int count = 0, maxOnes = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            count++;
            if (count > maxOnes)
            {
                maxOnes = count;
            }
        }
        else
        {
            count = 0;
        }
    }
    return maxOnes;
}

// Find longest subarray with sum k
// Works for both +ve & -ve values
// Better Approach - Method 1
int longestSubArraySum(vector<int> &a, int k)
{
    int maxlen = 0;
    long long sum = 0;
    map<long long, int> preSumMap;
    for (int i = 0; i < a.size(); i++)
    {
        sum += a[i];
        if (sum == k)
            maxlen = max(maxlen, i + 1);

        long long rem = sum - k;
        if (preSumMap.find(rem) != preSumMap.end())
        {
            int len = i - preSumMap[rem];
            maxlen = max(maxlen, len);
        }
        if (preSumMap.find(sum) == preSumMap.end())
        {
            preSumMap[sum] = i;
        }
    }
    return maxlen;
}

// Optimized Approach - Method 2
int longestSubArray(vector<int> &a, int k)
{
    int left = 0, right = 0;
    long long sum = a[0];
    int len = 0;
    int n = a.size();
    while (right < n)
    {
        while (left <= right && sum > k)
        {
            sum -= a[left++];
        }
        if (sum == k)
        {
            len = max(len, right - left + 1);
        }
        right++;
        if (right < n)
            sum += a[right];
    }
    return len;
}
int main()
{
    unordered_map<int, int> mp;
    // sum=1;
    vector<int> v = {1, 2, 3, 1, 1, 1, 1};
    int k = 3;
    cout << longestSubArray(v, k);
    return 0;
}