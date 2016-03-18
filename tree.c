/*
 * Author: Jacob Neighbors
 * Date: 2/12/16
 * Desc: A binary tree data structure.
 */

#include <stdlib.h>
#include <string.h>
#include <utilities.h>
#include <tree.h>
#define LINE_BUF 100


// add a node into the tree structure (designated by the root node)
//TODO: handle adding a duplicate node
void addNode(TreeNode *root, TreeNode *newNode)
{
  int comparison = strcmp(newNode->word,root->word);
  if(comparison <= 0){
    if(root->left == NULL){
      root->left = newNode;
      newNode->parent = root;
    } else {
      addNode(root->left, newNode);
    }
  } else {
    if(root->right == NULL){
      root->right = newNode;
      newNode->parent = root;
    } else {
      addNode(root->right, newNode);
    }
  }
}

// mallocs a treenode, and initializes values to given letter;
TreeNode *initNodeWithValue(char *word, int level)
{
  TreeNode *tnptr = (TreeNode*) malloc(sizeof(TreeNode));
  tnptr->parent = NULL;
  tnptr->left = NULL;
  tnptr->right = NULL;
  tnptr->word = word;
  tnptr->level = level;
  return tnptr;
}

void buildTreeFromArray(char **lexiconArray, int numEntries, TreeNode *root, int level)
{
  // add middle element of array into tree
  int midIndex = numEntries/2;
  TreeNode *newNode = initNodeWithValue(lexiconArray[midIndex], level);
  addNode(root, newNode);

  //recurse on left elements
  int numLeftEntries = numEntries/2;
  if(numLeftEntries>0) buildTreeFromArray(lexiconArray, numLeftEntries, newNode, level+1);

  //recurse on right elements
  int numRightEntries = numEntries - numLeftEntries - 1;
  if(numRightEntries>0) buildTreeFromArray(lexiconArray+midIndex+1, numRightEntries, newNode, level+1);
}

// builds an array of words from the lexicon file. The lexicon file must have
// 1 word per line and be in alphabetical order.
char **buildArrayFromFile(FILE *fp, int numWords)
{
  // allocate room for word pointers
  char **lexiconArray = (char**)malloc(numWords * sizeof(char*));

  // grab each line and stick it in the array
  char line[LINE_BUF];
  for(int i = 0; i < numWords; i++){
    if(getLine(line, LINE_BUF, fp) <= 0){
      //error
      fprintf(stderr, "SUMFIN BROKE! tree.c, fn: buildArrayFromFile");
      exit(1);
    }
    // get rid of newline char at end of each line
    line[strlen(line)-1] = '\0';
    lowerString(line);
    // copy line (lowercase and sans newline) over into the lexicon array
    lexiconArray[i] = (char*)malloc(strlen(line)+1 * sizeof(char));
    memcpy(lexiconArray[i], line, strlen(line)+1 * sizeof(char));
  }
  return lexiconArray;
}

void printNode(TreeNode node)
{
  // printf("%c\n", node.letter);
}

void printTree(TreeNode node)
{
  // printf("TODO: implement printTree()\n");
}

int isPrefix(TreeNode *root, char *wordToTest)
{
  TreeNode *node = traverseTree(root, wordToTest);

  while(1){
    int comparison = strcmp(wordToTest, node->word);
    if(comparison<0){
      if(strncmp(wordToTest, node->word, strlen(wordToTest))==0){
        return 1;
      }
      return 0;
    } else if(comparison == 0){
      return 1;
    } else {
      if(node->parent == NULL){
        return 0;
      } else {
        node = node->parent;
      }
    }
  }

}

int isSolution(TreeNode *root, char *wordToTest)
{
  TreeNode *node = traverseTree(root, wordToTest);
  return strcmp(wordToTest, node->word)==0;
}

TreeNode *traverseTree(TreeNode *root, char *wordToTest)
{
  int comparison = strcmp(wordToTest, root->word);
  if(comparison < 0){
    if(root->left != NULL){
      return traverseTree(root->left, wordToTest);
    } else {
      return root;
    }
  } else if(comparison > 0){
    if(root->right != NULL){
      return traverseTree(root->right, wordToTest);
    } else {
      return root;
    }
  } else {
    return root;
  }
}


//TODO: implement
void freeTree(TreeNode* root)
{
  // if(root->left != NULL) freeTree(root->left);
  // if(root->right != NULL) freeTree(root->right);
  // free(root);
}



TreeNode *buildTreeFromFile(FILE *fp)
{
  int numWords = countLines(fp);
  char **lexiconArray = buildArrayFromFile(fp, numWords);

  TreeNode *root = initNodeWithValue(lexiconArray[numWords/2], 0);
  buildTreeFromArray(lexiconArray, numWords/2, root, 1);
  buildTreeFromArray(lexiconArray+numWords/2+1, numWords - numWords/2 - 1, root, 1);

  return root;
}

// load lexicon into array
// using merge sort like recursive algorithm, go through array and build nodes
