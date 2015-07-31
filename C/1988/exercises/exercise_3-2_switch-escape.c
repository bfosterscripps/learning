#include <stdio.h>
#include <stdlib.h>

# define STRLEN 15

// change tabs and newlines into "\t", and "\n" respectively
int toEscape(char newString[], char originalString[]){

	int originalStringLength;
	int newStringLength; 
	int totalSize; // how long the new string should be

	totalSize = newStringLength = originalStringLength = 0;

	// first, count up how many instances exist so you can increase the new string size accordingly
	for(int i = 0; originalString[i] != '\0'; i++){
		switch(originalString[i]){
			case '\t' :
			case '\n' : 
				totalSize += 1;
			default :
				totalSize += 1;
		}
	}
  // find the original length of newString	
	for(int i = 0; newString[i] != '\0'; i++){
		newStringLength += 1;	
	}

	if(totalSize > newStringLength){
		// TODO: reallocate the size of the array to meet the new requirements
		// size_t newSize = sizeof(char) * totalSize;
		// realloc(*newString, newSize);
		printf("You gave a string with a length of %d to hold %d chars; try again...\n", newStringLength, totalSize); 
	  return -1;
	} else {
		// the size is appropriate
		int newStringIndex;
		newStringIndex = 0; // index of the new string

		for(int i = 0; originalString[i] != '\0'; i++){
			printf("i: %d, nsi: %d\t", i, newStringIndex);	
			newStringIndex++;
			switch(originalString[i]){
				case '\t' :
					newString[newStringIndex] = '\\';
					printf("newString: %c\n", newString[newStringIndex]);
					++newStringIndex;
					printf("i: %d, nsi: %d\t", i, newStringIndex);	
					newString[newStringIndex] = 't';
					printf("newString: %c\n", newString[newStringIndex]);
					break;
				case '\n' : 
					newString[newStringIndex] = '\\';
					printf("newString: %c\n", newString[newStringIndex]);
					++newStringIndex;
					printf("i: %d, nsi: %d\t", i, newStringIndex);	
					newString[newStringIndex] = 'n';
					printf("newString: %c\n", newString[newStringIndex]);
					break;
				default :
					newString[newStringIndex] = originalString[i];
					printf("newString: %c\n", newString[newStringIndex]);
			}
		}
	}
	return 0;
}// end of toEscape function

// change "\t" and "\n" into actual tabs and newlines, respectively
int fromEscape(char newString[], char originalString[]) {

	int originalStringLength;
	int newStringLength; 
	int totalSize; // how long the new string should be

	totalSize = newStringLength = originalStringLength = 0;

	// first, count up how many instances exist so you can increase the new string size accordingly
	for(int i = 0; originalString[i] != '\0'; i++){
		switch(originalString[i]){
			case '\\' :
				switch(originalString[++i]){
					case 't':
					case 'n':
						totalSize -= 1;
						break;
				}
				break;
			default :
				totalSize++;
		}
	}
  // find the original length of newString	
	for(int i = 0; newString[i] != '\0'; i++){
		newStringLength += 1;	
	}

	if(totalSize > newStringLength){
		// TODO: reallocate the size of the array to meet the new requirements
		// size_t newSize = sizeof(char) * totalSize;
		// realloc(*newString, newSize);
		printf("You gave a string with a length of %d to hold %d chars; try again...\n", newStringLength, totalSize); 
	  return -1;
	} else {
		// the size is appropriate
		int newStringIndex;
		newStringIndex = 0; // index of the new string

		for(int i = 0; originalString[i] != '\0'; i++){
			printf("i: %d, nsi: %d\t", i, newStringIndex);	
			newStringIndex++;
			switch(originalString[i]){
				case '\\' :
					switch(originalString[++i]){
						case 'n' :
							newString[newStringIndex] = '\n';
							printf("newString: %c\n", newString[newStringIndex]);
							--newStringIndex;
							printf("i: %d, nsi: %d\t", i, newStringIndex);	
							break;
						case 't' :
							newString[newStringIndex] = '\t';
							printf("newString: %c\n", newString[newStringIndex]);
							--newStringIndex;
							i++;
							printf("i: %d, nsi: %d\t", i, newStringIndex);	
							break;
					}
				default :
					newString[newStringIndex] = originalString[i];
					printf("newString: %c\n", newString[newStringIndex]);
			}
		}
	}
	return 0;
}

int main(){
	char oldString[STRLEN] = "fish	tab there";
	char newString[STRLEN + 2] = "";
	for(int i = 0; i < (STRLEN + 2) - 1; i++){
		newString[i] = ' ';
		printf("This is ... %d\n", i);
	}
	for (int i = 0; oldString[i] != '\0'; i++){
		printf("old string: %d\n", i);
	}

	for (int i = 0; newString[i] != '\0'; i++){
		printf("new string: %d\n", i);
	}
	toEscape(newString, oldString);

	char evenNewerString[STRLEN];	
	for(int i = 0; i < STRLEN; i++){
		evenNewerString[i] = ' ';
	}

	fromEscape(evenNewerString, newString);
}
