#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct LIST
{
    int ID;
    int problemID;
    char date[15];
    char time[10];
};
int main(void)
{
    struct LIST col[30000];
    char col1[100];
    int c1=1;
    FILE *fp=fopen("c2017.txt","r");
    if (fp == NULL)
    {
        printf("���ļ�ʧ�ܣ������ļ���·�������ԣ�\n");
        exit(0);
    }
    fseek(fp,0,0);
    fgets(col1,100,fp);
    while( !feof(fp))
    {
        fscanf(fp,"%d %d %s %s",&col[c1].ID,&col[c1].problemID,col[c1].date,col[c1].time);
        c1++;
    }
    fclose(fp);
    //���б��������
    int IDnumber=1;
    for(IDnumber=1;IDnumber<=300;IDnumber++)
    {
        int c2=1,min=1,max;
        for(c2=1;c2<=c1;c2++)
        {
            if(col[c2].ID==IDnumber&&col[c2-1].ID!=IDnumber)
            {
                min=c2;
            }
            if(col[c2].ID==IDnumber&&col[c2+1].ID!=IDnumber)
            {
                max=c2;
                break;
            }
        }
        int i =min;
        int j = 0;
        struct LIST temp;
        int tempmin= 0;
        for (i=min; i<max-1;i++)
        {
            tempmin= i;
            for (j=i+1;j<=max; j++)
            {
                if (strcmp(col[tempmin].date , col[j].date)>0)
                {
                    tempmin = j;
                }
                else
                {
                    if(strcmp(col[tempmin].date , col[j].date)==0)
                    {
                        if(strcmp(col[tempmin].time, col[j].time)>0)
                        {
                          tempmin = j;
                        }
                    }
                }
            }

            if (tempmin!= i)
            {
                temp = col[tempmin];
                col[tempmin] = col[i];
                col[i] = temp;
            }
        }
    }
    printf("********�ļ���ȡ�������**********\n��һ�������������\n");
    int L,N;
    char newname[255],txt[]=".txt";
    printf("������ʱ��(����):");
    scanf("%d",&L);
    printf("�����������:\t");
    scanf("%d",&N);
    printf("������������ļ��ļ���:\t");
    scanf("%s",&newname);
    strcat(newname,txt);




    FILE *fpt=fopen(newname,"w");
    fseek(fpt,0,0);
    fprintf(fpt,"ID\tproblem_ID\tdate\ttime\n");
    /*for(c1=1;strcmp(col[c1].date,"\0")!=0;c1++)
    {
        fprintf(fpt,"%d\t%d\t%s\t%s\n",col[c1].ID,col[c1].problemID,col[c1].date,col[c1].time);
    }*/
    fclose(fpt);
    printf("********�����ļ��ɹ���********\n");
    /*for(c1=1;c1<=20000;c1++)
    {
        printf("%d %d %s %s\n",col[c1].ID,col[c1].problemID,col[c1].date,col[c1].time);
    }*/
}
