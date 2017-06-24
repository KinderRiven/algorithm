#include <bits/stdc++.h>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        return dfs(t1, t2);
    }
    TreeNode* dfs(TreeNode *t1, TreeNode *t2){
        if(t1 == NULL && t2 == NULL)
            return NULL;
        if(t1 == NULL)
            t1 = new TreeNode(0);
        if(t2 == NULL)
            t2 = new TreeNode(0);
        t1 -> val += t2 -> val;
        t1 -> left = dfs(t1 -> left, t2 -> left);
        t1 -> right = dfs(t1 -> right, t2 -> right);
        return t1;
    }
    void print(TreeNode *t){

    }
};

int main(){

}
