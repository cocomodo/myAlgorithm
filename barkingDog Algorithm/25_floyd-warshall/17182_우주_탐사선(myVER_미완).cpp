#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int d[15][15];
int n, st;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>st; //이때 st는 탐색을 시작하는 행성의 위치
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>d[i][j];
        }
    }
    
    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(d[i][k]+d[k][j]<d[i][j]){
                    d[i][j]=d[i][k]+d[k][j];
                }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<d[i][j]<<' ';
        }
        cout<<'\n';
    }
}