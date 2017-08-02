#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int main(){
    int k;
    char s[maxn];
    while(scanf("%d", &k) != EOF){
        scanf("%s", s);
        int L = strlen(s);
        int sum = 0;
        int vis[10] = {0};
        int ret = 0;
        for(int i = 0; i < L; i++){
            vis[s[i] - '0']++;
            sum += (s[i] - '0');
        }
        for(int i = 0; i < 9 && sum < k; i++){
            int all = (9 - i) * vis[i];
            if(sum + all < k){
                ret += vis[i];
                sum += all;
            }
            else{
                int left = (k - sum) / (9 - i);
                if((k - sum)  % (9 - i) != 0){
                    left++;
                }
                ret += left;
                break;
            }
        }
        printf("%d\n", ret);
    }
    return 0;
}
