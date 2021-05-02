#include <stdio.h>

int my_atoi(const char *str);

int main(void) {

  char str1[] = "135";
  char str2[] = "-100";
  char str3[] = "123456";
  char str4[] = "-12345";
  int a, b;

  a = my_atoi(str1);
  b = my_atoi(str2);
  printf("a: %d\n",a);
  printf("b: %d\n",b);
  printf("(%d) + (%d) = %d \n",a ,b, a + b);
  a = my_atoi(str3);
  b = my_atoi(str4);
  printf("a: %d\n",a);
  printf("b: %d\n",b);
  printf("(%d) + (%d) = %d \n",a ,b, a + b);
  return 0;
}

int my_atoi(const char *str) {
  int i = 0, sign = 1, resultInt = 0;

  if(*str == '-') {
    sign = -1;
    i++;
  }

  while( *(str + i) != 0) {
    resultInt *= 10;
 
    resultInt += (int)*(str + i) - '0';
    i++;
  }

  return resultInt * sign;
}
    
    
    
