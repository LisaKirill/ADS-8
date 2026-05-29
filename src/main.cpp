// Copyright 2021 NNTU-CS
#include <iostream>
#include <string>
#include <cstdlib>
#include "bst.h"

void makeTree(BST<std::string>& tree, const char* filename);
void printFreq(BST<std::string>& tree);

int main() {
#ifdef _WIN32
  int dir_res = std::system("mkdir result 2>nul");
#else
  int dir_res = std::system("mkdir -p result");
#endif

  if (dir_res == -1) {
    std::cout << "Failed to create directory." << std::endl;
    return 1;
  }

  BST<std::string> tree;
  const char* filename = "src/war_peace.txt";

  std::cout << "Building tree..." << std::endl;
  makeTree(tree, filename);

  std::cout << "Tree depth: " << tree.depth() << std::endl;

  std::cout << "Saving frequencies..." << std::endl;
  printFreq(tree);

  return 0;
}
