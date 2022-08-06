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
/*
TC: O(N)
SC: O(N) when the tree is skewed

If the linked list id to be formed on the left child:
    root->left = prev;
    root->right = NULL;
    prev = root;

What happens if you visit left first and then right?
    1 5 6 2 4 3

Direction of traversal is opposite to the resultant flatenned LL
*/

class Solution {
public:
    void flatten(TreeNode* root, TreeNode* &prev){
        if(!root) return;
        
        flatten(root->right, prev);
        flatten(root->left, prev);
        
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
    void flatten(TreeNode* root) {
        TreeNode* prev = NULL;
        flatten(root, prev);
    }
};