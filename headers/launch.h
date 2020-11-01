#ifndef LAUNCH_H
#define LAUNCH_H 
int seash_launch(char **args)
{
	pid_t pid, wpid;
	int status;

	pid = fork();
	if(pid == 0) { //Is child
		if(execvp(args[0], args) == -1) { //Execs arg and checks for errors
			perror("seash"); //Prints error with program name provided
		}
		exit(EXIT_FAILURE);
	} else if(pid < 0) { //Fork failiure
		perror("seash");
	} else { //Is parent
		do {
			wpid = waitpid(pid, &status, WUNTRACED); //Waits for child status to change
		} while(!WIFEXITED(status) && !WIFSIGNALED(status)); //Loops waitpid until process is exited or killed
	}

	return 1;
}
#endif /* LAUNCH_H */
