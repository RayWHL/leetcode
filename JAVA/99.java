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
    private TreeNode first,last,pre;
    private void helper(TreeNode root){
        if(root.left!=null){
            helper(root.left);
        }
        if(pre!=null){
            if(root.val<pre.val){
                if(first==null) first=pre;
                last=root;
            }
        }
        pre=root;
        if(root.right!=null){
            helper(root.right);
        }
    }
    public void recoverTree(TreeNode root) {
        first=null;
        last=null;
        pre=null;
        if(root!=null){
            helper(root);
            int temp=first.val;
            first.val=last.val;
            last.val=temp;
        }
    }
}