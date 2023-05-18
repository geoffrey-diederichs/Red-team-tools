#include <stdio.h>

unsigned char message[] =  "\x00\x06\x00\x0a\x0c\x15\x08\x1a\x0d\x11\x1f\x13\x13\x06\x15\x72\x7d\x08\x00\x67";
int message_size = sizeof(message);
char key[] = "<KEY_TO_REPLACE>";
int key_size = sizeof(key);

int print_result(char *str, int len)
{
	printf("%d bytes\n", len);                 		
	
	int i;
	for (i = 0; i < len; i++)
		printf("\\x%hhx", str[i]);
	printf("\n");                         
	
	for (i = 0; i < len; i++)
		printf("%c", str[i]);
	printf("\n");	

	return 0;
}

int main(int argc, char* argv[])
{
	unsigned char encoded[message_size];	
	
	int i;
	for (i = 0; i < message_size-1; i++)
		encoded[i] = message[i] ^ key[i%(key_size-1)];
	encoded[i] = '\0';

	print_result(encoded, message_size-1);

	return 0;
}
