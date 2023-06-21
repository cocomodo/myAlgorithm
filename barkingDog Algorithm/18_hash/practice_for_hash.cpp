#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    unordered_map<string,string> maching;
    while(n--){
        string gname;
        int gnum;
        cin>>gname;
        cin>>gnum;
        while(gnum--){
            string mname;
            cin>>mname;
            maching[mname]=gname;
        }
    }
    while(m--){
        string sq;
        int iq;
        cin>>sq>>iq;
        if(iq==1){
            cout<<maching[sq]<<'\n';
        }
        else{// iq==0이면, 

        }
    }
}