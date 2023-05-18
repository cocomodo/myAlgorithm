#include <bits/stdc++.h>
using namespace std;

int n;
string s[55];

bool cmp(const string& a,const string& b)  {
    // cout<<"Comparing "<<a<<" and "<<b<<'\n';
    int lena=a.size(),lenb=b.size();
    int suma=0, sumb=0;
    if(lena!=lenb) return lena<lenb;
    /*
    내가 공부한 것으로 되돌아보면, a는 뒤에것, b는 앞에것
    그렇다는 얘기는 여기서 return lena<lenb;는,
    앞에것의 길이값이 뒤에것의 길이값보다 크다면, true를 반환하고,
    그럴때 위치를 바꾸며 정렬이 이루어질것이다. 그렇게 되면 다시 앞에것의
    길이값이 작아질 것이고, 뒤의것이 길이값이 길어질것이다. 
    그렇다면 그건 원하는 형태의 정렬이 될것이다.
    결국 이건 true를 반환하면 정렬을 행한다, 
    false를 반환하면 정렬을 행하지 않는다. 
    그때에 a요소는 뒤에 원소, b요소는 앞의 원소이다. 
    */
   for(int i=0; i<lena;i++){ //숫자만 더한다.
    if(isdigit(a[i])) suma+=(a[i]-'0');
    if(isdigit(b[i])) sumb+=(b[i]-'0');
   }
   if(suma!=sumb) return suma<sumb;
   return a<b; //사전순 부분.
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>s[i];
    }
    sort(s,s+n,cmp);
    for(int i=0; i<n; i++)
        cout<<s[i]<<'\n';
}