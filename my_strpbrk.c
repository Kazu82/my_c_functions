#include <stdio.h>

char *my_strpbrk(const char *s, const char *accept);

int main(void) {
  printf("%s : %s の場合\n","abcde","bcd");
  printf("%s\n", my_strpbrk("abcde", "bcd"));
  printf("%s : %s の場合\n","abdefg","ce");
  printf("%s\n", my_strpbrk("abdefg", "ce"));
  return 0;
}

char *my_strpbrk(const char *s, const char *accept) {
  int i = 0, j = 0;

  while(*(accept + j) != 0) {
    while(*(s + i) != 0) {
      if(*(s + i) == *(accept + j)) {
	return (char *)s + i;
	break;
      }
      i++;
    }
    i = 0;
    j++;
  }
  return NULL;
}
    
  
