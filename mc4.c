//program tp delet file
#include<stdio.h>
int main()
{
	int ret;
	char filename[20];
	scanf("%c",filename);

	ret=remove(filename);
	if(ret==0)
		printf("file successfully deleted\n");
	else
		printf("unable to delet file\n");
}