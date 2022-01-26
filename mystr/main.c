#include <stdio.h>
#include <string.h>

int main(void)
{
    char buf[1024] = "I am a boy.";
    char *token;

    token = strtok(buf, " ");
    printf("buf : %s\n", buf);
    printf("token : %s\n", token);

    while ((token = strtok(NULL, " ")) != NULL) {
        printf("buf : %s\n", buf);
        printf("token : %s\n", token);
    }
    
}