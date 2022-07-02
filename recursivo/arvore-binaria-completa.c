#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int data;
    struct TreeNode *up;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *newTreeNode(int data)
{
    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

bool completa(struct TreeNode *node)
{
    if (node == NULL)
        return false;

    if (node->left == NULL && node->right == NULL)
        return true;

    bool l = completa(node->left);
    bool r = completa(node->right);

    return l && r;
}

struct TreeNode *construct()
{
    struct TreeNode *node1 = newTreeNode(1);
    struct TreeNode *node2 = newTreeNode(2);
    struct TreeNode *node3 = newTreeNode(3);
    struct TreeNode *node4 = newTreeNode(4);
    struct TreeNode *node5 = newTreeNode(5);
    struct TreeNode *node6 = newTreeNode(6);
    struct TreeNode *node7 = newTreeNode(7);

    // up
    node1->up = node2;
    node2->up = node4;
    node3->up = node2;
    node5->up = node6;
    node6->up = node4;
    node7->up = node6;

    // left
    node4->left = node2;
    node2->left = node1;
    node6->left = node5;

    // right
    node2->right = node3;
    node4->right = node6;
    node6->right = node7;

    return node4;
}

int main(int argc, char const *argv[])
{
    struct TreeNode *raiz = construct();
    if (completa(raiz))
    {
        printf("Completa");
    }
    else
    {
        printf("Não completa");
    }
    return 0;
}
