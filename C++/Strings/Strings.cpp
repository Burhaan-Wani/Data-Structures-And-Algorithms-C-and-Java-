#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string str)
{
    int i = 0, j = str.length() - 1;
    while (i <= j)
    {
        if (str.at(i) != str[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

void replaceAscii(string str)
{
    string s = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (i % 2 == 0)
        {
            s.push_back((char)(str.at(i) + 1));
        }
        else
        {
            s.push_back((char)(str.at(i) - 1));
        }
    }
    cout << s;
}

void substrings()
{
    string str = "code";
    for (int i = 0; i < str.length(); i++)
    {
        for (int j = i + 1; j <= str.length(); j++)
        {
            cout << str.substr(i, j) << " ";
        }
        cout << endl;
    }
}

int maxLengthBetweenTwoEqualCharacters(string str)
{
    vector<int> arr(26, 0);
    int maxLength = -1;
    for (int i = 0; i < str.length(); i++)
    {
        int idx = str.at(i) - 'a';
        if (arr[idx] > 0)
        {
            maxLength = max(maxLength, i - arr[idx]);
        }
        else
        {
            arr[idx] = i + 1;
        }
    }
    return maxLength;
}

string reverseWords(string s)
{
    stringstream ss(s);
    string word;
    vector<string> words;
    while (ss >> word)
    {
        words.push_back(word);
    }

    reverse(words.begin(), words.end());
    string str = "";
    for (int i = 0; i < words.size(); i++)
    {
        str.append(i < words.size() - 1 ? words[i] + " " : words[i]);
    }
    cout << str;
}

bool isValidPalindrome(string s)
{
    int i = 0;
    int j = s.length() - 1;

    while (i < j)
    {
        while (i < j && !isalnum(s.at(i)))
        {
            i++;
        }
        while (i < j && !isalnum(s.at(j)))
        {
            j--;
        }
        if (i < j && tolower(s.at(i)) != tolower(s.at(j)))
        {
            return false;
        }

        i++;
        j--;
    }

    return true;
}

string largestOddNumber(string s)
{
    // s='234567'
    // result='234567'

    // s='52'
    // result='5'
    int right = s.length() - 1;
    while (right >= 0)
    {
        if ((s.at(right) - '0') % 2 == 0)
        {
            right--;
        }
        else
        {
            break;
        }
    }
    return s.substr(0, right + 1);
}

int main()
{
    string s = " A man, a plan, a canal: Panama ";
    cout << isValidPalindrome(s);
    return 0;
}