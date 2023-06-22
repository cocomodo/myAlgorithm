#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<int> arr(n);
    vector<bool> chk(100'002);
    for(int i=0; i<n; i++) cin>>arr[i];/*먼저 vecotr의 원소의 갯수를 선언하면
    이런식으로 array를 사용하듯이 똑같이 사용할 수 있다. 결국 vector는 동적 배열이니까*/

    long long ans =0;
    chk[arr[0]]=1;//첫번째 원소는 체크
    int en=0;
    for(int st=0; st<n; st++){
        while(en<n-1 && !chk[arr[en+1]]){/*en<n-1까지만 en을 움직이고, 
        en==n-1이 되면 그때부터는 st만 움직이며 불을 끄고 ans를 더하게 된다.*/ 
            en++;
            chk[arr[en]]=1;
        }
        ans+=en-st+1;/*이 연산이 의미하는 바는, 예를들어 1부터 5까지 쭉 막힘없이
        en++을 하게 되면, 그때 가능한 경우들은
        1
        1 2
        1 2 3
        1 2 3 4
        1 2 3 4 5
        가 될것이고, 이 가능한 경우들의 경우의 수는 en-st+1과 같게 된다는 것을
        나타내는것으로 보여진다. */
        chk[arr[st]]=0; //st를 옮기기 전에 체크 불을 꺼두는 과정. 
    } 
    cout<<ans;
}

// 100'000*99'999/2 의 값이 최대
// 거의 50'000*100'000와 유사한 값
// 이때의 값은 5'000'000'000 50억개. int 범위를 넘어선다. 이런 유형에서는 정답의 값의 범위를
// 주의하도록 하자. 

/*
5
1 2 3 1 2 의 예제 입력에 대한 경우의 수를 나열해보면, 

1 
1 2
1 2 3 //en++ 할때마다 경우의 수를 ans++ 한다.
2 //체크한 배열의 원소를 만나면 st++ 하고 en=st로 옮긴다. st++ 시에도 ans++ 한다.
2 3
2 3 1
3
3 1
3 1 2
1
1 2
2

==> 그런데 경우의 수들의 합을 더 쉽게 구하는 방법이 있다. 
이 경우는
1
1 2
1 2 3

2 
2 3
2 3 1

3
3 1
3 1 2

1
1 2

2

으로 묶음으로 분류해서, 각각의 묶음이, 결국 맨 끝자리에 도달한 en에서 시작 위치 st를 뺀뒤+1을
한것이라는 사실을 이용한다. 참고로 en-st+1 은 갯수를 카운트 하는 형태와 같다. 
*/ 