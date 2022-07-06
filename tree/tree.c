 #include <stdlib.h>

struct TreeNode
{
    int data;
    struct TreeNode *up;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *newTreeNode(int data) {
  struct TreeNode *node = malloc(sizeof(struct TreeNode));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}