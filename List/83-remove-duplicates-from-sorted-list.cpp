class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head){
            ListNode* cur = head->next, *pre = head;
            while(cur){
                if(cur->val == pre->val){
                    pre->next = cur->next;
                    delete cur;
                    cur = pre->next;
                }else{
                    pre = cur;
                    cur = cur->next;
                }
            }
        }
        return head;
    }
};
