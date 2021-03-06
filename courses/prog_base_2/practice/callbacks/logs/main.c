#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef void (*LogCallback)(const char *);

void longFunc(LogCallback cb);

void logger1(const char * msg) { printf(">> %s\n", msg); }
void logger2(const char * msg) { printf("Log message: %s\n", msg); }

int main(void)
{
    LogCallback cb = logger1;
    longFunc(cb);
    return 0;
}

void longFunc(LogCallback cb) {
    int i;
    cb("Function started");
    sleep(1);
    cb("Well, hello!");
    sleep(1);
    cb("Wazup?");
    sleep(2);
    for (i = 0; i < 5; i++) {
        cb("Doing smth...");
        sleep(1);
    }
    cb("Function finished");
}
