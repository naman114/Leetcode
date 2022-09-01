# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    cnt = 0
    def solve(self, root: TreeNode, max_so_far):
        if root == None:
            return
        
        if root.val >= max_so_far:
            self.cnt += 1
        
        max_so_far = max(max_so_far, root.val)
        
        self.solve(root.left, max_so_far)
        self.solve(root.right, max_so_far)
        
    def goodNodes(self, root: TreeNode) -> int:
        self.solve(root, -10**5)
        return self.cnt