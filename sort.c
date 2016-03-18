/*
 * Author: Jacob Neighbors
 * Date: 3/18/16
 * Desc: Sort a given lexicon file into an order that allows a binary tree to be
 *  created from it very efficiently. Outputs this sorted lexicon in a file specified
 *  by the SORTED_LEXICON macro for persitent storage. This needs to be run only once
 *  per new lexicon.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <utilities.h>
#define SORTED_LEXICON "binary_sorted_lexicon.txt"
#define LINE_BUF 100

// // merge the left and right arrays together, in sorted order
// char **merge(char **l_array, int l_arraySize, char **r_array, int r_arraySize)
// {
//   int totalSize = l_arraySize + r_arraySize;
//   char *outputArray[totalSize];
//
//   int l = 0;  //l_array index
//   int r = 0;  //r_array index
//   int k = 0;  //outputArray index
//
//   // copy both halves over to outputArray in sorted order
//   while(k<totalSize){
//     if(strcmp(l_array[l], r_array[r]) < 0){
//       outputArray[k++] = l_array[l++];
//       // This array is empty. Flush the other array
//       if(l==l_arraySize)
//         while(r<r_arraySize) outputArray[k++] = r_array[r++];
//     } else {
//       outputArray[k++] = r_array[r++];
//       // This array is empty. Flush the other array
//       if(r==r_arraySize)
//         while(l<l_arraySize) outputArray[k++] = l_array[l++];
//     }
//   }
//
//   // copy outputArray back over the array that was passed in
//   memcpy(l_array, outputArray, totalSize*sizeof(int));
//   return l_array;
// }
//
// // the recursive mergeSort function! split the arrays in half, then merge the sorted halves!
// char **mergeSortRecursive(char **arrayToSort, int numElements)
// {
//   /* Base case! If only 1 element, then it must be sorted! */
//   if(numElements <= 1) return arrayToSort;
//
//   /* Separate out left/right half of array and recursively sort them */
//   mergeSortRecursive(arrayToSort, numElements/2);
//   mergeSortRecursive(arrayToSort+numElements/2, numElements-numElements/2);
//
//   /* return the merged versions */
//   return merge(arrayToSort, numElements/2, arrayToSort+numElements/2, numElements-numElements/2);
// }



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
    // copy line (sans newline) over into the lexicon array
    lexiconArray[i] = (char*)malloc(strlen(line)+1 * sizeof(char));
    memcpy(lexiconArray[i], line, strlen(line)+1 * sizeof(char));
  }
  return lexiconArray;
}


void sortLexicon(FILE *unsortedInputFile)
{
  // build array
  int numWords = countLines(unsortedInputFile);
  char **lexiconArray = buildArrayFromFile(unsortedInputFile, numWords);

  // sort into alphabetical order
  // mergeSortRecursive(lexiconArray, numWords);

  //sort into efficient binary tree creation order
  FILE *sortedOutputFile = fopen(SORTED_LEXICON, "w");
  for(int i = 0; i < numWords; i++){
    printf("%s\n", lexiconArray[i]);
  }

}

int main(int argc, char *argv[])
{
  FILE *fp = fopen(argv[1], "r");
  sortLexicon(fp);
}
