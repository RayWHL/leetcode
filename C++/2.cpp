/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *output=new ListNode();
        ListNode *ans=output;
        int bit=0;
        int out;
        int flag;
        while(true){
            flag=0;
            out=0;
            if(l1!=nullptr){
                out=l1->val;
                l1=l1->next;
                flag=1;
            }
            if(l2!=nullptr){
                if(out+l2->val+bit>9){
                    out=out+l2->val-10+bit;
                    bit=1;
                }else{
                    out+=l2->val+bit;
                    bit=0;
                }
                flag=1;
                l2=l2->next;
            }else{
                if(out+bit>9){
                    out=out+bit-10;
                    bit=1;
                }else{
                    out+=bit;
                    bit=0;
                }
            }
            if(flag!=1){
                if(out!=0){
                    ListNode *next=new ListNode(out);
                    ans->next=next;
                }
                return output->next;
            }
            ListNode *next=new ListNode(out);
            ans->next=next;
            ans=next;
        }
    }
};
