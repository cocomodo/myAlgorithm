#include <bits/stdc++.h>
using namespace std;

void unordered_set_example(){
    unordered_set<int> s;
    s.insert(-10); s.insert(100); s.insert(15);//{-10,100,15}
    s.insert(-10); // {-10,100,15}
    cout<<s.erase(100)<<'\n'; //{-10,15}, 1; 지울 수 있으면 지우고 1을 반환
    cout<<s.erase(20)<<'\n';//{-10,15}, 0; 지울것이 없으면 아무것도 하지 않고 0을 반환
    if(s.find(15)!=s.end()) cout<<"15 in s\n"; 
    cout<<s.size()<<'\n';//2
    cout<<s.count(50)<<'\n'; //unordered_set은 중복을 허용하지 않기 때문에, 이때에 count 함수는 결국 있으면 1, 없으면 0을 반환할 것이다 
    for(auto e: s ) cout<<e<<' ';
    cout<<'\n';//해시의 특성상 원소들이 크기 순서 혹은 삽입한 순서로 위치해 있지 않다.
    /*
    이게 재미있는 점인것 같은데, 결국 해시 자료구조를 통해서 자료를 담을때, 해시의 특성상
    원소들이 삽입 순서 혹은 크기 순서로 위치해 있지 않다. 그런 부분을 잘 생각해봐야 한다
    각각의 자료구조마다 특징이 있다. 근데 해시라는 자료구조는 그러한 점이 재미있는 부분이라는 생각이 든다. 
    그래서 출력을 해보면 뒤죽박죽이다. 이건 해시의 특성이다. 
    */
}

void unordered_multiset_example(){//여기서 멀티셋(multiset)은 중복을 허용한다.
    unordered_multiset<int> ms;
    ms.insert(-10); ms.insert(100); ms.insert(15);
    ms.insert(-10); ms.insert(15);//(-10,-10,100,15,15)
    cout<<ms.size()<<'\n'; // 5;
    for(auto e: ms) cout<<e<<' ';
    cout<<'\n';
    cout<<ms.erase(15)<<'\n'; // {-10, -10,100}, 2 매우중요** 다 지워버리고 지워버린 원소의 개수를 반환
    ms.erase(ms.find(-10)); // {-10,100} // 이게 또 재미있는 부분이다. erase를 find를 통해서 반환한 값을 넣어서 하면, 하나만 지워진다
    ms.insert(100);
    cout<<ms.count(100)<<'\n';//2
}

void unordered_map_example(){
    unordered_map<string,int> m;
    m["hi"]=123;
    m["bkd"]=1000;
    m["gogo"]=165;//("hi",123),("bkd",1000),("gogo",165)
    cout<<m.size()<<'\n'; //3
    m["hi"]=-7; //("hi",-7), ("bkd",1000), ("gogo",165)
    if(m.find("hi") != m.end()) cout<<"hi in m\n";
    else cout<< "hi not in m\n";
    m.erase("bkd"); // ("hi",123), ("gogo", 165)
    for(auto e:m)
        cout<<e.first<<' '<<e.second<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
}