#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    int row_size, column_size;
    int vis[150][150];
    void init(){
        memset(vis, 0, sizeof(vis));
    }
    void dfs(int x, int y, vector<vector<char> > &board){
        if(!vis[x][y] && board[x][y] == 'X'){
            vis[x][y] = 1;
            if(x + 1 < row_size)
                dfs(x + 1, y, board);
            if(x - 1 >= 0)
                dfs(x - 1, y, board);
            if(y + 1 < column_size)
                dfs(x, y + 1, board);
            if(y - 1 >= 0)
                dfs(x, y - 1, board);
        }
    }
public:
    int countBattleships(vector<vector<char> >& board) {
        init();
        this -> row_size = board.size();        //hang
        this -> column_size = board[0].size();  //lie
        int ret = 0;
        for(int i = 0; i < this -> row_size; i++){
            for(int j = 0; j < this -> column_size; j++){
                if(board[i][j] == 'X' && !vis[i][j]){
                    dfs(i, j, board);
                    ret++;
                }
            }
        }
        return ret;
    }
};
int main(){
    vector<vector<char> >mapper;
    string s;
    Solution solve;
    while(cin >> s){
        vector<char> tmp;
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            tmp.push_back(c);
        }
        mapper.push_back(tmp);
    }
    cout << solve.countBattleships(mapper) << endl;
    return 0;
}
