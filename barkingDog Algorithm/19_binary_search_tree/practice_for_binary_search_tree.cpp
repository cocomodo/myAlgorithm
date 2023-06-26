/* 일주일간 목표. 하루에 알고리즘 문제 5문제 풀고, 하루에 운영체제 책 60페이지 읽기
이렇게 해야 나중에 나만무 끝나고 나서 알고리즘과 네트워크 공부에 올인하고 코딩테스트 준비를 할 
수 있을 것이다.*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    set<int> hu;
    int N, Q, t, curr=1;
    cin>>N>>Q;
    for(int i=1; i<=N; i++){
        cin>>t;
        if(t) hu.insert(i);
    }
    while(Q--){
        cin>>t;
        switch(t){
            case 1:
                cin>>t;
                if(hu.find(t)!=hu.end())
                    hu.erase(t);
                else
                    hu.insert(t);
                break;
            case 2:
                cin>>t;
                curr=(curr-1+t)%N+1;
                break;
            case 3:
                if(hu.empty()) cout<<-1<<'\n';
                else{
                    auto it=hu.lower_bound(curr);
                    if(it!=hu.end())
                        cout<<*it-curr<<'\n';
                    else
                        cout<<N-curr+ *hu.begin()<<'\n';
                }
                break;
        }
    }
}