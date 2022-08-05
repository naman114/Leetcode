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

// 2 STACKS: ACTUALLY TRAVERSING IN ZIG ZAG FASHION
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        if(!root) return ans;
        
        stack<TreeNode*> LR;
        stack<TreeNode*> RL;
        
        LR.push(root);
        
        while(!LR.empty() || !RL.empty()){
            vector<int> lvl;
            
            while(!LR.empty()){
                TreeNode* node = LR.top();
                LR.pop();
                
                lvl.push_back(node->val);
                
                if(node->left) RL.push(node->left);
                if(node->right) RL.push(node->right);
            }
            
            if(lvl.size() > 0){
                ans.push_back(lvl);
                lvl.clear();
            }
            
            while(!RL.empty()){
                TreeNode* node = RL.top();
                RL.pop();
                
                lvl.push_back(node->val);
                
                if(node->right) LR.push(node->right);
                if(node->left) LR.push(node->left);
            }
            
            if(lvl.size() > 0)
                ans.push_back(lvl);
        }
        
        return ans;
    }
};


/*
*****WITHOUT REVERSING*****

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        if(!root) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int dir = 1; // LR 1, RL 0
        
        while(!q.empty()){
            int n = q.size();
            
            vector<int> lvl(n);
            
            for(int i = 0; i < n; ++i){
                TreeNode* node = q.front();
                q.pop();
                
                if(dir == 1) lvl[i] = node->val;
                else lvl[n - i - 1] = node->val;
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            
            ans.push_back(lvl);
            
            dir ^= 1;
        }
        
        return ans;
    }
};
*/

/*
*****Reversing the vector*****

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        if(!root) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int dir = 1; // LR 1, RL 0
        
        while(!q.empty()){
            int n = q.size();
            
            vector<int> lvl;
            
            for(int i = 0; i < n; ++i){
                TreeNode* node = q.front();
                q.pop();
                
                lvl.push_back(node->val);
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            
            if(dir == 0) 
                reverse(lvl.begin(), lvl.end());
            
            ans.push_back(lvl);
            
            dir ^= 1;
        }
        
        return ans;
    }
};

*/