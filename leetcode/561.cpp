#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ret = 0;
        for(int i = 0; i < nums.size(); i+=2){
            ret += nums[i];
        }
        return ret;
    }
};
int main(){

    vector<int> vec;
    int n, tmp;
    Solution solve;

    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++){
            scanf("%d", &tmp);
            vec.push_back(tmp);
        }
        printf("%d\n", solve.arrayPairSum(vec));
    }
    return 0;
}
