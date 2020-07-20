#ifndef EXECUTE_H
#define EXECUTE_H 
#include "builtin.h"
int seash_execute(char **args) {
	if(args[0] == NULL) {
		return 1;
	} 
	for (i = 0; i < lsh_num_builtins(); i++) {
		if (strcmp(args[0], builtin_str[i]) == 0) {
      			return (*builtin_func[i])(args);
    
		}
  
	}

  	return lsh_launch(args);
}
#endif /* EXECUTE_H */
