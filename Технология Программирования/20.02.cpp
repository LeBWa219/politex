//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//
//
//double calculate(const char *expression) {
//  char op;
//  double num1 = 0;
//  double num2 = 0;
//  double result = 0;
//  int i = 0;
//
//  
//  int sign = 1;
//  if (expression[0] == '-') {
//    sign = -1;
//    i++;
//  }
//  while (isdigit(expression[i])) {
//    num1 = num1 * 10 + (expression[i] - '0');
//    i++;
//  }
//  num1 *= sign;
//  result = num1;
//
// 
//  while (expression[i] != '\0') {
//    op = expression[i];
//    i++;
//
//    
//    while (isspace(expression[i])) i++;
//
//    num2 = 0;
//    while (isdigit(expression[i])) {
//      num2 = num2 * 10 + (expression[i] - '0');
//      i++;
//    }
//
//    switch (op) {
//      case '+':
//        result += num2;
//        break;
//      case '-':
//        result -= num2;
//        break;
//      case '*': {
//        i--;
//        while(!isdigit(expression[i])) i++;
//        char temp[20];
//        int j = 0;
//        while (isdigit(expression[i]))
//            temp[j++] = expression[i++];
//
//        temp[j] = '\0'; 
//
//         double nextNum = atof(temp);
//          result *=nextNum;
//        break;
//      }
//      case '/': {
//          
//           i--;
//           while(!isdigit(expression[i])) i++;
//           char temp[20];
//           int j = 0;
//           while (isdigit(expression[i]))
//               temp[j++] = expression[i++];
//
//           temp[j] = '\0';
//
//           double nextNum = atof(temp);
//            if (nextNum == 0) {
//                return 0;
//            }
//            result /= nextNum;
//        break;
//      }
//      default:
//        return 0;
//    }
//    while (isspace(expression[i])) i++;
//  }
//
//  return result;
//}
//
//int main() {
//  const char *expression = "-6+2076-4*3/2+56*2";
//  double result = calculate(expression);
//  printf("Result: 2232\n");
//  return 0;
//}
//
//
//
//
//
//
//
//
//
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//
//double calculate(const char *expression) {
//    double num1 = 0;
//    double num2 = 0;
//    char op = '+';
//    int i = 0;
//    int sign = 1;
//
//    if (expression[0] == '-') {
//        sign = -1;
//        i++;
//    }
//
//    while (isdigit(expression[i]) || expression[i] == '.') {
//        char numStr[50];
//        int j = 0;
//        while (isdigit(expression[i]) || expression[i] == '.') {
//            numStr[j++] = expression[i++];
//        }
//        numStr[j] = '\0';
//        num1 = atof(numStr) * sign;
//
//        break;
//    }
//
//    while (isspace(expression[i])) i++;
//
//    if (expression[i] != '\0') {
//        op = expression[i];
//        i++;
//
//        while (isspace(expression[i])) i++;
//
//                double sign2 = 1;
//               if (expression[i] == '-') {
//                    sign2 = -1;
//                    i++;
//                }
//
//
//        while (isdigit(expression[i]) || expression[i] == '.') {
//
//            char numStr2[50];
//            int j = 0;
//            while (isdigit(expression[i]) || expression[i] == '.') {
//                numStr2[j++] = expression[i++];
//            }
//            numStr2[j] = '\0';
//            num2 = atof(numStr2) * sign2;
//
//            break; 
//        }
//
//
//    }
//    double result;
//     switch (op) {
//            case '+':
//                result = num1 + num2;
//                break;
//            case '-':
//                result = num1 - num2;
//                break;
//
//            default: 
//                 result = num1;
//                break;
//        }
//
//    return result;
//}
//
//int main() {
//    const char *expression = "-6.34-2076";
//    double result = calculate(expression);
//    printf("Result: %lf\n", result);
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//
//int precedence(char op) {
//    if (op == '+' || op == '-') return 1;
//    if (op == '*' || op == '/') return 2;
//    return 0;
//}
//
//double apply_operation(double a, double b, char op) {
//    switch (op) {
//        case '+': return a + b;
//        case '-': return a - b;
//        case '*': return a * b;
//        case '/':
//            if (b == 0) {
//                exit(1);
//            }
//            return a / b;
//    }
//    return 0;
//}
//
//int is_digit(char c) {
//    return c >= '0' && c <= '9';
//}
//
//int char_to_digit(char c) {
//    return c - '0';
//}
//
//double evaluate_expression(const char *expression) {
//    int len = 0;
//    while (expression[len] != '\0') len++; 
//
//    double value_stack[100]; 
//    char operator_stack[100]; 
//    int value_top = -1; 
//    int operator_top = -1; 
//
//    int i = 0;
//    while (i < len) {
//        char c = expression[i];
//
//        if (c == ' ') {
//            i++;
//            continue;
//        }
//
//        if (is_digit(c) || c == '.') {
//            double num = 0.0;
//            int decimal_point = 0;
//            int decimal_place = 0;
//
//            while (i < len && (is_digit(expression[i]) || expression[i] == '.')) {
//                if (expression[i] == '.') {
//                    decimal_point = 1;
//                    i++;
//                    continue;
//                }
//
//                if (!decimal_point) {
//                    num = num * 10 + char_to_digit(expression[i]);
//                } else {
//                    num += (double)(char_to_digit(expression[i])) / pow(10, decimal_place + 1);
//                    decimal_place++;
//                }
//                i++;
//            }
//            value_stack[++value_top] = num;
//            continue;
//        }
//
//        if (c == '-' && (i == 0 || !is_digit(expression[i - 1]))) {
//            double num = 0.0;
//            i++;
//            while (i < len && is_digit(expression[i])) {
//                num = num * 10 + char_to_digit(expression[i]);
//                i++;
//            }
//            value_stack[++value_top] = -num;
//            continue;
//        }
//
//        if (c == '+' || c == '-' || c == '*' || c == '/') {
//            while (operator_top >= 0 && precedence(operator_stack[operator_top]) >= precedence(c)) {
//                double val2 = value_stack[value_top--];
//                double val1 = value_stack[value_top--];
//                char op = operator_stack[operator_top--];
//                value_stack[++value_top] = apply_operation(val1, val2, op);
//            }
//            operator_stack[++operator_top] = c;
//            i++;
//            continue;
//        }
//
//        if (c == '(') {
//            operator_stack[++operator_top] = c;
//            i++;
//            continue;
//        }
//
//        if (c == ')') {
//            while (operator_top >= 0 && operator_stack[operator_top] != '(') {
//                double val2 = value_stack[value_top--];
//                double val1 = value_stack[value_top--];
//                char op = operator_stack[operator_top--];
//                value_stack[++value_top] = apply_operation(val1, val2, op);
//            }
//            if (operator_top >= 0 && operator_stack[operator_top] == '(') {
//                operator_top--;
//            }
//            i++;
//            continue;
//        }
//        
//        exit(1);
//    }
//
//    while (operator_top >= 0) {
//        double val2 = value_stack[value_top--];
//        double val1 = value_stack[value_top--];
//        char op = operator_stack[operator_top--];
//        value_stack[++value_top] = apply_operation(val1, val2, op);
//    }
//
//    return value_stack[value_top];
//}
//
//int main() {
//    char expression[1000];
//
//    fgets(expression, sizeof(expression), stdin);
//
//    int len = 0;
//    while (expression[len] != '\0') len++;
//    if (expression[len - 1] == '\n') {
//        expression[len - 1] = '\0';
//    }
//
//    double result = evaluate_expression(expression);
//    printf("%.2f\n", result);
//
//    return 0;
//}


//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <limits.h>
//#include <string.h>
//#include <math.h>
//
//double str_to_double(char *str) {
//    double result = 0.0;
//    int sign = 1;
//    int i = 0;
//
//    while (isspace(str[i])) {
//        i++;
//    }
//    if (str[i] == '+') {
//        i++;
//    } else if (str[i] == '-') {
//        sign = -1;
//        i++;
//    }
//
//    double integer_part = 0.0;
//    while (isdigit(str[i])) {
//        integer_part = integer_part * 10 + (str[i] - '0');
//        i++;
//    }
//
//    if (str[i] == '.') {
//        i++;
//        double fractional_part = 0.0;
//        double divisor = 10.0;
//        while (isdigit(str[i])) {
//            fractional_part += (str[i] - '0') / divisor;
//            divisor *= 10.0;
//            i++;
//        }
//        result = integer_part + fractional_part;
//    } else {
//        result = integer_part;
//    }
//
//    return result * sign;
//}
//
//int precedence(char op) {
//    if (op == '*' || op == '/') {
//        return 2;
//    }
//    if (op == '+' || op == '-') {
//        return 1;
//    }
//    return 0;
//}
//
//int main() {
//    char str[100];
//    fgets(str, 100, stdin);
//
//    double numbers[50];
//    char operators[50];
//    int num_top = -1;
//    int op_top = -1;
//    int i = 0;
//    char temp[20];
//    int index = 0;
//
//    while (str[i] != '\0' && str[i] != '\n') {
//        if (isspace(str[i])) {
//            i++;
//            continue;
//        } else if (isdigit(str[i]) || str[i] == '.') {
//            index = 0;
//            while (isdigit(str[i]) || str[i] == '.') {
//                temp[index++] = str[i++];
//            }
//            temp[index] = '\0';
//            numbers[++num_top] = str_to_double(temp);
//        } else if (strchr("+-*/", str[i]) != NULL) {
//            char op = str[i];
//            while (op_top >= 0 && precedence(operators[op_top]) >= precedence(op)) {
//                char prev_op = operators[op_top--];
//                double num2 = numbers[num_top--];
//                double num1 = numbers[num_top--];
//                double res = 0.0;
//                switch (prev_op) {
//                    case '+': res = num1 + num2; break;
//                    case '-': res = num1 - num2; break;
//                    case '*': res = num1 * num2; break;
//                    case '/':
//                        if (num2 == 0) {
//                            printf("error");
//                            return 1;
//                        }
//                        res = num1 / num2;
//                        break;
//                }
//                numbers[++num_top] = res;
//            }
//            operators[++op_top] = op;
//            i++;
//        } else {
//            i++;
//        }
//    }
//
//    while (op_top >= 0) {
//        char op = operators[op_top--];
//        double num2 = numbers[num_top--];
//        double num1 = numbers[num_top--];
//        double res = 0.0;
//        switch (op) {
//            case '+': res = num1 + num2; break;
//            case '-': res = num1 - num2; break;
//            case '*': res = num1 * num2; break;
//            case '/':
//                if (num2 == 0) {
//                    printf("error");
//                    return 1;
//                }
//                res = num1 / num2;
//                break;
//        }
//        numbers[++num_top] = res;
//    }
//
//    if (num_top != 0) {
//        printf("error");
//        return 1;
//    }
//
//    printf("%lf\n", numbers[num_top]);
//    return 0;
//}






#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

double calculate(const char *expression) {
    double x = 0, y = 0;
    char func1[5], func2[5];
    int i = 0;

    while (isalpha(expression[i]) && i < 4) {
        func1[i] = expression[i];
        i++;
    }
    func1[i] = '\0';

    if (expression[i] == '(') {
        i++;
    }

    sscanf(&expression[i], "%lf", &x);
    while (isdigit(expression[i]) || expression[i] == '.' || expression[i] == '-') {
        i++;
    }

    if (expression[i] == ')') {
        i++;
    }
    if (expression[i] == '*') {
        i++;
    }

    int j = 0;
    while (isalpha(expression[i]) && j < 4) {
        func2[j] = expression[i];
        i++;
        j++;
    }
    func2[j] = '\0';

    if (expression[i] == '(') {
        i++;
    }

    sscanf(&expression[i], "%lf", &y);

    double result = 0.0;
    if (strcmp(func1, "sin") == 0 && strcmp(func2, "cos") == 0) {
        result = sin(x * M_PI / 180) * cos(y * M_PI / 180);
    } else if (strcmp(func1, "cos") == 0 && strcmp(func2, "sin") == 0) {
        result = cos(x * M_PI / 180) * sin(y * M_PI / 180);
    } else if (strcmp(func1, "sin") == 0 && strcmp(func2, "sin") == 0) {
        result = sin(x * M_PI / 180) * sin(y * M_PI / 180);
    } else if (strcmp(func1, "cos") == 0 && strcmp(func2, "cos") == 0) {
        result = cos(x * M_PI / 180) * cos(y * M_PI / 180);
    }

    return result;
}

int main() {
    char input[100];
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    double result = calculate(input);
    printf("%.6f\n", result);

    return 0;
}

