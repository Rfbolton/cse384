#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/inotify.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#define SIZE 100


int main(int argc, char* argv[]){
int fd = inotify_init();
int fd_in,fd_out, fd_new; //input/output file descriptors
ssize_t in_ret,out_ret; //bytes returned by read/write
char buffer[SIZE]; //character buffer
int wd = inotify_add_watch(fd, "/etc/passwd", IN_MODIFY | IN_DELETE );
char* filename = argv[1];

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
		char* get_timestring() {

		time_t time;
		struct tm *timedata;
		timedata = localtime(&time);
	}

	char* timestring = get_timestring();


     int fd = open(argv[1], O_WRONLY | O_CREAT | O_APPEND);

     size_t len = strlen (timestring);

       write (fd, timestring, len); 

       close(fd);

       return EXIT_SUCCESS;
	}

fd_in = open(argv[1], O_RDONLY | O_CREAT | O_TRUNC);

if (fd_in == -1){
	perror( "open" );
	return EXIT_SUCCESS;
}

while((in_ret = read (fd_in, &buffer, SIZE )) > 0) {
	out_ret = write(fd_out, &buffer, (ssize_t) in_ret);
	if(out_ret != in_ret){
		perror("write");
		return EXIT_SUCCESS;
	}

fd_new = open(fd_out, O_CREAT);

close (fd_in);
close (fd_out);
close(fd_new);



}
	return EXIT_SUCCESS;
}