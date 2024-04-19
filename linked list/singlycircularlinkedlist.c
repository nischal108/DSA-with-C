#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};

struct node *header = NULL;

struct node *getnode(int);
void insertAtFront();
void insertAtEnd();
void insertAfter();
void removeFromFront();
void removeFromEnd();
void removeAny();
void display();

int main()
{
    char choice;
    do
    {
        printf("\nSelect an option:\n");
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Insert after\n");
        printf("4. Remove from front\n");
        printf("5. Remove from end\n");
        printf("6. Remove any\n");
        printf("7. Display list\n");
        printf("8. Exit\n");
        fflush(stdin);
        choice = getchar();
        switch (choice)
        {
        case '1':
            insertAtFront();
            break;
        case '2':
            insertAtEnd();
            break;
        case '3':
            insertAfter();
            break;
        case '4':
            removeFromFront();
            break;
        case '5':
            removeFromEnd();
            break;
        case '6':
            removeAny();
            break;
        case '7':
            display();
            break;
        case '8':
            exit(0);
        default:
            printf("Invalid choice! Please enter again.\n");
        }
    } while (1);
}

struct node *getnode(int n)
{
    struct node *ptrnew = (struct node *)malloc(sizeof(struct node));
    if (ptrnew == NULL)
    {
        printf("Memory allocation failed.");
        exit(1);
    }
    ptrnew->info = n;
    ptrnew->next = NULL;
    return ptrnew;
}

void insertAtFront()
{
    int data;
    printf("Enter a number: ");
    scanf("%d", &data);
    struct node *ptrnew = getnode(data);
    if (header == NULL)
    {
        header = ptrnew;
        ptrnew->next = header;
    }
    else
    {
        ptrnew->next = header->next;
        header->next = ptrnew;
    }
    printf("Item inserted at the front.\n");
}

void insertAtEnd()
{
    int data;
    printf("Enter a number: ");
    scanf("%d", &data);
    struct node *ptrnew = getnode(data);
    if (header == NULL)
    {
        header = ptrnew;
        ptrnew->next = header;
    }
    else
    {
        ptrnew->next = header->next;
        header->next = ptrnew;
        header = header->next;
    }
    printf("Item inserted at the end.\n");
}

void insertAfter()
{
    int data, key;
    printf("Enter a number after which you want to insert: ");
    scanf("%d", &key);
    if (header == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct node *ptrthis = header->next;
    do
    {
        if (ptrthis->info == key)
        {
            printf("Enter new number: ");
            scanf("%d", &data);
            struct node *ptrnew = getnode(data);
            ptrnew->next = ptrthis->next;
            ptrthis->next = ptrnew;
            if (ptrthis == header)
            {
                header = header->next;
            }
            printf("Item inserted after %d.\n", key);
            return;
        }
        ptrthis = ptrthis->next;
    } while (ptrthis != header->next);
    printf("Key not found in the list.\n");
}

void removeFromFront()
{
    if (header == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct node *ptrthis = header->next;
    if (ptrthis->next == ptrthis)
    {
        free(ptrthis);
        header = NULL;
    }
    else
    {
        header->next = ptrthis->next;
        free(ptrthis);
    }
    printf("Item removed from the front.\n");
}

void removeFromEnd()
{
    if (header == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct node *ptrprev = NULL;
    struct node *ptrthis = header;
    while (ptrthis->next != header)
    {
        ptrprev = ptrthis;
        ptrthis = ptrthis->next;
    }
    if (ptrprev == NULL)
    {
        free(ptrthis);
        header = NULL;
    }
    else
    {
        ptrprev->next = header->next;
        free(ptrthis);
        header = ptrprev;
    }
    printf("Item removed from the end.\n");
}

void removeAny()
{
    int remove_item;
    printf("Enter the item you want to remove: ");
    scanf("%d", &remove_item);
    if (header == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct node *ptrprev = header;
    struct node *ptrthis = header->next;
    do
    {
        if (ptrthis->info == remove_item)
        {
            ptrprev->next = ptrthis->next;
            if (ptrthis == header)
            {
                header = ptrprev;
            }
            free(ptrthis);
            printf("Item %d removed from the list.\n", remove_item);
            return;
        }
        ptrprev = ptrthis;
        ptrthis = ptrthis->next;
    } while (ptrthis != header->next);
    printf("Item %d not found in the list.\n", remove_item);
}

void display()
{
    if (header == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct node *ptrthis = header->next;
    printf("List contains:\n");
    do
    {
        printf("%d\t", ptrthis->info);
        ptrthis = ptrthis->next;
    } while (ptrthis != header->next);
    printf("\n");
}
