/* this function detect the curly '}' bracket and indent
   the code like line change */

void bb()
{
	int temp=0;
	FILE *f,*fd,*fp,*fo;
	fpos_t pos;
	long p1;
	fo=fopen("temp1.txt","a+");
	f=fopen("temp1.txt","a+");
	fd=fopen("temp1.txt","a+");
	fp=fopen("temp2.txt","w");
	char c,d,e,f1;
	int count=0,sam=0,comment=0,sc=0,last=0;
	while(1)
	{
		if(c==EOF)
		{
			break;
		}
		if(count==0)
		{
			c=fgetc(f);
			count++;
		}
		if(count>0)
		{
			c=fgetc(f);
			d=fgetc(fd);
			fprintf(fp,"%c",d);
		}
		/*if(count>0)
		{
			fprintf(fp,"%c",d);
		}
		*/
		if(c=='"')
		{
			if(sam==0)
			{
				sam++;
			}
			else
			{
				sam--;
			}
		}
		if(c==39 && sam==0)
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
		if(comment==2 && sam==0)
		{
			// fprintf(fp,"%c",d);
			while(1)
			{
				if(c=='\n')
				break;
				c=fgetc(f);
				d=fgetc(fd);
				fprintf(fp,"%c",d);
			}
			comment=0;
		}
		if(c=='{')
		{
			temp++;
		}
		if(c=='\n')
		{
			temp=0;
			comment=0;
			sc=0;
		}
		if(c=='}')
		{
			if(temp==0 && sc==0 && last==0)
			{
				fprintf(fp,"\n");
				d=fgetc(fd);
				c=fgetc(f);
				fprintf(fp,"%c",d);
				fprintf(fp,"\n");
			}
			else
			{
				temp--;
			}
		}
	}
	fclose(f);
	fclose(fo);
	fclose(fd);
	fclose(fp);
}
