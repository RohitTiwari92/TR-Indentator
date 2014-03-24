/* this function detect the semicolen(;) and give the line break in code*/

void sem(char *s)
{
	FILE *f,*fo;
	fo=fopen(s,"a+");
	f=fopen("temp3.txt","w");
	char c;
	int temp=0,comment=0,sam=0,last=0,sc=0;
	while(1)
	{
		c=fgetc(fo);
		if(c==EOF)
		{
			break;
		}
		if(c=='"' && sc==0)
		{
			if(temp==0)
			{
				temp++;
			}
			else
			{
				temp--;
			}
		}
		if(c==39 && temp==0)
		{
			if(sc==0)
			{
				sc++;
			}
			else
			{
				sc--;
			}
		}
		if(c=='(' && temp==0 && sc==0)
		{
			last++;
		}
		if(c==')' && temp==0 && sc==0)
		{
			last--;
		}
		if(c=='/')
		{
			comment++;
		}
		else
		{
			comment=0;
		}
		if(comment==2 && temp==0)
		{
			fprintf(f,"%c",c);
			while(1)
			{
				if(c=='\n')
				break;
				c=fgetc(fo);
				fprintf(f,"%c",c);
			}
			comment=0;
		}
		if(c=='\n')
		{
			temp=0;
			sc=0;
		}
		fprintf(f,"%c",c);
		if(c==';' && temp==0 && last==0 && sc==0)
		{
			fprintf(f,"\n");
		}
	}
	fclose(f);
	fclose(fo);
}
