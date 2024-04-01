#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning (disable :4996)

struct FlightData {
	char source[50];
	char destination[50];
	int fare;
};

int parseLine(char* source, char* destination, int* fare, char* line);

int main(void) {
	struct FlightData data {};
	FILE* flightFile;
	FILE* fp;
	flightFile = fopen("flights.txt", "r");
	if (!flightFile) {
		printf("Error opening the file");
		return 0;
	}
	char SingleLine[40];
	char Textdetails[40];
	while (fgets(SingleLine, 40, flightFile) != 0) {
		if (SingleLine[strlen(SingleLine) - 1] == '\n') {

			SingleLine[strlen(SingleLine) - 1] = '\0';
		}
		fp = fopen(SingleLine, "r");
		if (!fp) {
			printf("Error opening file: %s", SingleLine);
			return 0; // Move to the next line in flights.txt
		}
		while (fgets(Textdetails, sizeof(Textdetails), fp) != 0) {
			parseLine(data.source, data.destination, &data.fare, Textdetails);
		}
	}
	
		return 0;
	}
		int parseLine(char* source, char* destination, int* fare, char* line) {
			if (source == NULL || destination == NULL || fare == NULL || line == NULL) {
				return -1;
			}

			return 0; // Success
		}
	