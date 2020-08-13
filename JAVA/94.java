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
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> output= new ArrayList<>();
        if(root!=null)
            travel(root,output);
        return output;
    }

    public void travel(TreeNode root, List<Integer> output){
        if(root.left!=null)
            travel(root.left,output);
        output.add(root.val);
        if(root.right!=null)
            travel(root.right,output);
    }
}

//java List必须先new