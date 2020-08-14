/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

 //使用中序遍历判断是否有序
 func helper(root *TreeNode, pre int64) (bool,int64) {
	flag:=true
	if root.Left!=nil {
		flagl,pre1:=helper(root.Left,pre)
		flag=flag&&flagl
        pre=pre1
	}
    if int64(root.Val)>pre {
        pre=int64(root.Val)
	}else{
		flag=false
	}
	if root.Right!=nil {
		flagr,pre1:=helper(root.Right,pre)
		flag=flag&&flagr
        pre=pre1
	}
    return flag,pre
 }
 func isValidBST(root *TreeNode) bool {
    if root!=nil {
        flag,_:=helper(root, -0x7fffffffffffffff-1)
        return flag
	}
	return true
}