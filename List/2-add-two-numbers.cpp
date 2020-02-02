/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 递归
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addNodes(l1, l2, 0);
    }
    ListNode* addNodes(ListNode* n1, ListNode* n2, int c){
        if(!n1 && !n2 && !c){
            return nullptr;
        }
        int sum = c;
        ListNode* next1 = nullptr, *next2 = nullptr;
        if(n1){
            sum += n1->val;
            next1 = n1->next;
        }
        if(n2){
            sum += n2->val;
            next2 = n2->next;
        }
        ListNode *node = new ListNode(sum % 10);
        node->next = addNodes(next1,next2, sum / 10);
        return node;
    }
};

//迭代
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *pt1 = l1,*pt2 = l2;
        ListNode *head = new ListNode(0), *curr = head;
        int overFlag = 0;
        if(pt1 == nullptr || pt2 == nullptr)
            throw "input list is null!";
        while (pt1 || pt2)
        {
            int x = pt1?pt1->val:0;
            int y = pt2?pt2->val:0;
            int s = x + y + overFlag;
            curr->next = new ListNode(s%10);
            curr = curr->next;
            overFlag = s / 10;
            if(pt1) pt1 = pt1->next;
            if(pt2) pt2 = pt2->next;
        }

        if(overFlag)
        {
            curr->next = new ListNode(overFlag);
        }

        return head->next;
    }
};