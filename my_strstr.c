#include <stdio.h>
#include <string.h>

void *my_strstr(const char *s1, const char *s2);
void test_my_strstr(const char *s1, const char *s2);

int main(void) {
  test_my_strstr("abcdddef", "dde");
  test_my_strstr("abcabc", "abc");
  test_my_strstr("abc", "");
  test_my_strstr("", "");
  test_my_strstr("age:20, name:tom", "name:");
  test_my_strstr("This is a pen", "never");
  return 0;
}

void test_my_strstr(const char *s1, const char *s2) {
  char *p;

  p = strstr1(s1,s2);
  if(p == NULL)
    printf("[%s], [%s] -> [NULL]\n",s1,s2);
  else
    printf("[%s], [%s] -> [%s]\n",s1,s2,p);
}

void *my_strstr(const char *s1, const char *s2) {
  int i = 0, j = 0;
  
  if(*(s2 + i) == 0)
    return (char *)s1;
  
  while(*(s1 + i) != 0) {
    if(*(s1 + i) == *s2) {
      while(*(s1 + i + j) == *(s2 + j)) {
	j++;
	if(*(s2 + j) == 0)
	  return (char *)(s1 + i);
      }
    }
    j = 0;
    i++;
  }
  return NULL;
}


      
  
  
