#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store student information
struct Student {
    int id;
    char name[50];
    float gpa;
};

// Global array to store student records
struct Student students[100];
int numStudents = 0;

// Function prototypes
void add_student();
void display_all_students();
void search_student_by_id();
void update_student_record();
void delete_student_record();
void save_to_file();
void load_from_file();

int main() {
    load_from_file();
    int choice;
    do {
        printf("\nStudent Management System Menu\n");
        printf("1. Add a new student record\n");
        printf("2. Display all student records\n");
        printf("3. Search for a student record by ID\n");
        printf("4. Update a student record\n");
        printf("5. Delete a student record\n");
        printf("6. Save student records to a file\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                display_all_students();
                break;
            case 3:
                search_student_by_id();
                break;
            case 4:
                update_student_record();
                break;
            case 5:
                delete_student_record();
                break;
            case 6:
                save_to_file();
                break;
            case 7:
                save_to_file(); // Save before exiting
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}

// Function to add a new student record
void add_student() {
    if (numStudents < 100) {
        printf("Enter student ID: ");
        scanf("%d", &students[numStudents].id);
        printf("Enter student name: ");
        scanf("%s", students[numStudents].name);
        printf("Enter student GPA: ");
        scanf("%f", &students[numStudents].gpa);
        numStudents++;
        printf("Student record added successfully.\n");
    } else {
        printf("Maximum number of students reached.\n");
    }
}

// Function to display all student records
void display_all_students() {
    if (numStudents == 0) {
        printf("No student records to display.\n");
    } else {
        printf("Student Records:\n");
        for (int i = 0; i < numStudents; i++) {
            printf("ID: %d, Name: %s, GPA: %.2f\n", students[i].id, students[i].name, students[i].gpa);
        }
    }
}

// Function to search for a student record by ID
void search_student_by_id() {
    int search_id;
    printf("Enter student ID to search: ");
    scanf("%d", &search_id);
    for (int i = 0; i < numStudents; i++) {
        if (students[i].id == search_id) {
            printf("Student found:\n");
            printf("ID: %d, Name: %s, GPA: %.2f\n", students[i].id, students[i].name, students[i].gpa);
            return;
        }
    }
    printf("Student with ID %d not found.\n", search_id);
}

// Function to update a student record
void update_student_record() {
    int update_id;
    printf("Enter student ID to update: ");
    scanf("%d", &update_id);
    for (int i = 0; i < numStudents; i++) {
        if (students[i].id == update_id) {
            printf("Enter new name: ");
            scanf("%s", students[i].name);
            printf("Enter new GPA: ");
            scanf("%f", &students[i].gpa);
            printf("Student record updated successfully.\n");
            return;
        }
    }
    printf("Student with ID %d not found.\n", update_id);
}

// Function to delete a student record
void delete_student_record() {
    int delete_id;
    printf("Enter student ID to delete: ");
    scanf("%d", &delete_id);
    for (int i = 0; i < numStudents; i++) {
        if (students[i].id == delete_id) {
            for (int j = i; j < numStudents - 1; j++) {
                students[j] = students[j + 1];
            }
            numStudents--;
            printf("Student record deleted successfully.\n");
            return;
        }
    }
    printf("Student with ID %d not found.\n", delete_id);
}

// Function to save student records to a file
void save_to_file() {
    FILE *file = fopen("student_records.txt", "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }
    for (int i = 0; i < numStudents; i++) {
        fprintf(file, "%d %s %.2f\n", students[i].id, students[i].name, students[i].gpa);
    }
    fclose(file);
    printf("Student records saved to file.\n");
}

// Function to load student records from a file
void load_from_file() {
    FILE *file = fopen("student_records.txt", "r");
    if (!file) {
        printf("No existing student records file found.\n");
        return;
    }
    numStudents = 0;
    while (fscanf(file, "%d %s %f", &students[numStudents].id, students[numStudents].name, &students[numStudents].gpa) != EOF) {
        numStudents++;
    }
    fclose(file);
    printf("Student records loaded from file.\n");
}
