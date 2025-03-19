#include <stdio.h>

//
int IsVowel(char a){
  if (a == 'a'|| a == 'a'-32 || a == 'e'|| a == 'e'-32 || a == 'i' || a == 'i'-32 || 
  a == 'o' || a == 'o'-32 || a == 'u' || a == 'u'-32 || a == 'y' || a == 'y'-32){
    return true;
  }
  else return false;
}
int main(){

////¹1
//
//  char str[] = "abc-12de950";
//  int res = 0, res1 = 0;
//  for (int i = 0; str[i] != '\0'; i++){
//    if ((str[i] <= '9') && (str[i] >= '0')){
//      res = res*10 + ((str[i])-'0');
//      if (str[i+1] == '\0'){
//        res1 += res;
//      }
//    }
//    else{
//      res1 += res;
//      res = 0;
//    }
//  }
//  printf("%i", res1);
//
//
//¹2
// #include <stdio.h>
//    char str[] = "daeerfghtyooaa";
//    int i, cons = 0, len = 0;
//    for (i = 0; str[i] != '\0'; i++){
//        len++;
//    }
//    for (int i = 0; i < len; i++){
//        if (!(IsVowel(str[i]))){
//          str[cons++] = str[i];  
//    }
//    }
//    str[cons] = '\0';
//    puts(str);
//
//
//¹3
//char str[] = "AbcDeRff";
//  int cons = 0, vow = 0, len = 0, dynamic = 0;
//  for (int i = 0; str[i] != '\0'; i++){
//        if (IsVowel(str[i])){
//            vow += 1;
//        } 
//    else{
//            cons += 1;
//        }
//        len += 1;
//  }
//  if (cons < vow){
//    str[len+cons] = '\0';
//    for (int i = len-1; i != -1; i--){
//      if (!(IsVowel(str[i]))){
//              str[i+cons-dynamic] = str[i];
//        str[i+cons-dynamic-1] = str[i];
//        dynamic++;
//      }
//      else{
//        str[i+cons-dynamic] = str[i];
//      }
//    }
//  }
//  else if (vow < cons){
//    str[len+vow] = '\0';
//    for (int i = len-1; i != -1; i--){
//      if (IsVowel(str[i])){
//              str[i+vow-dynamic] = str[i];
//        str[i+vow-dynamic-1] = str[i];
//        dynamic++;
//      }
//      else{
//        str[i+vow-dynamic] = str[i];
//      }
//    }
//  }
//  puts(str);
//
//
//
//¹4
int arr[] = {1, 3, 4, 3, 7, 3, 8, 0}, len = 0;
  for (int i = 0; arr[i] != '\0'; i++){
    len += 1;
  }
  int arr1[10] = {0};
  for(int i = 0; i <= len; i++){
    arr1[arr[i]] += 1;
  }
  printf("[");
  for (int i = 9; i != -1; i--){
    for (int j = arr1[i]; j != 0; j--){
        if (arr1[i] > 0){
          printf("%i, ", i);
      }
    }
  }
  printf("\b\b]");
}
