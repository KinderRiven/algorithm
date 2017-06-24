#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void reverseWords(string &s) {
        int len = s.size(), flag = 0;
        int leading, trailing;
        for(leading = 0; s[leading] == ' '; leading++);
        for(trailing = len - 1; s[trailing] == ' '; trailing--);
        s = s.substr(leading, trailing - leading + 1);
        len = s.size();
        for(int i = 0, j = 0; i <= len;){
            if(i == len){
                s = s.substr(0, j);
                break;
            }
            else if(s[i] != ' '){
                s[j++] = s[i++];
            }
            else if(s[i] == ' '){
                s[j++] = ' ';
                while(s[i] == ' '){
                    i++;
                }
            }
        }
        len = s.size();
        for(int i = 0, j = len - 1; i < j; i++, j--){
            swap(s[i], s[j]);
        }
        flag = 0;
        for(int i = 0; i <= len; i++){
            if(s[i] == ' ' || i == len){
                for(int j = flag, k = i - 1; j < k; j++, k--){
                    swap(s[j], s[k]);
                }
                flag = i + 1;
            }
        }
    }
};

int main(){
    string s;
    ifstream is;
    Solution solve;
    getline(cin, s);
    solve.reverseWords(s);
    cout << s.size() << endl;
    cout << s << endl;
    return 0;
}
