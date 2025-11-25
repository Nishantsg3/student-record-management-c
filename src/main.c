#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char stdname[50];
    float marks;
};

void addStudent() {
    FILE *fp = fopen("student.dat", "ab");
    if (!fp) { printf("Error opening file!\n"); return; }

    struct Student s;

    printf("\nEnter Roll No: ");
    scanf("%d", &s.rollno);

    printf("Enter Name: ");
    scanf("%s", s.stdname);

    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(s), 1, fp);

    fclose(fp);
    printf("\nStudent added successfully!\n");
}

void displayStudents() {
    FILE *fp = fopen("student.dat", "rb");
    if (!fp) {
        printf("\nNo records found!\n");
        return;
    }

    struct Student s;

    printf("\n=== Student Records ===\n");

    while (fread(&s, sizeof(s), 1, fp)) {
        printf("Roll: %d | Name: %s | Marks: %.2f\n",
               s.rollno, s.stdname, s.marks);
    }

    fclose(fp);
}

void searchStudent() {
    FILE *fp = fopen("student.dat", "rb");
    if (!fp) { printf("No records found!\n"); return; }

    int roll;
    struct Student s;
    int found = 0;

    printf("Enter Roll No to search: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.rollno == roll) {
            printf("\nRecord Found!\n");
            printf("Roll: %d | Name: %s | Marks: %.2f\n",
                   s.rollno, s.stdname, s.marks);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nRecord not found!\n");

    fclose(fp);
}

void updateStudent() {
    FILE *fp = fopen("student.dat", "rb+");
    if (!fp) { printf("No records found!\n"); return; }

    int roll;
    struct Student s;
    int found = 0;

    printf("Enter Roll No to update: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.rollno == roll) {
            printf("\nEnter new name: ");
            scanf("%s", s.stdname);

            printf("Enter new marks: ");
            scanf("%f", &s.marks);

            fseek(fp, -sizeof(s), SEEK_CUR);
            fwrite(&s, sizeof(s), 1, fp);

            printf("\nRecord updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nRecord not found!\n");

    fclose(fp);
}

void deleteStudent() {
    FILE *fp = fopen("student.dat", "rb");
    if (!fp) { printf("No records found!\n"); return; }

    FILE *temp = fopen("temp.dat", "wb");
    struct Student s;
    int roll, found = 0;

    printf("Enter Roll No to delete: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.rollno == roll) {
            found = 1;
            continue;
        }
        fwrite(&s, sizeof(s), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove("student.dat");
    rename("temp.dat", "student.dat");

    if (found)
        printf("\nRecord deleted successfully!\n");
    else
        printf("\nRecord not found!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n===== Student Record Management =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: exit(0);
            default: printf("\nInvalid choice!\n");
        }
    }

    return 0;
}
