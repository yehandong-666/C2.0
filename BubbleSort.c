#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hand.h"

void BubbleSort(PNode *hand)
{
    int count = 1, num;
    PNode p, q, tail;
    p = *hand;
    while (p->next != NULL)
    {
        count++;
        p = p->next;
    }
    for (int i = 0; i < count - 1; i++)
    {
        num = count - i - 1;
        q = (*hand)->next;
        p = q->next;
        tail = *hand;
        while (num--)
        {
            if (q->data.totalcount < p->data.totalcount)
            {
                q->next = p->next;
                p->next = q;
                tail->next = p;
            }
            tail = tail->next;
            q = tail->next;
            p = q->next;
        }
    }
}
