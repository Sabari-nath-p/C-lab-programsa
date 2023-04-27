#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid1, pid2, pid3;

    // Create first child process
    pid1 = fork();

    // Check for errors
    if (pid1 < 0) {
        fprintf(stderr, "Error: fork() failed.\n");
        exit(EXIT_FAILURE);
    } else if (pid1 == 0) {
        // First child process
        printf("First child process with PID %d, parent PID %d\n", getpid(), getppid());

        // Create second child process
        pid2 = fork();

        // Check for errors
        if (pid2 < 0) {
            fprintf(stderr, "Error: fork() failed.\n");
            exit(EXIT_FAILURE);
        } else if (pid2 == 0) {
            // Second child process
            printf("Second child process with PID %d, parent PID %d\n", getpid(), getppid());
        } else {
            // Parent of second child process
            wait(NULL); // wait for second child process to complete
        }
    } else {
        // Parent of first child process
        printf("Parent process with PID %d\n", getpid());

        // Create third child process
        pid3 = fork();

        // Check for errors
        if (pid3 < 0) {
            fprintf(stderr, "Error: fork() failed.\n");
            exit(EXIT_FAILURE);
        } else if (pid3 == 0) {
            // Third child process
            printf("Third child process with PID %d, parent PID %d\n", getpid(), getppid());
        } else {
            // Parent of third child process
            wait(NULL); // wait for third child process to complete
        }

        wait(NULL); // wait for first child process to complete
    }

    return 0;
}
