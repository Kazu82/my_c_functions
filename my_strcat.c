#include <stdio.h>

char *my_strcat(char *dest, const char *src);

int main(void) {
  char src1[] = "abcd";
  char src2[] = " abcd";
  char first[20] = "abc";
  char dest[50] = "abcdefg";
  
  printf("src1 = %s\n",src1);
  printf("dest = %s\n",dest);
  my_strcat(dest, src1);
  printf("dest1 = %s\n",dest);
  printf("src2 = %s\n",src2);
  my_strcat(dest, src2);
  printf("dest2 = %s\n",dest);

  printf("\n");
  printf("result = %s\n", my_strcat(first, "def"));

  return 0;
}
  
char *my_strcat(char *dest, const char *src){
  int i = 0, j = 0;
  char *p;
  while( *(dest + i) != 0) {
    i++;
  }
  p = dest + i;
  while( *(src + j) != 0) {
    *(p + j) = *(src + j);
    j++;
  }
  *(p + j) = *(src + j);
  return dest;
}
