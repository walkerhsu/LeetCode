/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        int ans = -1;
        countSubTree(root, cnt, ans, k);
        return ans;
    }
    void countSubTree(TreeNode* root, int& cnt, int& ans,int& k) {
        if(root->left) {
            countSubTree(root->left, cnt, ans, k);
            if (ans!=-1) return;
        }
        cnt += 1;
        if(cnt == k) {
            ans = root->val;
            return;
        }
        if(root->right) {
            countSubTree(root->right, cnt, ans, k);
            if (ans!=-1) return;
        }
        return;

        
    }
};