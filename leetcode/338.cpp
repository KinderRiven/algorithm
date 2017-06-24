#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    int cen;
    int calc(int num){
        int cen = 0;
        while(num){
            cen++;
            num /= 2;
        }
        return cen;
    }
    void dfs(vector<int> &vec, int cnt, int ce){
        if(ce + 1 > cen){
            vec.push_back(cnt);
            return;
        }
        else{
            dfs(vec, cnt, ce + 1);
            dfs(vec, cnt + 1, ce + 1);
        }
    }
public:
    vector<int> countBits(int num) {
        vector<int> vec;
        this -> cen = calc(num);
        dfs(vec, 0, 1);
        dfs(vec, 1, 1);
        vec.erase(vec.begin() + num + 1, vec.begin() + vec.size());
        return vec;
    }
};
int main(){
    Solution solve;
    int n;
    cin >> n;
    vector<int> vec = solve.countBits(n);
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    return 0;
}
