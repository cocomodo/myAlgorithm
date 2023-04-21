#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(vector<int> &arr, int c, int distance)
{
    int cnt = 1;       // 설치한 공유기의 개수
    int prev = arr[0]; // 이전에 공유기를 설치한 집의 위치

    // 현재 거리(distance)를 기준으로 공유기를 설치
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] - prev >= distance)
        {
            cnt++;
            prev = arr[i];
        }
    }

    return cnt >= c; // 설치한 공유기의 개수가 c보다 크거나 같은지 확인
}

int main()
{
    int n, c;
    cin >> n >> c;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end()); // 집의 위치를 오름차순으로 정렬

    int left = 1;                    // 최소 거리
    int right = arr[n - 1] - arr[0]; // 최대 거리
    int answer = 0;

    // 이진 탐색을 통해 최적의 거리를 찾음
    while (left <= right)
    {
        int mid = (left + right) / 2;

        // 현재 거리를 기준으로 공유기를 설치할 수 있는지 확인
        if (isPossible(arr, c, mid))
        {
            answer = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << answer << endl; // 최적의 거리 출력

    return 0;
}
