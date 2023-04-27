#include<stdio.h>

int pages[100][3];
int slot[100];
int Least[100];
int slotCount = 3;
int lastAcess = -1;
int fault = 0;
int nfault = 0;
int least = 0;
void first(int n) {
  for (int i = 0; i < n; i++) {
    int flag = 0;
    for (int j = 0; j < slotCount; j++) {
      if (j > lastAcess) {
        break;
      } else if (pages[i][0] == slot[j]) {

        flag = 1;
        break;
      }

    }

    if (flag == 0) {
      lastAcess++;
      slot[(lastAcess) % slotCount] = pages[i][0];
      fault++;

    }
    printf("\n [");
    for (int k = 0; k < slotCount; k++) {

      printf("%d", slot[k]);
      if (k < slotCount - 1) {
        printf("\t");

      }

    }
    printf("]");
    if (flag == 0) {
      printf("\tmiss");
    } else printf("\thit");

  }
}

void least(int n) {

  for (int i = 0; i < n; i++) {
    int flag = -1;
    for (int j = 0; j < slotCount; j++) {
      if (j > lastAcess) {
        break;
      } else if (pages[i][0] == Least[j]) {
        //pages[i][1] = i;
        flag = j;
        break;
      }

    }

    if (flag == 0) {
      lastAcess++;
      Least[(lastAcess) % slotCount] = pages[i][0];
      fault++;

    }

    if (flag == -1) {
      
      int leastValue=0;
      for (int k = 0; k < slotCount; k++) {
        if (pages[k][1] < leastValue) {
          leastValue = k;
          least = Least[k];
        }

      }

      Least[least] = pages[i][0];
      pages[i][1] = least;
      nfault++;

    }
    else {
    
    pages[i][1] = flag;}

    printf("\n [");
    for (int k = 0; k < slotCount; k++) {

      printf("%d", Least[k]);
      if (k < slotCount - 1) {
        printf("\t");

      }

    }
    printf("]");
    if (flag == 0) {
      printf("\tmiss");
    } else printf("\thit");

  }

}

void main() {
  int n;

  printf("enter the number of pages");
  scanf("%d", & n);
  printf("enter the slot number");
  scanf("%d", & slotCount);
  for (int k = 0; k < slotCount; k++) {

    slot[k] = 0;

  }

  for (int i = 0; i < n; i++) {
    scanf("%d", & pages[i][0]);
    pages[i][1] = -1;
  }
  printf("page replacement blocks");
  first(n);
  printf("\nPage fault is %d", fault);
  printf("page replacement blocks");
  least(n);
  printf("\nPage fault is %d", nfault);

}
