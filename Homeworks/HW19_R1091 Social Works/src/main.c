// Author: Daniel Fabrizio Di Módica
// Title: Patient's social works

// Relevant libraries are included below...
#include "patient.h"
#include "files.h"

uint8_t menuOption(void);

int main(int argc, char *argv[]) {
	patient_st patients[MAX_PATIENTS];
	char *socialWorks;
	uint16_t amountPatients = 0;
	if (argc > 1 && argc < MAX_SOCIAL_WORKS + 4) {
		size_t index;
		patient_st patient;
		while (1) {
			switch (menuOption()) {
			case 0:
				return EXIT_SUCCESS;
				break;
			case 1:
				socialWorks = (char *)(malloc(sizeof(char)));
				for (index = 2; index < argc; index++)
					if (getSocialWorks(socialWorks, argv[index])) return EXIT_FAILURE;
				if (createPatient(&patient, socialWorks)) {
					free(socialWorks);
					return EXIT_FAILURE;
				}
				free(socialWorks);
				if (addPatient(patients, &amountPatients, patient)) return EXIT_FAILURE;
				break;
			case 2:
				// printPatients(patients, amountPatients);
				break;
			case 3:
				
				break;
			default:
				break;
			}
		}
	} else {
		fprintf(stderr, "The program arguments entered are not correct!!\n");
		fprintf(stdout, "Usage: Open the \"README.md\" file and follow the instructions.\n\n");
		return EXIT_FAILURE;
	}
}

uint8_t menuOption(void) {
	uint8_t option;
	bool checkValidEntry;
    fprintf(stdout, "------------------------------------\n");
	fprintf(stdout, "Choose any of the following options.\n\n");
	fprintf(stdout, "0) Exit the program\n");
	fprintf(stdout, "1) Add a new patient\n");
	fprintf(stdout, "2) Print patient inventory\n");
	fprintf(stdout, "3) Filter patients by social work\n");
	while (!checkValidEntry) {
		fprintf(stdout, "\nInsert option: ");
		checkValidEntry = scanf("%hhu", &option);
		if (!checkValidEntry) {
			fprintf(stdout, "Invalid option\n");
			while (getchar() != '\n');
		} else if (option > 3) {
			checkValidEntry = false;
			fprintf(stdout, "Invalid option\n");
		}
	}
	return option;
}