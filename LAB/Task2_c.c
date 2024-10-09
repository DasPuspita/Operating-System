#include <stdio.h>

int main() {
    char pass[200];
    printf("Password: ");
    scanf("%s", pass);

    int digit= 0;
    int l_case = 0;
    int u_case= 0;
    int special_case= 0;

    char *idx = pass;
    while (*idx) {
        if (*idx >= 'a' && *idx <= 'z') {
            l_case = 1;
        }
        else if (*idx >= 'A' && *idx <= 'Z') {
            u_case= 1;
        }
        else if (*idx >= '0' && *idx <= '9') {
            digit= 1;
        }
        else if (*idx == '_' || *idx == ',' || *idx == '$' || *idx == '#' || *idx == '@') {
            special_case= 1;
        }
        idx++;
    }

    if (!l_case) {
        printf("Lowercase character missing\n");
    }
    if (!u_case) {
        printf("Uppercase character missing\n");
    }
    if (!digit) {
        printf("Digit missing\n");
    }
    if (!special_case) {
        printf("Special character missing\n");
    }

    if (l_case && u_case&& digit&& special_case) {
        printf("OK\n");
    }

    
}

