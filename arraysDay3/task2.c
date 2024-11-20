#include <stdio.h>
#define STUDENTS 3
#define COURSES 2

int main() {
    int grades[STUDENTS][COURSES];
    int total, courseSum;
    float average;

    // Input grades for each student
    for (int i = 0; i < STUDENTS; i++) {
        printf("Enter grades for student %d:\n", i + 1);
        for (int j = 0; j < COURSES; j++) {
            printf("Course %d: ", j + 1);
            scanf("%d", &grades[i][j]);
        }
    }

    // Calculate and print total and grade for each student
    printf("\nTotal and Grade for each student:\n");
    for (int i = 0; i < STUDENTS; i++) {
        total = 0;
        for (int j = 0; j < COURSES; j++) {
            total += grades[i][j];
        }

        // Calculate the average for the student
        average = (float) total / COURSES;

        // Determine grade
        char grade;
        if (average >= 85) grade = 'A';
        else if (average >= 75) grade = 'B';
        else if (average >= 65) grade = 'C';
        else if (average >= 60) grade = 'D';
        else grade = 'F';

        printf("Student %d -> Total = %d, Grade = %c\n", i + 1, total, grade);
    }

    // Calculate and print average grade for each course
    printf("\n Average grade for each course:\n");
    for (int j = 0; j < COURSES; j++) {
        courseSum = 0;
        for (int i = 0; i < STUDENTS; i++) {
            courseSum += grades[i][j];
        }
        printf("Course %d Average = %.2f\n", j + 1, (float)courseSum / STUDENTS);
    }

    return 0;
}
