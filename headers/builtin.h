#ifndef BUILTIN_H
#define BUILTIN_H 
//Builtin command functins
int seash_cd(char **args);
int seash_help(char **args);
int seash_exit(char **args);


//Command list
char *builtin_arr[] = {
	"cd",
	"help",
	"exit"
};

int  (*func_list[]) (char **) = {
	&seash_cd,
	&seash_help,
	&seash_exit
};

int seash_builtin_count() {
	return sizeof(builtin_arr) / sizeof(char *);
}

int seash_cd(char **args) {
	//If argument isnt provided to cd throw error
	if(args[1] == NULL) {
		fprintf(stderr, "seash: expected argument to \"cd\"\n");
	} else {
		if(chdir(args[1]) != 0) {
			perror("seash");
		}
	}
	return 1;
}

int seash_help(char **args){
	printf("Seash: A C shell, by ie04\n");
	printf("The following commands are built in:\n");

	for(int i = 0; i < seash_builtin_count(); i++){
		printf("%s\n", builtin_arr[i]);
	}
	return 1;
}
int seash_exit(char **args) {
	return 0;
}

#endif /* BUILTIN_H */
