//#include <stdio.h>
////
//int main(){
//	int arr[] = {-4,5,-8,3,2,-1,-9,4,7};
//	int arr1[20];
//	int size = sizeof(arr) / sizeof(arr[0]);
//	int index = 0;
//	int temp;
//	for (int i = 0; i < size; i++){
//		if(arr[i] > 0){
//			arr1[index] = arr[i];
//			index++;
//			arr1[index] = i;
//			index++;
//		}
//	}
//	for(int i=0; i<size; i++){
//		if(arr[i]<=0){
//			arr1[index] = arr[i];
//			index++;
//			arr1[index] = i-size;
//			index++;	
//		}
//	}
//	int size2= sizeof(arr1)/sizeof(arr1[0]);
//	for (int i=0; i < size2; i++){
//		printf("%i ", arr1[i]);
//	}
//}




//#include <stdio.h>
//#include <stdlib.h>
//
//void print_numbers_with_hashes(int arr[], int size) {
//    int min_negative = 0;  // Ищем минимальное отрицательное число
//    for (int i = 0; i < size; i++) {
//        if (arr[i] < 0 && arr[i] < min_negative) {
//            min_negative = arr[i];
//        }
//    }
//
//    int abs_min_negative = abs(min_negative);
//
//    for (int i = 0; i < size; i++) {
//        int num = arr[i];
//        printf("%d: ", num);
//
//        if (num > 0) {
//            for (int j = 0; j < abs_min_negative; j++) {
//                printf(" ");
//            }
//            printf("|");
//            for (int j = 0; j < num; j++) {
//                printf("#");
//            }
//        } else if (num < 0) {
//            for (int j = 0; j < abs(num); j++) {
//                printf("#");
//            }
//            for (int j = 0; j < abs_min_negative - abs(num); j++) {
//                printf(" ");
//            }
//            printf("|"); 
//        } else {
//            for (int j = 0; j < abs_min_negative; j++) {
//                printf(" ");
//            }
//            printf("|");
//        }
//
//        printf("\n");
//    }
//}
//
//int main() {
//    int my_array[] = {3, -2, 0, 5, -1, -5};
//    int size = sizeof(my_array) / sizeof(my_array[0]);
//    print_numbers_with_hashes(my_array, size);
//    return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Функция для печати числа в виде решеток и звездочек
void print_double_as_hashes(double num, int min_negative_abs) {
    int num_int = (int)num; // Целая часть числа
    double num_frac = fabs(num - num_int); // Дробная часть числа

    if (num >= 0.0) {
        // Выравнивание
        for (int i = 0; i < min_negative_abs; i++) {
            printf(" ");
        }
        printf("|");

        // Решетки (целая часть)
        for (int i = 0; i < num_int; i++) {
            printf("#");
        }

        // Звездочки (дробная часть)
        for (int i = 0; i < (int)(num_frac * 10); i++) {
            printf("*");
        }
    } else {
        // Решетки (целая часть)
        for (int i = 0; i < abs(num_int); i++) {
            printf("#");
        }

        // Звездочки (дробная часть)
        for (int i = 0; i < (int)(num_frac * 10); i++) {
            printf("*");
        }

        // Выравнивание
        for (int i = 0; i < min_negative_abs - abs(num_int); i++) {
            printf(" ");
        }
        printf("|");
    }
}


void print_numbers_with_hashes(double arr[], int size, double min_negative) {
    int abs_min_negative_int = abs((int)min_negative);

    for (int i = 0; i < size; i++) {
        double num = arr[i];
        printf("%lf: ", num);
        print_double_as_hashes(num, abs_min_negative_int); // Вызываем функцию для печати числа
        printf("\n");
    }
}

int main() {
    double my_array[] = {3.5, -2.1, 0.0, 5.8, -1.9, -5.2};
    int size = sizeof(my_array) / sizeof(my_array[0]);

    double min_negative = 0.0;
    for (int i = 0; i < size; i++) {
        if (my_array[i] < 0.0 && my_array[i] < min_negative) {
            min_negative = my_array[i];
        }
    }

    print_numbers_with_hashes(my_array, size, min_negative);

    // Вычисление суммы, произведения и среднего арифметического
    double sum = 0.0;
    double product = 1.0;
    for (int i = 0; i < size; i++) {
        sum += my_array[i];
        product *= my_array[i];
    }
    double average = sum / size;

    // Вывод результатов с использованием решеток и звездочек
    printf("Sum: ");
    print_double_as_hashes(sum, abs((int)min_negative));
    printf("\n");

    printf("Product: ");
    print_double_as_hashes(product, abs((int)min_negative));
    printf("\n");

    printf("Average: ");
    print_double_as_hashes(average, abs((int)min_negative));
    printf("\n");

    return 0;
}









