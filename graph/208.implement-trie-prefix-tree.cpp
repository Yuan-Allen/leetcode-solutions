/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
class Trie {
  vector<Trie*> children;
  bool isEnd;

 public:
  Trie() {
    isEnd = false;
    children = vector<Trie*>(26);
  }

  void insert(string word) {
    Trie* node = this;
    for (auto c : word) {
      if (node->children[c - 'a'] == nullptr) {
        node->children[c - 'a'] = new Trie();
      }
      node = node->children[c - 'a'];
    }
    node->isEnd = true;
  }

  bool search(string word) {
    Trie* node = this;
    for (auto c : word) {
      if (node->children[c - 'a'] == nullptr) {
        return false;
      }
      node = node->children[c - 'a'];
    }
    return node->isEnd;
  }

  bool startsWith(string prefix) {
    Trie* node = this;
    for (auto c : prefix) {
      if (node->children[c - 'a'] == nullptr) {
        return false;
      }
      node = node->children[c - 'a'];
    }
    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
