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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        
        if(!root) return ans;
        
        vector<TreeNode*> q;
        q.push_back(root);
        
        while(q.size()){
            ans.push_back(q.back()->val);
            int n = q.size();
            for(int i = 0; i < n; ++i){
                TreeNode* node = q[0];
                q.erase(q.begin());
                if(node->left) q.push_back(node->left);
                if(node->right) q.push_back(node->right);
            }
        }
        return ans;
    }
};