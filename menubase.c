//copy content of file 1 into file 2
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
void display();
void printmenu()
{
	printf("print menus----\n");
	printf(" D for display\n R for remove\n N for new file\n C for copying file\n Q for quit\n W for write a contetnt on file\n");
	printf("eneter  your choice\n");
}
void display()
{
	FILE *fp;
	char ch;
	char filename[20];
	printf("Enter filename\n");
	scanf("%s",filename);
	fp=fopen(filename,"r");
	if(fp==NULL)
	{
		printf("file not exist\n");
		return 0;

	}
	while((ch=fgetc(fp))!=EOF)
		printf("%c",ch);
printf("\n");

	fclose(fp);

}

void newfile()
{
	FILE *fp;
	char filename[20];
	printf("Enter filename\n");
	scanf("%s",filename);
	fp=fopen(filename,"w");
	if(fp==NULL)
	{
		printf("file not exist\n");
		return 0;
	}
	printf("file successfully created\n");
fclose(fp);
}

void fremove()
{
	

	int ret=1;
	char filename[20];
	printf("enter file name\n");
	scanf("%s",filename);
	
	ret=remove(filename);
	if(ret==0)
		printf("file successfully deleted\n");
	else
		printf("unable to delet file\n");
	
}

// void writefile()
// {
// 	FILE *fp;
// 	char data[100];
// 	char filename[20];
// 	//temp=getstring();
// 	printf("Enter filename\n");
// 	scanf("%s",filename);
	
// 	fp=fopen(filename,"w+");
// 	 gets(data);
//         while(strlen(data)>0)
//         {
//             fputs(data, fp);
//             fputs("\n", fp);
//             gets(data);
//         }

// 	fclose(fp);

// }
// char* getstring()
// {
// 	char *p=NULL;
// 	int i=0;
// 	do{
// 		p=realloc(p,i+1);
// 		p[i]=getchar();
// 	}while(p[i++]!='\n');
// 	p[i-1]='\0';
// 	return p;
// }
void copyfile()
{
	FILE *source ,*dest;
	char ch;
	char filename1[20];
	char filename2[20];

	printf("enter  file name  to be copy\n");
	scanf("%s",filename1);
	printf("enter file name in which it will be copied\n");
	scanf("%s",filename2);

	source=fopen(filename1,"r");

	if(source==NULL)
	{
		printf("file not exist\n");
		return 0;
	}
	dest=fopen(filename2,"w");
	if(dest==NULL)
	{
		fclose(source);
		return 0;
	}



	while((ch=fgetc(source))!=EOF)
		fputc(ch,dest);

	printf("file successfully copied\n");
	fclose(dest);

}

int main()
{
	while(1)
	{
		printmenu();
		char choice;
		__fpurge(stdin);
		scanf("%c",&choice);
		switch(choice)
		{
			case 'D':display(); break;
			case 'R':fremove(); break;
			case 'N':newfile(); break;
			case 'C':copyfile(); break;
		
			case 'Q':return 0;
			default :printf("error invalid entry\n"); break;
		}

	}
}