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
    void recoverTree(TreeNode* root) {
        // inorder traversal
        vector<TreeNode*> vec;

        TreeNode* head = root;
        traverseTree(head, vec);

        int first = -1, second = -1;
        
        // find the swapped nodes and swap again
        for(int i=1; i<vec.size(); i++){
            if(vec[i-1]->val > vec[i]->val){
                if(first == -1) first = i - 1;
                second = i;
            }
        }

        if(first != -1 && second != -1) swap(vec[first]->val, vec[second]->val);

        return;
    }

    void traverseTree(TreeNode* node, vector<TreeNode*>& vec){
        if(!node) return;

        traverseTree(node->left, vec);
        vec.push_back(node);
        traverseTree(node->right, vec);

        return;
    }
};