#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int L,P,V;
    int i=1;
    while(true){
        
        int n=0;
        cin>>L>>P>>V;
        if(L==0&&P==0&&V==0) break;
        while(V>=0){
            if(V<P){
                if(V>=L) {
                    n=n+L;
                    break;
                }else{//V<L
                    n=n+V;
                    break;
                }
            }
            V=V-P;
            n=n+L;
        }
        cout<<"Case "<<i<<": "<<n<<'\n';//최대 몇일 사용할 수 있는지 이 뒤에 출력
        i++;
    }
}