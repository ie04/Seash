#ifndef READ_H
#define READ_H
#define LINE_BUFSIZE 2048

char *seash_read_line(void) {

	int current_bufsize = LINE_BUFSIZE;
	int current_position = 0;
	char *buffer = malloc(sizeof(char) * current_bufsize);
	int c;

	//if buffer var is null throw error
	if(!buffer){
		fprintf(stderr, "seash: memory allocation error\n");
		exit(EXIT_FAILURE);
	}

	//getchar loop for line reading; EOF and newline signal end of line
	while(1) {
		c = getchar();
		
		if(c == EOF || c == '\n') {
			//if end is reached the last position is made null to tell end of line from buffer
			buffer[current_position] = '\0';
			return buffer;
		} else {
			buffer[current_position] = c;
		}
		current_position++;	

		//Check if buffer is exceeded and resize appropriately
		if(current_position >= current_bufsize) {
			current_bufsize += LINE_BUFSIZE;
			buffer = realloc(buffer, current_bufsize);
			if(!buffer){
				fprintf(stderr, "seash: memory allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		
	}
}

#endif /* READ_H */
