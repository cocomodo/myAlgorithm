#include <bits/stdc++.h>
using namespace std;

void set_example(){
    set<int> s;
    s.insert(-10); s.insert(100); s.insert(15);//{-10,15,100}
    s.insert(-10); //{-10,15,100}
    cout<<s.erase(100)<<'\n'; //{-10,15}, 1
    cout<<s.erase(20)<<'\n'; //{-10,15}, 0
    if(s.find(15)!=s.end()) cout<<"15 in s\n";
    else cout<< "15 not in s\n";
    cout<<s.size()<<'\n';//2
    cout<<s.count(50)<<'\n'; //0 =>count 함수는 주어진 값과 일치하는 원소의 개수를 반환하는 함수.
    for(auto e: s) cout<<e<<' ';
    cout<<'\n';
    s.insert(-40); // {-40,-10,15}
    set<int>::iterator it1=s.begin();//{-40(<-it1),-10,15}
    it1++; // {-40, -10(<-it1), 15}
    auto it2 = prev(it1); //{-40(<-it2), -10, 15}
    it2=next(it1); // {-40, -10, 15(<- it2)}
    advance(it2, -2); // {-40(<-it2),-10,15}
    auto it3 = s.lower_bound(-20);//{-40, -10(<-it3),15}
    auto it4=s.find(15); //{-40,-10,15(<-it4)}
    cout<<*it1<<'\n'; //-10
    cout<<*it2<<'\n'; //-40
    cout<<*it3<<'\n'; //-10
    cout<<*it4<<'\n'; // 15
}

void multiset_example(){
    multiset<int> ms;
    ms.insert(-10); ms.insert(100); ms.insert(15);//{-10,15,100}
    ms.insert(-10); ms.insert(15); //{-10,-10,15,15,100}
    cout<<ms.size()<<'\n'; //  5
    for(auto e : ms) cout << e <<  ' ';
    cout<<'\n';
    cout<< ms.erase(15)<<'\n';// {-10,-10,100}, 2 => 지워진 원소의 개수를 반환
    ms.erase(ms.find(-10)); // {-10, 100} => find 함수는 첫번째 원소를 찾아주는걸 보장하지 않음. 하지만 바킹독의 실험결과 gcc 상에서는 현재까지 첫번째를 반환. 만약 첫번째가 꼭 보장되어야 한다면 find를 쓰면 안되고, lower_bound 를 사용해야 한다. 
    /*erase함수는 인자를 값으로 주면 값이 그와 같은 모든 원소를 제거. 
    인자를 iterator로 주면 그 원소를 제거*/
    ms.insert(100); // {-10, 100, 100}
    cout<<ms.count(100)<<'\n'; // 2
    auto it1=ms.begin(); // {-10 (<-it1), 100, 100}
    auto it2=ms.upper_bound(100); //{-10,100,100} (<-it2)
    auto it3=ms.find(100); //{10, 100(<-it3),100}
    cout<<*it1<<'\n'; // -10
    cout<<(it2==ms.end())<<'\n'; // 1
    cout<<*it3<<'\n'; // 100
}

void map_example(){
    map<string, int> m;
    m["hi"] = 123;
    m["bkd"] = 1000;
    m["gogo"] = 165; //("bkd",1000),("gogo",165),("hi",123)=>순서를 나타내고, 이 순서들은 key 값의 순서로 결정된다. 
    cout<<m.size()<<'\n'; // 3
    m["hi"] =-7; // ("bkd", 1000), ("gogo", 165), ("hi", -7)
    if(m.find("hi")!=m.end()) cout<<"hi in m\n";
    else cout<< "hi not in m\n";
    m.erase("bkd"); // ("gogo",165), ("hi", 123)
    for(auto e: m)
        cout<<e.first<<' '<<e.second<<'\n';
    auto it1=m.find("gogo");
    cout<<it1->first<<' '<<it1->second<<'\n';

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
}