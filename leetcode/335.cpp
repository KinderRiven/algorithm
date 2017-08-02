#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {

    }
};
int main(){
    vector<int> x;
    Solution solve;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int tmp;
        scanf("%d", &tmp);
        x.push_back(tmp);
    }
    printf("%d\n", solve.isSelfCrossing(x));
    return 0;
}
