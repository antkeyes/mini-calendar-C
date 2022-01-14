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

int daysInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void addDaysToDate(int* mm, int* dd, int* yy, int daysLeftToAdd) {

    int daysLeftInMonth;

    while (daysLeftToAdd > 0) {

        daysLeftInMonth = daysInMonth[*mm] - *dd;

    // may have to change 'true' to 1 if function does not work
        if (*mm == 2 && isLeapYear(*yy) == true) {
            daysLeftInMonth++;
        }

    // if there are more days left to add than there are remaining days in the current month
        if (daysLeftToAdd > daysLeftInMonth && *mm == 12) {
            daysLeftToAdd -= daysLeftInMonth;
            //subtract one more day from dayaslefttoadd so that we can enter the first day of the next month
            daysLeftToAdd--;
            //reset the current day of the month to 1
            *dd = 1;
            
            //cycle through to next year if the last month was December
            *mm = 1;
            yy++;

        } else if (daysLeftToAdd > daysLeftInMonth && *mm != 12) {
            *mm += 1;
        } else {
            *dd += daysLeftToAdd;
            daysLeftToAdd = 0;
        }

    }



}

int main() {

    // int year;
    // printf("Please enter a year between 1800 and 10000: ");
    // scanf("%d", &year);

    // int conclusion = isLeapYear(year);

    // printf("Is the year %d a leap year?: %d\n", year, conclusion);


    int mm, dd, yy, daysLeftToAdd;

    printf("Please enter a date between the years 1800 and 10000 in the format of mm dd yy\nand provide the number of days to add to this date     ");
    scanf("%d %d %d %d", &mm, &dd, &yy, &daysLeftToAdd);
    printf("\n\n");

    addDaysToDate(&mm, &dd, &yy, daysLeftToAdd);

    printf("The new date is: %d/%d/%d\n\n", mm, dd, yy);



}

