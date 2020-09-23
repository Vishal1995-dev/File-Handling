//Accept two file names from user and copy contents of one file in another file

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

void filecopy(char *source,char *dest)
{
	int fd_src=0;
	int fd_dest=0;
	int ret=0;
	char mug[100]={'\0'};
	
	fd_src=open(source,O_RDONLY);
	
	if(fd_src==-1)
	{
		printf("Unable to read file\n");
		return;
	}
	
	fd_dest=open(dest,O_RDWR | O_CREAT,0777);
	
	if(fd_dest==-1)
	{
		printf("Unable to create file\n");
		close(fd_src);
		return;
	}
	
	while((ret=read(fd_src,mug,sizeof(mug)))!=0)
	{
		write(fd_dest,mug,ret);
	}
	close(fd_src);
	close(fd_dest);
}

int main()
{
	char source[20]={'\0'};
	char dest[20]={'\0'};
	
	printf("Enter name of source\n");
	scanf("%[^'\n']s",source);
	printf("Enter name of destination\n");
	scanf(" %[^'\n']s",dest);

	filecopy(source,dest);

	return 0;
}
