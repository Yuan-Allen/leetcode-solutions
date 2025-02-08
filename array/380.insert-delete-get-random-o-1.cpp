/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 */

// @lc code=start
class RandomizedSet {
    vector<int> v;
    unordered_map<int, int> h;

  public:
    RandomizedSet() { srand((unsigned)time(NULL)); }

    bool insert(int val) {
        if (h.count(val)) {
            return false;
        }
        h[val] = v.size();
        v.emplace_back(val);
        return true;
    }

    bool remove(int val) {
        if (h.count(val) == 0) {
            return false;
        }
        int backVal = v.back();
        v[h[val]] = backVal;
        h[backVal] = h[val];
        v.pop_back();
        h.erase(val);
        return true;
    }

    int getRandom() {
        int idx = rand() % v.size();
        return v[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end
