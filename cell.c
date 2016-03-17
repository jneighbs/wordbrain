/*
 * Author: Jacob Neighbors
 * Date: 3/15/16
 * Desc: A 'cell' data structure to represent each letter tile in the
 *  wordbrain game
 */

#include <stdlib.h>
#include <stdio.h>
#include <cell.h>
#include <utilities.h>
#define LINE_BUF 20


void printCell(WBCell *cell)
{
  printf("cell:\n\tvalue: %c\n\tvisited: %d\n\tindex: [%d][%d]\n\tadjacent cells: ", cell->value, cell->visited, cell->index.row, cell->index.col);

  for(int i = 0; i<NUM_ADJACENT_CELLS; i++){
    cell->adjacentCells[i]==NULL ? printf("[NULL] ") : printf("[%c] ", (*(cell->adjacentCells[i])).value);
  }
  printf("\n");
}

// initialize the given cell with the given values
void makeCell(WBCell *cell, char value, int row, int col)
{
  cell->index.row = row;  //set row position in matrix
  cell->index.col = col;  //set col position in matrix
  cell->value = value;    //set value
  cell->visited = 0;      //set to false
  for(int i = 0; i<NUM_ADJACENT_CELLS; i++){
    cell->adjacentCells[i]=NULL;
  }
}

// connect the cells so that they know who their neighbors are
void connectCells(WBCell **cells, int numCols, int numRows)
{
  for(int i = 0; i < numRows; i++){
    for(int j = 0; j < numCols; j++){
      WBCell *cellPtr = &cells[i][j];
      // printCell(cell);
      if(cellPtr->value != '-'){
        // right/left connection
        if(j+1 < numCols && cells[i][j+1].value != '-'){
          cellPtr->adjacentCells[RIGHT] = &cells[i][j+1];
          cells[i][j+1].adjacentCells[LEFT] = cellPtr;
        }
        // bottom right/top left connection
        if(i+1 < numRows  && j+1 < numCols && cells[i+1][j+1].value != '-'){
          cellPtr->adjacentCells[BOTTOM_RIGHT] = &cells[i+1][j+1];
          cells[i+1][j+1].adjacentCells[TOP_LEFT] = cellPtr;
        }
        // bottom/top connection
        if(i+1 < numRows && cells[i+1][j].value != '-'){
          cellPtr->adjacentCells[BOTTOM] = &cells[i+1][j];
          cells[i+1][j].adjacentCells[TOP] = cellPtr;
        }
        // bottom left/top right connection
        if(i+1 < numRows && j-1 >=0 && cells[i+1][j-1].value != '-'){
          cellPtr->adjacentCells[BOTTOM_LEFT] = &cells[i+1][j-1];
          cells[i+1][j-1].adjacentCells[TOP_RIGHT] = cellPtr;
        }
      }
      // printCell(cellPtr);
      // printCell(&cells[i][j+1]);
    }
  }
}

void freeCells(WBCell **cells, int numRows, int numCols)
{

}

/* Initializes the cells given a correctly formatted input file
 * File should be of the form:
 *    xad-st
 *    efeujj
 *    soorpt
 * Where dashes are blank spaces
 */
WBCell **initializeCells(FILE *fp, int height, int width)
{
  WBCell **cells = (WBCell**)malloc(height * sizeof(WBCell*));
  char line[LINE_BUF];
  int rowNumber = 0;
  int numChars;
  while((numChars = getLine(line, LINE_BUF, fp)-1) > 0){
    WBCell *cellRow = (WBCell*)malloc(numChars * sizeof(WBCell));
    for(int i = 0; i < numChars; i++){
      makeCell(cellRow+i, line[i], rowNumber, i);
    }
    cells[rowNumber++]=cellRow;
  }
  connectCells(cells, height, width);
  return cells;
}
