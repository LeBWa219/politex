//#include <stdio.h>
//#include <stdlib.h>
//
//void vertical_histogram(int arr[], int size) {
//  if (size <= 0) {
//    printf("Массив пуст.\n");
//    return;
//  }
//
//  int max_value = arr[0];
//  for (int i = 1; i < size; i++) {
//    if (arr[i] > max_value) {
//      max_value = arr[i];
//    }
//  }
//
//  for (int i = max_value; i > 0; i--) {
//    for (int j = 0; j < size; j++) {
//      if (arr[j] >= i) {
//        printf("#"); 
//      } else {
//        printf("_"); 
//      }
//    }
//    printf("\n"); 
//  }
//}
//
//int main() {
//  int numbers[] = {2, 3, 1, 5, 4};
//  int size = sizeof(numbers) / sizeof(numbers[0]);
//
//  vertical_histogram(numbers, size);
//
//  return 0;
//}



//#include <stdio.h>
//#include <stdlib.h>
//#include <limits.h>
//
//void vertical_histogram(int arr[], int size) {
//  if (size <= 0) {
//    printf("Массив пуст.\n");
//    return;
//  }
//
//  int max_positive = INT_MIN;
//  int min_negative = INT_MAX;
//
//  for (int i = 0; i < size; i++) {
//    if (arr[i] > 0 && arr[i] > max_positive) {
//      max_positive = arr[i];
//    } else if (arr[i] < 0 && arr[i] < min_negative) {
//      min_negative = arr[i];
//    }
//  }
//
//  if (max_positive == INT_MIN) {
//    max_positive = 0;
//  }
//  if (min_negative == INT_MAX) {
//    min_negative = 0;
//  }
//
//  for (int i = max_positive; i >= min_negative; i--) {
//    for (int j = 0; j < size; j++) {
//      if (i == 0) { 
//        printf("-");
//      } else {
//        if (arr[j] >= 0) { 
//          if (arr[j] >= i && i > 0) {
//            printf("#");
//          } else {
//            printf("_");
//          }
//        } else { 
//          if (arr[j] <= i && i < 0) {
//            printf("#");
//          } else {
//            printf("_");
//          }
//        }
//      }
//    }
//    printf("\n");
//  }
//}
//
//int main() {
//  int numbers[] = {2, 3, 1, 5, -4, -3, -2};
//  int size = sizeof(numbers) / sizeof(numbers[0]);
//
//  vertical_histogram(numbers, size);
//
//  return 0;
//}


//#include <stdio.h>
//#include <stdlib.h>
//#include <limits.h>
//
//void vertical_histogram(int arr[], int size, int scale) {
//  if (size <= 0) {
//    return;
//  }
//
//  if (scale <= 0) {
//    return;
//  }
//
//  int max_positive_scaled = INT_MIN;
//  int min_negative_scaled = INT_MAX;
//
//  for (int i = 0; i < size; i++) {
//    int scaled_value = arr[i] / scale; 
//
//    if (arr[i] > 0 && scaled_value > max_positive_scaled) {
//      max_positive_scaled = scaled_value;
//    } else if (arr[i] < 0 && scaled_value < min_negative_scaled) {
//      min_negative_scaled = scaled_value;
//    }
//  }
//
//  if (max_positive_scaled == INT_MIN) {
//    max_positive_scaled = 0;
//  }
//  if (min_negative_scaled == INT_MAX) {
//    min_negative_scaled = 0;
//  }
//
//  for (int i = max_positive_scaled; i >= min_negative_scaled; i--) {
//    for (int j = 0; j < size; j++) {
//      int scaled_value = arr[j] / scale; 
//
//      if (i == 0) { 
//        printf("-");
//      } else {
//        if (arr[j] >= 0) { 
//          if (scaled_value >= i && i > 0) {
//            printf("#");
//          } else {
//            printf("_");
//          }
//        } else { 
//          if (scaled_value <= i && i < 0) {
//            printf("#");
//          } else {
//            printf("_");
//          }
//        }
//      }
//    }
//    printf("\n");
//  }
//}
//
//int main() {
//  int numbers[] = {102, 86, 66, -25, -80};
//  int size = sizeof(numbers) / sizeof(numbers[0]);
//  int scale;
//
//  printf("Mashtab: ");
//  scanf("%d", &scale);
//
//  vertical_histogram(numbers, size, scale);
//
//  return 0;
//}


//#include <stdio.h>
//#include <stdlib.h>
//
//#define WIDTH 30   
//#define HEIGHT 20  
//#define X_MIN -5.0  
//#define X_MAX 5.0   
//
//void draw_graph(float k, float b) {
//
//  float x_step = (X_MAX - X_MIN) / WIDTH;
//  char graph[HEIGHT][WIDTH + 1]; 
//  for (int i = 0; i < HEIGHT; i++) {
//    for (int j = 0; j < WIDTH; j++) {
//      graph[i][j] = ' ';
//    }
//    graph[i][WIDTH] = '\0'; 
//  }
//  int x_axis_row = HEIGHT / 2;  
//  int y_axis_col = -X_MIN / x_step; 
//  for (int i = 0; i < WIDTH; i++) {
//    graph[x_axis_row][i] = '-'; 
//  }
//  for (int i = 0; i < HEIGHT; i++) {
//    graph[i][y_axis_col] = '|';  
//  }
//  graph[x_axis_row][y_axis_col] = '+'; 
//
//  for (int x_col = 0; x_col < WIDTH; x_col++) {
//    float x = X_MIN + x_col * x_step;
//    float y = k * x + b;
//    int y_row = x_axis_row - (int)(y * (HEIGHT / (X_MAX - X_MIN)));
//
//    if (y_row >= 0 && y_row < HEIGHT) {
//      graph[y_row][x_col] = '*';
//    }
//  }
//  for (int i = 0; i < HEIGHT; i++) {
//    printf("%s\n", graph[i]);
//  }
//}
//int main() {
//  float k, b;
//
//  printf("Vvedite k: ");
//  scanf("%f", &k);
//
//  printf("Vvedite b: ");
//  scanf("%f", &b);
//
//  draw_graph(k, b);
//
//  return 0;
//}


//#include <stdio.h>
//
//#define X_MIN -5.0
//#define X_MAX 5.0
//
//float calculate_area(float k, float b) {
//  float y_min = k * X_MIN + b;
//  float y_max = k * X_MAX + b;
//  float height = X_MAX - X_MIN;
//
//  float area = (y_min + y_max) * height / 2.0;
//
//  return area;
//}
//
//int main() {
//  float k, b;
//
//  printf("Write k: ");
//  scanf("%f", &k);
//
//  printf("Write b: ");
//  scanf("%f", &b);
//
//  float area = calculate_area(k, b);
//
//  printf("Area is: %f\n", area);
//
//  return 0;
//}
//
//
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 30
#define HEIGHT 20
#define X_MIN -5.0
#define X_MAX 5.0
#define Y_MIN -20.0
#define Y_MAX 20.0

void draw_graph(float k1, float b1, float k2, float b2) {
    char graph[HEIGHT][WIDTH + 1];
    float x_step = (X_MAX - X_MIN) / WIDTH;
    float y_step = (Y_MAX - Y_MIN) / HEIGHT;
    int i, j;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            graph[i][j] = ' ';
        }
        graph[i][WIDTH] = '\0';
    }

    int xAxisRow = (int)round((Y_MAX - 0) / y_step);
    int yAxisCol = (int)round((0 - X_MIN) / x_step);

    if (xAxisRow >= 0 && xAxisRow < HEIGHT) {
        for (j = 0; j < WIDTH; j++) {
            graph[xAxisRow][j] = '-';
        }
    }

    if (yAxisCol >= 0 && yAxisCol < WIDTH) {
        for (i = 0; i < HEIGHT; i++) {
            graph[i][yAxisCol] = '|';
        }
    }

    if (xAxisRow >= 0 && xAxisRow < HEIGHT && yAxisCol >= 0 && yAxisCol < WIDTH) {
        graph[xAxisRow][yAxisCol] = '+';
    }
    
    for (j = 0; j < WIDTH; j++) {
        float x = X_MIN + j * x_step;
        float y1 = k1 * x + b1;
        int row = (int)round((Y_MAX - y1) / y_step);

        if (row >= 0 && row < HEIGHT) {
            graph[row][j] = '*'; 
        }
    }

    for (j = 0; j < WIDTH; j++) {
        float x = X_MIN + j * x_step;
        float y2 = k2 * x + b2;
        int row = (int)round((Y_MAX - y2) / y_step);

        if (row >= 0 && row < HEIGHT) {
            if(graph[row][j] == '*'){
                 graph[row][j] = 'X'; 
            } else {
               graph[row][j] = 'o'; 
            }
        }
    }
    for (i = 0; i < HEIGHT; i++) {
        printf("%s\n", graph[i]);
    }
}

int main() {
    float k1, b1, k2, b2;

    printf("Write k1: ");
    scanf("%f", &k1);

    printf("Write b1: ");
    scanf("%f", &b1);

    printf("Write k2: ");
    scanf("%f", &k2);

    printf("Write b2: ");
    scanf("%f", &b2);

    draw_graph(k1, b1, k2, b2);

    return 0;
}


