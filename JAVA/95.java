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
    public void helper(int begin, int end, List<TreeNode> output){
        if(begin>end){
            output.add(null);
            return;
        }
        for(int i=begin;i<=end;++i){
            List<TreeNode> left=new ArrayList<>();
            List<TreeNode> right=new ArrayList<>();
            helper(begin,i-1,left);
            helper(i+1,end,right);
            for(TreeNode lefttree:left){
                for(TreeNode righttree:right){
                    TreeNode root=new TreeNode(i);
                    root.left=lefttree;
                    root.right=righttree;
                    output.add(root);
                }
            }
        }
    }

    public List<TreeNode> generateTrees(int n) {
        List<TreeNode> output=new ArrayList<>();
        if(n!=0)
            helper(1,n,output);
        return output;
    }
}