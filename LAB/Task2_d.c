#include <stdio.h>


int new(char *mail) {
    int x = 0;
    

    while (mail[x] != '\0' && mail[x] != '@') {
        x++;
    }
    if (mail[x] == '\0') {
        return 0; 
    }
    
    char o_domain[] = "kaaj.com";
    char n_domain[] = "sheba.xyz";
    int y = x + 1; 
    while (mail[y] != '\0' && mail[y] == n_domain[y - x - 1]) {
        y++;
    }
    if (mail[y] == '\0' && n_domain[y - x - 1] == '\0') {
        return 1; 
    }
    
    return 0;
}

int main() {
    char mail[200];
    printf("Email address: ");
    scanf("%s", mail);

    if (new(mail)) {
        printf("Email address is okay\n");
    } else {
        printf("Email address is outdated\n");
    }

   
}

