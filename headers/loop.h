#ifndef LOOP_H
#define LOOP_H
#include "parse.h"
#include "read.h"
void seash_main_loop(void) {
	char *line;
	char **args;
	int status;

	do {
		printf("seash> ");
		line = seash_read_line();
		args = seash_tokenize_line(line);
		status = seash_execute(args);
		
		free(line);
		free(args);

	  } while(status);
}

#endif /* LOOP_H */
