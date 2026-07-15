#include <stdio.h>

int find_substring(const char *haystack, const char *needle){
	if(*needle == '\0'){
	    return 0;
	}
	
	for(int i = 0; haystack[i] != '\0'; i++){
	    int j = 0;
	    
	    while(needle[j] != '\0' && haystack[i+j] == needle[j]){
		  j++;
	    }

	    if(needle[j] == '\0'){
	       return i;
	    }
	}

	return -1;
}

int main(){
    char *haystack = "Embedded Systems";
    char *needle = "bed";

    int result = find_substring(haystack, needle);
    printf("Result: %d\n", result);

    return 0;
}
