/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func helper(begin int, end int, output *[]*TreeNode)  {
	if begin>end {
		*output=append(*output,nil);
	}
	for i:=begin;i<=end;i++ {
		var left []*TreeNode;
		var right []*TreeNode;
		helper(begin,i-1,&left);
		helper(i+1,end,&right);
		for _,lefttree:=range left {
			for _,righttree:=range right{
				root:=TreeNode{i,lefttree,righttree}
				*output=append(*output,&root)
			}
		}
	}
}
func generateTrees(n int) []*TreeNode {
	var output []*TreeNode
	if n!=0 {
		helper(1,n,&output)
	}
	return output
}