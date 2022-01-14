#include <stdio.h>
#include <stdbool.h>

bool isLeapYear(int year) {

    if (year % 400 == 0) {
        return true;
    } else if (year % 4 == 0 && year % 100 != 0) {
        return true;
    } else {
        return false;
    }

}

void addDaysToDate(int month, int day, int year) {
    
}

int main() {

    int year;
    printf("Please enter a year between 1800 and 10000: ");
    scanf("%d", &year);

    int conclusion = isLeapYear(year);


    printf("Is the year %d a leap year?: %d\n", year, conclusion);



}

