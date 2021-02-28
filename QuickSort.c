
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hand.h"

void swap(PNode p, PNode q)
{
    DataType temp = p->data;
    p->data = q->data;
    q->data = temp;
}

PNode FindTail(PNode hand)
{
    PNode p = hand;
    while (p->next != NULL)
        p = p->next;
    return p;
}

void QuickSort(PNode hand)
{
    PNode tail = FindTail(hand);
    if (hand == tail || hand == NULL || hand == tail->next)
        return;
    PNode p, q;
    p = q = hand;
    while (q != tail)
    {
        q = q->next;
        if (q->data.totalcount < hand->data.totalcount)
        {

            p = p->next;
            swap(p, q);
        }
    }
    swap(hand, p);
    QuickSort(hand);
    QuickSort(p->next);
}
