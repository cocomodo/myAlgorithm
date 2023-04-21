// #include <bits/stdc++.h>
// using namespace std;

// int n, s;
// vector<int> nums;
// int cnt;

// void func(int idx, int sum)
// {
//     if (idx == n)
//     {
//         if (sum == s)
//         {
//             cnt++;
//         }
//         return;
//     }
//     func(idx + 1, sum + nums[idx]);
//     func(idx + 1, sum);
// }

// int main(void)
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cin >> n >> s;
//     nums.resize(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> nums[i];
//     }
//     func(0, 0);

//     if (s == 0)
//     {
//         cnt--;
//     }
//     cout << cnt << "\n";
// }

// 아래 코드의 경우는 vector대신 array를 사용하여서 하는 풀이

#include <bits/stdc++.h>
using namespace std;

int n, s;
int arr[25];
int cnt;

void func(int idx, int sum)
{
    if (idx == n)
    {
        if (sum == s)
        {
            cnt++;
        }
        return;
    }
    func(idx + 1, sum + arr[idx]);
    func(idx + 1, sum);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    func(0, 0);

    if (s == 0)
    {
        cnt--;
    }
    cout << cnt << "\n";
}