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
    bool isValidBST(TreeNode* root) {
        if(!root) return true;

        queue<tuple<TreeNode*, long long, long long>> q;
        q.push({root, LLONG_MIN, LLONG_MAX});


        while(!q.empty()){
            auto [current, low, high] = q.front();
            q.pop();

            if(current->val <= low || current->val >= high) return false;

            if(current->left){
                q.push({current->left, low, current->val});
            }
            if(current->right){
                q.push({current->right, current->val, high});
            }
        }

        return true;
    }
};