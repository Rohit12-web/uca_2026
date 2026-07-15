#include <stdio.h>

int my_strlen(const char *str){
	int length = 0;
	while(str[length] != '\0'){
	      length++;
	}

	return length;
}

int main(){
	char str[100];
	printf("Enter a String: ");
	scanf("%99s", str);
	printf("Length = %d\n", my_strlen(str));

	return 0;
}
