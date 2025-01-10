/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
class MinStack {
    stack<int> _stack;
    stack<int> _minStack;

  public:
    MinStack() {}

    void push(int val) {
        _stack.push(val);
        if (_minStack.empty() || val <= _minStack.top()) {
            _minStack.push(val);
        }
    }

    void pop() {
        int val = _stack.top();
        _stack.pop();
        if (val == _minStack.top()) {
            _minStack.pop();
        }
    }

    int top() { return _stack.top(); }

    int getMin() { return _minStack.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
