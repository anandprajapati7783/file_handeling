
//menubase program for student database using structure
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cnt=0;
int flag=0;
struct student
{
	char name[20];
	int roll;
	float mark;
}*db=NULL;





void syncfile()
{
	FILE *fp;
	fp=fopen("student.dat","r");
	if(fp==NULL) return ;

	fseek(fp,0,2);
	cnt=ftell(fp)/sizeof(struct student);
	db=malloc(cnt*sizeof(struct student));
	fseek(fp,0,0);
	fread(db,sizeof(struct student),cnt,fp);
	fclose(fp);
	
}



void  printmenu()
{
	printf("menu\n");
	printf("i for input\np for print \nd for delet\nq for quit\ns for save\n");
}



void input()
{//whenever called, add a record to the existing database.
	
	db=realloc(db,(cnt+1)*sizeof(struct student));

	printf("Enter name:");
__fpurge(stdin);
	gets(db[cnt].name);
	printf("Enter mark");
	scanf("%f",&db[cnt].mark);
	printf("enter roll:");
	scanf("%d",&((db+cnt)->roll));

	cnt++;

flag=0;
}

void print()
{
	int i;
	for(i=0;i<cnt;i++)
printf("record %d: %20s %d %0.2f\n",i,db[i].name,db[i].roll,db[i].mark);
}

void save()
{
	FILE *fp;
	fp=fopen("student.dat","w");
	fwrite(db,sizeof( struct student),cnt,fp);
	fclose(fp);
	flag=1;
}
void delete()
{
	int rolll , i;;
	printf("enter a roll to delet\n");
	scanf("%d",&rolll);
	for(i=0;i<cnt;i++)
	{
		if(db[i].roll==rolll)
			break;
	}
	if(i==cnt) { printf("data not found\n"); return 0;}

	memmove(db+i,db+i+1,(cnt-i-1)*sizeof(struct student));
	cnt--;

	db=realloc(db,cnt*sizeof(struct student));

	if(cnt==0) db=NULL;

	flag=0;
}







int main()
{	char choice;
	syncfile();
	while(1)
	{
		
		printmenu();

		
		printf("enter choice\n");
		__fpurge(stdin);
		scanf("%c",&choice);
		
		switch(choice)
		{
				case 'i':input(); break;
				case 'd':delete();break;
				case 'q':if(flag==0){
					printf("Warning: you have not saved records. do u want to save now:(Y/N)");
					__fpurge(stdin);
					choice=getchar();
					if(choice=='y')
						save();
					}
					return 0;
				case 'p':print();break;
				case 's':save();break;
				default: printf("Error:invalid entry\n");
			
				
		}
	}


}

