//중요한것. compress함수, 그리고 compare 함수. 압축하고, 차례대로 비교하고. 
#include <bits/stdc++.h>
using namespace std;

int m, n; 
int arr[102][10'005];

void compress(int a[]){
    vector<int> v(a,a+n);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=0; i<n; i++)
      a[i]=lower_bound(v.begin(),v.end(),a[i])-v.end();
}

bool compare(int a[],int b[]){/*이게 a[]와 b[]가, 입력으로 arr[i],arr[j]가 주어졌을때, 행에 대한 연산이 아니라 열에 대한 연산을 한다는것을 주의해야 한다.*/
    for(int i=0; i<n;i++){
        if(a[i]!=b[i]) return false;
    }
    return true;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>m>>n;
    for(int i=0; i<m; i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0; i<m; i++){
        compress(arr[i]);
    }
    int cnt=0;
    for(int i=0; i<m-1;i++){
        for(int j=i+1;j<m;j++){
            cnt+=compare(arr[i],arr[j]);
        }
    }
    cout<<cnt;
}