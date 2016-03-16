/*
 * Author: Jacob Neighbors
 * Date: 2/12/16
 * Desc: A binary tree data structure.
 */

#include <tree.h>
#include <stdlib.h>

void printNode(TreeNode node)
{
  // printf("%c\n", node.letter);
}

void printTree(TreeNode node)
{
  // printf("TODO: implement printTree()\n");
}

void traverseTree(TreeNode root)
{
  // if(root.left != NULL) traverseTree(*(root.left));
  // printNode(root);
  // if(root.right != NULL) traverseTree(*(root.right));
}

// add a node into the tree structure (designated by the root node)
void addNode(TreeNode *root, TreeNode *newNode)
{
  // if(newNode->letter <= root->letter){
  //   if(root->left == NULL){
  //     root->left = newNode;
  //     newNode->parent = root;
  //   } else {
  //     addNode(root->left, newNode);
  //   }
  // } else {
  //   if(root->right == NULL){
  //     root->right = newNode;
  //     newNode->parent = root;
  //   } else {
  //     addNode(root->right, newNode);
  //   }
  // }
}

//TODO: Should I memcpy the word into the struct, or just keep the pointer?
// If I copy the whole word, how do I allocate space accurately for the struct?
// mallocs a treenode, and initializes values to given letter;
TreeNode *initNodeWithValue(char *word)
{
  // TreeNode *tnptr = (TreeNode*) malloc(sizeof(TreeNode));
  // tnptr->parent = NULL;
  // tnptr->left = NULL;
  // tnptr->right = NULL;
  // tnptr->word = word;
  // return tnptr;
}

void freeTree(TreeNode* root)
{
  // if(root->left != NULL) freeTree(root->left);
  // if(root->right != NULL) freeTree(root->right);
  // free(root);
}

TreeNode buildTreeFromFile(FILE *fp)
{
  // TreeNode *n = initNodeWithValue('j');
  // TreeNode *n1 = initNodeWithValue('c');
  // TreeNode *n2 = initNodeWithValue('x');
  // TreeNode *n3 = initNodeWithValue('a');
  // TreeNode *n4 = initNodeWithValue('r');
  // TreeNode *n5 = initNodeWithValue('d');
  // TreeNode *n6 = initNodeWithValue('f');
  // addNode(n, n1);
  // addNode(n, n2);
  // addNode(n, n3);
  // addNode(n, n4);
  // addNode(n, n5);
  // addNode(n, n6);
  // traverseTree(*n);
  // freeTree(n);
  // return *n;
}

// load lexicon into array
// using merge sort like recursive algorithm, go through array and build nodes
