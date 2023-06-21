/*
가능한 경우들끼리 곱하고 빼기 1(빼기 1 하는 이유는 ) 헐벗고 있는 경우를
제외하기 위해서 이다. 
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin>>tc;
    while(tc--){
        unordered_map<string,int> clothings;
        int n, ans=1;
        cin>>n;
        string a, b;
        while(n--){
            cin>>a>>b;/*받기만 하고 사용하지 않는 인자가 있는 문제도 있구나. 생각을 깨자
            고정관념에 사로잡혀 있지 말자. */
            clothings[b]++;
        }
        for(auto v: clothings) ans*=v.second+1;/*+1의 의미는 그 카테고리의 옷을
        안입는 경우에 해당한다. */
        cout<<ans-1<<'\n';
    }
}