#include <stdio.h>

int my_strlen(const char *s);

int main(void) {
  char src1[] = "abcdefghi";
  char src2[] = "aaabbbcccddd";
  char src3[] = "";

  printf("%s: ",src1);
  printf("%d\n",my_strlen(src1));
  printf("%s: ",src2);
  printf("%d\n",my_strlen(src2));
  printf("%s: ",src3);
  printf("%d\n",my_strlen(src3));
  return 0;
}

int my_strlen(const char *s) {
  int i = 0;
  int count = 0;
  while ( *(s + i) != 0) {
    count++;
    i++;
  }
  return count;
}
