#include "hand.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    PNode hand;
    hand = fileread();
    hand = CombineList(&hand);
    BubbleSort(&hand);
    filewrite(hand);
    return 0;
}
