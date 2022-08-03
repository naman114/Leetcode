/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int solve(Node* root){
        if(!root) return 0;
        
        int maxDepth = 0;
        for(Node* child: root->children){
            maxDepth = max(maxDepth, solve(child));    
        }
        
        return maxDepth + 1;
    }
    
    int maxDepth(Node* root) {
        return solve(root);    
    }
};