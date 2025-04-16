// cdseq.c -- cdseq implementation.
#include <stdlib.h>
#include <stdio.h>
#include "cdseq.h"
struct cdsec
{
    int value;
    int diff;
};
struct cdsec *cdsec_new(int s, int d)
{
    struct cdsec *r = malloc(sizeof(struct cdsec));
    r->value = s;
    r->diff = d;
    return r;
}
int cdsec_get(struct cdsec *r)
{
    int v = r->value;
    r->value += r->diff;
    return v;
}
void cdseq_free(struct cdsec *r)
{
    free(r);
}
int main(void)
{
    struct cdsec *s1 = cdsec_new(1, 2);
    struct cdsec *s2 = cdsec_new(0, 3);
    for (int i = 0; i < 6; i++)
    {
        printf(" %2d", cdsec_get(s1));
        printf(" %2d", cdsec_get(s2));
        printf(" %2d", cdsec_get(s2));
    }
    printf("\n");
    cdseq_free(s1);
    cdseq_free(s2);
    return 0;
}