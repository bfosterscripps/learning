/*
	Author: Brandon Foster
	Date: 20150819
	Purpose:
		Write the function strrindex(s,t) which returns the position
		of the rightmost occurence of t in s, or -1 if there is none.
*/
#include <stdio.h>
#define MAXLINE 1000 // maximum input line length

int getline_local(char line[], int max);
int strrindex(char source[], char searchFor[]);

char pattern[] = "ould"; // what to search for

// find all lines matching pattern
int main() {
	char line[MAXLINE];
	int found = 0;

	while (getline_local(line, MAXLINE) > 0) {
		if (strrindex(line, pattern) >= 0) {
			printf("Found at: %d", strrindex(line, pattern));
			printf("%s", line);
			found++;
		}
	}
	return found;
} 

// getline_local: get line into s, return length
int getline_local(char s[], int lim) {
	int c, i;
	
	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
		s[i++] = c;
	}
	if ( c == '\n') {
		s[i++] = c;
	}
	return i;
}

// strrindex: return index of t in s starting from the right, -1 if none
int strrindex(char s[], char t[]) {
	int i, j, k;

	for (i = 0; s[i] != '\0'; i++){
		for (j = k, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}
