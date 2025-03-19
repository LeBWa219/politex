//#include <stdio.h>
//#include <math.h>
//#include <string.h>
//#include <ctype.h>
//
//double calculate(const char *expression) {
//    double x = 0, y = 0;
//    char func1[5], func2[5];
//    int i = 0;
//
//    while (isalpha(expression[i]) && i < 4) {
//        func1[i] = expression[i];
//        i++;
//    }
//    func1[i] = '\0';
//
//    if (expression[i] == '(') {
//        i++;
//    }
//
//    sscanf(&expression[i], "%lf", &x);
//    while (isdigit(expression[i]) || expression[i] == '.' || expression[i] == '-') {
//        i++;
//    }
//
//    if (expression[i] == ')') {
//        i++;
//    }
//    if (expression[i] == '*') {
//        i++;
//    }
//
//    int j = 0;
//    while (isalpha(expression[i]) && j < 4) {
//        func2[j] = expression[i];
//        i++;
//        j++;
//    }
//    func2[j] = '\0';
//
//    if (expression[i] == '(') {
//        i++;
//    }
//
//    sscanf(&expression[i], "%lf", &y);
//
//    double result = 0.0;
//    if (strcmp(func1, "sin") == 0 && strcmp(func2, "cos") == 0) {
//        result = sin(x * M_PI / 180) * cos(y * M_PI / 180);
//    } else if (strcmp(func1, "cos") == 0 && strcmp(func2, "sin") == 0) {
//        result = cos(x * M_PI / 180) * sin(y * M_PI / 180);
//    } else if (strcmp(func1, "sin") == 0 && strcmp(func2, "sin") == 0) {
//        result = sin(x * M_PI / 180) * sin(y * M_PI / 180);
//    } else if (strcmp(func1, "cos") == 0 && strcmp(func2, "cos") == 0) {
//        result = cos(x * M_PI / 180) * cos(y * M_PI / 180);
//    }
//
//    return result;
//}
//
//int main() {
//    char input[100];
//    fgets(input, sizeof(input), stdin);
//
//    input[strcspn(input, "\n")] = '\0';
//
//    double result = calculate(input);
//    printf("%.6f\n", result);
//
//    return 0;
//}



//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <math.h>
//#include <ctype.h>
//
//int main() {
//    char expression[256];
//    printf("write: ");
//    fgets(expression, sizeof(expression), stdin);
//    expression[strcspn(expression, "\n")] = 0;
//    if (strstr(expression, "sqrt") != NULL || strstr(expression, "exp") != NULL) {
//        char *token = strtok(expression, " +-*/()sqrtexp");
//        while (token != NULL) {
//            char *endptr;
//            double num = strtod(token, &endptr);
//            if (*endptr == '\0' && isdigit(token[0])) {
//                double squared = pow(num, 2.0);
//                printf("„исло: %lf,  вадрат: %lf\n", num, squared);
//            }
//
//            token = strtok(NULL, " +-*/()sqrtexp");
//        }
//    } else {
//        printf("No 'sqrt' or 'exp'.\n");
//    }
//
//    return 0;
//}

