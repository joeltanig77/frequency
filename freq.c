#include <stdio.h>
#include <string.h>


int getWord(char oneWord[10000], int i, char wordArray[500][500], int *size) {
    char makeWord[10000];
    i++;
    strcpy(makeWord, "Dummy Value");
    strcpy(oneWord, "Dummy Value");
    *size += 1;
    scanf("%s", makeWord);
    // If the word is == to "zzzzz" stop reading the file
    if (strcmp(makeWord, "zzzzz") == 0) {
        return 0;
    }
    // If dummy value == dummy value, we are at the end of the text file
    if (strcmp(makeWord, oneWord) != 0) {
        strcpy(oneWord, makeWord); // Put one word in the array
        strcpy(wordArray[i], oneWord);
        return getWord(oneWord, i, wordArray, size);
    }
    return 0;
}

int compareArrays(char wordArray[500][500], int instancesOfWords[500], int size) {
    int count;
    for (int i = 0; i < size; i++) {
        count = 0;
        for (int j = 0; j < size; j++) {
            //If the thing next to it is the same word....
            if (strcmp(wordArray[i], wordArray[j]) == 0) {
                count += 1;
                instancesOfWords[i] = count;
            }
        }
    }
    return 0;
}

int clean2DArray(char array[500][500]) {
    // Take out junk in the arrays
    for (int i = 0; i < 500; ++i) {
        for (int j = 0; j < 500; ++j) {
            array[i][j] = '\0';
        }
    }
    return 0;
}

int isItInTheArray(char wordArray[500][500], char repeatedWords[500][500], int i) {
    // A helper function that checks if the the word is already in the array so we don't repeat words
    for (int j = 0; j < 500; ++j) {
        if ((strcmp(wordArray[i], repeatedWords[j]) == 0)) {
            return 1;
        }
    }
    return 0;
}

int cleanUpCompare(char wordArray[500][500], const int instancesOfWords[500], char repeatedWords[500][500],
                   int newInstancesOfWords[500], int size, int *newSize) {
    for (int i = 0; i < size; ++i) {
        // Is this a repeated word or not
        if (isItInTheArray(wordArray, repeatedWords, i) == 0) {
            // Increment the size of the non-repeated words we have
            *newSize += 1;
            // Save it into the non repeat arrays
            newInstancesOfWords[i] = instancesOfWords[i];
            strcpy(repeatedWords[i], wordArray[i]);
        }
    }
    return 0;
}


int findMax(int newInstancesOfWords[500], int top5RankSize[500], int size, int *i, const int *nextSpot) {
    /* A helper function that finds the max of the count instance and saves it to the top5RankSize which stores the
     count for each word in our UI */
    int max = 0;
    for (int j = 0; j < size; ++j) {
        if (newInstancesOfWords[j] > max) {
            max = newInstancesOfWords[j];
            // Increment the pointer that saves it state
            *i = j;
        }
    }
    // We found our max, save it
    top5RankSize[*nextSpot] = max;
    // Delete the max that we already counted
    newInstancesOfWords[*i] = '\0';
    return 0;
}


int
topFiveWords(char repeatedWords[500][500], int newInstancesOfWords[500], int top5RankSize[500], int newSize, int size,
             int *i, char top5RankWord[500][500]) {
    int nextSpot = 0;
    //Go through every single non-repeated word
    while (nextSpot < newSize) {
        findMax(newInstancesOfWords, top5RankSize, size, i, &nextSpot);
        // Save the word that goes along with it's count
        strcpy(top5RankWord[nextSpot], repeatedWords[*i]);
        // Go to the next index in the array
        nextSpot += 1;
        // reset the index counter
        *i = 0;
    }
    return 0;
}


int rearrangeToAlphabetOrderAndPrint(char arrangeToAlphabet[500][500], char organizedToAlphabet[500][500], int size,
                                     int top5RankSize[500], int *finalSpot) {
    int i;
    int j;
    int n = size;
    char temp[500];
    // Organize to alphabet using bubble sort. Used logic from CS 122 Data Structures
    for (i = 1; i <= n; i++) {
        for (j = 0; j <= n - i; j++) {
            if (strcmp(arrangeToAlphabet[j], arrangeToAlphabet[j + 1]) > 0) {
                strcpy(temp, arrangeToAlphabet[j]);
                strcpy(arrangeToAlphabet[j], arrangeToAlphabet[j + 1]);
                strcpy(arrangeToAlphabet[j + 1], temp);
            }
        }
    }
    for (i = 0; i <= size; i++) {
        // Print the values of the count and the word that is with that count!!
        strcpy(organizedToAlphabet[i], arrangeToAlphabet[i]);
        if (organizedToAlphabet[i][0] != '\0' && *finalSpot != 5) {
            printf("%d      ", top5RankSize[*finalSpot]);
            printf("%s\n", organizedToAlphabet[i]);
            *finalSpot += 1;
        }
    }
    return 0;
}


int findSameNumberOfOccurrence(char top5RankWord[500][500], int top5RankSize[500], int size) {
    int countOccurrence = 0;
    int theOccurrenceWeAreAt = 0;
    // Flag to fix the off one error after the first iteration of the for loop
    int flagToFixOffset = 0;
    char arrangeToAlphabet[500][500];
    char organizedToAlphabet[500][500];
    int nextSpot = 0;
    int finalSpot = 0;
    //Take out the junk in the arrays
    clean2DArray(arrangeToAlphabet);
    clean2DArray(organizedToAlphabet);
    for (int i = 0; i < size; ++i) {
        // Save the count occurrence we are at, we need to this for out alphabet algo
        if (i == 0) theOccurrenceWeAreAt = top5RankSize[i];
        // If the number of occurrence is the same as the next number
        if (theOccurrenceWeAreAt == top5RankSize[i]) {
            countOccurrence += 1;
            continue;
        }
        if (theOccurrenceWeAreAt != top5RankSize[i]) {
            // Fix the one off offset issue after counting the first occurrence
            if (flagToFixOffset) countOccurrence += 1;
            // printf("The sizes are %d\n",countOccurrence);
            // Save the count occurrence we are at now for the next read the counts
            theOccurrenceWeAreAt = top5RankSize[i];
            // This loop takes in the words with the same count occurrence to rearrange into alphabet order
            for (int u = 0; u < countOccurrence; u++) {
                // Save the word into alphabet order array
                strcpy(arrangeToAlphabet[u], top5RankWord[nextSpot]);
                // Increment the next spot the read
                nextSpot += 1;
                //printf("%s\n",arrangeToAlphabet[nextSpot]);
            }
            rearrangeToAlphabetOrderAndPrint(arrangeToAlphabet, organizedToAlphabet, size, top5RankSize, &finalSpot);
            // Reset the count occurrence and turn on the flag to fix the offset
            countOccurrence = 0;
            flagToFixOffset = 1;
            // Clean the arrange to alphabet website
            clean2DArray(arrangeToAlphabet);
        }
    }
    return 0;
}

void printUi() {
    // Print the ui for the user
    printf("%s", "Count  ");
    printf("%s\n", "Word");
    printf("%s", "=====  ");
    printf("%s\n", "====");
}


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
