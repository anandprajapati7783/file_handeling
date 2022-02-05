
//program to creat a file
#include<stdio.h>
int main()
{
	FILE *fp;
	char filename[20];

	printf("enter a file name for creat\n");
	scanf("%s",filename);

	fp=fopen(filename,"w");


	if(fp==NULL)
	{
		printf("file not exist\n");
		return 0;

	}
	printf("file successfilly created\n");
	return 0;
}
