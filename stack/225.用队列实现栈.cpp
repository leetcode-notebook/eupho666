/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack {
private:
    queue<int> q;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int sz = q.size();
        for(int i = 0; i < sz - 1;++i){
            q.push(q.front());
            q.pop();
        }
        q.pop();
    }
    
    /** Get the top element. */
    int top() {
        int sz = q.size();
        for(int i = 0; i < sz - 1;++i){
            q.push(q.front());
            q.pop();
        }
        int res = q.front();
        q.push(q.front());
        q.pop();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

