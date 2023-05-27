#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[1005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;    
    for(int i=0; i<n; i++)
        cin>>a[i];
    while(m--){
        sort(a,a+n);
        long long mnum=a[0]+a[1];
        a[0]=mnum;
        a[1]=mnum;
    }
    long long sum=0;
    for(int i=0; i<n; i++)
        sum+=a[i];
    cout<<sum;
}

/*
맞은 풀이. 수의 범위를 주의했어야 하는데 그러지 못해서 방향성 초반에 잘 잡았는데 지속적으로 틀렸다. 이렇게 수가 서로 합치면서 커지는 문제의 경우 int 범위를 넘어가는 경우가 생기는것은 아닌지 확실하게 생각하고 나서 문제를 풀기 시작하자. 이번 문제의 경우는 아무래도 방향성을 잘 잡았다고 생각해서 type의 경우는 다 작성하고 나서 수정하자는 생각으로 문제를 풀기 시작했는데, 그런 식으로 문제를 풀어선 안되겠다. 이번처럼 옳다고 생각하고 지속적으로 잘못된 방향으로 생각이 고정되버리면 아마 틀린 부분을 찾지 못할것이다. 처음부터 int를 써야할지, 혹은 long long을 써야할지 확실하게 방향을 잡고 문제를 풀어나가기 시작하자. 
*/