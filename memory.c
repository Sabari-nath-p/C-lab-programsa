#include<stdio.h>


int pro[100];

int block[100][4];

int pcount = 0;
int bcount = 0;

void firstFit() {

  for (int i = 0; i < pcount; i++) {
    int flag = 0;
    for (int j = 0; j < bcount; j++) {
      if (block[j][0] - block[j][1] >= pro[i]) {

        flag = 1;
        block[j][1] = block[j][1] + pro[i];
        printf("P[%d] allocated in block[%d] \n\n", i, j);
        break;

      }

    }
    if (flag == 0) printf("P[%d] is not allocated \n\n", i);
  }

}

void bestFit() {

  for (int i = 0; i < pcount; i++) {

    int flag = 0;
    int min = 0;

    for (int j = 0; j < bcount; j++) {

      if (block[j][0] - block[j][2] >= pro[i]) {
        if (block[j][0] - block[j][2] < block[min][0] - block[min][2]) {
          flag = 1;

          min = j;

        }

        if (flag == 0) {
          flag = 1;

          min = j;
        }

      }

    }

    if (flag == 1) {
      block[min][2] = block[min][2] + pro[i];
      printf("P[%d] allocated in block[%d] \n\n", i, min);
    } else {

      printf("P[%d] is not allocated \n\n", i);
    }

  }

}

void worstFit() {

  for (int i = 0; i < pcount; i++) {

    int flag = 0;
    int min = 0;

    for (int j = 0; j < bcount; j++) {

      if (block[j][0] - block[j][3] >= pro[i]) {
        if (block[j][0] - block[j][3] > block[min][0] - block[min][3]) {
          flag = 1;

          min = j;

        }

        if (flag == 0) {
          flag = 1;

          min = j;
        }

      }

    }

    if (flag == 1) {
      block[min][3] = block[min][3] + pro[i];
      printf("P[%d] allocated in block[%d] \n\n", i, min);
    } else {

      printf("P[%d] is not allocated \n\n", i);
    }

  }

}

void main() {

  printf("enter the number of block ");
  scanf("%d", & bcount);
  printf("enter the number of process ");
  scanf("%d", & pcount);

  printf("enter block size");
  for (int i = 0; i < bcount; i++) {
    int temp = 0;
    printf("Enter Block[%d] : ", i);
    scanf("%d", & temp);
    block[i][0] = temp;
    block[i][1] = 0;
    block[i][2] = 0;
    block[i][3] = 0;

  }

  printf("enter process size");
  for (int i = 0; i < pcount; i++) {
    int temp = 0;
    printf("Enter process[%d] : ", i);
    scanf("%d", & temp);
    pro[i] = temp;

  }

  firstFit();
  printf("Memory Allocation Using BestFit \n");
  bestFit();
  printf("Memory Allocation Using WorstFit \n");
  worstFit();

}
