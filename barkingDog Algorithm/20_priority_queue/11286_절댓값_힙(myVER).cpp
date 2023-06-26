#include <bits/stdc++.h>
using namespace std;

priority_queue<int,vector<int>,greater<int>> plusPq;
// priority_queue<int, vector<int>,greater<int>> minusPq;
priority_queue<int> minusPq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;

    while(n--){
        int t;
        cin>>t;
        if(t==0){
            if(plusPq.empty()&&!minusPq.empty()){
                cout<<minusPq.top()<<'\n';
                minusPq.pop();
                continue;
            }
            if(!plusPq.empty()&&minusPq.empty()){ /*여기서 continue를 빼면, 바로 case 3 인 경우도 같이 걸리네. */
                cout<<plusPq.top()<<'\n';
                plusPq.pop();
                continue;
            }
            if(plusPq.empty()&&minusPq.empty()){// 여기가 같이 문제야. 
                cout<<0<<'\n';
                continue;
            }
            if(!plusPq.empty()&&!minusPq.empty()){

                if(plusPq.top()>=-minusPq.top()) {
                    cout<<minusPq.top()<<'\n';
                    minusPq.pop();
                    continue;
                }
                else if(plusPq.top()<-minusPq.top()){
                    cout<<plusPq.top()<<'\n';
                    plusPq.pop();
                    continue;
                }
            }

        }
        else if(t>0){
            plusPq.push(t);
        }
        else{ // t<0
            minusPq.push(t);
        }
    }
}