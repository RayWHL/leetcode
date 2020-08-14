/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean helper(TreeNode root, long min, long max){
        if(root==null) return true;
        boolean flag=true;
        flag=flag && (root.val>min) && (root.val<max);
        if(root.left!=null)
            flag=flag && (root.val > root.left.val);
        if(root.right!=null)
            flag=flag && (root.val < root.right.val);
        return flag && helper(root.left,min,root.val) && helper(root.right,root.val,max);
    }
    public boolean isValidBST(TreeNode root) {
        return helper(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }
}

//java 没有long long int， long长度64位