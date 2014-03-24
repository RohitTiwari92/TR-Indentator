/* this is main program where all indention operation occur and other function calling*/


#include <stdio.h>
#include <stdlib.h>
#include<fcntl.h>
#include<string.h>
#include"sub.c"
#include"bbd.c"
#include"semi.c"
//void bcindent(char *s);
int main(int arg,char *argv[])
{
	int handle,bracketcount,count=0,i;
	char s[100],c,copy;
	for(i=2;i<arg;i++)
	{
		strcat(argv[1]," ");
		strcat(argv[1],argv[i]);
	}
	// printf("%s",argv[1]);
	/*printf("Enter path\n");
	scanf("%s",&s);
	*/
	//printf("%s",argv[1]);
	sem(argv[1]);
	bcindent();
	bb();
	FILE *f,*fp;
	FILE *fpc;
	f=fopen("temp2.txt","a+");
	fp=fopen("temp.txt","w");
	if(f==NULL)
	{
		printf("file not exist");
	}
	else
	{
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
				if(c=='\n')
				{
					c=fgetc(f);
					if(c==' '||c=='\t'||c=='\n')
					{
						while(1)
						{
							// printf("hello tab or space detected");
							c=fgetc(f);
							if(c!=' '&&c!='\t'&& c!='\n')
							break;
						}
					}
					if(c=='}')
					{
						count--;
					}
					// printf("%c%d",c,count);
					fprintf(fp,"\n");
					for(i=count;i>0;i--)
					{
						//printf("in tab loop%d\n",count);
						fprintf(fp,"\t");
					}
					if(c=='{')
					{
						count++;
					}
				}
				fprintf(fp,"%c",c);
			}
		}
	}
	fclose(f);
	fclose(fp);
	//wbc(argv[1]);
	return 0;
}
