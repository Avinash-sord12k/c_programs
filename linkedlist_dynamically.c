#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void printNode(struct Node node)
{
    printf("\ndata in node: %d, and pointing to: %p", node.data, node.next);
}

void newPrintNode(struct Node* node)
{
    printf("\ndata in node: %d and pointing to: %p", node->data, node->next);
}

struct Node *arrayToLinkedList(int *array, int length)
{
    struct Node *head = NULL;
    struct Node *lastnode = NULL;
    for (int idx = 0; idx < length; idx++)
    {
        struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
        newnode->data = array[idx];

        if (idx == 0)
        {
            head = newnode;
        }
        else if ((idx < length - 1) && (idx != 0))
        {
            lastnode->next = newnode;
            newPrintNode(lastnode);
        }
        else if (idx == length - 1)
        {
            lastnode->next = newnode;
            newnode->next = NULL;
        }
        lastnode = newnode;
    };

    return head;
};

void traverseLinkedList(struct Node *node)
{
    int idx = 0;
    while (node->next != NULL)
    {
        printf("\nElement at index %d is %d ", idx, node->data);
        node = node->next;
        idx++;
    }
}

int main()
{ 
    int arraysize = 100;
    int *array = (int *)malloc(arraysize * sizeof(int));
    for (int idx=0; idx<arraysize; idx++)
    {
        array[idx] = (idx + 1);
    }

    struct Node *linkedlist = arrayToLinkedList(array, arraysize);

    return 0;
}