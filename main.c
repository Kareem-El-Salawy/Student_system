#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxStudents 10

struct Student {
    char name[50];
    int id;
    char gender;
    int academicYear;
    float gpa;
};

struct Student students[maxStudents];
int studentCount = 0;

int isUniqueID(int id) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            return 0; // Not unique
        }
    }
    return 1; // Unique
}

int isValidAcademicYear(int year) {
    return (year >= 1 && year <= 5);
}

int isValidGPA(float gpa) {
    return (gpa >= 0.0 && gpa <= 4.0);
}

void addStudent() {
    if (studentCount >= maxStudents) {
        printf("Cannot add more students. Student limit reached.\n");
        return;
    }

    struct Student newStudent;// SHOULD check that both first and second name are entered
    printf("Enter student name (first and last name only): ");
    scanf("%s", newStudent.name);
    if (strchr(newStudent.name, ' ') == NULL) {
        printf("Error: Please enter both first and last name.\n");
        return;
       
    } 

    printf("Enter student ID (unique 7-digit number): ");// checks that 7 digit id is inputed
    scanf("%d", &newStudent.id);
    if (!isUniqueID(newStudent.id) || newStudent.id < 1000000 || newStudent.id > 9999999) {
        printf("Error: Invalid or non-unique ID.\n");
        return;
    }

    printf("Enter student gender (M/F): ");// gender input (case sensitive)
    scanf(" %c", &newStudent.gender);
    if (newStudent.gender != 'M' && newStudent.gender != 'F') {
        printf("Error: Invalid gender.\n");
        return;
    }

    printf("Enter student academic year (1-5): ");// check the entry of a valid academic year
    scanf("%d", &newStudent.academicYear);
    if (!isValidAcademicYear(newStudent.academicYear)) {
        printf("Error: Invalid academic year.\n");
        return;
    }

    printf("Enter student GPA (0.0-4.0): ");// checks entry of valid gpa
    scanf("%f", &newStudent.gpa);
    if (!isValidGPA(newStudent.gpa)) {
        printf("Error: Invalid GPA.\n");
        return;
    }

    students[studentCount++] = newStudent;
    printf("Student added successfully.\n");
}

void removeStudent() {//function to remove student
    int idToRemove;
    printf("Enter student ID to remove: ");
    scanf("%d", &idToRemove);

    int foundIndex = -1;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == idToRemove) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        for (int i = foundIndex; i < studentCount - 1; i++) {
            students[i] = students[i + 1];
        }
        studentCount--;
        printf("Operation Successful: Student with ID %d removed.\n", idToRemove);
    } else {
        printf("ID not found: No student with ID %d.\n", idToRemove);
    }
}

void retrieveStudentData() {// function to retrieve data
    int choice;
    printf("Retrieve student data by:\n");
    printf("1. Search by name\n");
    printf("2. Search by ID\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {//prompt user what identification to serach by
        case 1:
            printf("Search by name: ");
            char searchName[50];
            scanf("%s", searchName);
            for (int i = 0; i < studentCount; i++) {
                if (strcmp(students[i].name, searchName) == 0) {
                    printf("Operation Successful: Student found - Name: %s, ID: %d, Gender: %c, Academic Year: %d, GPA: %.2f\n",
                            students[i].name, students[i].id, students[i].gender, students[i].academicYear, students[i].gpa);
                    return;
                }
            }
            printf("Student not found.\n");
            break;
        case 2:
            printf("Search by ID: ");
            int searchID;
            scanf("%d", &searchID);
            for (int i = 0; i < studentCount; i++) {
                if (students[i].id == searchID) {
                    printf("Operation Successful: Student found - Name: %s, ID: %d, Gender: %c, Academic Year: %d, GPA: %.2f\n",
                            students[i].name, students[i].id, students[i].gender, students[i].academicYear, students[i].gpa);
                    return;
                }
            }
            printf("Student not found.\n");
            break;
        default:
            printf("Invalid choice.\n");
    }
}

void updateStudentData() {// function to update data
    int idToUpdate;
    printf("Enter student ID to update data: ");
    scanf("%d", &idToUpdate);

    int foundIndex = -1;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == idToUpdate) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {// prompts user what data to change
        int updateChoice;
        printf("Choose data to update:\n");
        printf("1. Update Academic Year\n");
        printf("2. Update GPA\n");
        printf("Enter your choice: ");
        scanf("%d", &updateChoice);

        switch (updateChoice) {
            case 1:
                printf("Enter new academic year: ");
                scanf("%d", &students[foundIndex].academicYear);
                printf("Operation Successful: Academic year updated.\n");
                break;
            case 2:
                printf("Enter new GPA: ");
                scanf("%f", &students[foundIndex].gpa);
                printf("Operation Successful: GPA updated.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } else {
        printf("Invalid ID: No student with ID %d.\n", idToUpdate);
    }
}

int main() {
    int choice;

    do {
        printf("\nStudent Management System Menu:\n");
        printf("1. Add Student\n");
        printf("2. Remove Student\n");
        printf("3. Retrieve Student's data\n");
        printf("4. Update Student's data\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
//main loop, cases for each input that call for differnt functions
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                removeStudent();
                break;
            case 3:
                retrieveStudentData();
                break;
            case 4:
                updateStudentData();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");}
    } while (choice != 5);

    return 0;
}

    

