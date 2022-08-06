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
    bool areMirrorImages(TreeNode* root1, TreeNode* root2){
        // NULL check: If either is NULL, both should be NULL
        if(root1 == NULL || root2 == NULL) return root1 == root2;
        
        // Value check
        if(root1->val != root2->val) return false;
        
        return areMirrorImages(root1->left, root2->right) && areMirrorImages(root1->right, root2->left);
    }
    bool isSymmetric(TreeNode* root) {
        return areMirrorImages(root, root);
    }
};

/*
class Solution {
public:
    bool areMirrorImages(TreeNode* root1, TreeNode* root2){
        if(!root1 || !root2) return true;
        
        bool valMismatch = root1->val != root2->val;
        bool leftMismatch = (root1->left != NULL) ^ (root2->right != NULL);
        bool rightMismatch = (root1->right != NULL) ^ (root2->left != NULL);
        
        if(valMismatch || leftMismatch || rightMismatch) return false;
        
        if(areMirrorImages(root1->left, root2->right) == false) return false;
        if(areMirrorImages(root1->right, root2->left) == false) return false;
        
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        return areMirrorImages(root, root);
    }
};
*/
