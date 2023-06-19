#include <bits/stdc++.h>
using namespace std;

int n;
unordered_set<string> worker;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    string name;
    string state;
    while(n--){
        cin>>name>>state;
        if(state=="enter"){
            worker.insert(name);
        }
        if(state=="leave"){
            worker.erase(name);
        }
    }
    sort(worker.begin(),worker.end(),greater<>());
    for(auto e:worker) cout<<e<<'\n';
}
/*
이렇게 풀이를 작성했을때, 코드를 실행해보면, 
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__algorithm/sort.h:211:46: error: invalid operands to binary expression ('std::__hash_const_iterator<std::__hash_node<std::string, void *> *>' and 'int')

라는 에러를 받게되어서 정상적으로 동작하지 않는다. */