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
  char * word;
} TreeNode;

TreeNode buildTreeFromFile(FILE *fp);
void printNode(TreeNode node);
void printTree(TreeNode node);
void traverseTree(TreeNode node);
void addNode(TreeNode *root, TreeNode *newNode);



#endif
