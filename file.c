
//reading data using  scanf here we can use %s and %c both but for string use fgets 

#include <stdio.h>
#include <stdlib.h>
int main()
{


char str[20];
FILE *fp;

if ((fp=fopen("student.dat","r"))== NULL)
{
printf("Error! The file does not exist.");
exit(0);
}
fscanf(fp,"%s", str);
printf("The character is: %s", str);
fclose(fp);
return 0;
}
