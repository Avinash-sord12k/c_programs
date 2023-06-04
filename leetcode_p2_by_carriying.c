// submitted and accepted
#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

void displayListNode(struct ListNode *list)
{
    // if (list == NULL) printf("0");
    while (list != NULL)
    {
        printf("%d | %p --->\n", list->val, list->next);
        list = list->next;
    }
    printf("\n");
}

struct ListNode *convertToListNode(long int number)
{
    int digits[10], index = 0, remainder;
    struct ListNode *lastNode = NULL;
    struct ListNode *head = NULL;
    if (number == 0)
    {
        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->val = 0;
        newNode->next = NULL;
        head = newNode;
        return head;
    }
    while (number != 0)
    {
        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->val = number % 10;
        newNode->next = NULL;

        if (index == 0)
            head = newNode;
        else
            lastNode->next = newNode;

        lastNode = newNode;
        number /= 10;
        index++;
    }
    return head;
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *firstListNode = l1;
    struct ListNode *secondListNode = l2;
    struct ListNode *lastNode = NULL;
    struct ListNode *head = NULL;
    int carry = 0, index = 0;
    while ((firstListNode != NULL || secondListNode != NULL || carry!=0) && index < 100)
    {
        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->val = 0;
        newNode->next = NULL;
        int firstListNodeVal = (firstListNode == NULL) ? 0 : firstListNode->val;
        int secondListNodeVal = (secondListNode == NULL) ? 0 : secondListNode->val;
        int sum = carry + firstListNodeVal + secondListNodeVal;
        carry = sum / 10;
        sum %= 10;
        newNode->val = sum;


        if (index == 0)
            head = newNode;
        else
            lastNode->next = newNode;

        lastNode = newNode;
        firstListNode = (firstListNode == NULL) ? NULL :firstListNode->next;
        secondListNode = (secondListNode == NULL) ? NULL :secondListNode->next;
        // printf("loop updates: first-NUM: %d, second-NUM: %d, carry: %d, sum: %d\n", firstListNodeVal, secondListNodeVal, carry, sum);
        index++;
    }
    return head;
}

int main()
{
    struct ListNode *l1;
    struct ListNode *l2;

    l1 = convertToListNode(11235324523452345);
    l2 = convertToListNode(123234523452345536);

    displayListNode(l1);
    displayListNode(l2);

    struct ListNode *result = addTwoNumbers(l1, l2);
    displayListNode(result);

    return 0;
}