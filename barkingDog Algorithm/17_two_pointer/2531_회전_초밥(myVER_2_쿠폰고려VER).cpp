#include <bits/stdc++.h>
using namespace std;

int n, d, k, c;
int a[33'005];//n+k에 조금 여유분 추가.선형으로 만들 예정. 
vector<int> chk(3'001,0);
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>d>>k>>c;
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=n;i<n+k-1;i++){
        a[i]=a[i-n]; //뒷부분에 일렬로 수열의 앞쪽을 맵핑.
    }//이제 시작 원소를 st=0; 범위를 <n+k-1; 까지로 잡으면 됨. 
    int enidx=n+k-1;
    chk[c]++;//쿠폰 받은건, 이미 먹은걸로 고려해서 check하고 ans++;mxans++; 해준 후 시작
    int ans=1;//최대 가짓수.
    int cnt=0;//먹은 가짓수.
    int st=0;
    int en=k-1;
    int maxans=1;
    for(int i=0; i<k; i++) chk[a[i]]++; // 0부터 k-1까지 먹었다고 치고 스타트.
    for(int i=0; i<k; i++){
        if(chk[a[i]]==1) ans++;
    }
    maxans=max(maxans,ans);
    while(en<enidx-1){
        chk[a[st]]--;
        if(chk[a[st]]==0) ans--;
        st++;
        en++;
        chk[a[en]]++;
        if(chk[a[en]]==1) ans++;
        maxans=max(maxans,ans);
    }
    cout<<maxans;
}
/*
이 풀이 시도의 경우 쿠폰을 고려하지 못한 형태의 풀이이다
쿠폰을 고려해서 애초부터 풀이를 작성해야 하는데 그렇게 하지 못했다. 
*/

/*
결국 가장 다양한 초밥을 먹을 수 있게 만들어주는게 포인트
무료로 쿠폰을 하나 주는데, 쿠폰을 통해 먹을 수 있는 초밥은
연속적으로 선택한 수열에 포함시키지 않아야 가장 많은 경우를 먹을 수 있다. 

음식점의 벨트 상태 == N
초밥의 가짓수 == d
연속해서 먹는 접시의 수 ==k
쿠폰 번호 == c 
N, d , k , c 순서로 예제입력을 받는다. 
*/



/*
8 30 4 30 
7
9
7
30
2
7
9
25
인 경우와

8 30 4 30
25
7
9
7
30
2
7
9
인 경우, 결국 경우에 해당하는 (2 7 9 25)+(30) 형태로 예제 출력 5를 얻어야 한다*/

/*
뒷부분에 k-1개의 배열의 앞쪽 원소들을 복사해서 넣어놓으면, 완전히 선형으로 변형 시킬 
수 있다. 그렇게 문제를 해결하면 그동안 알고있던 형태의 문제로 변환이 가능할 것으로 보여진다. 
*/
