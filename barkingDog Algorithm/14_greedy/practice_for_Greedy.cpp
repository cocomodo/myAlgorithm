#include <bits/stdc++.h>
using namespace std;

long long ans;

void seqSum(vector<int> v){
    while(1<v.size()){
        ans+=*(v.end()-1)*(*(v.end()-2));
        v.pop_back();
        v.pop_back();
    }
    if(v.size())
        ans+=v[0];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<int> seqP,seqN;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int t;
        cin>>t;
        if(t==1) ans++; //1은 바로 더해야 합이 최대가 된다. 
        else if(t>0)//이렇게 하면 일단 t==1 일때는 위에서 걸리고, 결국 t>1로 작성해야 하는거 아닌가? t>1로 작성해서 제출해보도록 하자. 이 경우 시퀀스_파시티브.
            seqP.push_back(t);
        else //(t<0) 이 경우 시퀀스_네거티브.  
            seqN.push_back(t);
    }
    sort(seqP.begin(),seqP.end());
    sort(seqN.begin(),seqN.end(),greater<>());//내림차순 정렬. 제일 큰수가 먼저, 작은수가 그다음으로
    seqSum(seqP);
    seqSum(seqN);
    cout<<ans;
}