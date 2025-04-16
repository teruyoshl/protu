// cdseq_demo.c -- cdseq demonstration.
#include <stdio.h>
#include "cdseq.h"
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