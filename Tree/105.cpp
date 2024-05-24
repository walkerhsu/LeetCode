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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int left = 0;
        int right = inorder.size()-1;
        int pre_idx = 0;
        return buildSubTree(preorder, inorder, pre_idx, left, right);
    }
    TreeNode* buildSubTree(vector<int>& preorder, vector<int>& inorder, int& pre_idx, int left, int right) {
        if (pre_idx >= preorder.size()) return nullptr;
        // cout<<preorder[pre_idx]<<'\n';
        TreeNode* root = new TreeNode(preorder[pre_idx]);
        if (left == right) {
            return root;
        }
        int cur = left;
        while(cur <= right) {
            if(preorder[pre_idx] == inorder[cur]) {
                break;
            }
            cur++;
        }
        if(left <= cur-1) {
            pre_idx += 1;
            root -> left = buildSubTree(preorder, inorder, pre_idx, left, cur-1); 
        }
        if(cur+1 <= right) {
            pre_idx += 1;
            root -> right = buildSubTree(preorder, inorder, pre_idx, cur+1, right);
        }
        return root;
    }
};