#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;
typedef struct {
    Node *front;
    Node *rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = NULL;
}

void enqueue(Queue *q, int value) {
    Node *newNode = malloc(sizeof(Node));
    if (!newNode) {
        printf("Помилка виділення памʼяті\n");
        exit(1);
    }
    newNode->value = value;
    newNode->next = NULL;
    if (q->rear)
        q->rear->next = newNode;
    else
        q->front = newNode;
    q->rear = newNode;
}

int sumQueue(Queue *q) {
    int sum = 0;
    Node *curr = q->front;
    while (curr) {
        sum += curr->value;
        curr = curr->next;
    }
    return sum;
}

void freeQueue(Queue *q) {
    Node *curr = q->front;
    while (curr) {
        Node *temp = curr;
        curr = curr->next;
        free(temp);
    }
    q->front = q->rear = NULL;
}

int main() {
    system("chcp 65001");
    Queue q;
    initQueue(&q);
    printf("Вводьте цілі числа. Натисніть Esc для завершення.\n");
    while (1) {
        printf("\nНатисніть будь-яку клавішу для введення або Esc для завершення.\n");
        int key = _getch();
        if (key == 27) {
            printf("Завершення введення.\n");
            break;
        }

        char buffer[100];
        printf("Введіть число: ");
        fgets(buffer, sizeof(buffer), stdin);
        char *endptr;
        int num = (int)strtol(buffer, &endptr, 10);
        if (endptr == buffer || *endptr != '\n') {
            printf("Неправильний ввід. Спробуйте ще раз.\n");
            continue;
        }
        enqueue(&q, num);
    }
    int total = sumQueue(&q);
    printf("\nСума елементів черги: %d\n", total);
    freeQueue(&q);
    return 0;
}