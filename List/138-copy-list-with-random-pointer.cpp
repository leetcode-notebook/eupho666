/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr)
            return head;
        map<Node*,Node*> m;
        Node* pre = nullptr;
        Node* cur = head;
        while(cur != nullptr){
            m[cur] = new Node(cur->val, nullptr, nullptr);
            if(pre)
                m[pre]->next = m[cur];
            pre = cur;
            cur = cur->next;
            if(cur == head)
                break;
        }
        cur = head;
        while(cur != nullptr){
            m[cur]->random = m[cur->random];
            cur = cur->next;
            if(cur == head)
                break;
        }
        
        return m[head];
    }
};
// @lc code=end

