#include <stdio.h>

char *my_strcpy(char *dest, const char *src);

int main(void) {
  char src1[] = "abcd";
  char src2[] = "abcdefg abcdefg abcdefg";
  char dest[1000] = "aaaaaaaa";
  char buffer[1024];
  
  printf("src1 = %s\n",src1);
  printf("dest = %s\n",dest);
  my_strcpy(dest, src1);
  printf("dest1 = %s\n",dest);
  printf("src2 = %s\n",src2);
  printf("dest = %s\n",dest);
  my_strcpy(dest, src2);
  printf("dest2 = %s\n",dest);
  printf("返り値のテスト\n");
  printf("result = [%s]\n", my_strcpy(buffer, "hello world"));

  return 0;
}


char *my_strcpy(char *dest, const char *src) {
  int i = 0;
  while(*(src + i) != 0) {
    *(dest + i) = *(src + i);
    i++;
  }
  *(dest + i) = *(src + i);
  return dest;
}
