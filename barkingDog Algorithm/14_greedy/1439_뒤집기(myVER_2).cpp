#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string st;
    cin>>st;
    int stlen=st.size();
    int cnt_0=0;
    int cnt_1=0;
    if(st[0]=='1') cnt_1++;
    else cnt_0++;
    for(int i=1; i<stlen;i++){
        if(i>0&&st[i-1]!=st[i]&&st[i]=='1') cnt_1++;
        if(i>0&&st[i-1]!=st[i]&&st[i]=='0') cnt_0++;
    }
    cout<<min(cnt_1,cnt_0);
}