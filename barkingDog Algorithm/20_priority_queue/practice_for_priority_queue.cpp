/*나는 하루에 5문제의 알고리즘 문제를 풀것이고, 그리고 매일 60페이지 정도 분량의 운영체제 책을
읽을것이다. 해낼 수 있다. 하루에 대부분의 시간을 이렇게 해서 보내보도록 하자. 
할 수 있다. 해낼 수 있다. 
*/
#include <bits/stdc++.h>
using namespace std;

class cmp{
public:
    bool operator() (int a, int b){
        if(abs(a)!=abs(b)) return abs(a)>abs(b);
        return a>0 && b<0;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<int, vector<int> , cmp > pq;
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        if(x==0){
            if(pq.empty()) cout<<"0\n";
            else{
                cout<<pq.top()<<'\n';
                pq.pop();
            }
        }
        else pq.push(x);
    }
}