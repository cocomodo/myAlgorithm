// a를 b번 곱한 수를 c로 나눈 나머지
// 이 곱해가는 과정에서 c로 나누고, 그 나머지들끼리 곱하면서 c로 나누면 되는거다. 

// <첫번째 코드>
#include <bits/stdc++.h>
using namespace std;

int func(int a, int b, int c){
    if(b==1) 
        return a%c;
    return (a*func(a,b-1,c))%c; 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 

    int a, b, c;
    cin>>a>>b>>c;
    cout<<func(a,b,c);
    return 0;

}
// <두번째 코드>
// #include <bits/stdc++.h>
// using namespace std;

// using ll = long long;

// ll POW(ll a, ll b, ll m){
//   if(b==1) return a % m;
//   ll val = POW(a, b/2, m);
//   val = val * val % m;
//   if(b%2 == 0) return val;
//   return val * a % m;
// }

// int main(void){
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   ll a,b,c;
//   cin >> a >> b >> c;
//   cout << POW(a,b,c);
// }

// 첫번째 코드는 분할정복을 사용하지 않고 재귀함수를 이용해 거듭제곱을 
// 구하는 방법이고, 두번째 코드는 분할정복을 사용하는 방법입니다.

// 두번째 코드에서 거듭제곱을 구하는 연산 횟수는 b의 이진수 표현에서 
// 1의 개수인 log(b)에 비례합니다. 따라서 두번째 코드의 연산 횟수는 
// log(b)에 비례합니다.

// 반면에 첫번째 코드에서는 b-1번의 재귀호출이 발생합니다.
// 이때 매번 나머지 연산을 하기 때문에 b가 아주 큰 경우 연산량이 
// 매우 많아질 수 있습니다. 예를 들어 b가 10^9이라면 첫번째 코드에서는
//  10^9-1번의 재귀호출이 발생하게 됩니다. 따라서 첫번째 코드에서의 
//  연산 횟수는 b-1에 비례합니다.

// 따라서 두 코드의 연산 횟수는 log(b)와 b-1에 비례하므로, b가 
// 아주 큰 경우 두번째 코드가 첫번째 코드보다 훨씬 빠르게 동작합니다.