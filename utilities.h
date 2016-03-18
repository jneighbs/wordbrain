#ifndef WORDBRAIN_UTILITIES_H
#define WORDBRAIN_UTILITIES_H
#include <stdio.h>

int countLines(FILE *fp);
int numCharsPerLine(FILE *fp);
int getLine(char line[], int lineLength, FILE *fp);
int getArray(char *charArray[], int length, FILE *fp);
void lowerString(char *stringToLower);

#endif
