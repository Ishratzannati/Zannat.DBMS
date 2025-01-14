#ifndef STUDENT_DB_H
#define STUDENT_DB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "bplus_tree.h"

#define MAX_STRING_SIZE 100


void display_all_students(StudentDB *db)
{
    if (db == NULL || db->db_file == NULL)
    {
        printf("Database is not initialized.\n");
        return;
    }

    
    FILE *file = fopen(db->db_file_path, "rb");
    if (file == NULL)
    {
        printf("Error: Could not open the database file.\n");
        return;
    }

    printf("All Students in the Database:\n");
    

    
    Student student;
    while (fread(&student, sizeof(Student), 1, file) == 1)
    {
        printf("Student ID: %d\n", student.student_id);
        printf("Name: %s\n", student.name);
        printf("Username: %s\n", student.username);
        printf("Email: %s\n", student.email);
        printf("Phone Number: %s\n", student.phone_number);
        printf("Semester: %s\n", student.semester);
        printf("CGPA: %.2f\n", student.CGPA);
        printf("Department: %s\n", student.department);
        printf("Date of Birth: %s\n", student.date_of_birth);
        printf("Date of Admission: %s\n", student.date_of_admission);
        printf("Blood Group: %s\n", student.blood_group);
        printf("Address: %s\n", student.address);
        printf("Advisor: %s\n", student.advisor);
        printf("Marital Status: %s\n", student.marital_status);
        printf("Credits Completed: %d\n", student.credits_completed);
        printf("Unique ID: %s\n", student.unique_id);
        
    }

    fclose(file); 
}
