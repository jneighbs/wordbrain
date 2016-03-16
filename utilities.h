#ifndef WORDBRAIN_UTILITIES_H
#define WORDBRAIN_UTILITIES_H

int countLines(FILE *fp);
int getLine(char line[], int lineLength, FILE *fp);
int getArray(char *charArray[], int length, FILE *fp);

#endif
