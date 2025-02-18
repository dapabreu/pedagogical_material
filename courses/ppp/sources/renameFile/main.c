#include <stdio.h>

int main () {
    int ret;

    ret = rename("..\\file.txt", "..\\new_file.txt");

    if(ret == 0)
        printf("File renamed successfully\n");
    else
        printf("Error: unable to rename the file\n");

    if (remove("..\\new_file.txt") == 0)
        printf("Deleted successfully\n");
    else
        printf("Unable to delete the file\n");

    return(0);
}