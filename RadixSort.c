#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "hand.h"
int SortNum(PNode hand)
{
    PNode p = hand;
    int x = 0, count = 0;
    for (; p != NULL; p = p->next)
    {
        if (x < p->data.totalcount)
        {
            x = p->data.totalcount;
        }
    }
    while (x)
    {
        x /= 10;
        count++;
    }
    return count;
}

int IsEmpty(PNode hand)
{
    return hand->next == NULL;
}

int IsLast(PNode hand)
{
    return hand->next == NULL;
}

void MoveNode(PNode L1, PNode L2)
{
    PNode temp;
    while (!IsLast(L1))
    {
        L1 = L1->next;
    }
    if (L2->next == NULL)
        exit(-1);
    temp = L2;
    L2 = L2->next;
    temp->next = L2->next;
    L1->next = L2;
    L2->next = NULL;
}

void RaidSort(PNode hand)
{
    int bucket = 1;
    PNode p = hand;
    PNode temp = hand;
    while (p->next != NULL)
    {
        bucket++;
        p = p->next;
    }
    PNode b[bucket];
    int i, Element, sum;
    for (i = 0; i < bucket; i++)
    {
        b[i] = temp;
        temp = temp->next;
    }
    int num = SortNum(hand);
    for (i = 0; i < num; i++)
    {
        while (!IsEmpty(hand))
        {
            Element = hand->data.totalcount;
            sum = (int)(Element / pow(10, i)) % 10;
            MoveNode(b[sum], hand);
        }
        for (int j = 0; j < 10; j++)
        {
            while (!IsEmpty(b[j]))
            {
                MoveNode(hand, b[j]);
            }
        }
    }
    for (int i = 0; i < bucket; i++)
        free(b[i]);
}
