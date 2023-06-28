#include <bits/stdc++.h>
using namespace std;

int a[2'250'000];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int t;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>> a[i*n+j];
        }
    }
    sort(a,a+n*n);
    cout<<a[n*n-1-(n-1)];
}

/* 이 풀이의 경우, 수가 굉장히 타이트하게 12mb에 맞을것 같아서, 
벡터를 사용하면(priority_queue의 경우 내부 구현이 vector라) 용량이 조금 더 필요하니까,
 조금이라도 줄이기 위해서 배열을 사용하여서 푼 풀이이다. 
 그리고 이 풀이를 이용해서 제출해보면, 사용 메모리는 10808kb, 408ms가 나온다. 
 이때에 이 값들은 최대 많은 용량을 차지한 입력값에 대한 메모리, 그리고 가장 오랜 시간이 걸린
 입력값에 대한 시간 으로 알고있다. 
 확실히 전체 개수에 대해서 따지고 타이트하게 int로 계산해서 딱 그것만이 차지하는 용량을 비교하면
 9'000'000byte( 2'250'000개의 int) 이기 때문에 배열로 풀 수 있었다고 본다. 
*/