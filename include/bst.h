// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <string>
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
    explicit Node(T val);
  };

  Node* root;

  void destroyTree(Node* node);
  Node* insertNode(Node* node, const T& val);
  int calcDepth(Node* node) const;
  bool searchNode(Node* node, const T& val) const;
  void inorderTraverse(Node* node, std::vector<std::pair<int, T>>& vec) const;

 public:
  BST();
  ~BST();
  void insert(const T& val);
  int depth() const;
  bool search(const T& value) const;
  std::vector<std::pair<int, T>> getFreqList() const;
};

#endif  // INCLUDE_BST_H_
