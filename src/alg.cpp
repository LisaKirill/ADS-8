// Copyright 2021 NNTU-CS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include "bst.h"

void makeTree(BST<std::string>& tree, const char* filename) {
  std::ifstream file(filename);
  if (!file) {
    std::cout << "File error!" << std::endl;
    return;
  }

  std::string word = "";
  while (true) {
    int ch = file.get();
    if (ch == EOF) {
      break;
    }

    if (ch >= 'a' && ch <= 'z') {
      word += static_cast<char>(ch);
    } else if (ch >= 'A' && ch <= 'Z') {
      word += static_cast<char>(ch + ('a' - 'A'));
    } else {
      if (!word.empty()) {
        tree.insert(word);
        word = "";
      }
    }
  }

  if (!word.empty()) {
    tree.insert(word);
  }

  file.close();
}

bool compareFreq(const std::pair<int, std::string>& a,
                 const std::pair<int, std::string>& b) {
  if (a.first != b.first) {
    return a.first > b.first;
  }
  return a.second < b.second;
}

void printFreq(BST<std::string>& tree) {
  std::vector<std::pair<int, std::string>> freqs = tree.getFreqList();
  std::sort(freqs.begin(), freqs.end(), compareFreq);

  std::ofstream outFile("result/freq.txt");
  if (!outFile.is_open()) {
    std::cout << "Cannot open result/freq.txt" << std::endl;
    return;
  }

  for (const auto& item : freqs) {
    std::cout << item.second << " " << item.first << std::endl;
    outFile << item.second << " " << item.first << "\n";
  }
  outFile.close();
}
