#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
    struct node *prev;
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
        printf("Enter your choice: ");
        fflush(stdin);
        scanf(" %c", &choice);
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
    ptrnew->prev = NULL;
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
        ptrnew->prev = header;
    }
    else
    {
        ptrnew->next = header;
        ptrnew->prev = header->prev;
        header->prev->next = ptrnew;
        header->prev = ptrnew;
        header = ptrnew;
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
        ptrnew->prev = header;
    }
    else
    {
        ptrnew->next = header;
        ptrnew->prev = header->prev;
        header->prev->next = ptrnew;
        header->prev = ptrnew;
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
    struct node *ptrthis = header;
    do
    {
        if (ptrthis->info == key)
        {
            printf("Enter new number: ");
            scanf("%d", &data);
            struct node *ptrnew = getnode(data);
            ptrnew->next = ptrthis->next;
            ptrnew->prev = ptrthis;
            ptrthis->next->prev = ptrnew;
            ptrthis->next = ptrnew;
            printf("Item inserted after %d.\n", key);
            return;
        }
        ptrthis = ptrthis->next;
    } while (ptrthis != header);
    printf("Key not found in the list.\n");
}

void removeFromFront()
{
    if (header == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct node *ptrthis = header;
    if (ptrthis->next == ptrthis)
    {
        free(ptrthis);
        header = NULL;
    }
    else
    {
        header->prev->next = header->next;
        header->next->prev = header->prev;
        header = header->next;
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
    struct node *ptrthis = header->prev;
    if (ptrthis == header)
    {
        free(ptrthis);
        header = NULL;
    }
    else
    {
        ptrthis->prev->next = header;
        header->prev = ptrthis->prev;
        free(ptrthis);
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
    struct node *ptrthis = header;
    do
    {
        if (ptrthis->info == remove_item)
        {
            if (ptrthis->next == ptrthis) // Only one node in the list
            {
                free(ptrthis);
                header = NULL;
            }
            else
            {
                ptrthis->prev->next = ptrthis->next;
                ptrthis->next->prev = ptrthis->prev;
                if (ptrthis == header) // Removing the first node
                {
                    header = ptrthis->next;
                }
                free(ptrthis);
            }
            printf("Item %d removed from the list.\n", remove_item);
            return;
        }
        ptrthis = ptrthis->next;
    } while (ptrthis != header);
    printf("Item %d not found in the list.\n", remove_item);
}

void display()
{
    if (header == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct node *ptrthis = header;
    printf("List contains:\n");
    do
    {
        printf("%d\t", ptrthis->info);
        ptrthis = ptrthis->next;
    } while (ptrthis != header);
    printf("\n");
}
