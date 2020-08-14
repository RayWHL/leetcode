/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

var first *TreeNode
var last *TreeNode
var pre *TreeNode
 
func helper(root *TreeNode) {
	if root.Left!=nil {
		helper(root.Left)
	}
	if pre!=nil {
		if root.Val < pre.Val {
			if first==nil {
				first=pre
			}
			last=root
		}
	}
	pre=root
	if root.Right!=nil {
		helper(root.Right)
	}
}
func recoverTree(root *TreeNode)  {
	first=nil
	last=nil
	pre=nil
	if root!=nil {
		helper(root)
		temp:=first.Val
		first.Val=last.Val
		last.Val=temp
	}
}