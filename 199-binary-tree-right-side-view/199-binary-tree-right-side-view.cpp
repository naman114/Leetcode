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
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size()){
            int n = q.size();
            for(int i = 0; i < n; ++i){
                TreeNode* node = q.front();
                q.pop();
                
                if(i == n-1) ans.push_back(node->val);
                
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }
        return ans;
    }
};

/*
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        
        if(!root) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        TreeNode* last = root;
        
        while(q.size()){
            ans.push_back(last->val);
            int n = q.size();
            for(int i = 0; i < n; ++i){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                    last = node->left;
                } 
                if(node->right){
                    q.push(node->right);
                    last = node->right;
                } 
            }
        }
        
        return ans;
    }
};
*/