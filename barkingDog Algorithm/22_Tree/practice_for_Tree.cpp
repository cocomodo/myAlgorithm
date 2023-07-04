/*
      1
    (2) (3)
   2     4
           (2)
            3
*/
/*이 문제의 경우는 트리의 각각의 간선들이 길이가 1이 아니라 다르게
주어지는 문제이다. 
*/
/*이중배열을 선언해서 각각의 간선들이 가지는 값을 2중배열로 저장하면
될것으로 보여진다 

0 1 2 3 4 
1 0 2 5 3
2 2 0 7 5
3 5 7 0 2 
4 5 5 2 0

*/

/*
4 2
2 1 2
4 3 2
1 4 3
1 2
3 2

*/
#include <bits/stdc++.h>
using namespace std;

int n, m;
int lth[1'005][1'005];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
}