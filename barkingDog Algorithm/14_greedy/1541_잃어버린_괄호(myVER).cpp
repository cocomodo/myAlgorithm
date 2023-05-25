#include <bits/stdc++.h>
using namespace std;

int tmp, ans;
int sign=1;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input;
    cin>>input;
    for(char c: input){
        if(c=='+'||c=='-'){
            ans+=tmp*sign;
            if(c=='-') sign=-1;
            tmp=0;
        }
        else{//temp에 계속해서 부호 앞에 나왔던 수들을 저장해서 쌓아나감 
            tmp*10;
            tmp+=c-'0';//이러한 방법을 통해서 char -'0'을 이용해서 int 값으로 변경해줌 이 방법에 대해서는 익숙해지고 이런식의 문제를 만나서 string으로 받고, 각각의 char를 이용해서 정수로 바꿀때 사용하도록 하자. 
        }
    }
    ans+=tmp*sign;//마지막 부호가 등장하고 난 뒤에 쌓인 tmp값을 저장해주는 과정
    cout<<ans;
}
//이 문제의 경우 처음 -가 나오고 나서부터는 그 뒤에 나오는 +는 모두 -의 범위 내로 괄호를 이용해서 엮을 수 있고, 그리고 나서 또 다시 등장하는 -는 결국에는 괄호로 잘 묶어내는 범위내의 새로운 시작점을 또 알려주기 때문에 또다시 거기서부터 -로 뒤에 나오는 모든걸 묶을 수 있기 때문에, 이 문제는 첫번째 -가 나오기 전까지의 숫자들은 모두 +로 넣고, 그리고 처음으로 -가 등장하고 난 뒤에 수들은 모두 -로 빼버리면 되기 때문에, 여기처럼 if(c=='-') sign=-1; 을 통해서 -1로만 바꾸는 부분만 있고, 다시 sign을 +1로 바꾸는 부분은 없다.