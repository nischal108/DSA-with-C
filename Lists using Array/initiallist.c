#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define EXIT_CHOICE 5

struct List {
    int arr[MAX_SIZE];
    int size;
};

void initList(struct List *list);
void addElement(struct List *list, int element, int position);
int getElement(struct List *list, int position);
int searchElement(struct List *list, int element);
void displayList(struct List *list);
void menu();

int main() {
    struct List myList;
    initList(&myList);
    int choice, position, element, searchResult;

    do {
        menu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter element to add: ");
                scanf("%d", &element);
                printf("Enter position to add: ");
                scanf("%d", &position);
                addElement(&myList, element, position);
                break;
            case 2:
                printf("Enter position to retrieve: ");
                scanf("%d", &position);
                printf("Element at position %d: %d\n", position, getElement(&myList, position));
                break;
            case 3:
                printf("Enter element to search: ");
                scanf("%d", &element);
                searchResult = searchElement(&myList, element);
                if (searchResult != -1)
                    printf("Element found at position %d.\n", searchResult);
                else
                    printf("Element not found.\n");
                break;
            case 4:
                displayList(&myList);
                break;
            case EXIT_CHOICE:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while(choice != EXIT_CHOICE);

    return 0;
}

void initList(struct List *list) {
   list->size = 0;
    printf("Enter the size of the list: ");
    scanf("%d", &list->size);
    if (list->size > MAX_SIZE) {
        printf("Size exceeds maximum allowed size. Truncating to %d.\n", MAX_SIZE);
        list->size = MAX_SIZE;
    }
    printf("Enter %d elements for the list:\n", list->size);
    for (int i = 0; i < list->size; i++) {
        printf("Element at index %d: ", i);
        scanf("%d", &list->arr[i]);
    }
}

void addElement(struct List *list, int element, int position) {
    if (list->size >= MAX_SIZE) {
        printf("List is full. Cannot add more elements.\n");
        return;
    }
    if (position < 0 || position > list->size) {
        printf("Invalid position.\n");
        return;
    }
    for (int i = list->size; i > position; i--) {
        list->arr[i] = list->arr[i - 1];
    }
    list->arr[position] = element;
    list->size++;
}

int getElement(struct List *list, int position) {
    if (position < 0 || position >= list->size) {
        printf("Invalid position.\n");
        return -1; // Assuming -1 as an invalid value
    }
    return list->arr[position];
}

int searchElement(struct List *list, int element) {
    for (int i = 0; i < list->size; i++) {
        if (list->arr[i] == element) {
            return i;
        }
    }
    return -1; // Element not found
}

void displayList(struct List *list) {
    printf("List elements: ");
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->arr[i]);
    }
    printf("\n");
}

void menu() {
    printf("\nMenu:\n");
    printf("1. Add Element\n");
    printf("2. Retrieve Element\n");
    printf("3. Search Element\n");
    printf("4. Display List\n");
    printf("%d. Exit\n", EXIT_CHOICE);
    printf("Enter your choice: ");
}
