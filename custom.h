#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//report error then exit with -1
void fatal_error(char *message) {

	char error_message[100];
	//create error message 
	strcpy(error_message, "[!?] FATAL ERROR ");
	strncat(error_message, message, 83);
	//report error message then exit with -1
	perror(error_message);
	exit(-1);
}

//malloc (memory allocation)  with error check
void* errcheck_malloc(unsigned int size) {
	//initialize void pointer
	void *ptr;
	//allocate memory
	ptr = malloc(size);
	//check pointer for NULL
	if (ptr == NULL) {
		fatal_error("in errcheck_malloc on memory allocation");
	}
	//return location address, don't forget to typecast into something useful
	return ptr;
}

//dump raw memory in both hex and printable formats
void raw_dump(const unsigned char *buffer, const unsigned int length) {
	unsigned char byte;
	unsigned int i, j;

	for (i=0; i < length; i++) {
		byte = buffer[i];  //because pointers and arrays are the same thing under the hood
		printf("%02x ", buffer[i]);  //print byte in hex format

		if(((i%16) == 15) || (i==length-1)) {
			for(j=0; j < 15-(i%16); j++) { printf("   "); }
			printf("| ");
			for(j=(i-(i%16)); j<=i; j++) {	//display printable characters from line
				byte = buffer[j];
				if(( byte>31) && (byte < 127)) //check if byte is within printable character range
					printf("%c", byte);
				else
					printf(".");		//if by is not printable write a . in its place

			}
		printf("\n"); //end of line printed at 16 bytes per line
		} //end outer if block
	}// end outside for loop
}
