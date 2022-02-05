//program for counting num of lines in file
#include<stdio.h>


int main()
{
	FILE *ptr;
	char ch;
	int line_count=0;
	char filename[100];


	scanf("%s",filename);
	ptr=fopen(filename,"r");
	if(ptr==NULL)
	{
		printf(" file not exist\n");
		return 0;
	}
	while((ch=fgetc(ptr))!=EOF)
	{
		if(ch=='\n')
			line_count++;
	}
	fclose(ptr);
	printf(" total num of lines are %d\n",line_count);
}