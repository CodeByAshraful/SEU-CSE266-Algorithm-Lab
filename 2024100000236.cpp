#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& a, int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;
    vector<int> L(n1), R(n2);

    for(int i = 0; i < n1; i++) L[i] = a[l + i];
    for(int i = 0; i < n2; i++) R[i] = a[m + 1 + i];

    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2)
        a[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    while(i < n1) a[k++] = L[i++];
    while(j < n2) a[k++] = R[j++];
}

void mergeSort(vector<int>& a, int l, int r)
{
    if(l < r)
    {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int prec(char c)
{
    if(c == '^') return 3;
    if(c == '*' || c == '/') return 2;
    if(c == '+' || c == '-') return 1;
    return -1;
}

string infixToPostfix(string s)
{
    stack<char> st;
    string res = "";

    for(char c : s)
    {
        if(isdigit(c))
            res += c;
        else if(c == '(')
            st.push(c);
        else if(c == ')')
        {
            while(!st.empty() && st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while(!st.empty() && prec(st.top()) >= prec(c))
            {
                res += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty())
    {
        res += st.top();
        st.pop();
    }
    return res;
}

string infixToPrefix(string s)
{
    reverse(s.begin(), s.end());
    for(char &c : s)
    {
        if(c == '(') c = ')';
        else if(c == ')') c = '(';
    }

    stack<char> st;
    string prefix = "";

    for(char c : s)
    {
        if(isdigit(c))
            prefix += c;
        else if(c == '(')
            st.push(c);
        else if(c == ')')
        {
            while(!st.empty() && st.top() != '(')
            {
                prefix += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while(!st.empty() && prec(st.top()) > prec(c))
            {
                prefix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty())
    {
        prefix += st.top();
        st.pop();
    }

    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main()
{

    string id = "2024100000236";
    cout << "ID: " << id << "\n\n";

    vector<int> arr;
    for(char c : id) arr.push_back(c - '0');

    cout << "Array from ID:\n";
    for(int x : arr) cout << x << " ";
    cout << "\n\n";

    mergeSort(arr, 0, arr.size() - 1);

    cout << "After Merge Sort:\n";
    for(int x : arr) cout << x << " ";
    cout << "\n\n";

    queue<int> q;
    for(int x : arr) q.push(x);

    cout << "Queue elements:\n";
    queue<int> tempQ = q;
    while(!tempQ.empty())
    {
        cout << tempQ.front() << " ";
        tempQ.pop();
    }
    cout << "\n\n";

    stack<int> st;
    while(!q.empty())
    {
        st.push(q.front());
        q.pop();
    }

    cout << "Stack after dequeuing from Queue:\n";
    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << "\n\n";

    string infix = "2+0-2*2/1+0-0*0/0+0-0*3/6";
    cout << "Infix Expression:\n" << infix << "\n\n";

    cout << "Postfix Expression:\n"
         << infixToPostfix(infix) << "\n\n";

    cout << "Prefix Expression:\n"
         << infixToPrefix(infix) << "\n";

    return 0;
}

