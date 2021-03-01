#include <stdio.h>
#include <string.h>
#include "func.h"
// This is the main which calls all other functions throughout the program
// The included makefile will build and run the program
int main() {
    char oneWord[10000];
    char wordArray[500][500];
    char repeatedWords[500][500];
    char top5RankWord[500][500];
    int top5RankSize[500];
    int instancesOfWords[500];
    int newInstancesOfWords[500];
    int i = -1;
    int size = 0;
    int newSize = 0;
    printUi();
    getWord(oneWord, i, wordArray, &size);
    compareArrays(wordArray, instancesOfWords, size);
    cleanUpCompare(wordArray, instancesOfWords, repeatedWords, newInstancesOfWords, size, &newSize);
    topFiveWords(repeatedWords, newInstancesOfWords, top5RankSize, newSize, size, &i, top5RankWord);
    findSameNumberOfOccurrence(top5RankWord, top5RankSize, size);
}
