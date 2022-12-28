#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define SIZE 150
//enum {SUCCESS,FAIL,SIZE =10};
typedef struct
{
	int id;
	//voi sdt va mssv nen de string de luu VD 098598457
	char name[30];
	char snum[30];
	char pnum[35];
	float score;
} sv;
int main(void)
{
	//de bai yeu cau doc file r in thong tin kem diem ra file bangdiem.txt
	FILE *fp, *f;
	// khong can cai nay
	//int reval =SUCCESS;
	int i=0,n;
	sv ls[SIZE];
	printf("Loading file...\n");
	//Tao 1 file ten nhu trong if hoac doi ten file m co san thanh info 
	if ((fp=fopen("info.txt","r"))==NULL)
	{
		printf("Cannot open %s.\n","info.txt");
		//reval = FAIL;
		return 1;
	}
	else if((f = fopen("bangdiem.txt", "w")) == NULL)
	{
		printf("Cannot open %s.\n","bangdiem.txt");
		//reval = FAIL;
		return 1;
	}
	else
	{
		while(fscanf(fp,"%d%s%s%s",&ls[i].id,ls[i].snum,ls[i].name,ls[i].pnum)!=EOF)
		{
			i++;
		}
		n=i;
				/*for (i=0;i<n;i++)
				{
					printf("%-6s%-15s%-30s%-15s\n","No","Student_number","Firstname","Phone_number");
					printf("%-6d%-15s%-30s%-15s\n",ls[i].id,ls[i].snum,ls[i].name,ls[i].pnum);
				} 
				} */
		printf("Xin moi nhap diem:\n\n");
		for (i=0;i<n;i++)
		{
			printf("Diem cua sinh vien %s:",ls[i].snum);
			scanf("%f",&ls[i].score);
		}

		int k;
    	fprintf(f, "%-10s%-20s%-35s%-20s%-10s\n", "No", "Student_number", "First-name", "Phone_number", "Score");
    	for(k = 0; k < i; ++k)
    	{
        	fprintf(f, "%-10d%-20s%-35s%-20s%-10.2f\n", ls[k].id, ls[k].snum, ls[k].name, ls[k].pnum, ls[k].score);
    	}
		//return reval;
		fclose(f);
		fclose(fp);
		return 0;
	}
}


