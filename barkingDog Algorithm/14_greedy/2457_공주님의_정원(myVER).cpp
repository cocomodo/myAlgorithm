//3 8 7 31 => 3월 8일에 피어서 7월 31일에 진다== 3.8~7.30까지 꽃을 볼 수 있다. 
// 3.1~11.30 사이에는 꽃이 매일 한가지 이상 피어있도록(12월 1일에 지는 꽃까지 가능)

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);
    int n;
    cin>>n;
    vector<pair<int,int>> flower;
    for(int i=0; i<n; i++){
        int sm, sd, em, ed;
        cin>>sm>>sd>>em>>ed;
        flower.push_back({sm*100+sd,em*100+ed});

    }
    int t=301; //현재 시간
    int ans=0; // 선택한 꽃의 개수
    while(t<1201){
        int nxt_t=t; //이번에 추가할 꽃으로 인해 변경된 시간
        for(int i=0; i<n; i++){
            if(flower[i].first<=t&&flower[i].second>nxt_t)
                nxt_t=flower[i].second;
        }
        if(nxt_t==t){//시간 t에서 더 전진이 불가능
            cout<<0;
            return 0;
        }
        ans++;
        t=nxt_t;
    }
    cout<<ans;
}