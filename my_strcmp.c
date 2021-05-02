#include <stdio.h>

int my_strcmp(const char *str1, const char *str2);
void printResult(int i);
int main(void) {
  char str1[] = "abcdef";
  char str2[] = "abcde";
  char str3[] = " ";
  char str4[] = "abc";
  char str5[] = "abc";
  printf("str1:%s\n",str1);
  printf("str2:%s\n",str2);
  printResult(my_strcmp(str1,str2));
  printf("str1:%s\n",str3);
  printf("str2:%s\n",str4);
  printResult(my_strcmp(str3,str4));
  printf("str1:%s\n",str4);
  printf("str2:%s\n",str5);
  printResult(my_strcmp(str4,str5));
  return 0;
}

int my_strcmp(const char *str1, const char *str2) {
  
  while(*(str1) == *(str2) && *(str1) != 0 && *(str2) != 0) {
    str1++;
    str2++;
  }

  return *str1 - *str2;
}

void printResult(int i) {
  if(i < 0)
    printf("辞書式で比較すると str1 は str2 より小さいです。\n");
  else if(i > 0)
    printf("辞書式で比較すると str1 は str2 より大きいです。\n");
  else
    printf("辞書式で比較すると srr1 は str2 と同じです。\n");
}

