#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void printhelp() {
	printf("Usage: ./NotifyMe <your shell command>\n\tSetting phone number: ./NotifyMe -d <number>");
}

int main(int argc, const char* argv[]) {
	FILE *pn;
	if (argc == 1) {
		printhelp();
		exit(-1);
	}
	if (argc == 2 && ((strcmp(argv[1], "-h") == 0) || (strcmp(argv[1], "help") == 0))) {
		printhelp();
		exit(-1);
	}
	if (argc == 3 && (strcmp(argv[1], "-d")) == 0) {
		pn = fopen("number.txt", "w");
		if (strlen(argv[2]) == 10){
			fputs(argv[2], pn);
			fclose(pn);
		}
		else {
			printf("Invalid phone number lengnth!\n");
			exit(-1);
		}
	}

	pn = fopen("number.txt", "r");

	if (!pn) {
		printf("No phone number specified. Set the phone number first!\n");
		exit(-1);
	}

	char* number = malloc(sizeof(char) * 11);
	fread(number, 11, 1, pn);
	fclose(pn);
	char* firsthalf = "curl -X POST http://textbelt.com/text -d number=";
	char* secondhalf = " -d \"message=Your program execution has started! Go take a coffee break :)\"";

	char* message = malloc(sizeof(char) * 200);
	message[0] = 0;
	strcat(message, firsthalf);
	strcat(message, number);
	strcat(message, secondhalf);

	// String concatenate the instructions from the argument
	int i;
	char* instruction = malloc(sizeof(char) * 4096);
	instruction[0] = 0;
	for (i = 1; i < argc; ++i) {
		strcat(instruction, argv[i]);
		strcat(instruction, " ");
	}

	// Send the text message
	system(message);

	// Executing instruction
	system(instruction);

	char* finishedhalf  = " -d \"message=Your program execution has finished! Get back to work :)\"";
	message[0] = 0;
	strcat(message, firsthalf);
	strcat(message, number);
	strcat(message, finishedhalf);
	
	// Send the finished message
	system(message);

	return 0;
}