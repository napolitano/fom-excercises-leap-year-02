#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define APP_BANNER         "\n\n-=> Schaltjahr oder nicht? <=\n\n"
#define INPUT_PROMPT       "Bitte geben Sie eine Jahreszahl ein: "
#define IS_A_LEAP_YEAR     "ist ein Schaltjahr"
#define IS_NOT_A_LEAP_YEAR "ist kein Schaltjahr"
#define SELFTEST_FAILED    "Der Selbsttest is fehlgeschlagen.\n"

/**
 * Returns true, if leap year and otherwise false
 *
 * If the year is divisible by 4, the year is a leap year. 
 * This rule has an exception: If the year is divisible by 100, the year is not a leap year. 
 * This exception has again an exception: If the year is divisible by 400, the year is a leap year.
 */
bool isLeapYear(int year) {
    if(year % 400 == 0) {
        return true; 
    } else if (year % 100 == 0) {
        return false;
    } else if (year % 4 == 0) {
        return true;
    } else {
        return false;
    }
}

/**
 * Returns a simply colored app header
 */
void printHeader() {
    printf(ANSI_COLOR_CYAN);
    printf(APP_BANNER);
    printf(ANSI_COLOR_RESET);
}

/**
 * Gets the year from the user
 */
int getYearFromUser() {
    int year = 0;
    
    printf(ANSI_COLOR_BLUE);
    printf(INPUT_PROMPT);
    printf(ANSI_COLOR_RESET);
    printf("\n");
    
    scanf("%d", &year);

    return year;
}

/**
 * Very simple self test based on script
 */
bool isSelfTestFailed(){
    bool result = false;

    if( !isLeapYear(2016) || 
        !isLeapYear(2020) || 
        !isLeapYear(2020) || 
        isLeapYear(2019) || 
        isLeapYear(2017) || 
        isLeapYear(1900)) {
        result = true;
    } 

    return result;
}

/**
 * The main function
 */
int main () {

    if (isSelfTestFailed()) {
        printf(SELFTEST_FAILED);
        return -1;
    }

    char *result = malloc(20);
    char *fontColor = malloc(8);
    
    strcpy(result, IS_NOT_A_LEAP_YEAR);
    strcpy(fontColor, ANSI_COLOR_RED);

    printHeader();

    int year = getYearFromUser();

    if(isLeapYear(year)) {
        strcpy(result, IS_A_LEAP_YEAR);
        strcpy(fontColor, ANSI_COLOR_GREEN);
    } 

    printf("\n%s%d %s%s%s\n", ANSI_COLOR_YELLOW, year, fontColor, result, ANSI_COLOR_RESET);

    free(fontColor);
    free(result);

    return 0;
}
