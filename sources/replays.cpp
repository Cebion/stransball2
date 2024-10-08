#include "stdio.h"
#include "unistd.h"

extern char* datadir;
extern char* confdir;

int replay_parameters(char *file, int *ship, int *length, char *levelname)
{
	int i;
	FILE *fp;
	int l,end;
	int v1,v2,fuel;

        chdir(confdir);
	fp=fopen(file,"rb");
        chdir(datadir);
	if (fp==0) return -1;
	v1=fgetc(fp);
	v2=fgetc(fp);
	for(i=0;i<256;i++) levelname[i]=fgetc(fp);
	fuel=fgetc(fp);
	*ship=fgetc(fp);

	l=0;
	do{
		for(i=0;i<7;i++) end=fgetc(fp);
		l++;
	}while(end==0);

	*length=l;

	fclose(fp);

	return end;
} /* replay_parameters */ 


void replay_copy(char *f1,char *f2)
{

	FILE *fp1,*fp2;

        chdir(confdir);
	fp1=fopen(f1,"rb");
        /* chdir(confdir); */
	fp2=fopen(f2,"wb");
        chdir(datadir);

	do{
		fputc(fgetc(fp1),fp2);
	}while(!feof(fp1));

	fclose(fp2);
	fclose(fp1);
} /* replay_copy */ 

