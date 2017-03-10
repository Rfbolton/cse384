#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/inotify.h>
#include <errno.h>

int main(int argc, char* argv[]){
int fd = inotify_init();


bool opt_h = false, opt_d = false, opt_m = false, opt_t = false;

int opt = getopt(argc, argv, "hdmt");

	if( argc < 2){
		printf("usage: %s ",argv[0]);
		return EXIT_SUCCESS;
	}

while (opt != -1)
	{
		if (opt == 'h')
		{
			opt_h = true;
		}
		else if (opt == 'd')
		{
			opt_d = true;
		}
		else if (opt == 'm')
		{
			opt_m = true;
		}
		else if (opt == 't')
		{
			opt_t = true;
		}
	}


	if (opt_h == true)
	{
		// prints helpful information when h arg is provided
		printf("Help Information:\n");
		printf("\n");
		printf("-d: customizes the backup location\n");
		printf("-m: disables meta-data duplication\n");
		printf("-t: appends the duplication time to the file name\n");
	}
	
	if (opt_d == true)
	{
		// customizes the backup location

	}

	if (opt_m == true)
	{
		// disables meta-data duplication

	}

	if (opt_t == true)
	{
		// appends the duplication time to the file name

	}

printf("Enter the name of the file: ");
scanf("%s",filename);

fprintf(stderr,"%s\n",strerror(errno));
//prints error information

	return EXIT_SUCCESS;
}