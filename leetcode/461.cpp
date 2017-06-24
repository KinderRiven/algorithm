#include <bits/stdc++.h>
class Solution {
public:
    int hammingDistance(int x, int y) {
        int ret = 0;
        while(x || y){
            ret += ((x & 1) ^ (y & 1));
            x >>= 1;
            y >>= 1;
        }
        return ret;
    }
};
int main(){
    int x, y;
    Solution solve;
    while(scanf("%d %d", &x, &y) != EOF){
        printf("%d\n", solve.hammingDistance(x, y));
    }
}
