#include <bits/stdc++.h>
using namespace std;

int countDigits(int n)
{
    int count = 0;
    while (n > 0)
    {
        n = n / 10;
        count++;
    }
    return count;
}

int reverseNumber(int x)
{
    int rev = 0;
    while (x != 0)
    {
        int pop = x % 10;
        x /= 10;

        if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7))
            return 0;
        if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8))
            return 0;

        rev = rev * 10 + pop;
    }
    return rev;
}

bool checkPalindrome(int n)
{
    // negative numbers and numbers ending with 0 are not considered palindrome numbers
    if (n < 0 || (n % 10 == 0 && n != 0))
    {
        return false;
    }

    int reversed = 0;
    while (n > reversed)
    {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }

    return n == reversed || n == reversed / 10;
}

void checkArmStrongNumber(int n)
{
    int duplicate = n;
    int result = 0;
    int count = countDigits(n);
    while (n > 0)
    {
        int remainder = n % 10;
        result += pow(remainder, count);
        n /= 10;
    }
    if (result == duplicate)
        cout << duplicate << " is an armStrong number";
    else
        cout << duplicate << " is not an armStrong number";
}

void printAllDivisors(int n)
{
    vector<int> vec;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            vec.push_back(i);
            if ((n / i) != i)
            {
                vec.push_back(n / i);
            }
        }
    }
    sort(vec.begin(), vec.end());
    for (auto it : vec)
        cout << it << " ";
}

void checkForPrimeNumber(int n)
{
    int count = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            count++;
            if ((n / i) != i)
                count++;
        }
    }
    if (count == 2)
        cout << n << " is a prime number";
    else
        cout << n << " is not a prime number";
}

int gcdOrHch(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }
    if (a == 0)
        return b;
    return a;
}

int main()
{
    int digit;
    cout << "Enter the digit: ";
    cin >> digit;
    // countDigits(digit);
    cout << reverseNumber(digit);
    // checkPalindrome(digit);
    // checkArmStrongNumber(digit);
    // printAllDivisors(digit);
    // checkForPrimeNumber(digit);
    // cout << gcdOrHch(20, 40);
    return 0;
}