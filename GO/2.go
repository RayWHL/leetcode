/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	output := ListNode{0,nil}
	ans:=&output
	flag:=0
	bit:=0
	out:=0
	for true {
		flag=0
		out=0
		if l1!=nil {
			out=l1.Val
			l1=l1.Next
			flag=1
		}
		if l2!=nil {
			if out+l2.Val+bit>9 {
				out=out+l2.Val+bit-10
				bit=1
			}else{
				out=out+l2.Val+bit
				bit=0
			}
			flag=1
			l2=l2.Next
		}else{
			if out+bit>9 {
				out=out+bit-10
				bit=1
			}else{
				out=out+bit
				bit=0
			}
		}
		if flag!=1 {
			if out!=0 {
				next:=ListNode{out,nil}
				ans.Next=&next
			}
			return output.Next
		}
		next:=ListNode{out,nil}
		ans.Next=&next
		ans=&next
	}
	return nil
}

// GO中可以返回函数中局部变量的地址
// 因为GO中变量只要被引用就不会被释放
// 存储位置（堆或栈）由编译器决定

// GO中结构指针访问成员同样使用 . 不是 ->