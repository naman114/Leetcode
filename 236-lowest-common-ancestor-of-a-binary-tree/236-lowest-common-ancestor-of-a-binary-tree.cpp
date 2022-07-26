/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
TC: O(N)
SC: O(logN)
*/
class Solution {
public:
    vector<TreeNode*> nrp(TreeNode* root, TreeNode* node){
        vector<TreeNode*> path;
        
        if(!root) return path;
        
        if(root == node){
            path.push_back(root);
            return path;
        }
        
        vector<TreeNode*> l = nrp(root->left, node);
        vector<TreeNode*> r = nrp(root->right, node);
        
        if(l.size()){
            l.push_back(root);
            return l;
        }
        
        if(r.size()){
            r.push_back(root);
            return r;
        }
        
        return path;
    }
    
    TreeNode* lca(vector<TreeNode*> a, vector<TreeNode*> b){
        int i = a.size() - 1;
        int j = b.size() - 1;
        
        TreeNode* ans;
        
        while(i>=0 && j>=0 && a[i] == b[j]){
            ans = a[i];
            i--;
            j--;
        }
        
        return ans;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> nrp1 = nrp(root, p);
        vector<TreeNode*> nrp2 = nrp(root, q);
        
        
        // for(auto x: nrp1) cout<<x->val<<endl;
        // cout<<endl;
        // for(auto x: nrp2) cout<<x->val<<endl;
        
        // return NULL;
        return lca(nrp1, nrp2);
    }
};