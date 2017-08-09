//
// Created by 韩书楷 on 2017/8/9.
//
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
};

int main() {

    vector<int> arr;
    Solution solution;
    int tmp;
 
   while(scanf("%d", &tmp) != EOF) {
        cin >> tmp;
        arr.push_back(tmp);
    }

    vector<vector<int>> res = solution.threeSum(arr);
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}

