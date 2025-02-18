#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    FILE *fptr1, *fptr2;
    char *line = NULL;
    size_t len = 0;

    if (argc != 3){
        printf("Wrong number of arguments have been passed to the program\n");
        printf("This program requeries two parameters -- $>ficha1611 file1.txt file2.txt\n");
        return 1;
    }

    printf("Running ficha1611\n");

    if ((fptr1 = fopen(argv[1],"r")) == NULL){
        printf("Error opening file: %s", argv[1]);
        fclose(fptr1);
        return 1;
    }
    if ((fptr2 = fopen(argv[2],"w")) == NULL){
        printf("Error opening file: %s", argv[2]);
        fclose(fptr2);
        return 1;
    }

    printf("Copying content from %s to %s \n", argv[1], argv[2]);

    while (getline(&line, &len, fptr1) != -1){
        fputs(line, fptr2);
    }

    free(line);
    fclose(fptr1);
    fclose(fptr2);

    printf("Done!!!\n");

    return 0;
}
