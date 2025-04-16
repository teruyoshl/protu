// sdseq.h --- constant difference sequence API.
struct cdsec *cdsec_new(int s, int d);
int cdsec_get(struct cdsec *r);
void cdseq_free(struct cdsec *r);
