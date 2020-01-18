/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */

// @lc code=start
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
  ListNode* rotateRight(ListNode* head, int k) {
    if (head) {
      int n = 0;
      ListNode* p = head;
      while (p != nullptr) {
        n++;
        p = p->next;
      }
      k = k % n;
      ListNode *pr = head, *pl = head;
      while (k > 0) {
        pr = pr->next;
        k--;
      }
      while (pr->next != nullptr) {
        pr = pr->next;
        pl = pl->next;
      }
      pr->next = head;
      head = pl->next;
      pl->next = nullptr;
    }

    return head;
  }
};
// @lc code=end
