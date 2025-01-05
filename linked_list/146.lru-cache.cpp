/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
class LRUCache {
    struct ListNode {
        int key;
        int val;
        ListNode *prev;
        ListNode *succ;

        ListNode(int key, int val)
            : key(key), val(val), prev(nullptr), succ(nullptr) {};
        ListNode(int key, int val, ListNode *prev, ListNode *succ)
            : key(key), val(val), prev(prev), succ(succ) {};
    };

    ListNode *dummyHead;
    ListNode *dummyTail;
    unordered_map<int, ListNode *> umap;
    int capacity;
    int size;

  public:
    LRUCache(int capacity) : capacity(capacity) {
        dummyHead = new ListNode(-1, 0);
        dummyTail = new ListNode(-1, 0);
        dummyHead->succ = dummyTail;
        dummyTail->prev = dummyHead;

        size = 0;
    }

    ListNode *getNode(int key) {
        auto iter = umap.find(key);
        if (iter == umap.end()) {
            return nullptr;
        }
        ListNode *node = iter->second;
        node->succ->prev = node->prev;
        node->prev->succ = node->succ;

        node->succ = dummyHead->succ;
        node->prev = dummyHead;
        dummyHead->succ->prev = node;
        dummyHead->succ = node;
        return node;
    }

    int get(int key) {
        ListNode *node = getNode(key);
        return node ? node->val : -1;
    }

    void put(int key, int value) {
        ListNode *node = getNode(key);
        if (!node) {
            node = new ListNode(key, value, dummyHead, dummyHead->succ);
            dummyHead->succ->prev = node;
            dummyHead->succ = node;
            size += 1;
            umap[key] = node;

            if (size > capacity) {
                node = dummyTail->prev;
                node->prev->succ = dummyTail;
                dummyTail->prev = node->prev;
                umap.erase(node->key);
                delete node;
                size -= 1;
            }
        } else {
            node->val = value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
