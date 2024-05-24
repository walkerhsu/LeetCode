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
    struct TreeNodeDepth {
        TreeNode* node;
        int depth = 0;
    };
    int maxDepth(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        queue<TreeNodeDepth> qtree;
        TreeNodeDepth rootDepth(root, 1);
        qtree.push(rootDepth);
        int answer = 1;
        while(!qtree.empty()) {
            TreeNodeDepth first = qtree.front();
            qtree.pop();
            if(first.node->left != nullptr) {
                TreeNodeDepth nodeDepth(first.node->left, first.depth + 1);
                qtree.push(nodeDepth);
                if(first.depth + 1 > answer) {
                    answer = first.depth + 1;
                }
            }
            if(first.node->right != nullptr) {
                TreeNodeDepth nodeDepth(first.node->right, first.depth + 1);
                qtree.push(nodeDepth);
                if(first.depth + 1 > answer) {
                    answer = first.depth + 1;
                }
            }
        }
        return answer;
    }
};