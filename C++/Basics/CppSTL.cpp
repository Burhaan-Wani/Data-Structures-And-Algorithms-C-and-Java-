#include <bits/stdc++.h>
using namespace std;

void explainPairs()
{
    pair<int, int> p = {1, 3};
    pair<int, pair<int, int>> np = {1, {2, 3}};
    cout << p.first << " " << p.second;
}

void explainVectors()

{
    int arr[5] = {1, 2, 3, 4, 5}; // Arrays are fixed in size
    vector<int> v;                // creates empty container ({})
    v.push_back(1);
    v.emplace_back(2);

    vector<pair<int, int>> vec;
    vec.push_back({1, 2});
    vec.emplace_back(1, 3);

    vector<int> v(5, 100);
    vector<int> v(5);
}

void explainListsAndDeque()
{
    list<int> ls;
    ls.push_back(1);
    ls.emplace_back(1);
    ls.push_front(3);
    ls.pop_back();
    ls.pop_front();
    ls.size(); // length of list
    // similar functions as vector

    deque<int> dq;
    // similar functions as vector
}

void explainStacks()
{
    // LIFO - last in first out
    stack<int> st;
    st.push(1);    // {1}
    st.push(2);    // {2,1}
    st.push(3);    // {3,2,1}
    st.pop();      // {2,1}
    st.emplace(4); // {4,2,1}
    st.top();      // 4
}

void explainQueue()
{
    // LIFO - last in first out
    stack<int> q;
    q.push(1);    // {1}
    q.push(2);    // {1,2}
    q.push(3);    // {1,2,3}
    q.pop();      // {2,3}
    q.emplace(4); // {2,3,4}
    q.top();
}
int main()
{
    // STL in c++ is divided into 4 parts
    /*
    1. Algorithms
    2. Containers
    3. Functions
    4. Iterators
    */

    // Containers
    /*  -> Pair
        ->vectors
     */

    return 0;
}