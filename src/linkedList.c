#pragma once

#include "./globals.h"
#include "./physics.c"
#include <stdlib.h>

OBJECT *newelement(OBJECT temp)
{
    OBJECT *p;
    p = (OBJECT *)malloc(sizeof(OBJECT));
    p->index = temp.index;
    p->Img = temp.Img;
    p->X = temp.X;
    p->Y = temp.Y;
    p->W = temp.W;
    p->H = temp.H;
    p->DIRX = temp.DIRX;
    p->DIRY = temp.DIRY;
    p->Life = temp.Life;
    p->DX = temp.DX;
    p->DY = temp.DY;
    p->FX = temp.FX;
    p->FY = temp.FY;
    p->Angle = temp.Angle;
    p->next = NULL;
    return p;
}

OBJECT *addend(OBJECT *head, OBJECT *newp)
{
    OBJECT *p2;
    if (head == NULL)
    {
        return newp;
    }
    for (p2 = head; p2->next != NULL; p2 = p2->next);
    p2->next = newp;
    return head;
}

int length(OBJECT **head)
{
    int count = 0;
 
    while (*head != NULL)
    {
        count++;
        head = &(*head)->next;
    }

    return count;
}

OBJECT *getObject(OBJECT *head, int index)
{
    OBJECT *p;
    for (p = head; p != NULL; p = p->next)
    {
        if (p->index == index)
        {
            break;
        }
    }
    
    return p;
}

void RemoveThing(OBJECT **head, int index)
{
    int present = FALSE;
    OBJECT *old;
    OBJECT **tracer = head;
    if ((*tracer)->index == index)
        present = TRUE;
    while ((*tracer) && !(present))
    {
        if ((*tracer)->index == index)
            present = TRUE;
        tracer = &(*tracer)->next;
    }

    if (present)
    {
        old = *tracer;
        *tracer = (*tracer)->next;
        free(old); // free up remainder of list element
    }
}

void reindex(OBJECT **head)
{
    int count = 0;
    OBJECT *p = NULL;
    OBJECT **tracer = head;
    while ((*tracer) != NULL)
    {
        p = *tracer;
        p->index = count;
        count++;
        tracer = &(*tracer)->next;
    }
}

OBJECT *delelement(OBJECT *head, int index)
{
    OBJECT *p, *prev;
    prev = NULL;
    for (p = head; p != NULL; p = p->next)
    {
        if (p->index == index)
        {
            if (prev == NULL)
                head = p->next;
            else
                prev->next = p->next;
            free(p); // remove rest of OBJECT
            return head;
        }
        prev = p;
    }
    return NULL;
}

void deleteObject(OBJECT **head, int index, int sort)
{
    OBJECT *p = *head;
    if (index == 0 || length(head) <= 1 || p->index == index)
        RemoveThing(head, index);
    else
        delelement(*head, index);
    if (sort == TRUE)
        reindex(head);
}
