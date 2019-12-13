/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
  ListNode* reverseList(ListNode* head, int n) {
    ListNode* temp = head;
    ListNode* old_head = nullptr;
    ListNode* old_end_next = nullptr;
    while (head != nullptr && n) {
      old_end_next = head->next;
      head->next = old_head;
      old_head = head;
      head = old_end_next;
      n--;
    }
    temp->next = old_end_next;
    return old_head;
  }
  ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (m == n || head == nullptr) return head;
    int start = min(m, n);
    int end = max(m, n);
    ListNode* start_pre = nullptr;
    ListNode *start_ptr = head, *end_ptr = head;

    for (int i = 1; i < start; ++i) {
      start_pre = start_ptr;
      start_ptr = start_ptr->next;
    }

    ListNode* subhead = reverseList(start_ptr, end - start + 1);
    if (start_pre) start_pre->next = subhead;

    if (start > 1) return head;
    return subhead;
  }
};
// @lc code=end
