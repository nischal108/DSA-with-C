#include <stdio.h>
#include <stdlib.h>

struct product {
    int id;
    char name[50];
    float price;
};

struct node {
    struct product data;
    struct node *next;
};

struct node *header = NULL;

struct node *getnode(int n) {
    struct node *ptrnew = (struct node *)malloc(sizeof(struct node));
    if (ptrnew == NULL) {
        printf("Memory Allocation failed..");
        exit(0);
    }
    ptrnew->data.id = n;
    ptrnew->next = NULL;
    return ptrnew;
}

void insertFirst(struct node *ptrnew) {
    ptrnew->next = header;
    header = ptrnew;
}

void insertAfter(struct node *ptrprev, struct node *ptrnew) {
    ptrnew->next = ptrprev->next;
    ptrprev->next = ptrnew;
}

void removeNode(int key) {
    struct node *ptrprev = NULL;
    struct node *ptrcurr = header;

    // Search for the node with the given key
    while (ptrcurr != NULL && ptrcurr->data.id != key) {
        ptrprev = ptrcurr;
        ptrcurr = ptrcurr->next;
    }

    // If node with key is found
    if (ptrcurr != NULL) {
        // If node to be removed is the first node
        if (ptrprev == NULL) {
            header = ptrcurr->next;
        } else {
            ptrprev->next = ptrcurr->next;
        }
        free(ptrcurr);
    }
}

void display() {
    struct node *ptrthis = header;
    if (header == NULL) {
        printf("List is Empty..\n");
    } else {
        printf("List Contains:\n");
        while (ptrthis != NULL) {
            printf("%d ", ptrthis->data.id);
            ptrthis = ptrthis->next;
        }
        printf("\n");
    }
}

int main() {
    int choice;
    int i;
    printf(".............LINEAR LINKED LIST....................\n");
    for (i = 0; i < 10; i++) {
        insertFirst(getnode(i + 1));
    }
    display();

    do {
        printf("Enter your choice\n");
        printf("1. Insert First\n2. Insert After\n3. Remove\n4. Display\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: 
                printf("Enter the value to insert at the beginning: ");
                int val1;
                scanf("%d", &val1);
                insertFirst(getnode(val1));
                break;
            case 2:
                printf("Enter the value to insert after: ");
                int val2;
                scanf("%d", &val2);
                // Example: Inserting a new node after the node with id val2
                struct node *temp = header;
                while (temp != NULL && temp->data.id != val2) {
                    temp = temp->next;
                }
                if (temp == NULL) {
                    printf("Value not found.\n");
                } else {
                    printf("Enter the value to insert: ");
                    int newVal;
                    scanf("%d", &newVal);
                    insertAfter(temp, getnode(newVal));
                }
                break;
            case 3: 
                printf("Enter the value to remove: ");
                int val3;
                scanf("%d", &val3);
                removeNode(val3);
                break;
            case 4: 
                display();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid Choice\n");
                break;
        }
    } while (1);

    return 0;
}
