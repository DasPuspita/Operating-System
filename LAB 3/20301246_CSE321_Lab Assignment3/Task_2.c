#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

struct msg {
    long int type;
    char txt[6];
};

int main() {
    int msgid;
    struct msg info;
    key_t key;
    pid_t pid_op, pid_ml;
   
    
    key = ftok("progfile", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);
    info.type = 1;
   
   
    printf("Please enter the workspace name:\n");
    scanf("%5s", info.txt);
   
    if (strcmp(info.txt, "cse321") != 0) {
        printf("Invalid workspace name\n");
        return 0;
    }

   
    msgsnd(msgid, &info, sizeof(info), 0);
    printf("Workspace name sent to otp generator from log in: %s\n", info.txt);
   
    
    pid_op = fork();
   
    if (pid_op == 0) {
        
        msgrcv(msgid, &info, sizeof(info), 1, 0);
        printf("OTP generator received workspace name from log in: %s\n", info.txt);
       
        sprintf(info.txt, "%d", getpid()); 
        info.type = 2;
        msgsnd(msgid, &info, sizeof(info), 0);
        printf("OTP sent to log in from OTP generator: %s\n", info.txt);
       
        // Fork 
        pid_ml = fork();
       
        if (pid_ml == 0) {
         
            msgrcv(msgid, &info, sizeof(info), 2, 0);
            printf("Mail received OTP from OTP generator: %s\n", info.txt);
           
            message.type = 3;
            msgsnd(msgid, &info, sizeof(info), 0);
            printf("OTP sent to log in from mail: %s\n", info.txt);
           
            // Terminate 
            exit(0);
        } else {
            wait(NULL); 
            exit(0); 
        }
    } else {
        
        wait(NULL); 
        struct msg otp_mg, mail_mg;
       
        
        msgrcv(msgid, &otp_mg, sizeof(otp_mg), 2, 0);
        printf("Log in received OTP from OTP generator: %s\n", otp_mg.txt);
       
       
        msgrcv(msgid, &mail_mg, sizeof(mail_mg), 3, 0);
        printf("Log in received OTP from mail: %s\n", mail_mg.txt);
       
        if (strcmp(otp_mg.txt, mail_mg.txt) == 0) {
            printf("OTP Verified\n");
        } else {
            printf("OTP Incorrect\n");
        }
       
       
        msgctl(msgid, IPC_RMID, NULL);
    }

    return 0;
}
