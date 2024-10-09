#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *p;
    char current[2048]; 
    char new[2048]; 
    

    
    while (fgets(current, 2048, stdin) != NULL) {
        
        int x;
        for (x = 0; x < 2048; x++) {
            new[x] = '\0';
        }
        p = strtok(current, " ");
        while (p != NULL) {
           
            strcat(new, p);
            strcat(new, " "); 
            p = strtok(NULL, " "); 
        }
        
        printf("%s\n", new);
    }

    
}


