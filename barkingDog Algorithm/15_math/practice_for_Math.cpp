#include <bits/stdc++.h>
using namespace std;

int chk(){
    for(int i=3; i<30; i+=6){
        if(i%5==2)
            return i;
    }
    return -1;
}