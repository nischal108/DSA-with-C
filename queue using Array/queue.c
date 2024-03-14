#include <stdio.h>
#define MAX 10
#define TRUE 1
#define FALSE 0

struct queue {
    int front;
    int rear;
    int items[MAX];
};

int isEmpty(struct queue *q) {
    if (q->rear < q->front)
        return TRUE;
    else
        return FALSE;
}

int isFull(struct queue *q) {
    if (q->rear == MAX - 1)
        return TRUE;
    else
        return FALSE;
}

void enqueue(struct queue *q, int n) {
    if (isFull(q)) {
        printf("The queue is full and more items can't be added\n");
        return;
    } else {
        q->rear++;
        q->items[q->rear] = n;
    }
}

void deque(struct queue *q) {
    if (isEmpty(q)) {
        printf("Sorry the queue is empty\n");
        return;
    } else {
        q->front++;
        printf("Item removed successfully\n");
    }
}

void display(struct queue *q) {
    int i;
    if (isEmpty(q))
        printf("Queue is Empty\n");
    else {
        printf("Queue contains: ");
        for (i = q->front; i <= q->rear; i++) {
            printf("%d\t", q->items[i]);
        }
        printf("\n");
    }
}

int main() {
    struct queue q;
    q.front = 0;
    q.rear = -1;
    int choice, item;
    do {
        printf("What action do you want to perform?\n");
        printf("1. Enter an item\n2. Remove an item\n3. See the contents of Queue\n4. Exit the program\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the number to insert: ");
                scanf("%d", &item);
                enqueue(&q, item);
                break;
            case 2:
                deque(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("Sad to see you go\n");
                return 0;
            default:
                printf("Invalid input\n");
                break;
        }
    } while (1);
}
