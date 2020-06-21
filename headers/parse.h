#ifndef PARSE_H
#define PARSE_H 
#define TOKEN_BUFSIZE 64
#define DELIMETERS " \t\r\n\a"

char **seash_tokenize_line(char *line){
	int current_token_bufsize = TOKEN_BUFSIZE 
	int current_position = 0;
	char **tokens = malloc(current_token_bufsize * sizeof(char *));
	char *token;

	if(!tokens){
		fprintf(stderr, "seash: memory allocation error\n");
		exit(EXIT_FALIURE);
	}

	token = strtok(line, DELIMETERS);
	while(token != NULL) {
		tokens[current_position] = token;
		current_position++;
		
		if(position >= current_token_bufsize) {
			current_token_bufsize += TOKEN_BUFSIZE;
			tokens = realloc(tokens, current_token_bufsize * sizeof(char *));
			if(!tokens) {
				fprintf(stderr, "seash: memory allocation error\n");
				exit(EXIT_FAILIURE);
			}
		}
		token = strtok(NULL, DELIMETERS);
	}
	tokens[current_position] = NULL;
	return tokens;
} 

#endif /* PARSE_H */ 
