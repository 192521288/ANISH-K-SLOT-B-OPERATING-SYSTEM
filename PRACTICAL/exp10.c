#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct message
{
    long msg_type;
    char msg_text[100];
};

int main()
{
    key_t key;
    int msgid;
    struct message msg;

    key = ftok("msgqfile", 65);

    msgid = msgget(key, IPC_CREAT | 0666);

    if (msgid == -1)
    {
        perror("msgget");
        return 1;
    }

    msg.msg_type = 1;
    strcpy(msg.msg_text, "Hello, message queue!");

    msgsnd(msgid, &msg, sizeof(msg.msg_text), 0);

    printf("Producer: Data sent: %s\n", msg.msg_text);

    msgrcv(msgid, &msg, sizeof(msg.msg_text), 1, 0);

    printf("Consumer: Data received: %s\n", msg.msg_text);

    msgctl(msgid, IPC_RMID, NULL);

    return 0;
