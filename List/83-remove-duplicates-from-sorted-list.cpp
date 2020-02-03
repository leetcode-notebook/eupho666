/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head){
            int cur = head->val;
            ListNode* node = head->next, *pre = head;
            while(node){
                if(node->val == cur){
                    pre->next = node->next;
                    delete node;
                    node = pre->next;
                }else{
                    cur = node->val;
                    pre = node;
                    node = node->next;
                }
            }
        }
        return head;
    }
};