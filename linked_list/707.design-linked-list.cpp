/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] Design Linked List
 */

// @lc code=start
class MyLinkedList {
 public:
  struct Node {
    int val;
    Node* next;
    Node* prev;
    Node(int val) : val(val), next(nullptr), prev(nullptr) {}
  };

  Node* head;
  Node* tail;
  int length;

  MyLinkedList() {
    head = new Node(0);
    tail = new Node(0);
    length = 0;

    head->next = tail;
    tail->prev = head;
  }

  Node* get_node(int index) {
    if (index < 0 || index >= length) {
      return nullptr;
    }

    Node* curr = head->next;
    if (index < length / 2) {
      for (int i = 0; i < index; ++i) {
        curr = curr->next;
      }
    } else {
      // Opt: near to tail
      curr = tail->prev;
      for (int i = 0; i < length - index - 1; ++i) {
        curr = curr->prev;
      }
    }

    return curr;
  }

  int get(int index) {
    Node* node = get_node(index);

    return node != nullptr ? node->val : -1;
  }

  void addAtHead(int val) {
    Node* node = new Node(val);
    head->next->prev = node;
    node->next = head->next;
    node->prev = head;
    head->next = node;

    length++;
  }

  void addAtTail(int val) {
    Node* node = new Node(val);
    tail->prev->next = node;
    node->prev = tail->prev;
    node->next = tail;
    tail->prev = node;

    length++;
  }

  void addAtIndex(int index, int val) {
    Node* node = new Node(val);
    Node* curr = tail;

    if (index != length) {
      curr = get_node(index);
    }
    if (curr == nullptr) {
      return;
    }

    node->prev = curr->prev;
    curr->prev->next = node;
    node->next = curr;
    curr->prev = node;
    length++;
  }

  void deleteAtIndex(int index) {
    Node* curr = get_node(index);
    if (curr == nullptr) {
      return;
    }

    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    delete curr;
    length--;
  }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end
