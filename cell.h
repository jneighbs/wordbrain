#define NUM_ADJACENT_CELLS 8

enum cellPositions {TOP_LEFT, TOP, TOP_RIGHT, RIGHT, BOTTOM_RIGHT, BOTTOM, BOTTOM_LEFT, LEFT};

struct matrixIndex{
  int row;
  int col;
} typedef cellIndex;

struct cell {
  char value;           // The character value of the cell
  int visited;          // boolean 0 or 1
  cellIndex index;      // the cells position in the matrix of cells
  struct cell *adjacentCells[NUM_ADJACENT_CELLS]; // pointer to adjacent cells
} typedef WBCell;

WBCell **initializeCells(FILE *fp, int height, int width);
void freeCells(WBCell **cells, int numRows, int numCols);
void printCell(WBCell *cell);
