/*1.Write a C program to emulate the ls command using stat and lstat API functions .Print File type, permission etc all the attributes. */
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<time.h>

void printFileProperties(struct stat stats)
{
	struct tm dt;
		
	printf("\nFile Permissions: \t");
	if(S_ISDIR(stats.st_mode))
		printf("d");
	else
		printf("-");
	if(stats.st_mode & S_IRUSR)
		printf("r");
	else
		printf("-");	
	if(stats.st_mode & S_IWUSR)
		printf("w");
	else
		printf("-");
	if(stats.st_mode & S_IXUSR)
		printf("x");
	else
		printf("-");
	printf("\t");	
	if(stats.st_mode & S_IRGRP)
		printf("r");
	else
		printf("-");	
	if(stats.st_mode & S_IWGRP)
		printf("w");
	else
		printf("-");
	if(stats.st_mode & S_IXGRP)
		printf("x");	
	else
		printf("-");
	printf("\t");	
	if(stats.st_mode & S_IROTH)
		printf("r");
	else
		printf("-");	
	if(stats.st_mode & S_IWOTH)
		printf("w");
	else
		printf("-");
	if(stats.st_mode & S_IXOTH)
		printf("x");	
	else
		printf("-");				
		
	printf("\nFile size: \t %ld", stats.st_size);	
	printf("\nNumber of Links: \t%ld", stats.st_nlink);
	printf("\nFile inode Number: \t%ld",stats.st_ino);	
	
	dt = *(gmtime(&stats.st_ctime));
	printf("\nFile Created On: \t%d-%d-%d\t%d:%d:%d", dt.tm_mday,dt.tm_mon,dt.tm_year + 1900, dt.tm_hour, dt.tm_min, dt.tm_sec);
	
	dt = *(gmtime(&stats.st_mtime));
	printf("\nFile Last Modified On: \t%d-%d-%d\t%d:%d:%d\n", dt.tm_mday,dt.tm_mon,dt.tm_year + 1900, dt.tm_hour, dt.tm_min, dt.tm_sec);	
}

int main() 
{
	char path[1000];
	struct stat stats;
	
	printf("Enter the File Path: ");
	scanf("%s", path );
	
	if(stat(path, &stats)==0)
	{
		printFileProperties(stats);
	}
	else
	{
		printf("Unable to Get File Properties.");
		printf("\nCheck Whether %s file Exists.",path);
	}
}
