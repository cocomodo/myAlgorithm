#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N; // 탑의 개수 입력

    vector<int> heights(N);    // 탑의 높이를 저장할 벡터
    vector<int> results(N, 0); // 탑의 결과를 저장할 벡터

    for (int i = 0; i < N; ++i)
    {
        cin >> heights[i]; // 탑의 높이 정보 입력
    }

    stack<int> st; // 높이 정보를 저장할 스택

    for (int i = 0; i < N; ++i)
    {
        while (!st.empty())
        {
            // 스택이 비어있지 않고, 스택의 높이가 현재 탑의 높이보다 낮다면
            if (heights[st.top()] <= heights[i])
            {
                st.pop(); // 스택의 높이를 비우고 pop
            }
            // 스택의 높이가 현재 탑의 높이보다 높다면
            else
            {
                results[i] = st.top() + 1; // 결과 벡터에 인덱스 저장
                break;
            }
        }
        st.push(i); // 현재 탑의 인덱스를 스택에 저장
    }

    for (int i = 0; i < N; ++i)
    {
        cout << results[i] << " "; // 결과 출력
    }
    cout << endl;

    return 0;
}
