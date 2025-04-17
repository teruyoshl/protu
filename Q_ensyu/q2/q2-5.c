#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define BUFSIZE 80
#define STDNT   100

#define ST_UNDERGRADUATE 10
#define ST_POSTGRADUATE  20


struct student {
    int type;
    int id;
    char account[9];
};

struct undergraduate {
    int type; 
    int id;
    char account[9];
    char program[20];
};

struct postgraduate {
    int type;
    int id;
    char account[9];
    char department[20];
    char supervisor[20];
};


void set_undergraduate(struct undergraduate *s, int type, int id, char *account, char *program) {
    //s = malloc(sizeof(struct undergraduate));
    s->type = type;
    s->id = id;
    for (int i=0; i<8; i++) {
        s->account[i] = account[i];
    }
    s->account[8] = '\0';
    for (int i=0; i<19; i++) {
        s->program[i] = program[i];
    }
    s->program[19] = '\0';
}

void set_postgraduate(struct postgraduate *s, int type, int id, char *account, char *department, char *supervisor) {
    //s = malloc(sizeof(struct postgraduate));
    s->type = type;
    s->id = id;
    for (int i=0; i<8; i++) {
        s->account[i] = account[i];
    }
    s->account[8] = '\0';
    for (int i=0; i<19; i++) {
        s->department[i] = department[i];
    }
    s->department[19] = '\0';
    for (int i=0; i<19; i++) {
        s->supervisor[i] = supervisor[i];
    }
    s->supervisor[19] = '\0';

}


void search(struct student *students[STDNT], int n, int type) {
    struct student *selected[100];
    int i, j, numSameType=0;
    for(i=0; i<n; i++) {
        if(students[i]->type == type) {
            selected[numSameType++] = students[i];
        }
    }
    /*
    for (i=0; i<1; i++) {
        printf("students[%d]->type: %d\n", i, selected[i]->type);
        printf("students[%d]->id: %d\n", i, selected[i]->id);
        printf("students[%d]->account: %s\n", i, selected[i]->account);
    }
    */

    // add your code here
    // sort selected[numSameType]
    
    for (i=0; i<numSameType-1; i++) {
        for (j=i+1; j<numSameType; j++) {
            if (selected[i]->id > selected[j]->id) {
                struct student *temp = selected[i];
                selected[i] = selected[j];
                selected[j] = temp;
            }
        }
    }
    

    for (i=0; i<numSameType; i++) {
        if (selected[i]->type==ST_UNDERGRADUATE) {
            printf("%d %d %s %s\n", selected[i]->type, selected[i]->id, selected[i]->account, ((struct undergraduate*)selected[i])->program);
        }
        else if (selected[i]->type==ST_POSTGRADUATE) {
            printf("%d %d %s %s %s\n", selected[i]->type, selected[i]->id, selected[i]->account, ((struct postgraduate*)selected[i])->department, ((struct postgraduate*)selected[i])->supervisor);
        }
    }
}

int main(void) {
    struct student *students[STDNT];
    char buf[BUFSIZE], *account, *param1, *param2;
    int numStudent, len, type, id;
    for (numStudent=0; numStudent<STDNT; ) {
        if (!fgets(buf, sizeof(buf), stdin)) break;
        if (strlen(buf)==0 || buf[0]=='\n') {
             break;
        }
        len = strlen(buf);
        if (len<=3) break;

        if (buf[len - 1] == '\n')
            buf[len - 1] = '\0';
        buf[2] = '\0';
        type = atoi(buf);
        buf[10] = '\0';
        id = atoi(buf+3);
        buf[19] = '\0';
        account = buf + 11;
        while (*account == ' ')
            account++;
        param1 = account + 9;
        while (*param1 == ' ')
            param1++;
        if (type==ST_POSTGRADUATE) {
            param2 = param1;
            while (*param2 != ' ')
                param2++;
            *param2++ = 0;
            while (*param2 == ' ')
                param2++;
        }

        if (type==ST_UNDERGRADUATE) {
            students[numStudent] = (struct student*)malloc(sizeof(struct undergraduate));
            set_undergraduate((struct undergraduate*)students[numStudent], type, id, account, param1);
        }
        else if (type==ST_POSTGRADUATE) {
            students[numStudent] = (struct student*)malloc(sizeof(struct postgraduate));
            set_postgraduate((struct postgraduate*)students[numStudent], type, id, account, param1, param2);
        }
        numStudent++;
    }

    type = atoi(buf);
    search(students, numStudent, type);

    for (--numStudent; numStudent>=0; numStudent--)
        free(students[numStudent]);
    return 0;
}

