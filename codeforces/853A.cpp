#include <bits/stdc++.h>
using namespace std;
int main(){

    int s,t1,t2,v1,v2;
    while(scanf("%d %d %d %d %d", &s, &v1, &v2, &t1, &t2) != EOF){
        int s1 = t1 + v1 * s + t1;
        int s2 = t2 + v2 * s + t2;
        if(s1 < s2)
            printf("First\n");
        else if(s1 > s2)
            printf("Second\n");
        else
            printf("Friendship\n");
    }
}
