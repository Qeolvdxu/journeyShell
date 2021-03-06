#include <dirent.h>
#include <stdio.h>
 
int main(int argc, char **argv) 
{
	DIR *dir;
	struct dirent *direntry;
	char echar = '.';
	int i = 1;

	/* Print hidden files with the -a flag */
	if(argc > 1 && strcmp("-a",argv[1]) == 0)
	{
		i++;
		echar = 0;
	}

	/* Default to current directory */
	if (argc < 1+i)
		argv[i] = ".";
			
	
	if((dir = opendir(argv[i])) == NULL)
		printf("%s does not exist\n", argv[i]);
	else
	{
		/* Print each item until there are no more */
		while ((direntry = readdir(dir)) != NULL)
		{
			if(direntry->d_name[0] != echar) 
				printf("%s  ", direntry->d_name);
		}
		printf("\n");

		closedir(dir);
	}
 
	return 0;
}
