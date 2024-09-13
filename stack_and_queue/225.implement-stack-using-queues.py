#
# @lc app=leetcode.cn id=225 lang=python3
#
# [225] Implement Stack using Queues
#


# @lc code=start
import queue


class MyStack:
    def __init__(self):
        self.q1 = queue.Queue()
        self.q2 = queue.Queue()

    def push(self, x: int) -> None:
        self.q1.put(x)

    def pop(self) -> int:
        if self.q1.empty():
            self.q1, self.q2 = self.q2, self.q1
        size = self.q1.qsize()
        while size > 1:
            self.q2.put(self.q1.get())
            size -= 1
        popped = self.q1.get()

        return popped

    def top(self) -> int:
        popped = self.pop()
        self.push(popped)
        return popped

    def empty(self) -> bool:
        return self.q1.empty() and self.q2.empty()


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
# @lc code=end
