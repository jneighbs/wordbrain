/*
 * Author: Jacob Neighbors
 * Date: 2/11/16
 * Desc: Building a program to solve the problems on the "wordbrain" app for
 *  iphone. Mom is obsessed with that game...
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <utilities.h>
#include <tree.h>
#include <cell.h>

int isPrefix(char *wordSoFar, TreeNode *node)
{
  // printf("TODO: implement isPrefix()\n");
  return 1;
}

int isSolution(char *wordSoFar, TreeNode *node)
{
  // printf("TODO: implement isSolution()\n");
  return strcmp(wordSoFar,"cactus")==0;
}

void recursiveSolve(TreeNode *lexTree, WBCell *cell, int solutionLen, char *solutionSoFar)
{
  // base case - if solution is of correct length and is an actual word, then print it
  if(strlen(solutionSoFar) == solutionLen){
    if(isSolution(solutionSoFar, lexTree)){
      printf("%s\n", solutionSoFar);
    }
  // else, word isn't long enough yet. Try expanding in all directions
  } else {
    int newLetterIndex = strlen(solutionSoFar);
    for(int i = 0; i < NUM_ADJACENT_CELLS; i++){
      WBCell *nextCellPtr = cell->adjacentCells[i];
      if(nextCellPtr!=NULL && !nextCellPtr->visited){
        solutionSoFar[newLetterIndex]=(*nextCellPtr).value;
        // if new direction is a valid prefix, mark current cell as visited,
        // and recurse on next cell with updated solution
        if(isPrefix(solutionSoFar, lexTree)){
          cell->visited = 1;
          recursiveSolve(lexTree, nextCellPtr, solutionLen, solutionSoFar);
        }
        // unwind after returning from recursion
        cell->visited = 0;
        solutionSoFar[newLetterIndex] = '\0';
      }
    }
  }
}

// Solves the wordbrain puzzle. Triggers the first call to recursiveSolve.
void solvePuzzle(TreeNode *lexTree, WBCell **cells, int numRows, int numCols, int solutionLen)
{
  //loop throught the double array of cells
  for(int i = 0; i < numRows; i++){
    for(int j = 0; j < numCols; j++){
      WBCell *cellPtr = &cells[i][j];
      // printCell(cellPtr);
      // initialize solutionSoFar to be all null except for first character
      char solutionSoFar[solutionLen+1];
      for(int x = 0; x < solutionLen+1; x++){
        if(x==0){
          solutionSoFar[x]=cellPtr->value;
        } else {
          solutionSoFar[x]='\0';
        }
      }
      // printf("solutionSoFar: %s\n", solutionSoFar);
      // recursively solve
      if(cellPtr->value != '-') recursiveSolve(lexTree, cellPtr, solutionLen, solutionSoFar);
    }
  }
}

int main(int argc, char *argv[])
{
  FILE *fp = fopen(argv[2], "r");
  int height = countLines(fp);
  int width = numCharsPerLine(fp);


  WBCell **cells = initializeCells(fp, height, width);
  TreeNode *lexTree = NULL;
  solvePuzzle(lexTree, cells, height, width, atoi(argv[1]));
  // int count = countLines(stdin);
  // char *words[count];
  // getArray(words, count, stdin);
  // for(int i = 0; i < count; i++){
  //   printf("%s\n", words[i]);
  // }
  // buildTreeFromFile(stdin);

  // TreeNode root = buildTreeFromFile(stdin);
  // TreeNode left = {NULL, NULL, NULL, 'c'};
  // TreeNode right = {NULL, NULL, NULL, 'r'};
  // addNode(&root, &left);
  // addNode(&root, &right);
  // traverseTree(root);
  freeCells(cells, height, width);
  freeTree(lexTree);
  return 0;
}
