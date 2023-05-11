#ifndef PATIENT_H_
#define PATIENT_H_

#include "utils.h"

#define MAX_AGE 150
#define MAX_PATIENTS 100
#define MAX_SOCIAL_WORKS 30

#define NAME_LENGTH 30
#define SOCIAL_WORK_LENGTH 30

typedef struct {
	char name[NAME_LENGTH];
	uint8_t age;
	char socialWork[SOCIAL_WORK_LENGTH];
} patient_st;

bool createPatient(patient_st *patient, char *socialWorks);

bool addPatient(patient_st *patients, uint16_t *amountPatients, patient_st patient);

bool getSocialWorks(char *socialWorks, char *socialWork);

int16_t filterPatient(patient_st patients[MAX_PATIENTS], uint16_t amountPatients, char **socialWorks, uint8_t amountSocialWorks, char *fileName);

void printPatients(patient_st patients[MAX_PATIENTS], uint16_t amountPatients);

#endif // PATIENT_H_