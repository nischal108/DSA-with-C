#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_NAME_LENGTH 50

// Task structure
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
} Task;

// Global variables
Task todoList[MAX_TASKS];
int taskCount = 0;

// Function prototypes
void insertFront(char *name);
void insertEnd(char *name);
void insertAfter(char *name, int afterId);
void insertBefore(char *name, int beforeId);
void removeFront();
void removeEnd();
void removeItem(int id);
void listItems();
int searchByName(char *name);

int main() {
    int choice;
    char taskName[MAX_NAME_LENGTH];
    int id;

    while (1) {
        printf("\nTo-Do List Menu:\n");
        printf("1. Insert at the front\n");
        printf("2. Insert at the end\n");
        printf("3. Insert after an item\n");
        printf("4. Insert before an item\n");
        printf("5. Remove from front\n");
        printf("6. Remove from end\n");
        printf("7. Remove any item\n");
        printf("8. List items\n");
        printf("9. Search by name\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter task name: ");
                scanf("%s", taskName);
                insertFront(taskName);
                break;
            case 2:
                printf("Enter task name: ");
                scanf("%s", taskName);
                insertEnd(taskName);
                break;
            case 3:
                printf("Enter task name: ");
                scanf("%s", taskName);
                printf("Enter ID of the task after which to insert: ");
                scanf("%d", &id);
                insertAfter(taskName, id);
                break;
            case 4:
                printf("Enter task name: ");
                scanf("%s", taskName);
                printf("Enter ID of the task before which to insert: ");
                scanf("%d", &id);
                insertBefore(taskName, id);
                break;
            case 5:
                removeFront();
                break;
            case 6:
                removeEnd();
                break;
            case 7:
                printf("Enter ID of the task to remove: ");
                scanf("%d", &id);
                removeItem(id);
                break;
            case 8:
                listItems();
                break;
            case 9:
                printf("Enter task name to search: ");
                scanf("%s", taskName);
                id = searchByName(taskName);
                if (id != -1)
                    printf("Task found with ID: %d\n", id);
                else
                    printf("Task not found\n");
                break;
            case 10:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void insertFront(char *name) {
    if (taskCount == MAX_TASKS) {
        printf("To-Do List is full!\n");
        return;
    }

    for (int i = taskCount; i > 0; i--)
        todoList[i] = todoList[i - 1];

    Task newTask;
    newTask.id = taskCount + 1;
    strcpy(newTask.name, name);
    todoList[0] = newTask;

    taskCount++;
    printf("Task inserted at the front successfully.\n");
}

void insertEnd(char *name) {
    if (taskCount == MAX_TASKS) {
        printf("To-Do List is full!\n");
        return;
    }

    Task newTask;
    newTask.id = taskCount + 1;
    strcpy(newTask.name, name);
    todoList[taskCount] = newTask;

    taskCount++;
    printf("Task inserted at the end successfully.\n");
}

void insertAfter(char *name, int afterId) {
    int i;
    for (i = 0; i < taskCount; i++) {
        if (todoList[i].id == afterId)
            break;
    }

    if (i == taskCount) {
        printf("Task with specified ID not found!\n");
        return;
    }

    if (taskCount == MAX_TASKS) {
        printf("To-Do List is full!\n");
        return;
    }

    for (int j = taskCount; j > i + 1; j--)
        todoList[j] = todoList[j - 1];

    Task newTask;
    newTask.id = taskCount + 1;
    strcpy(newTask.name, name);
    todoList[i + 1] = newTask;

    taskCount++;
    printf("Task inserted successfully.\n");
}

void insertBefore(char *name, int beforeId) {
    int i;
    for (i = 0; i < taskCount; i++) {
        if (todoList[i].id == beforeId)
            break;
    }

    if (i == taskCount) {
        printf("Task with specified ID not found!\n");
        return;
    }

    if (taskCount == MAX_TASKS) {
        printf("To-Do List is full!\n");
        return;
    }

    for (int j = taskCount; j > i; j--)
        todoList[j] = todoList[j - 1];

    Task newTask;
    newTask.id = taskCount + 1;
    strcpy(newTask.name, name);
    todoList[i] = newTask;

    taskCount++;
    printf("Task inserted successfully.\n");
}

void removeFront() {
    if (taskCount == 0) {
        printf("To-Do List is empty!\n");
        return;
    }

    for (int i = 0; i < taskCount - 1; i++)
        todoList[i] = todoList[i + 1];

    taskCount--;
    printf("Task removed from the front successfully.\n");
}

void removeEnd() {
    if (taskCount == 0) {
        printf("To-Do List is empty!\n");
        return;
    }

    taskCount--;
    printf("Task removed from the end successfully.\n");
}

void removeItem(int id) {
    int i;
    for (i = 0; i < taskCount; i++) {
        if (todoList[i].id == id)
            break;
    }

    if (i == taskCount) {
        printf("Task with specified ID not found!\n");
        return;
    }

    for (int j = i; j < taskCount - 1; j++)
        todoList[j] = todoList[j + 1];

    taskCount--;
    printf("Task removed successfully.\n");
}

void listItems() {
    if (taskCount == 0) {
        printf("To-Do List is empty!\n");
        return;
    }

    printf("To-Do List:\n");
    for (int i = 0; i < taskCount; i++)
        printf("%d. %s\n", todoList[i].id, todoList[i].name);
}

int searchByName(char *name) {
    for (int i = 0; i < taskCount; i++) {
        if (strcmp(todoList[i].name, name) == 0)
            return todoList[i].id;
    }
    return -1;
}
