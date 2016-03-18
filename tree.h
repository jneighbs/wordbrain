/*
 * Author: Jacob Neighbors
 * Date: 2/12/16
 * Desc: binary tree header file
 */

#ifndef TREE_H
#define TREE_H
#include <stdio.h>

typedef struct tnode{
  struct tnode *parent;
  struct tnode *left;
  struct tnode *right;
  char *word;
  int level;
} TreeNode;

TreeNode *buildTreeFromFile(FILE *fp);
void printNode(TreeNode node);
void printTree(TreeNode node);
TreeNode *traverseTree(TreeNode *root, char *wordToTest);
int isPrefix(TreeNode *root, char *wordToTest);
int isSolution(TreeNode *root, char *wordToTest);
void addNode(TreeNode *root, TreeNode *newNode);
void freeTree(TreeNode* root);



#endif
