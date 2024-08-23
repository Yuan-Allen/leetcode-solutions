/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
class MyQueue {
  stack<int> input_stack;
  stack<int> output_stack;

  void transform_stack() {
    while (!input_stack.empty()) {
      output_stack.push(input_stack.top());
      input_stack.pop();
    }
  }

 public:
  MyQueue() {}

  void push(int x) { input_stack.push(x); }

  int pop() {
    if (output_stack.empty()) {
      transform_stack();
    }
    int ret = output_stack.top();
    output_stack.pop();
    return ret;
  }

  int peek() {
    if (output_stack.empty()) {
      transform_stack();
    }
    return output_stack.top();
  }

  bool empty() { return output_stack.empty() && input_stack.empty(); }
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
