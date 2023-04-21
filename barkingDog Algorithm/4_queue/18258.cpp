#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    queue<int> Q;
    while (n--)
    {
        string op;
        cin >> op;
        if (op == "push")
        {
            int m;
            cin >> m;
            Q.push(m);
        }
        else if (op == "pop")
        {
            if (Q.empty())
                cout << "-1"
                     << "\n";
            else
            {
                cout << Q.front() << "\n";
                Q.pop();
            }
        }
        else if (op == "front")
        {
            if (Q.empty())
                cout << "-1"
                     << "\n";
            else
                cout << Q.front() << "\n";
        }
        else if (op == "size")
        {
            cout << Q.size() << "\n";
        }
        else if (op == "empty")
        {
            if (Q.empty())
                cout << "1"
                     << "\n";
            else
                cout << "0"
                     << "\n";
        }
        else
        { // back
            if (Q.empty())
                cout << "-1"
                     << "\n";
            else
                cout << Q.back() << "\n";
        }
    }
}