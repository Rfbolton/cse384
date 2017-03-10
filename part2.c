#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/inotify.h>
#include <errno.h>
#include <time.h>


int main(int argc, char* argv[]){
int fd = inotify_init();
int fd_in,fd_out; //input/output file descriptors
char buffer[100]; //character buffer
char filename[100];
int wd = inotify_add_watch(fd, "/etc/passwd", IN_MODIFY | IN_DELETE );

bool opt_h = false;
bool opt_d = false;
bool opt_m = false; 
bool opt_t = false;
char* arg_d = NULL;
bool backup_modified = false;

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
		if (arg_d = NULL)
		{
			printf("No path used for option -d.\n");
		}

	if (opt_m == true)
	{
		// disables meta-data duplication

	}

	if (opt_t == true)
	{
		// appends the duplication time to the file name
		char buffer[100];
		time_t time;
		struct tm *timedata;
		timedata = localtime(&time);

	}


printf("Enter the name of the file: ");
scanf("%s",filename);


}
	return EXIT_SUCCESS;
}