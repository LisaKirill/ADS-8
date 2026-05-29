// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <algorithm>
#include <vector>
#include <utility>

template <typename T>
class BST {
 private:
  struct Node {
    T value;
    int count;
    Node* left;
    Node* right;
    explicit Node(T val) : value(val), count(1),
                           left(nullptr), right(nullptr) {}
  };

  Node* root;

  void destroyTree(Node* node) {
    if (node != nullptr) {
      destroyTree(node->left);
      destroyTree(node->right);
      delete node;
    }
  }

  Node* insertNode(Node* node, const T& val) {
    if (node == nullptr) {
      return new Node(val);
    }
    if (val < node->value) {
      node->left = insertNode(node->left, val);
    } else if (val > node->value) {
      node->right = insertNode(node->right, val);
    } else {
      node->count++;
    }
    return node;
  }

  int calcDepth(Node* node) const {
    if (node == nullptr) {
      return 0;
    }
    int leftDepth = calcDepth(node->left);
    int rightDepth = calcDepth(node->right);
    return 1 + std::max(leftDepth, rightDepth);
  }

  bool searchNode(Node* node, const T& val) const {
    if (node == nullptr) {
      return false;
    }
    if (val == node->value) {
      return true;
    }
    if (val < node->value) {
      return searchNode(node->left, val);
    }
    return searchNode(node->right, val);
  }

  void inorderTraverse(Node* node, std::vector<std::pair<int, T>>& vec) const {
    if (node != nullptr) {
      inorderTraverse(node->left, vec);
      vec.push_back(std::make_pair(node->count, node->value));
      inorderTraverse(node->right, vec);
    }
  }

 public:
  BST() : root(nullptr) {}

  ~BST() {
    destroyTree(root);
  }

  void insert(const T& val) {
    root = insertNode(root, val);
  }

  int depth() const {
    return calcDepth(root);
  }

  bool search(const T& value) const {
    return searchNode(root, value);
  }

  std::vector<std::pair<int, T>> getFreqList() const {
    std::vector<std::pair<int, T>> result;
    inorderTraverse(root, result);
    return result;
  }
};

#endif  // INCLUDE_BST_H_
