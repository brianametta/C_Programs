#include <stdio.h>

struct item
{
        char name[256];
        int rate;
        int hours;
};

struct item* ReadFile(char *filename, int *count);
void WriteFile(char *filename, struct item *inv, int count);

int main(int argc, char **argv)
{
        int N;
        int i;
        int select;
        struct item* inv = ReadFile(argv[1], &N);
        printf("Assignment #4-1, Briana Wright, masc1429\n");
        while(1)
        {
        for(i = 0; i < N; i++)
        {
                printf("%d: %s %d %d\n",(i+1),inv[i].name,inv[i].rate,inv[i].hours);
        }
        printf("%d: [NEW ENTRY]\n", (N+1));
        printf(">>> ");
        int sval = scanf("%d", &select);
        if( sval == 0)
        {
                break;
        }
        select -= 1;
        if( select >= N )
        {
                struct item *temp_inv = malloc( (N+1) * sizeof(struct item));
                for(i=0;i<N;i++)
                {
                        temp_inv[i] = inv[i];
                }
                free(inv);
                inv = temp_inv;
                int newrate;
                int newhours;
                printf("Name >>> ");
                char newname[256];
                scanf(" %[^\n]", newname);
                strcpy(inv[N].name,newname);

                printf("Rate >>> ");
                scanf(" %d", &newrate);
                inv[N].rate = newrate;

                printf("Hours >>> ");
                scanf(" %d", &newhours);
                inv[N].hours = newhours;
                N++;
        }
        else
        {
                int addhours;
                printf("Additional Hours >>> ");
                scanf(" %d",&addhours);
                inv[select].hours += addhours;
        }
        }
        WriteFile(argv[1],inv,N);
        return 0;
}
void WriteFile(char *filename, struct item *inv, int count)
{
        int i;
        FILE *fp;
        fp = fopen(filename,"w");
        fprintf(fp,"%d\n",count);
        for(i = 0; i < count; i++)
        {
                fprintf(fp,"%s,%d,%d\n",inv[i].name,inv[i].rate,inv[i].hours);
        }
        fclose(fp);
}

struct item* ReadFile(char *filename, int *count)
{
        struct item* inventory;
        int i;
        FILE *fp;
        char ctemp[256];
        int itemp;
        int jtemp;
        fp = fopen(filename,"r");
        fscanf(fp,"%d\n",count);

        inventory = malloc( sizeof(struct item) * (*count));

        for(i=0;i< *count;i++)
        {
                fscanf(fp,"%[^,],%d,%d\n",ctemp,&itemp,&jtemp);
                strcpy(inventory[i].name,ctemp);
                inventory[i].rate = itemp;
                inventory[i].hours = jtemp;
        }


        fclose(fp);


        return inventory;
}