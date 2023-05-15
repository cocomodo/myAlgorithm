#include <bits/stdc++.h>
using namespace std;

int n=10;
int arr[1'000'005];//={...}; 형태로 주어지면 됨
int tmp[1'000'005];

void merge(int st, int en){
    int mid=(st+en)/2;
    int idx_L=st;
    int idx_R=mid;
    for(int i=st; i<en;i++){
        if(idx_R==en) tmp[i]=arr[idx_L++];
        else if(idx_L==mid) tmp[i]=arr[idx_R++];
        else if(arr[idx_L]<=arr[idx_R]) tmp[i]=arr[idx_L++];
        else tmp[i]=arr[idx_R++];
    }
    for(int i=st; i<en; i++) arr[i]=tmp[i];
}
void merge_sort(int st, int en){
    if(en==st+1) return;
    int mid=(st+en)/2;
    merge_sort(st,mid);
    merge_sort(mid,en);
    merge(st,en);
}
int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);
    merge_sort(0,n);
    for(int i=0; i<n; i++) cout<<arr[i]<<' ';
}