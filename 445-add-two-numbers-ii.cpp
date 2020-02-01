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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2 || l1->val == 0 && l2->val == 0)
            return new ListNode(0);
        if(!l1 || l1->val == 0 )
            return l2;
        if(!l2 || l2->val == 0)
            return l1;

        string num1;
        string num2;
        while(l1 || l2){
            if(l1) {
                num1 += to_string(l1->val);
                l1 = l1->next;
            }
            if(l2){
                num2 += to_string(l2->val);
                l2 = l2->next;
            }
        }
        int i = num1.length() - 1, j = num2.length() - 1;
        ListNode* pre = nullptr;
        int c = 0;
        while(i >= 0 || j >= 0 || c){
            int number = c;
            if(i >= 0 && j >= 0){
                number += num1[i] - '0' + num2[j] - '0';
            }else if(i >= 0){
                number += num1[i] - '0';
            }else if(j >= 0){
                number += num2[j] - '0';
            }
            ListNode* node = new ListNode(number % 10);
            node->next = pre;
            c = number / 10;
            pre = node;
            i--;
            j--;
        }
        return pre;
    }

};