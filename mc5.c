//reading content of file using string

#include<stdio.h>
int main()
{
	FILE *fp;
	char filename[20];
	char data[80];
	scanf("%s",filename);
	fp=fopen(filename,"r");
	int cnt=0;
	if(fp==NULL)
	{
		printf("file  is not exist\n");
		return 0;
	}

	while(fgets(data,80,fp))
		{
			
				
			printf("%d.%s",++cnt,data);
		}

	fclose(fp);
} 

