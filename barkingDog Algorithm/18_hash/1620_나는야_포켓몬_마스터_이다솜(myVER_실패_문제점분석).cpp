#include <bits/stdc++.h>
using namespace std;

int n, m;

unordered_map<string,int> name;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>m;
    int cnt=1;
    while(n--){
        string s;
        cin>>s;
        name[s]=cnt;
        cnt++;
    }
    while(m--){
        string tmpS;
        int tmpI;
        

    }
}
/*이 풀이의 경우는 밸류값을 이용해서 키 값을 찾아보는 방법을 고려해서 작성한 코드이다
그런데 이때에 unordered_map의 경우 hash자료구조를 이용해서 만든 컨테이너이기 때문에 밸류값을
이용한 키 값을 찾는 방향을 직접적으로 제공하지 않는다. 
그렇기 때문에 이러한 기능을 구현하기 위해서는, 


string searchKey;
int searchValue = 5;

for (const auto& pair : myMap) {
    if (pair.second == searchValue) {
        searchKey = pair.first;
        break;
    }
}

위와 같은 간접적인 방향으로 계속해서 myMap을 순회하면서 value값을 찾고 그에 pair로 엮여있는
key 값을 찾아야해서 매우 비효율적이게 될 수 있다. 
unordered_map이 어떠한 자료구조를 이용해서 만들어진 컨테이너인지, 그 자료구조의 특징을 통해서
어떠한 성질을 가질 수 있는지 등에 대해서 생각해보고, 
어떤 방향이 효율적인지, 비효율적인지 등을 고려하면서 문제를 해결하도록 하자. 

*/