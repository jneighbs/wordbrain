/*
 * Author: Jacob Neighbors
 * Date: 3/15/16
 * Desc: word brain cell header file
 */

#ifndef CELL_H
#define CELL_H

#define NUM_ADJACENT_CELLS 8

// the positions of the different adjacent cells in the adjacentCells array
enum cellPositions {TOP_LEFT, TOP, TOP_RIGHT, RIGHT, BOTTOM_RIGHT, BOTTOM, BOTTOM_LEFT, LEFT};

// a basic matrix position struct
typedef struct matrixIndex{
  int row;  // row i
  int col;  // column j
} cellIndex;

// the WBCell struct
typedef struct cell {
  char value;           // The character value of the cell
  int visited;          // boolean 0 or 1
  cellIndex index;      // the cells position in the matrix of cells
  struct cell *adjacentCells[NUM_ADJACENT_CELLS]; // pointer to adjacent cells
} WBCell;

// initializes all of the cells according to the file
WBCell **initializeCells(FILE *fp, int height, int width);
// frees the memory consumed by the cells
void freeCells(WBCell **cells, int numRows, int numCols);
// prints a single cell. Usefule for debugging.
void printCell(WBCell *cell);
// prints all cells
void printCells(WBCell **cells, int numRows, int numCols);


#endif
