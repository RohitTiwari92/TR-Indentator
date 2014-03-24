/* this function detect the curly '}' bracket and indent
   the code like line change */
void bcindent()
{
	FILE *f,*fp,*fd,*fo;
	f=fopen("temp3.txt","a+");
	fd=fopen("temp3.txt","a+");
	fo=fopen("temp3.txt","a+");
	fp=fopen("temp1.txt","w");
	char c,d,e;
	int count=0,comment=0,sam=0,sc=0;
	int counter=0,cfsc=0;
	int temp=0,last=0;
	if(f==NULL)
	{
		printf("file not exist");
		exit(0);
	}
	else
	{
		while(1)
		{
			if(count==0)
			{
				c=fgetc(f);
				d=fgetc(fd);
			}
			else
			{
				c=fgetc(f);
				d=fgetc(fd);
				e=fgetc(fo);
			}
			if(e==EOF)
			{
				break;
			}
			if(count>0)
			{
				fprintf(fp,"%c",e);
			}
			count++;
			if(c=='"' && sc==0)
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
			if(c=='(' && sc==0 && sam==0)
			{

					last++;


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
				// fprintf(fp,"%c",e);
				while(1)
				{
					if(c=='\n')
					break;
					c=fgetc(f);
					d=fgetc(fd);
					e=fgetc(fo);
					fprintf(fp,"%c",e);
				}
				comment=0;
			}
			if(c=='{' && sam==0 && sc==0 && last!=0)
			{
				while(d!='\n')
				{
					d=fgetc(fd);
					if(d=='"' && cfsc==0)
					{
						if(counter==0)
						{
							counter++;
						}
						else
						{
							counter--;
						}
					}
					if(d==39 && counter==0)
					{
						if(cfsc==0)
						{
							cfsc++;
						}
						else
						{
							cfsc--;
						}
					}
					if(d=='{' && counter==0 && cfsc==0)
					temp++;
					if(d=='}' && counter==0 && cfsc==0)
					temp--;
				}
				if(temp==0 && sam==0 && sc==0)
				{
					fprintf(fp,"\n");
					c=fgetc(f);
					e=fgetc(fo);
					fprintf(fp,"%c",e);
					fprintf(fp,"\n");
				}
				else
				{
					temp=0;
				}
				while(c!='\n')
				{
					c=fgetc(f);
					e=fgetc(fo);
					fprintf(fp,"%c",e);
					sc=0;
					last=0;
					temp=0;
					comment=0;
					sam=0;
				}
			}
		}
	}
	fclose(f);
	fclose(fo);
	fclose(fd);
	fclose(fp);
}
