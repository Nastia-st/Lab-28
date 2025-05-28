#include <stdio.h>
#define SIZE 12

typedef struct {
    int data[SIZE];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}
int isFull(Stack *s) {
    return s->top == SIZE - 1;
}
int isEmpty(Stack *s) {
    return s->top == -1;
}
void push(Stack *s, int value) {
    if (!isFull(s)) {
        s->data[++s->top] = value;
    }
}
void printStack(Stack *s, const char *name) {
    printf("%s: ", name);
    if (isEmpty(s)) {
        printf("(порожній)");
    } else {
        for (int i = 0; i <= s->top; i++) {
            printf("%d ", s->data[i]);
        }
    }
    printf("\n");
}
int main() {
    system("chcp 65001");
    Stack positiveStack, negativeStack;
    initStack(&positiveStack);
    initStack(&negativeStack);
    int number;
    printf("Введіть 12 цілих чисел:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("Число %d: ", i + 1);
        scanf("%d", &number);
        if (number > 0) {
            push(&positiveStack, number);
        } else if (number < 0) {
            push(&negativeStack, number);
        }
    }
    printStack(&positiveStack, "Стек додатніх чисел");
    printStack(&negativeStack, "Стек від’ємних чисел");
    return 0;
}