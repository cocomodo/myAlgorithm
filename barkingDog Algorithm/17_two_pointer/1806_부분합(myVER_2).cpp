#include <bits/stdc++.h>
using namespace std;

int n, s;
int a[100'005];
int mn=0x7fffffff;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>s;
    for(int i=0; i<n;i++) cin>>a[i];
    int en=0;
    int tot=a[0];
    for(int st=0;st<n;st++){
        while(en<n && tot<s){
            en++;
            tot+=a[en];
        }//여길 탈출한 순간 en==n이거나, tot>=s인 것이다.
        if(en==n) break;//en==n인 경우는 여기서 걸러내고, 이걸 지나간 뒤부터는 tot>=s인 경우들만 있는 것이다. 
        mn=min(mn,en-st+1);
        tot-=a[st];
    }
    if(mn==0x7fffffff) mn=0;//위의 경우에서, en==n이 되었는데, tot>=s가 한번도 일어나지 않았다면, mn값이 갱신이 안되서 mn==0x7fffffff 으로 남아있게 된다. 
    cout<<mn;
}