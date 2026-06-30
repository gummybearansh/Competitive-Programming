#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  int height(TreeNode *root) {
    if (!root)
      return 0;

    int leftH = height(root->left);
    int rightH = height(root->right);

    return max(leftH, rightH) + 1;
  }

  bool isBalanced(TreeNode *root) {
    // base case -> null -> true
    if (!root)
      return true;

    // find the hight of left and right subtree
    int leftH = height(root->left);
    int rightH = height(root->right);

    if (abs(leftH - rightH) > 1)
      return false;

    // check for all it's children
    return isBalanced(root->left) && isBalanced(root->right);
  }
};
