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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            vector<int> lvl;
            int n = q.size();
            
            for(int i = 0; i < n; ++i){
                TreeNode* rem = q.front();
                q.pop();
                
                lvl.push_back(rem->val);
                
                if(rem->left) q.push(rem->left);
                if(rem->right) q.push(rem->right);
            }
            
            ans.push_back(lvl);
        }
        
        return ans;
    }
};