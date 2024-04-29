PROGRAM FOR CRICKET SCORE:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PATIENTS 100
struct Patient {
int id;
char name[50];
int age;
char gender;
char diagnosis[100];
int admitted;
};
struct Patient patients[MAX_PATIENTS];
int patient_count = 0;
void admitPatient() {
if (patient_count >= MAX_PATIENTS) {
printf("Hospital capacity reached. Cannot admit more patients.\n");
return;
}
printf("Enter patient name: ");
scanf("%s", patients[patient_count].name);
printf("Enter patient age: ");
scanf("%d", &patients[patient_count].age);
printf("Enter patient gender (M/F): ");
scanf(" %c", &patients[patient_count].gender);
printf("Enter diagnosis: ");
HOSPITAL MANAGEMENT SYSTEM
scanf("%s", patients[patient_count].diagnosis);
patients[patient_count].id = patient_count + 1;
patients[patient_count].admitted = 1; // Mark patient as admitted
patient_count++;
printf("Patient admitted successfully.\n");
}
void dischargePatient() {
int id;
printf("Enter patient ID to discharge: ");
scanf("%d", &id);
if (id >= 1 && id <= patient_count && patients[id - 1].admitted) {
patients[id - 1].admitted = 0; // Mark patient as discharged
printf("Patient %s discharged successfully.\n", patients[id - 1].name);
} else {
printf("Invalid patient ID or patient already discharged.\n");
}
}
void displayPatientInfo() {
int id;
printf("Enter patient ID: ");
scanf("%d", &id);
if (id >= 1 && id <= patient_count && patients[id - 1].admitted) {
printf("Patient ID: %d\n", patients[id - 1].id);
printf("Name: %s\n", patients[id - 1].name);
printf("Age: %d\n", patients[id - 1].age);
printf("Gender: %c\n", patients[id - 1].gender);
printf("Diagnosis: %s\n", patients[id - 1].diagnosis);
printf("Admission Status: Admitted\n");
} else {
printf("Patient not found or discharged.\n");
}
}
HOSPITAL MANAGEMENT SYSTEM
void displayAdmittedPatients() {
printf("Admitted Patients:\n");
for (int i = 0; i < patient_count; i++) {
if (patients[i].admitted) {
printf("ID: %d, Name: %s, Age: %d, Gender: %c, Diagnosis: %s\n",
patients[i].id, patients[i].name, patients[i].age,
patients[i].gender, patients[i].diagnosis);
}
}
}
int main() {
int choice;
do {
printf("\nHospital Management System\n");
printf("1. Admit Patient\n");
printf("2. Discharge Patient\n");
printf("3. Display Patient Information\n");
printf("4. Display Admitted Patients\n");
printf("5. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
admitPatient();
break;
case 2:
dischargePatient();
break;
case 3:
displayPatientInfo();
break;
case 4:
displayAdmittedPatients();
break;
case 5:
printf("Exiting...\n");
break;
default:
printf("Invalid choice. Please enter a number between 1 and 5.\n");
}
} while (choice != 5)
return 0;
}


