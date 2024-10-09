#include <stdio.h>
#include <string.h>


int palindrome(char *string) {
    int len = strlen(string);
    int x, y;

  
    for (x = 0; x < len; x++) {
       
        if (string[x] >= 'A' && string[x] <= 'Z') {
            string[x] = string[x] + ('a' - 'A');
        } else if (string[x] < '0' || (string[x] > '9' && string[x] < 'A') || (string[x] > 'Z' && string[x] < 'a') || string[x] > 'z') {
         
            for (y = x; y < len; y++) {
                string[y] = string[y + 1];
            }
            len--;
            x--;
        }
    }

 
    for (x = 0, y = len - 1; x < y; x++, y--) {
        if (string[x] != string[y]) {
            return 0; 
        }
    }

    return 1; 
}

int main() {
    char string[200];
    printf("String: ");
    scanf("%s", string);

    if (palindrome(string)) {
        printf("Palindrome\n");
    }
    else {
        printf("Not Palindrome\n");
    }

   
}

