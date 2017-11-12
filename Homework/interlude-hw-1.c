#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char* argv[])
{
    int x = 100;
    int fk = fork();

    if (fk < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (fk == 0) {
        wait(NULL);
        x = 50;
        printf("Child PID: %d, x in child: %d\n", getpid(), x);
        exit(1);
    } else {
        //wait(NULL);
        x = 30;
        printf("Parent PID: %d, x in parent: %d\n", getpid(), x);
    }

    return 0;
}
