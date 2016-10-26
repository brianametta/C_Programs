#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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
        cout << "Assignment #4-2, Briana Wright, masc1429" << endl;
        while(1)
        {
        for(i = 0; i < N; i++)
        {
           cout << (i+1) << ":" << inv[i].name << "," << inv[i].rate <<","<< inv[i].hours <<endl;
        }
        cout << (N+1) << ":";
        cout << "[NEW ENTRY]" << endl;
        cout << ">>> ";
        int sval = select;
        cin >> select;
        if(cin.fail())
        {
                break;
        }
        cin.ignore();
        select -= 1;
        if( select >= N )
        {
                struct item *temp_inv = (struct item*) malloc( (N+1) * sizeof(struct item));
                for(i=0;i<N;i++)
                {
                        temp_inv[i] = inv[i];
                }
                free(inv);
                inv = temp_inv;
                int newrate;
                int newhours;
                cout << "Name >>> ";
                char newname[256];
                cin.getline(newname,256);
                strcpy(inv[N].name,newname);

                cout << "Rate >>> ";
                cin >> newrate;
                inv[N].rate = newrate;

                cout << "Hours >>> ";
                cin >> newhours;
                inv[N].hours = newhours;
                N++;
        }
        else
        {
                int addhours;
                cout << "Additional Hours >>> ";
                cin >> addhours;
                inv[select].hours += addhours;
        }
        }
        WriteFile(argv[1],inv,N);
        return 0;
}
void WriteFile(char *filename, struct item *inv, int count)
{
        int i;
        ofstream outfile;
        outfile.open(filename);
        outfile << count << endl;
        for(i = 0; i < count; i++)
        {
          outfile << inv[i].name <<","<< inv[i].rate <<","<< inv[i].hours << endl;

        }
        outfile.close();
}

struct item* ReadFile(char *filename, int *count)
{
        struct item* inventory;
        int i;
        char ctemp[256];
        int itemp;
        int jtemp;
        char garbage;
        string garbages;

        ifstream infile;
        infile.open(filename);
        infile >> (*count);

        inventory = (struct item*) malloc( sizeof(struct item) * (*count));

        for(i=0;i< *count;i++)
        {
                getline(infile,garbages,'\n');
                infile.getline(ctemp, 256, ',');

                infile >> itemp;
                infile >> garbage;
                infile >> jtemp;

                strcpy(inventory[i].name, ctemp);

                inventory[i].rate = itemp;
                inventory[i].hours = jtemp;
        }


        infile.close();


        return inventory;
}