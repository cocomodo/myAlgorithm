#include <bits/stdc++.h>
using namespace std;

int n; 
int a[1005];
vector<int> sum;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a,a+n);// 여기서 sort를 해놔야 나중에 binary_search를 사용할때 a[i]-a[j]를  사용할때 원하는 값인 가장 큰 a[i]를 i=n-1순서로 뒤부터 찾아서 나타낼 수 있다. 그 의도를 위해서 이 부분을 정렬해야한다. 
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            sum.push_back(a[i]+a[j]);
        }
    }
    sort(sum.begin(),sum.end());/*이걸 위해선 sort(a,a+n)을 안해도 된다. 
    sort(a,a+n)은 나중에 binary_search를 사용할때 a[i]-a[j]를 의도한 바대로 사용하려고
    하는 것이다. */
    for(int i=n-1;i>0; i--){
        for(int j=0;j<i;j++){/*여기를 int j=0; j<n; j++로 작성해도 통과되는데 소모되는 시간이 조금 더 늘어남.*/
            if(binary_search(sum.begin(),sum.end(),a[i]-a[j])){
                cout<<a[i];
                return 0;
            }
        }
    }
}