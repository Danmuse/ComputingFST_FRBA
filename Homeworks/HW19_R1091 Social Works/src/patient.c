#include "patient.h"

static bool checkAlloc(char *pointer);

static char *insertString(char *buffer, size_t size);

static bool checkName(char *name);

static void chooseSocialWork(char *socialWork, char *socialWorks);

static uint8_t patientAge(void);

static bool checkAlloc(char *pointer) {
    if (!pointer) {
        fprintf(stderr, "Critical program error!!\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

static char *insertString(char *buffer, size_t size) { 
	if (buffer[strlen(buffer - 1)] != '\n') while (getchar() != '\n'); 
	fgets(buffer, size, stdin);
	size = strlen(buffer);
	buffer[size - 1] = '\0';
	return buffer;
}

static bool checkName(char *name) {
    size_t index;
    for (index = 0; index != strlen(name); index++) {
        if (!((name[index] >= 'A' && name[index] <= 'Z') || (name[index] >= 'a' && name[index] <= 'z'))) {
            fprintf(stderr, "The patient's name entered is invalid!!\n\n");
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

static void chooseSocialWork(char *socialWork, char *socialWorks) {
    uint8_t option, amountSocialWorks = 1;
	bool checkValidEntry;
    char *socialWorksCopied;
    socialWorksCopied = (char *)(malloc((strlen(socialWorks) + 1) * sizeof(char)));
    strcpy(socialWorksCopied, socialWorks);
    char *token = strtok(socialWorks, " ");
    fprintf(stdout, "\nChoose any of the following social works.\n\n");
	fprintf(stdout, "1) %s\n", token);
    while (token != NULL) {
        token = strtok(NULL, " ");
        if (!token) break;
        amountSocialWorks++;
		fprintf(stdout, "%hhu) %s\n", amountSocialWorks, token);
	}
	while (!checkValidEntry) {
		fprintf(stdout, "\nInsert option: ");
		checkValidEntry = scanf("%hhu", &option);
		if (!checkValidEntry) {
			fprintf(stdout, "Invalid option\n");
			while (getchar() != '\n');
		} else if (option == 0 || option > amountSocialWorks) {
			checkValidEntry = false;
			fprintf(stdout, "Invalid option\n");
		}
	}
    if (option == 1) strcpy(socialWork, socialWorks);
    else {
        amountSocialWorks = 1;
        token = strtok(socialWorksCopied, " ");
        while (token != NULL) {
            token = strtok(NULL, " ");
            amountSocialWorks++;
		    if (amountSocialWorks == option) strcpy(socialWork, token);
	    }
    }
	fprintf(stdout, "Social Work: %s\n", socialWork);
}

static uint8_t patientAge(void) {
	uint8_t age;
	bool checkValidEntry;
	while (!checkValidEntry) {
		fprintf(stdout, "Insert patient's age: ");
		checkValidEntry = scanf("%hhu", &age);
		if (!checkValidEntry) {
			fprintf(stdout, "Invalid patient's age\n");
			while (getchar() != '\n');
		} else if (age > MAX_AGE) {
			checkValidEntry = false;
			fprintf(stdout, "Invalid patient's age\n");
		}
	}
	return age;
}

bool createPatient(patient_st *patient, char *socialWorks) {
    if (!patient) {
        fprintf(stderr, "Critical program error!!\n");
        return EXIT_FAILURE;
    }
    fprintf(stdout, "\n------------------------------------");
    fprintf(stdout, "\nInsert patient's name: ");
    if (checkName(insertString(patient->name, NAME_LENGTH))) return EXIT_FAILURE;
    patient->age = patientAge();
    chooseSocialWork(patient->socialWork, socialWorks);
    return EXIT_SUCCESS;
}

bool getSocialWorks(char *socialWorks, char *socialWork) {
    uint32_t socialWorksLength = strlen(socialWorks);
    socialWorksLength += strlen(socialWork);
    if (socialWorksLength == strlen(socialWork)) socialWorks = (char *)(realloc(socialWorks, (socialWorksLength + 1) * sizeof(char)));
    else socialWorks = (char *)(realloc(socialWorks, (socialWorksLength + 2) * sizeof(char)));
    if (checkAlloc(socialWorks)) return EXIT_FAILURE;
    if (socialWorksLength == strlen(socialWork)) strcat(socialWorks, socialWork);
    else {
        strcat(socialWorks, " ");
        strcat(socialWorks, socialWork);
    }
    return EXIT_SUCCESS;
}

bool addPatient(patient_st patients[MAX_PATIENTS], uint16_t *amountPatients, patient_st patient) {
    FILE *fileSystem;
    patients[*amountPatients] = patient;
    *amountPatients++;
    fileSystem = fopen("./inventory.csv", "ab");
    if (!fileSystem) {
        fprintf(stderr, "Critical program error!!\n");
        return EXIT_FAILURE;
    }

    // It will continue...

    fclose(fileSystem);
    return EXIT_SUCCESS;
}

void printPatients(patient_st patients[MAX_PATIENTS], uint16_t amountPatients) {
    fprintf(stdout, "\n------------------------------------");
    while (amountPatients > 0) {
	    fprintf(stdout, "\nAffiliate #%hu\n", amountPatients);
	    fprintf(stdout, "Patient's name: %s\n", patients[amountPatients].name);
	    fprintf(stdout, "Patient's age: %hhu\n", patients[amountPatients].age);
	    fprintf(stdout, "Patient's social work: %s\n", patients[amountPatients].socialWork);
        amountPatients--;
    }
}