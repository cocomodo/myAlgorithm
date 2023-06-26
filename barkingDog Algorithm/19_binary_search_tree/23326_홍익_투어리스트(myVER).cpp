#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    set<int> hu; // 홍익대학교의 명소들 위치. 인덱스로 나타낼 예정
    int N, Q, tmp, curr=1; // curr의 경우는 현재의 위치를 나타낼 예정
    cin>>N>>Q;
    for(int i=1; i<=N; i++){
        cin>>tmp;
        if(tmp) hu.insert(i); /* tmp 값이 1 이라면, 그 때의 인덱스 i 값이 바로 
        홍익대학교의 명소의 위치가 된다. 그 인덱스 값을 이진탐색트리를 이용한 set에 저장할 예정
        */
    }
    while(Q--){
        cin>>tmp;
        switch(tmp){
            case 1://그 tmp 값이 1 이라면,
                cin>>tmp;//이때 입력받는 tmp 값은 index 값이다.
                if(hu.find(tmp)!=hu.end())
                    hu.erase(tmp);
                else
                    hu.insert(tmp);
                break;
            case 2:
                cin>>tmp;
                curr=(curr+tmp-1)% N + 1;
                break;
            case 3:
                if(hu.empty()) cout<<-1<<'\n';
                else{
                    auto it = hu.lower_bound(curr);
                    if(it!=hu.end())
                        cout<<*it-curr<<'\n';
                    else 
                        cout<<N-curr+ *hu.begin()<<'\n';
                }
        }
    }
}