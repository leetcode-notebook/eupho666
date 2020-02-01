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
    ListNode* sortList(ListNode* head) {
        return mergesort(head);
    }
    ListNode* mergesort(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* breakNode;
        while(fast && fast->next){
            fast = fast->next->next;
            breakNode = slow;
            slow = slow->next;
        }
        breakNode->next = nullptr;
        ListNode* l1 = mergesort(head);
        ListNode* l2 = mergesort(slow);
        return merge(l1,l2);

    }
    ListNode* merge(ListNode* l1, ListNode* l2){
        if(l1 == nullptr)   return l2;
        if(l2 == nullptr)   return l1;
        
        if(l1->val <= l2->val){
            l1->next = merge(l1->next, l2);
            return l1;
        }else {
            l2->next = merge(l1, l2->next);
            return l2;
        }

    }
};