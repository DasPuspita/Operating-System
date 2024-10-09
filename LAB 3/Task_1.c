#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>

struct shared {
    char sel[100];
    int b;
};

int main() {
    int shmId;
    struct shared *shmPtr;
    int fd[2];
    pid_t pid;

    
    shmId = shmget(IPC_PRIVATE, sizeof(struct shared), IPC_CREAT | 0666);
    if (shmId < 0) {
     perror("shmget");
        exit(1);
    }

    shmPtr = (struct shared *)shmat(shmId, NULL, 0);
    if (shmPtr == (struct shared *) -1) {
        perror("shmat");
        exit(1);
    }

    
    (*shmPtr).b = 1000;

    
    if (pipe(fd) < 0) {
        perror("pipe");
        exit(1);
    }

    
    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid > 0) {
    
        close(fd[0]); 

        printf("Provide Your Input From Given Options:\n");
        printf("1. Type a to Add Money\n");
        printf("2. Type w to Withdraw Money\n");
        printf("3. Type c to Check Balance\n");
        scanf("%s", (*shmPtr).sel);
        printf("Your selection: %s\n", (*shmPtr).sel);

        wait(NULL);

        
        char readBuffer[100];
        close(fd[1]); 
        read(fd[0], readBuffer, sizeof(readBuffer));
        printf("%s\n", readBuffer);

        shmdt(shmPtr);
        shmctl(shmId, IPC_RMID, NULL);
    } 
    else {
        
        close(fd[1]); 

        if (strcmp((*shmPtr).sel, "a") == 0) {
            int addAmount;
            printf("Enter amount to be added:\n");
            scanf("%d", &addAmount);
            if (addAmount > 0) {
                (*shmPtr).b += addAmount;
                printf("Balance added successfully\n");
                printf("Updated balance after addition:\n%d\n", (*shmPtr).b);
            } 
            else {
                printf("Adding failed, Invalid amount\n");
            }
        } 
        else if (strcmp((*shmPtr).sel, "w") == 0) {
            int withdrawAmount;
            printf("Enter amount to be withdrawn:\n");
            scanf("%d", &withdrawAmount);
            if (withdrawAmount > 0 && withdrawAmount <= (*shmPtr).b) {
                (*shmPtr).b -= withdrawAmount;
                printf("Balance withdrawn successfully\n");
                printf("Updated balance after withdrawal:\n%d\n", (*shmPtr).b);
            } 
            else {
                printf("Withdrawal failed, Invalid amount\n");
            }
        } 
        else if (strcmp((*shmPtr).sel, "c") == 0) {
            printf("Your current balance is:\n%d\n", (*shmPtr).b);
        } 
        else {
            printf("Invalid selection\n");
        }

     
        close(fd[0]); 
        char message[] = "Thank you for using";
        write(fd[1], message, strlen(message) + 1);
        close(fd[1]);

        shmdt(shmPtr);
        exit(0);
    }

    return 0;
}
