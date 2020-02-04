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
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return;
        ListNode* mid = head, *fast = head;
        while(fast && fast->next){
            fast = fast->next->next;
            mid = mid->next;
        }
        stack<ListNode*> st;
        while(mid){
            st.push(mid);
            mid = mid->next;
        }

        ListNode* a1 = head, *a2, *b;
        while(!st.empty() && a1 != st.top()){
            a2 = a1->next;
            b = st.top();
            st.pop();
            a1->next = b;
            b->next = a2;
            a1 = a2;
        }
        if(a2) a2->next = nullptr;
    }
};