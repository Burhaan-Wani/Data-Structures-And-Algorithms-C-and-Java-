#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    if (n == 1)
        return 1;
    return n * factorial(n - 1);
}

int power(int a, int b)
{
    if (b == 0)
        return 1;
    return a * power(a, b - 1);
}

void printDecreasingOrder(int n)
{
    if (n == 0)
        return;
    cout << n << " ";
    printDecreasingOrder(n - 1);
}

void printIncreasingOrder(int n)
{
    if (n == 0)
        return;
    printIncreasingOrder(n - 1);
    cout << n << " ";
}

int fibonacci(int n)
{
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Given a number x, count the number of binary strings of length x,
// which has no consecutive 1's
int countBinaryStrings(int x)
{
    if (x == 1)
        return 2;
    if (x == 3)
        return 3;
    return countBinaryStrings(x - 1) + countBinaryStrings(x - 2);
}

int maxElementInArray(vector<int> &vec, int idx)
{
    if (idx == vec.size() - 1)
        return vec[vec.size() - 1];
    return max(vec[idx], maxElementInArray(vec, idx + 1));
}

int minElementInArray(vector<int> &vec, int idx)
{
    if (idx == vec.size() - 1)
        return vec[vec.size() - 1];
    return min(vec[idx], maxElementInArray(vec, idx + 1));
}

// Given an array and a number x, return index of first occurence of x.
int returnIndexOfElement(vector<int> &vec, int idx, int target)
{
    if (idx >= vec.size())
        return -1;
    return vec[idx] == target ? idx : returnIndexOfElement(vec, idx + 1, target);
}

void pattern1(int n, int rows, int cols)
{
    if (rows == n)
        return;
    if (cols == n)
    {
        cout << "\n";
        pattern1(n, rows + 1, 0);
        return;
    }
    cout << "*" << " ";
    pattern1(n, rows, cols + 1);
}

void pattern2(int n, int rows, int cols)
{
    if (rows == n)
        return;
    if (cols > rows)
    {
        cout << "\n";
        pattern2(n, rows + 1, 0);
        return;
    }
    cout << "*" << " ";
    pattern2(n, rows, cols + 1);
}

void pattern3(int n, int rows, int cols)
{
    if (rows == n)
        return;
    if (cols == n - rows)
    {
        cout << "\n";
        pattern3(n, rows + 1, 0);
        return;
    }
    cout << "*" << " ";
    pattern3(n, rows, cols + 1);
}

void removeCharactersOccurenceFromString(string s, int idx, char target, string str)
{

    if (idx >= s.length())
    {
        cout << str;
        return;
    }
    if (s.at(idx) != target)
    {
        removeCharactersOccurenceFromString(s, idx + 1, target, str + s.at(idx));
    }
    else
    {
        removeCharactersOccurenceFromString(s, idx + 1, target, str);
    }
}

void subsequencesOfString(string s, int idx, string str)
{
    if (idx == s.length())
    {
        cout << "[" << str << "]" << endl;
        return;
    }
    subsequencesOfString(s, idx + 1, str + s.at(idx));
    subsequencesOfString(s, idx + 1, str);
}

int main()
{
    // pattern3(4, 0, 0);
    subsequencesOfString("abc", 0, "");
    return 0;
}