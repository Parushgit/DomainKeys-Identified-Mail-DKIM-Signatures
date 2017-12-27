#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <openssl/sha.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
    struct timeval start, end;
    int processid;
    int i = 0;
    int v;
    char *mailName[] = {
        "msg.1",
        "msg.2",
        "msg.3",
        "msg.4",
        "msg.5",
        "msg.6",
        "msg.7",
        "msg.8",
        "msg.9",
        "msg.10"
    };
    
    clock_t startClock, endClock;

    while ( i < 10)
    {
        startClock = clock();
        gettimeofday(&start, NULL);
        processid = fork();
            //For child process
            if(processid == 0)
            {
                //SHA1Digest1024Sign
                char outputmailName[100] = "";
                strcat(outputmailName, mailName[i]);
                strcat(outputmailName, ".sha1.1024");
                char *command[] = {
                    "openssl",
                    "dgst",
                    "-sha1",
                    "-verify",
                    "rsapublickey1024.pem",
                    "-signature",
                    outputmailName,
                    mailName[i],
                    NULL
                };
                execvp(command[0],command);
            }
        
        waitpid(processid,&v,0);
        gettimeofday(&end, NULL);
        endClock = clock();
        printf("Time for : %s is - %f milliseconds\n", mailName[i], (double)(endClock - startClock) * 1000/CLOCKS_PER_SEC);
        startClock = clock();
        processid = fork();
            //For child process
            if (processid == 0)
            {
                //SHA256Digest1024Sign
                char outputmailName[100] = "";
                strcat(outputmailName, mailName[i]);
                strcat(outputmailName, ".sha256.1024");
                char *command[] = {
                    "openssl",
                    "dgst",
                    "-sha256",
                    "-verify",
                    "rsapublickey1024.pem",
                    "-signature",
                    outputmailName,
                    mailName[i],
                    NULL
                };
                execvp(command[0],command);
            }

        waitpid(processid,&v,0);
        endClock = clock();
        printf("Time for : %s is - %f milliseconds\n", mailName[i], (double)(endClock - startClock) * 1000/CLOCKS_PER_SEC);
        startClock = clock();
        processid = fork();
            //For child process
            if (processid == 0)
            {
                //SHA1Digest2048Sign
                char outputmailName[100] = "";
                strcat(outputmailName, mailName[i]);
                strcat(outputmailName, ".sha1.2048");
                char *command[] = {
                    "openssl",
                    "dgst",
                    "-sha1",
                    "-verify",
                    "rsapublickey2048.pem",
                    "-signature",
                    outputmailName,
                    mailName[i],
                    NULL
                };
                execvp(command[0],command);
            }

        waitpid(processid,&v,0);
        endClock = clock();
        printf("Time for : %s is - %f milliseconds\n", mailName[i], (double)(endClock - startClock) * 1000/CLOCKS_PER_SEC);
        startClock = clock();
        gettimeofday(&start, NULL);
        processid = fork();
            //For child process
            if (processid == 0)
            {
                //SHA256Digest2048Sign
                char outputmailName[100] = "";
                strcat(outputmailName, mailName[i]);
                strcat(outputmailName, ".sha256.2048");
                char *command[] = {
                    "openssl",
                    "dgst",
                    "-sha256",
                    "-verify",
                    "rsapublickey2048.pem",
                    "-signature",
                    outputmailName,
                    mailName[i],
                    NULL
                };
                execvp(command[0],command);
            }

        waitpid(processid,&v,0);
        gettimeofday(&end, NULL);
        endClock = clock();
        printf("Time for : %s is - %f milliseconds\n", mailName[i], (double)(endClock - startClock) * 1000/CLOCKS_PER_SEC);
        i++;
    }
    return 0;
}