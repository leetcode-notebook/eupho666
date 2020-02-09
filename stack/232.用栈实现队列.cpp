/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue
{
private:
    stack<int> st1;
    stack<int> st2;

public:
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        st1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        if (!st2.empty())
        {
            int res = st2.top();
            st2.pop();
            return res;
        }
        if (!st1.empty())
        {
            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
            if (!st2.empty())
            {
                int res = st2.top();
                st2.pop();
                return res;
            }
        }
        return -1;
    }

    /** Get the front element. */
    int peek()
    {
        if (!st2.empty())
            return st2.top();
        if (!st1.empty())
        {
            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
            if (!st2.empty())
            {
                return st2.top();
            }
        }
        return -1;
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return st1.empty() && st2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
