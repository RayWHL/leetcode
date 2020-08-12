/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode output = new ListNode(0);
        ListNode ans=output;
        int flag;
        int bit=0;
        int out;
        while(true){
            flag=0;
            out=0;
            if(l1!=null){
                out=l1.val;
                l1=l1.next;
                flag=1;
            }
            if(l2!=null){
                if(out+l2.val+bit>9){
                    out+=l2.val+bit-10;
                    bit=1;
                }else{
                    out+=l2.val+bit;
                    bit=0;
                }
                flag=1;
                l2=l2.next;
            }else{
                if(out+bit>9){
                    out+=bit-10;
                    bit=1;
                }else{
                    out+=bit;
                    bit=0;
                }
            }
            if(flag!=1){
                if(out!=0){
                    ListNode next=new ListNode(out);
                    ans.next=next;
                }
                return output.next;
            }
            ListNode next=new ListNode(out);
            ans.next=next;
            ans=next;
        }
    }
}


/** ATTENTION：
 * java没有指针
 * 类名只是引用，相当于指针
 */