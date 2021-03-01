#ifndef FUNC_H
#define FUNC_H

/* Gets the word from the text file and stores it into the array */
int getWord(char oneWord[10000], int i, char wordArray[500][500], int *size);

/* Looks into the array and keeps counts of instances for each word in the array  */
int compareArrays(char wordArray[500][500], int instancesOfWords[500], int size);

/* Clean the junk from the array */
int clean2DArray(char array[500][500]);
/* Checks if the item in the repeatedWords array is already counted, this is to stop repeated words */
int isItInTheArray(char wordArray[500][500], char repeatedWords[500][500], int i);

/* Clean up the compare array to contain only unique words and counts */
int cleanUpCompare(char wordArray[500][500], const int instancesOfWords[500], char repeatedWords[500][500],
                   int newInstancesOfWords[500], int size, int *newSize);

/* A helper function that finds the max of the count instance and saves it to the top5RankSize which stores the
                    count for each word in our UI */
int findMax(int newInstancesOfWords[500], int top5RankSize[500], int size, int *i, const int *nextSpot);

/* Finds the top 5 words and stores them into the array */
int
topFiveWords(char repeatedWords[500][500], int newInstancesOfWords[500], int top5RankSize[500], int newSize, int size,
             int *i, char top5RankWord[500][500]);

/* Rearranges the array to alphabetacal order and prints the word as well as the occurences */
int rearrangeToAlphabetOrderAndPrint(char arrangeToAlphabet[500][500], char organizedToAlphabet[500][500], int size,
                                                  int top5RankSize[500], int *finalSpot);
/* Finds which words has the same number of occurences and stores the number into an array of top5RankSize */
int findSameNumberOfOccurrence(char top5RankWord[500][500], int top5RankSize[500], int size);

/* A fcuntion for printing the UI in the terminal */
void printUi();

#endif
