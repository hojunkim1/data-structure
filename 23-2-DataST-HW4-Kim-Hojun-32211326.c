// Kim Hojun 32211326

#include <stdio.h>

void problem_3_1();
void problem_3_2();

int main() {
  printf("Problem 1\n");
  problem_3_1();

  printf("\nProblem 2\n");
  problem_3_2();

  return 0;
}

void problem_3_1() {
  int N;
  char swings[50];

  scanf("%d %s", &N, swings);

  int x = 1, y = 1, i = 0;
  while (swings[i] != '\0') {
    switch (swings[i]) {
    case 'L':
      if (x > 1)
        x--;
      break;
    case 'R':
      if (x < N)
        x++;
      break;
    case 'U':
      if (y > 1)
        y--;
      break;
    case 'D':
      if (y < N)
        y++;
      break;
    default:
      printf("Unexpectable value: %c", swings[i]);
      return;
    }
    i++;
  }

  printf("(%d, %d)\n", y, x);
}

void problem_3_2() {
  int N, M, i, j, v;

  // Get number of terms
  scanf("%d", &N);

  // Get terms
  char terms[N][50];
  for (i = 0; i < N; i++)
    scanf("%s", terms[i]);

  // Get number of document
  scanf("%d", &M);

  // Struct for tdm
  typedef struct {
    char *row;
    int col;
    int value;
  } term;

  // Get tdm
  term *min_tdm;
  int count = 0;
  for (i = 0; i < N; i++)
    for (j = 0; j < M; j++) {
      scanf("%d", &v);
      if (v != 0) {
        min_tdm[count].row = terms[i];
        min_tdm[count].col = j + 1;
        min_tdm[count].value = v;
        count++;
      }
    }

  // Result
  for (i = 0; i < count; i++)
    printf("%s 문서%d %d\n", min_tdm[i].row, min_tdm[i].col, min_tdm[i].value);
}
