#include <bits/stdc++.h>
using namespace std;

int ttoi(string time){
    int t;
    string h, m;
    h=time.substr(0,2);
    m=time.substr(3,2);
    t=60*(stoi(h))+stoi(m);    
    return t;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    unordered_set<string> slist;
    unordered_set<string> flist;
    string st_t, en_t, quit_t;
    cin>>st_t>>en_t>>quit_t;
    int st_tnum,en_tnum, quit_tnum;
    st_tnum=ttoi(st_t);
    en_tnum=ttoi(en_t);
    quit_tnum=ttoi(quit_t);
    while(true){
        string ch_t, user_id;
        cin>>ch_t>>user_id;
        if(cin.eof()==true) break;
        int ch_tnum;
        ch_tnum=ttoi(ch_t);
        if(ch_tnum<=st_tnum)
            slist.insert(user_id);
        if(ch_tnum>=en_tnum && ch_tnum<=quit_tnum){
            if(slist.find(user_id)!=slist.end()){
                flist.insert(user_id);
            }
        }
    }
    cout<<flist.size();
}