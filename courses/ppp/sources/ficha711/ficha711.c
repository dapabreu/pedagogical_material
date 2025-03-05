#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define num_arrayData 10
#define min_day 1
#define max_day 31
#define min_month 1
#define max_month 12
#define min_year 1
#define max_year 2024

typedef struct{
    int day, month, year;
} Data;

void initData(Data arrayData[]);
int compareData(Data arrayData[], int fdata, int sdata);
Data diffData(Data arrayData[], int fdata, int sdata);
int findCentury(Data arrayData[], int data);

int main() {
    Data arrayData[num_arrayData];
    Data diff;
    int fdata, sdata, value;
    srand(time(0));

    initData(arrayData);
    printf("Choose the index of the first data to compare: ");
    scanf("%d", &fdata);
    printf("Choose the index of the second data to compare: ");
    scanf("%d", &sdata);
    value = compareData(arrayData, fdata, sdata);
    printf("\n---\n");
    printf("\nCompare is %d\n", value);
    printf("First date %d %d %d\n", arrayData[fdata].day,arrayData[fdata].month,arrayData[fdata].year);
    printf("Second date %d %d %d\n", arrayData[sdata].day,arrayData[sdata].month,arrayData[sdata].year);
    diff = diffData(arrayData, fdata, sdata);
    printf("\n---\n");
    printf("\nDiff between dates is days: %d, months: %d, years: %d\n", diff.day, diff.month, diff.year);
    printf("\n---\n");
    printf("\nFirst date year: %d, century: %d\n", arrayData[fdata].year, findCentury(arrayData, fdata));
    printf("Second date year: %d, century: %d\n", arrayData[sdata].year, findCentury(arrayData, sdata));
    return 0;
}

void initData(Data arrayData[]){
    for(int i=0; i<num_arrayData; i++){
        arrayData[i].day = (rand() % (max_day - min_day + 1)) + min_day;
        arrayData[i].month = (rand() % (max_month - min_month + 1)) + min_month;
        arrayData[i].year = (rand() % (max_year - min_year + 1)) + min_year;
    }
}

int compareData(Data arrayData[], int fdata, int sdata){
    if(arrayData[sdata].year > arrayData[fdata].year){
        return 2;
    }
    else{
        if(arrayData[sdata].year < arrayData[fdata].year){
            return 1;
        }
        else{
            if(arrayData[sdata].month > arrayData[fdata].month){
                return 2;
            }
            else{
                if(arrayData[sdata].month < arrayData[fdata].month){
                    return 1;
                }
                else{
                    if(arrayData[sdata].day > arrayData[fdata].day){
                        return 2;
                    }
                    else
                    {
                        if(arrayData[sdata].day < arrayData[fdata].day){
                            return 1;
                        }
                        else{
                            return 0;
                        }
                    }
                }
            }
        }
    }
}

Data diffData(Data arrayData[], int fdata, int sdata){
    Data ldiff;
    ldiff.year = abs(arrayData[fdata].year - arrayData[sdata].year);
    ldiff.month = abs(arrayData[fdata].month - arrayData[sdata].month);
    ldiff.day = abs(arrayData[fdata].day - arrayData[sdata].day);
    return ldiff;
}

int findCentury(Data arrayData[], int data){
    int century = 0;

    if (arrayData[data].year <= 100)
        century = 1;
    else if (arrayData[data].year % 100 == 0)
        century = arrayData[data].year / 100;
    else
        century = arrayData[data].year / 100 + 1;

    return century;
}
