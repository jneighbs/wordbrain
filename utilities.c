#include <utilities.h>
#include <string.h>
#include <ctype.h>

void lowerString(char *stringToLower)
{
  for(int i = 0; i < strlen(stringToLower); i++){
    stringToLower[i] = tolower(stringToLower[i]);
  }
}

// gets next line of file. Returns 0 when EOF is reached.
int getLine(char line[], int lineLength, FILE *fp)
{
  int i = 0;
  int c;

  while(i<lineLength-1 && (c=getc(fp)) != EOF){
    line[i++]=c;
    if(c=='\n') break;
  }
  line[i] = '\0';
  return i;
}

// counts the number of lines in given file
int countLines(FILE *fp)
{
  int count = 0;
  int maxLen = 1000;
  char line[maxLen];

  while(getLine(line, maxLen, fp) > 0) count++;
  rewind(fp);
  return count;
}

//TODO: make sure all lines have the same number of characters. This is kinda just hacked.
int numCharsPerLine(FILE *fp)
{
  char line[100];
  int numChars = getLine(line, 100, fp);
  rewind(fp);
  return numChars-1; //subtract 1 for newline char
}

// converts each line of file into entry in an array
int getArray(char *charArray[], int length, FILE *fp)
{
  int maxLineLen = 50;
  char line[maxLineLen];
  int i = 0;
  while(getLine(line, maxLineLen, fp) > 0){
    if(i>=length){
      fprintf(stderr, "ERROR (Fn: getArray) - File too big! Increase the \'length\' parameter to fix.\n");
    }
    charArray[i++] = line;
    printf("%s\n", charArray[i]);

  }
  return i;
}
