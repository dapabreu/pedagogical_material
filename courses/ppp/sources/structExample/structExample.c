#include <stdio.h>
#include <string.h>

// struct with typedef person

typedef struct Person {
    char name[50];
    int citNo;
    float salary;
} person;

//typedef long long ll;

/*struct Person {
    char name[50];
    int citNo;
    float salary;
};*/


int main() {

    // create  Person variable
    person p1;
    //ll value = 15612357;

    //struct Person p1;

    // assign value to name of p1
    strcpy(p1.name, "George Orwell");
    //p1.name= "George Orwell";

    /*
    An array name is not a modifiable lvalue. So, you cannot use the assignment operator (=) on that

    Now, to elaborate the actual reason behind the error message, quoting C11, chapter §6.5.16, Assignment operators

        - Assignment operator shall have a modifiable lvalue as its left operand.

    and then, quoting chapter §6.3.2.1 from the same standard,

        - A modifiable lvalue is an lvalue that does not have array type, [....]

    So, an array name is not a modifiable lvalue hence, you cannot assign anything to it. This is the reason behind the error message.
    */


    // assign values to other p1 variables
    p1.citNo = 1984;
    p1.salary = 2500;

    // print struct variables
    printf("Name: %s\n", p1.name);
    printf("Citizenship No.: %d\n", p1.citNo);
    printf("Salary: %.2f\n", p1.salary);
    //printf("ll value: %lld\n", value);

    return 0;
}