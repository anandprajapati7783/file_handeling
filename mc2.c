
//program to print content of file
#include<stdio.h>

int main()
{
	FILE *fp;
	char ch;
	char filename[20];

	printf("enter a file name\n");
	scanf("%s",filename);
	fp=fopen(filename,"r");

	if(fp==NULL)
		{
			printf("file not exist\n");
			return 0;
		}

	while((ch=fgetc(fp))!=EOF)
		printf("%c",ch);

	
	fclose(fp);
}