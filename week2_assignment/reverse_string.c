#include <stdio.h>
#include <string.h>

void reverse_string(char *str){
	int left = 0;
	int right = strlen(str) - 1;

	while(left < right){
	      char temp = str[left];
	      str[left] = str[right];
	      str[right] = temp;

	      left++;
	      right--;
	}
}

int main(){
	char str[100];
	printf("Enter a String: ");
	fgets(str, sizeof(str), stdin);

	int len = strlen(str);
	if(str[len - 1] == '\n'){
	   str[len - 1] = '\0';
	}

	reverse_string(str);
	printf("Reversed String: %s\n", str);

	return 0;
}
