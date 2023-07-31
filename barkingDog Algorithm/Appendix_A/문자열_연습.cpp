#include <bits/stdc++.h>
using  namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s="hello";
    s+="BKD!"; // hello BKD!
    cout<<s.size()<<'\n'; // 10 
    cout<<s.substr(2,3) <<'\n'; //llo
    cout<<s[1]<<'\n'; //e
    s.replace(6,4,"guys"); // hello guys
    cout<<s<<'\n';
    int it=s.find("guys"); //6
    s.replace(it, 4, "everyone"); //hello everyone
    cout<<s<<'\n';
    s.erase(7,6); // hello ee
    cout<<s<<'\n';
    s[6]='m'; //hello me
    cout<<s<<'\n';
    s.insert(0,"say "); //say hello  me
    cout<<s<<'\n';
    if(s.find("to")==string::npos) // string ::npos==-1
     cout<<"'to' is not in string 's'\n";
}