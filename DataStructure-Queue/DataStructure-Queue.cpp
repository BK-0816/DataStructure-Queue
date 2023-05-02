#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

QueueType q;

void init_queue(QueueType* q) {
    q->front = -1;
    q->rear = 0;
}

int is_empty(QueueType* q) {
    return q->rear == q->front;
}

int is_full(QueueType* q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

int enqueue(QueueType* q, element item) {
    if (is_full(q)) {
        fprintf(stderr, "큐가 포화상태입니다\n");
        return -1;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
    return 0;
}

element dequeue(QueueType* q) {
    if (is_empty(q)) {
        fprintf(stderr, "큐가 공백상태입니다\n");
        return -1;
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

void print_queue(QueueType* q) {
    int i;
    printf("Queue(front = %d, rear = %d) = ", q->front, q->rear);
    if (!is_empty(q)) {
        i = q->front;
        do {
            i = (i + 1) % (MAX_QUEUE_SIZE);
            printf("%d | ", q->data[i]);
            if (i == q->rear) break;
        } while (i != q->front);
    }
    printf("\n");
}

int main() {
    int menu, element;
    init_queue(&q);
    do {
        printf("\n");
        printf("==============Menu============.\n");
        printf("1.Input data and Enqueue \n");
        printf("2.Dequeue and Print data \n");
        printf("3.Print Queue \n");
        printf("4.Exit\n");
        printf("Select Number: ");
        scanf_s("%d", &menu);

        switch (menu) {
        case 1:
            printf("\n");
            printf("Input the data : ");
            scanf_s("%d", &element);
            enqueue(&q, element);
            break;
        case 2:
            element = dequeue(&q);
            if (element != -1) printf("Dequeue: %d\n", element);
            break;
        case 3:
            print_queue(&q);
            break;
        case 4:
            printf("Exit the program.\n");
            break;
        default:
            printf("Wrong Number.\n");
            break;
        }
    } while (menu != 4);

    return 0;
}