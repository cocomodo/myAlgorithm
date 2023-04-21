#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> S;
    int n;
    cin >> n;
    while (n--)
    {
        string op;
        cin >> op;
        if (op == "push")
        {
            int num;
            cin >> num;
            S.push(num);
        }
        else if (op == "pop")
        {
            if (!S.empty())
            {
                cout << S.top() << "\n";
                S.pop();
            }
            else
            {
                cout << "-1"
                     << "\n";
            }
        }
        else if (op == "size")
        {
            cout << S.size() << "\n";
        }
        else if (op == "empty")
        {
            if (S.empty())
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else
        {
            // top인 경우
            if (S.empty())
                cout << "-1"
                     << "\n";
            else
                cout << S.top() << "\n";
        }
    }
}