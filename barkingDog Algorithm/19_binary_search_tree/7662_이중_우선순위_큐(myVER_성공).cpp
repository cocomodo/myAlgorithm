#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin>>tc;
    while(tc--){
        int query;
        cin>>query;
        multiset<int> mset;//각각의 테스트 케이스마다 담아야 하는 정보는 다르다. 매우 중요
        while(query--){
            char order;
            int num;
            cin>>order>>num;
            if(order=='I') mset.insert(num);
            else{//order=='D'라면 
                if(!mset.empty()){
                    if(num==1){
                        auto it=prev(mset.end());
                        mset.erase(it);
                    }
                    else
                        mset.erase(mset.begin());
                }
            }
        }
        if(mset.empty()) cout<<"EMPTY"<<'\n';
        else{
            auto it=prev(mset.end());
            cout<<*it<<' ';
            auto itst=mset.begin();
            cout<<*itst;
            cout<<'\n';
        }
    }
}