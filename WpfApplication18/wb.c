/* this is write back function of intendent file*/

#include<stdio.h>
#include<string.h>
int main(int arg,char *s[])
{
	FILE *f,*fp;
	char c;
	int i;
	for(i=2;i<arg;i++)
	{
		strcat(s[1]," ");
		strcat(s[1],s[i]);
	}
	f=fopen("temp.txt","a+");
	fp=fopen(s[1],"w");
	while(1)
	{
		c=fgetc(f);
		//     printf("%c",c);
		if(c==EOF)
		{
			break;
		}
		else
		{
			fprintf(fp,"%c",c);
		}
	}
	fclose(f);
	fclose(fp);
}
