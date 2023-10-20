#include <stdio.h>
#include <stdlib.h>

// Linked queue example in EasyDS-C
typedef int element;

typedef struct QNode
{
  element data;
  struct QNode *link;
} QNode;

typedef struct
{
  QNode *front, *rear;
} LQueueType;

LQueueType *createLinkedQueue(void);
int isLQEmpty(LQueueType *LQ);
void enLQueue(LQueueType *LQ, element item);
element deLQueue(LQueueType *LQ);
element peekLQ(LQueueType *LQ);
void printLQ(LQueueType *LQ);

// Solution
void problem_6_12();
void problem_6_2();

int main()
{
  problem_6_12();
  // problem_6_2(); cannot done :(
  return 0;
}

void problem_6_12()
{
  int N, K, select;
  LQueueType *human = createLinkedQueue();

  // Scan N, K
  scanf("%d %d", &N, &K);

  // Enqueue human
  for (int i = 0; i < N; i++)
    enLQueue(human, i + 1);

  int count = 0;
  while (!isLQEmpty(human))
  {
    count++;
    select = deLQueue(human);

    // Last human
    if (isLQEmpty(human))
    {
      printf("%d ", select);
      break;
    }

    // Count until K
    if (count == K)
    {
      printf("%d ", select);
      count = 0;
    }
    else
    {
      enLQueue(human, select);
    }
  }

  printf("\n");
}

void problem_6_2() {}

LQueueType *createLinkedQueue(void)
{
  LQueueType *LQ;
  LQ = (LQueueType *)malloc(sizeof(LQueueType));
  LQ->front = NULL;
  LQ->rear = NULL;
  return LQ;
}

int isLQEmpty(LQueueType *LQ)
{
  if (LQ->front == NULL)
    return 1;
  else
    return 0;
}

void enLQueue(LQueueType *LQ, element item)
{
  QNode *newNode = (QNode *)malloc(sizeof(QNode));
  newNode->data = item;
  newNode->link = NULL;
  if (LQ->front == NULL)
  {
    LQ->front = newNode;
    LQ->rear = newNode;
  }
  else
  {
    LQ->rear->link = newNode;
    LQ->rear = newNode;
  }
}

element deLQueue(LQueueType *LQ)
{
  QNode *old = LQ->front;
  element item;
  if (isLQEmpty(LQ))
    exit(0);
  else
  {
    item = old->data;
    LQ->front = LQ->front->link;
    if (LQ->front == NULL)
      LQ->rear = NULL;
    free(old);
    return item;
  }
}

element peekLQ(LQueueType *LQ)
{
  element item;
  if (isLQEmpty(LQ))
    exit(0);
  else
  {
    item = LQ->front->data;
    return item;
  }
}

void printLQ(LQueueType *LQ)
{
  QNode *temp = LQ->front;
  printf("Linked Queue : [ ");
  while (temp)
  {
    printf("%d ", temp->data);
    temp = temp->link;
  }
  printf("]\n");
}
