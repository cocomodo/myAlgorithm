#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,int>> event;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++){
        int s, t;
        cin>>s>>t;
        event.push_back({s,1});
        event.push_back({t,-1});//-1로 두번째 인자를 만들어서 t를 넣었기 때문에, 정렬을 했을때 만약 s=3인 경우와, t=3인 경우가 있을때, t=3인 경우가 더 먼저 놓이고, 그 다음에 s=3인 경우가 놓이게 된다(기본 정렬 오름차순으로 했을시에)
    }
    sort(event.begin(),event.end());
    int ans=0; //가장 큰 값이 되었을때를 저장할 변수. 강의의 중첩 수들중에 최댓값을 저장.
    int curtime=event[0].first; //결국 판단의 기준이 되는 때는 각 강의들의 첫 시작 시간때에 확인하면 되므로 그때를 curtime으로 잡아서 판단의 기준으로 삼는다.
    int cur=0; //현재 강의가 중첩된 강의들의 수
    int idx=0; //vector event의 각각의 원소들을 나타내는 index. 가능 갯수는 2*n으로 n보다 사이즈가 2배로 늘어나있는 상태. 
    while(true){
        while(idx<2*n&&event[idx].first==curtime){//시작값과 끝값을 vector에 두개로 나누어서 받았기 때문에 이때에 idx는 결국 쭉 일렬로 늘어서서 2배로 길이 늘어난 상태에서의 idx를 나타낸다. 그래서 idx<2*n 라는 얘기는 맨 마지막 제일 늦은 시간에 끝나는 수업에서의 끝값까지 도달하기 전의 경우를 말한다. 
        /*event[idx].first==curtime이라는 조건을 통해서 같은 시작 시간,혹은 끝 시간을 가지는 모든 이벤트를 처리할 수 있다. 예를들면, {3,-1}과 {3,1}을 모두 이 while문 내부에서 처리할 수 있다. 그리고 idx++가 되어서 {4,-1}의 경우를 판단하게 되면, 이때에는 event[idx].first의 값인 4와, curtime인 3이 달라지기 때문에 while문 내부로 들어가지 않는다. */
            cur+=event[idx].second;//시작의 경우 1이기 때문에 더해지면 cur+1, 끝시간의 경우 -1이기 때문에 더해지면 cur-1. 이걸 통해서 현재 열려있는 강의실의 갯수를 cur의 수로 나타낼 수 있다. 
            idx++;
        }
        ans=max(ans,cur);
        if(idx==2*n) break; //이 경우는 idx가 쭉 일렬로 2배로 늘어난 시작과 끝값으로 나뉘어진 상태에서 각각의 경우들을 나타내는 숫자인데, 그게 2n이 되었다는건 결국 지금 확인하고 있는 과정에서 가장 마지막(sort를 했기 때문) 시간대의 수업의 끝나는 시간까지 도달했음을 의미한다. 그래서 이 while(true) 문을 break로 끝내고 나온다. 
        curtime=event[idx].first;
    }
    cout<<ans<<'\n';
}
/*
문제의 답은 결국 가장 많은 수업이 열리는 시간에서의 수업의 개수.
수업 개수의 변화가 발생하는 (s,1),(t,-1) 을 전부 수집한 후 정렬하고 같은 시간대의 event를
묶어서 처리한다. 
*/