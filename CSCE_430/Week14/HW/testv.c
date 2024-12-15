#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STUDENTS 100
#define BUFFER_SIZE 256

typedef enum ENUM_STRUCT
{
    UNDECLARED,
    ELECTRICAL_ENGINEERING,
    COMPUTER_SCIENCE,
    PHYSICS,
    BIOLOGY,
    MECHANICAL_ENGINEERING,
    ARCHITECHTURE,
    POLITICAl_SCIENCE,
    BUSINESS,
    JOURNALISM,
    CULINARY_ARTS,
    PALEONTOLOGY,
    MAJOR_COUNT
} Major;

const char *major_strings[50] = {
    "Undeclared",
    "Electrical Engineering",
    "Computer Science",
    "Physics",
    "Biology",
    "Mechanical Engineering",
    "Architechture",
    "Political Science",
    "Business",
    "Journalism",
    "Culinary Arts",
    "Paleontology"
};

typedef struct STRUCT_CATEGORIES
{
    char name[200];
    unsigned long uin;
    char year[200];
    Major major;
} Student;

Major getMajorFromString(const char *str)
{
    for (int i = 0; i < 12; i++)
    {
        if (strcasecmp(str, major_strings[i]) == 0)
        {
            return (Major)i;
        }
    }
    return UNDECLARED;
}

void printStudentInfo(Student student)
{
    printf("Name: %s, UIN: %lu, Year: %s, Major: %s\n", student.name, student.uin, student.year, major_strings[student.major]);
}

int compare_students(const void *a, const void *b)
{
    const char *lastNameA = strrchr(((Student *)a)->name, ' ') + 1;
    const char *lastNameB = strrchr(((Student *)b)->name, ' ') + 1;
    return strcmp(lastNameA, lastNameB);
}

void sort_student_by_lastname(Student *students, int count)
{
    qsort(students, count, sizeof(Student), compare_students);
}

int main()
{
    Student student_array[MAX_STUDENTS];
    int student_count = 0;
    char buffer[BUFFER_SIZE];

    FILE *file = fopen("roster.txt", "r");

    if (!file)
    {
        perror("Oops");
        return 1;
    }

    fgets(buffer, BUFFER_SIZE, file);

    while (fgets(buffer, BUFFER_SIZE, file))
    {

        char major_buffer[BUFFER_SIZE];
       
        sscanf(buffer, "%[^\t]\t%lu\t%[^\t]\t%[^\n]",
               student_array[student_count].name,
               &student_array[student_count].uin,
               student_array[student_count].year,
               major_buffer);
        student_array[student_count].major = getMajorFromString((char *)major_buffer);
        student_count++;
         
    }

    sort_student_by_lastname(student_array, student_count);

    // char user_major[100] = "";
    printf("Enter a major:\n");
    // sscanf("%c", & user_major);

    if (fgets(buffer, BUFFER_SIZE, stdin) != NULL)
    {
        buffer[strcspn(buffer, "\n")] = 0;

        if (islower((unsigned char)buffer[0]))
        {
            buffer[0] = toupper((unsigned char)buffer[0]);
        }

        Major user_major = getMajorFromString(buffer);

        for (int i = 0; i < student_count; i++)
        {
            if (student_array[i].major == user_major)
            {
                printStudentInfo(student_array[i]);
            }
        }
    }

    fclose(file);
    return 0;
}