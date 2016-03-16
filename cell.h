#define NUM_ADJACENT_CELLS 8

struct cell {
  char value;           // The character value of the cell
  int visited;          // boolean 0 or 1
  struct cell *adjacentCells[NUM_ADJACENT_CELLS]; // pointer to adjacent cells
} typedef WBCell;
