#include <math.h>
#include <stdio.h>
#include <string.h>
#define MAX 30

int problem_12_1();
int problem_12_2();

int main()
{
    printf("problem 12-09\n");
    problem_12_1();

    printf("problem 12-09\n");
    problem_12_2();

    return 0;
}

// Rescue Cat
int problem_12_1()
{
    int i, size, N, K, M[2047] = {-1};

    // Input N, K
    scanf("%d %d", &N, &K);

    // Input tree info
    for (i = 1; i <= pow(2, N + 1) - 1; i++)
        scanf("%d", &M[i]);

    // If the barnch is the end point, cat should be there!
    for (i = pow(2, K); i <= pow(2, K + 1) - 1; i++)
        if ((M[i * 2] == 0) && (M[i * 2 + 1] == 0))
            printf("%d ", i);

    printf("\n\n");

    return 0;
}

// Decision Animal
int problem_12_2()
{
    return 0;
}

// Array base
int problem_12_3()
{
}

// Linked list base
int problem_12_4()
{
}
