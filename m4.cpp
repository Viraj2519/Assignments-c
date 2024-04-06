#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning (disable :4996)

struct FlightData {
	char source[50];
	char destination[50];
	int  fare;
};

int parseLine(char* source, char* destination, int* fare, char* line);
int processFlights(char* filename, struct FlightData details[], int numFlights);
void displayLeastFareDetails(char filename[], struct FlightData* flights, int numFlights);

int main(void) {
	int numberLine = 0;
	struct FlightData data[100];
	FILE* flightFile;
	FILE* fp;
	flightFile = fopen("flights.txt", "r");
	if (!flightFile) {
		printf("Error opening the file");
		return 0;
	}
	char SingleLine[40];
	char line[40];
	while (fgets(SingleLine, 40, flightFile) != NULL) {
		if (SingleLine[strlen(SingleLine) - 1] == '\n') {
			SingleLine[strlen(SingleLine) - 1] = '\0';
		}
		fp = fopen(SingleLine, "r");
		if (!fp) {
			printf("Error opening file: %s", SingleLine);
			return 0; // Move to the next line in flights.txt
		}
		while (fgets(line, 40, fp) != NULL) {
			if (line[strlen(line) - 1] == '\n') {
				line[strlen(line) - 1] = '\0';
			}

			if (processFlights(line, data, numberLine) == 1) {
				continue;
			}
			displayLeastFareDetails(SingleLine,data, numberLine);
		}
	}

	return 0;
}
int parseLine(char* source, char* destination, int* fare, char* line) {
	int i, j;

	for (i = 0; line[i] != '-'; i++) {
		if (line[i] == '\0') {
			return -2;
		}
		source[i] = line[i];
	}
	source[i] = '\0';

	for (j = i + 1; line[j] != ','; j++) {
		if (line[j] == '\0') {

			return -1;
		}
		destination[j - i - 1] = line[j];
	}
	destination[j - i - 1] = '\0';

	*fare = atoi(&line[j + 1]);
	return 0;
}

int processFlights(char* filename, struct FlightData details[], int numFlights) {
	int result = parseLine(details->source, details->destination, &details->fare, filename);
	if (result == -2) {
		printf("Error: Missing dash in the line: %s\n", filename);
		return 1;
	}
	else if (result == -1) {
		printf("Error: Missing comma in the line: %s\n", filename);
		return 1;
	}
	return 0;
}

void displayLeastFareDetails(char filename[], struct FlightData* flights, int numFlights) {
	int minFare = flights[0].fare;
	int minIndex = 0;
	int i;

	for (i = 1; i < numFlights; i++) {
		if (strcmp(flights[i].source, flights[minIndex].source) == 0 &&
			strcmp(flights[i].destination, flights[minIndex].destination) == 0) {
			if (flights[i].fare < minFare) {
				minFare = flights[i].fare;
				minIndex = i;
			}
		}
	}

	printf("%s : %s to %s, $%d\n",filename , flights[minIndex].source, flights[minIndex].destination, flights[minIndex].fare);
}