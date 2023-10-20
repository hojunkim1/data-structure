#include <stdio.h>

typedef struct
{
  unsigned int student_number;
  char *name;
  int grading[4];
} result_type;

void insert_student(result_type *arr[], int i);
void print_students(result_type *arr[]);

int main()
{
  result_type *std_array[4];

  for (int i = 0; i < 4; i++)
  {
    insert_student(std_array, i);
  }

  print_students(std_array);

  return 0;
}

result_type a[4] = {{1001, "name 1", 99, 88, 77, 66},
                    {1002, "name 2", 96, 86, 73, 65},
                    {1002, "name 3", 93, 83, 72, 63},
                    {1004, "name 4", 94, 84, 74, 64}};

void insert_student(result_type *arr[], int i) { arr[i] = &a[i]; }

void print_students(result_type *arr[])
{
  for (int i = 0; i < 4; i++)
  {
    printf("Student Number: %u\n", arr[i]->student_number);
    printf("Name: %s\n", arr[i]->name);
    printf("Grades: %d %d %d %d\n", arr[i]->grading[0], arr[i]->grading[1],
           arr[i]->grading[2], arr[i]->grading[3]);
    printf("\n");
  }
}
