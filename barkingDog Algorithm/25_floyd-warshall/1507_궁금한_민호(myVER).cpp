#include <bits/stdc++.h>
using namespace std;

int n;
int d[30][30];
bool un[30][30];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin>>d[i][j];
    
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++){
            bool isunique=true;
            for(int k=1; k<=n; k++){
                if(k==i || k==j) continue;
                if(d[i][k]+d[k][j]<d[i][j]){
                    cout<<"-1";
                    return 0;
                }
                else if(d[i][k]+d[k][j]==d[i][j])
                    isunique=false;
                
                /*모든 k들에 대해서 위의 과정들을 싹 거치고 나서도, 아직 isunique==true로 남아 있다면, */
            }
            if(isunique==true){
                un[i][j]=true;
                un[j][i]=true;
            }
        }

    int ans=0;
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            if(un[i][j]) ans+=d[i][j];
        }
    }
    cout<<ans;
}

