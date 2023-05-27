#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string st;
    cin >> st;
    int stlen = st.size();
    int cnt_0 = 0;
    int cnt_1 = 0;
    
    for (int i = 0; i < stlen; i++) {
        if (i > 0 && st[i - 1] != st[i] && st[i] == '1') cnt_1++;//이러면 첫번째 글자와 두번째 글자가 다른 경우, 예를 들어 01110101 같은건 못잡아낼텐데.
        if (i > 0 && st[i - 1] != st[i] && st[i] == '0') cnt_0++;
    }
    cout << min(cnt_1, cnt_0);
}
