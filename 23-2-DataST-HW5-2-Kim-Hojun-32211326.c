#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element;

typedef struct stackNode {
  element data;
  struct stackNode *link;
} stackNode;

stackNode *top = NULL;

int isStackEmpty(void);
void push(element item);
element pop(void);
element peek(void);
void printStack(void);

void fromInorderToPostorder(stackNode *myStack);
int checkPriority(char c);

const char *inorder = "A / (B + C) * D";

int main(void) {
  fromInorderToPostorder(top);
  return 0;
}

void fromInorderToPostorder(stackNode *myStack) {

  for (int i = 0; i < strlen(inorder); i++) {
    char token = inorder[i];

    // Whitespace: ignore
    if (token == ' ') {
      continue;
    }

    // Operand: just print
    else if (isalpha(token)) {
      printf("%c ", token);
    }

    // Left bracket: push stack for flag
    else if (token == '(') {
      push(token);
    }

    // Right bracket: pop and print until pop left bracket
    else if (token == ')') {
      while (!isStackEmpty() && peek() != '(') {
        printf("%c ", pop());
      }
      pop(); // erase left bracket
    }

    // Operator: print high priority, stack low priority
    else if ((token == '+' || token == '-' || token == '*' || token == '/')) {
      while (!isStackEmpty() && peek() != '(') {
        if (checkPriority(peek()) >= checkPriority(token))
          printf("%c ", pop());
      }
      push(token); // wait next process
    }
  }

  // Rest operators: print left operators
  while (!isStackEmpty()) {
    printf("%c ", pop());
  }

  // End of world
  printf("\n");
}

int checkPriority(char c) {
  if (c == '+' || c == '-')
    return 1;
  else if (c == '*' || c == '/')
    return 2;
  return 0;
}

int isStackEmpty(void) {
  if (top == NULL)
    return 1;
  else
    return 0;
}

void push(element item) {
  stackNode *temp = (stackNode *)malloc(sizeof(stackNode));
  temp->data = item;
  temp->link = top;
  top = temp;
}

element pop(void) {
  element item;
  stackNode *temp = top;

  if (isStackEmpty()) {
    printf("\n\n Stack is empty!\n");
    return 0;
  } else {
    item = temp->data;
    top = temp->link;
    free(temp);
    return item;
  }
}

element peek(void) {
  if (isStackEmpty()) {
    printf("\n\n Stack is empty!\n");
    return 0;
  } else {
    return (top->data);
  }
}

void printStack(void) {
  stackNode *p = top;
  printf("STACK [");
  while (p) {
    printf("%c ", p->data);
    p = p->link;
  }
  printf("]\n");
}
