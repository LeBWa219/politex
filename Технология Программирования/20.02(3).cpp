#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
  char eq[100]; 
  printf("Write: ");
  fgets(eq, sizeof(eq), stdin);
  eq[strcspn(eq, "\n")] = 0;
  for (int i = 0; eq[i]; i++) {
    eq[i] = tolower(eq[i]);
  }
  char *functions[] = {"sin", "cos", "tan", "tg", "ctg", "cot"};
  int num_functions = sizeof(functions) / sizeof(functions[0]);

  printf("Res: ");
  for (int i = 0; i < num_functions; i++) {
    if (strstr(eq, functions[i]) != NULL) {
      printf("%s\n", functions[i]);
    }
  }

  return 0;
}

