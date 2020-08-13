/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func travel (root * TreeNode, output * []int){
	if(root.Left!=nil){
		travel(root.Left,output)
	}
	*output=append(*output,root.Val)
	if(root.Right!=nil){
		travel(root.Right,output)
	}
}
// solution 1
func inorderTraversal(root *TreeNode) []int {
	var output []int;
	if(root!=nil){
		travel(root,&output)
	}
	return output
}

//solution 2
func inorderTraversal(root *TreeNode) []int {
    if root == nil {
        return []int{}
    }
    result := inorderTraversal(root.Left)
    result = append(result, root.Val)
    return append(result, inorderTraversal(root.Right)...)
}

//GO 有指针操作 & *

// ...将切片打散传入