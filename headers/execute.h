#ifndef EXECUTE_H
#define EXECUTE_H 
#include "builtin.h"
#include "launch.h"
int seash_execute(char **args) {
	if(args[0] == NULL) {
		return 1;
	} 
	for (int i = 0; i < seash_builtin_count(); i++) {
		if (strcmp(args[0], builtin_arr[i]) == 0) {
      			return (*func_list[i])(args);
    
		}
  
	}

  	return seash_launch(args);
}
#endif /* EXECUTE_H */
