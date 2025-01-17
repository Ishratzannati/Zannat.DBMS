#ifndef STUDENT_DB_H
#define STUDENT_DB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "student_db.h"
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

    printf("\nAll Students in the Database:\n");
    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("| %-10s | %-20s | %-15s | %-10s | %-10s |\n", "Student ID", "Name", "Username", "CGPA", "Department");
    printf("--------------------------------------------------------------------------------------------------------\n");

    Student student;

    while (fread(&student, sizeof(Student), 1, file) == 1)
    {
        printf("| %-10d | %-20s | %-15s | %-10.2f | %-10s |\n",
               student.student_id, student.name, student.username, student.CGPA, student.department);
    }

    printf("--------------------------------------------------------------------------------------------------------\n");

    fclose(file); 
}
