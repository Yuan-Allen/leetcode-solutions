/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution {
  public:
    void maxHeapify(vector<int> &a, int i, int heapSize) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int largest = i;
        if (l < heapSize && a[l] > a[largest]) {
            largest = l;
        }
        if (r < heapSize && a[r] > a[largest]) {
            largest = r;
        }
        if (largest != i) {
            swap(a[i], a[largest]);
            maxHeapify(a, largest, heapSize);
        }
    }

    void buildMaxHeap(vector<int> &a, int heapSize) {
        for (int i = heapSize / 2 - 1; i >= 0; --i) {
            maxHeapify(a, i, heapSize);
        }
    }

    int findKthLargest(vector<int> &nums, int k) {
        int heapSize = nums.size();
        buildMaxHeap(nums, heapSize);
        while (--k) {
            swap(nums[0], nums[heapSize - 1]);
            heapSize -= 1;
            maxHeapify(nums, 0, heapSize);
        }
        return nums[0];
    }
};
// @lc code=end
