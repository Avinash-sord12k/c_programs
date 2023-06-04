#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode * next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *firstListNode = l1;
    struct ListNode *secondListNode = l2;
    struct ListNode *head = NULL;
    struct ListNode *previousNode;
    int index = 0;

    while (firstListNode->next != NULL)
    {
        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->val = firstListNode->val + secondListNode->val;

        if (index == 0)
            head = newNode;
        else
            previousNode->next = newNode;

        previousNode = newNode;
        firstListNode = firstListNode->next;
        secondListNode = secondListNode->next;

        if (firstListNode->next == NULL)
        {
            struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
            newNode->val = firstListNode->val + secondListNode->val;
            previousNode->next = newNode;
            newNode->next = NULL;
        }

        index++;
    }

    return head;
}

int main()
{
    // code goes here;
}