/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start
class MedianFinder {
    priority_queue<int> lessHeap;
    priority_queue<int, vector<int>, greater<int>> greaterHeap;

  public:
    MedianFinder() {}

    void addNum(int num) {
        if (lessHeap.empty() || num < lessHeap.top()) {
            lessHeap.push(num);
            if (lessHeap.size() > greaterHeap.size() + 1) {
                greaterHeap.push(lessHeap.top());
                lessHeap.pop();
            }
        } else {
            greaterHeap.push(num);
            if (greaterHeap.size() > lessHeap.size()) {
                lessHeap.push(greaterHeap.top());
                greaterHeap.pop();
            }
        }
    }

    double findMedian() {
        return lessHeap.size() > greaterHeap.size()
                   ? lessHeap.top()
                   : (lessHeap.top() + greaterHeap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
