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
        vector<int> l;
        ListNode *output=new ListNode();
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
                    l.push_back(out);
                }
                for(int i=l.size();i>0;--i){
                    ListNode *next=new ListNode(l[i-1], output->next);
                    output->next=next;
                } 
                return output->next;
            }
            l.push_back(out);
        }
    }
};
