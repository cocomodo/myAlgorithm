#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, l;
    cin>>k>>l;
    unordered_map<string, int> signup{};
    for(int i=0; i<l; i++){
        string student_num;
        cin>>student_num;
        if(signup.find(student_num)!=signup.end()){
            signup.erase(student_num);
            signup[student_num]=i;
        }
        else
            signup[student_num]=i;
    }
    vector<pair<string,int>> slist(signup.begin(),signup.end());
    sort(slist.begin(),slist.end(),[](auto& a, auto& b){
        return a.second<b.second;
    });
    int en=min(k,(int)slist.size());/*수강 가능 인원보다 수강을 신청한 인원이 적을
    수도 있기 때문에 이런식의 과정을 통해서 작은 값을 찾아야 한다. 
    */

    for(int i=0; i<en; i++)
        cout<<slist[i].first<<'\n';
}