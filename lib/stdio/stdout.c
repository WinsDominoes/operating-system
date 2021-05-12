# include "../../kernel/kernel.h"

/**
 * Prints a new line
 */
void printReturn() {
    if (VGAIndex > 56) {
        VGAIndex = 0;
        clearVGABuffer(&VGABuffer, gForeground, gBackground);
    }
    VGAPointer = 80*VGAIndex;
    VGAIndex++;
}

/**
 * Prints a character
 * @param c char
 */
void printChar(char c) {
    VGABuffer[VGAPointer] = makeVGAChar(c, gForeground, gBackground);
    VGAPointer++;
}

/**
 * Prints a string
 * @param str char array
 */
void print(char *str) {
    uint32 i = 0;
    while(str[i]){
        printChar(str[i]);
        i++;
    }
}

/**
 * Prints a new line
 * @param str char array
 */
void println(char *str) {
    print(str);
    printReturn();
}