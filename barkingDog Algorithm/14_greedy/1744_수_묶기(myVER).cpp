#include <bits/stdc++.h>
using namespace std;

long long ans; // 출력 설명에서 정답은 항상 1<<32보다 작다고 설명해놓았기 때문에 int로 설정해도 된다. 

void seqSum(vector<int> v){
    while(1<v.size()){ //지속적으로 연산을 하면서 vector의 원소들을 2개씩 빼기 때문에 1보다 클때까지 이 연산 과정을 지속하고, 만약 1보다 크지 않다면, 그 경우는 원소가 짝수개였다면 v의 남은 원소가 0 이 될것이고, 홀수개였다면 1이 될것이다. 
        ans+=*(v.end()-1)*(*(v.end()-2));
        v.pop_back();
        v.pop_back();
    }
    if(v.size()) //이 경우가 의미하는 바는, 원소가 하나 남았을때이다. 위의 연산을 다 거치면, 원소의 개수가(v.size()가) 0혹은 1이 되느네, 이 if문은 v.size()==1 일때, 즉 원래 원소의 개수가 홀수여서 남은것이 하나일때 이 연산을 수행해주라는 의미. 
        ans+=v[0];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<int> seqP;
    vector<int> seqN;
    int n;
    cin>> n;
    for(int i=0; i<n; i++){
        int t;
        cin>>t;
        if(t==1) ans++;//1은 바로 더해야 합이 최대
        else if(t>1) //이 경우 시퀀스_파시티브에 넣기. t>0으로 작성해도 된다. 0을 seqN에 넣게 해야한다. 
            seqP.push_back(t);
        else //(t<=0) 이 경우 시퀀스_네거티브.
            seqN.push_back(t);
    }
    sort(seqP.begin(),seqP.end());// 이 경우 오름차순 정렬;
    sort(seqN.begin(),seqN.end(),greater<>());//내림차순 정렬. 예로, 4 3 2 1 순서
    seqSum(seqP);
    seqSum(seqN);
    cout<<ans;
}