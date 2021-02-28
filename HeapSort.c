#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hand.h"

DataType *Change_A_L(PNode hand)
{
    int count = 1;
    PNode p = hand;
    PNode temp = hand;
    while (p->next != NULL)
    {
        count++;
        p = p->next;
    }
    DataType array[count];
    for (int i = 0; i < count; i++)
    {
        array[i] = temp->data;
        temp = temp->next;
    }
    return array;
}

PNode Change_L_A(DataType *array)
{
    int count = sizeof(array) / sizeof(DataType);
    PNode *hand = NULL;
    PNode p = *hand;
    for (int i = 0; i < count; i++)
    {
        p->data = array[i];
        p = p->next;
    }
    return *hand;
}

void swap(DataType array[], int x, int y)
{
    DataType key = array[x];
    array[x] = array[y];
    array[y] = key;
}

void Down(DataType array[], int i, int n)
{
    int parent = i;
    int child = 2 * i + 1;
    while (child < n)
    {
        if (child + 1 < n && array[child].totalcount < array[child + 1].totalcount)
        {
            child++;
        }
        if (array[parent].totalcount < array[child].totalcount)
        {
            swap(array, parent, child);
            parent = child;
        }
        child = child * 2 + 1;
    }
}

void BuildHeap(DataType array[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        Down(array, i, size);
    }
}

void HeapSort(PNode *hand)
{
    PNode p = *hand;
    DataType *array = Change_A_L(p);
    int size = sizeof(array) / sizeof(DataType);
    BuildHeap(array, size);
    for (int i = size - 1; i > 0; i--)
    {
        swap(array, 0, i);
        Down(array, 0, i);
    }
}
