#
# @lc app=leetcode.cn id=150 lang=python3
#
# [150] Evaluate Reverse Polish Notation
#


# @lc code=start
class Solution:
    def eval_op(self, num1: int, num2: int, op: str) -> int:
        if op == "+":
            return int(num2 + num1)
        elif op == "-":
            return int(num2 - num1)
        elif op == "*":
            return int(num2 * num1)
        elif op == "/":
            return int(num2 / num1)
        else:
            print("Invalid OP")
            return -1

    def evalRPN(self, tokens: List[str]) -> int:
        operand = []
        for token in tokens:
            if token in "+-*/":
                num1 = operand.pop()
                num2 = operand.pop()
                operand.append(self.eval_op(num1, num2, token))
            else:
                operand.append(int(token))
        assert len(operand) == 1
        return operand.pop()


# @lc code=end
