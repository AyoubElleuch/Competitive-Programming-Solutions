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
        // use BFS and stop at the kth pop from the stack.
        stack<TreeNode*> s;
        TreeNode* current = root;
        int counter = 0;

        while(!s.empty() || current != nullptr){
            if(current) {
                s.push(current);
                current = current->left;
            }else {
                current = s.top();
                s.pop();
                ++counter;

                if(counter==k) return current->val;

                current = current->right;
            }
        }
        return current->val;
    }
};