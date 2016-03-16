/*
 * Author: Jacob Neighbors
 * Date: 2/11/16
 * Desc: Building a program to solve the problems on the "wordbrain" app for
 *  iphone. Mom is obsessed with that game...
 */

#include <stdio.h>
#include <utilities.h>
#include <tree.h>

int isPrefix(char *wordSoFar, TreeNode node)
{
  printf("TODO: implement isPrefix()\n");
  return 0;
}

int main()
{
  // int count = countLines(stdin);
  // char *words[count];
  // getArray(words, count, stdin);
  // for(int i = 0; i < count; i++){
  //   printf("%s\n", words[i]);
  // }
  // buildTreeFromFile(stdin);

  TreeNode root = buildTreeFromFile(stdin);
  // TreeNode left = {NULL, NULL, NULL, 'c'};
  // TreeNode right = {NULL, NULL, NULL, 'r'};
  // addNode(&root, &left);
  // addNode(&root, &right);
  // traverseTree(root);
  return 0;
}
