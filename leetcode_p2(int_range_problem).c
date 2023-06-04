#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

long int tenPower(int power) {
    return (power==0) ? 1 : 10 * tenPower(power-1);
}

long int convertToInt(struct ListNode *l) {
    if (l == NULL) {
        return 0;
    }

    long int number = 0, index = 0;
    struct ListNode *list = l;

    while (list != NULL) {
        number += (list->val) * tenPower(index);
        list = list->next;
        index++;
    }
    return number;
}

struct ListNode *convertToListNode(long int number) {
    int digits[10], index = 0, remainder;
    struct ListNode *lastNode = NULL;
    struct ListNode *head = NULL;
    if (number == 0) {
        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode)); 
        newNode->val = 0;
        newNode->next = NULL;
        head = newNode;
        return head;
    }
    while (number != 0) {
        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode)); 
        newNode->val = number % 10;
        newNode->next = NULL;

        if (index == 0) head = newNode;
        else lastNode->next = newNode;

        lastNode = newNode;
        number /= 10;
        index++;
    }
    return head;
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode * firstListNode = l1;
    struct ListNode * secondListNode = l2;
    int sum = convertToInt(secondListNode) + convertToInt(firstListNode);
    return convertToListNode(sum);
}

void displayListNode(struct ListNode * list) {
    // if (list == NULL) printf("0");
    while (list!=NULL) {
        printf("%d | %p --->\n", list->val, list->next);
        list = list->next;
    } printf("\n");
}

int main()
{
    struct ListNode *l1;
    struct ListNode *l2;

    l1 = convertToListNode(999999999);
    l2 = convertToListNode(1);

    printf("the sum of l1 is: %ld\n", convertToInt(l1));
    printf("the sum of l1 is: %ld\n", convertToInt(l2));

    struct ListNode *result = addTwoNumbers(l1, l2);
    displayListNode(result);
    return 0;
}