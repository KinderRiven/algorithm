#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void parseString(string s, int *a, int *b){
        int i = 0, flag = 0, tmp = 0;
        if(s[0] == '-') {
            i++;
            flag = 1;
        }
        for(; i < s.size(); i++){
            if(s[i] == '+'){
                *a = (flag == 1) ? -tmp : tmp;
                if(s[i + 1] == '-'){
                    flag = 1;
                    i++;
                }
                else flag = 0;
                tmp = 0;
            }
            else if(s[i] == 'i'){
                *b = (flag == 1) ? -tmp : tmp;
            }
            else{
                tmp = tmp * 10 + (s[i] - '0');
            }
        }
    }
    string complexNumberMultiply(string a, string b) {
        int a_a = 0, a_b = 0;
        int b_a = 0, b_b = 0;
        parseString(a, &a_a, &a_b);
        parseString(b, &b_a, &b_b);
        int c_a = a_a * b_a - a_b * b_b;
        int c_b = a_a * b_b + b_a * a_b;
        stringstream stream;
        stream << c_a << "+" << c_b << "i";
        string ret = stream.str();
        return ret;
    }
};
int main(){
    string s1, s2;
    Solution solve;
    while(cin >> s1 >> s2)
        cout << solve.complexNumberMultiply(s1, s2) << endl;
    return 0;
}
