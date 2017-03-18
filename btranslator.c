#include <stdio.h>
#include <math.h>
#include<sys/stat.h>
unsigned char binaryStringtoValue(char digits [8]){ //input binary array, return int value
  int sum = 0;
  for(int i = 0; i < 8; i ++){
    int scale = pow(2, 7-i);
    sum = sum + scale * (digits [i] - 48);
  }
  //printf("%d\n", sum);
  return sum;
}

void writeValueAsBinaryString(unsigned char val, char digits[8]){ //convert int to binary string and write it to digits array
  for (int i = 0; i < 8; i++){
    printf("%d\n", val);
    if (val % (int) pow (2, 7-i) != val){
      digits[i] = '1';
      val = val - (int) pow (2, 7-i);
    }
    else {
      digits[i] = '0';
    }
  }
  /*printf("\n");
  for (int i = 0; i < 8; i++){
    printf("%d, ", digits[i]);
  }
  printf("\n");
*/}

unsigned char hexStringToValue(char digits[2]){ //convert hexa string to integral
  int sum = 0;
  for (int i = 0; i < 2; i ++){
    if (digits[i] < '9'){
      sum = sum + pow (16, 1-i) * (digits[i] - '0');
    }
    else if(digits[i] < 'z') {
      sum = sum + pow(16, 1-i) * (digits[i] - 'a' + 10);
    }
    else {
      sum = sum + pow(16, 1-i) * (digits[i] - 'A' + 20);
    }   
  }
  //printf("%d\n", sum);
  return sum;
}


void writeValueAsHexString(unsigned char val, char digits[2]){ //convert int value to 2 digit hexa and write to digits array
  digits[0] = val / (int) pow (16, 1);
  digits[1] = val % (int)  pow (16, 1);
  for (int i = 0; i < 2; i++){
    if (digits[i] > 9){
      digits[i] = digits[i] - 10 + 'a';
    }
    else{
      digits[i] = digits[i] + '0';
    }
  } 
  for(int i = 0; i < 2; i++){ 
    printf("%c ", digits[i]);
  }
  printf("\n");
}

void writePermissionString(int perms, char str[9]){
  //perms will be converted from octal to decimal
  //convert from octal to binary
  for (int i = 0; i < 9; i++){
      if (perms % (int) pow (2, 8-i) < perms){
         str[i] = '1';
         perms = perms - (int) pow (2, 8-i);
      }
      else { 
        str[i] = '0';  
      }
  }
  for (int i = 0; i < 9; i++){
    if (i % 3 == 0){
      if (str[i] == '1'){
        str[i] = 'r';
      }
      else {str[i] = '-';}
    }
    else if (i % 3 == 1){
      if (str[i] == '1'){
          str[i] = 'w';
      }
      else {str[i] = '-';}
    }
    else{ 
      if (str[i] == '1'){
          str[i] = 'x';
      }
      else {str[i] = '-';}
    }
  }
  printf("%s\n", str);
  printf("\n");
}


int generatePermissionBits(char str[9]){
//convert from rwx to 1s and 0s
  for (int i = 0; i < 9; i++){
    if (i % 3 == 1){
      if (str[i] == 'r'){
        str[i] = 1;
      }
    else {str[i] = 0;}
    }
    else if (i % 3 == 1){
      if (str[i] == 'w'){
          str[i] = 1;
      }
      else {str[i] = 0;}
    }
    else{ 
      if (str[i] == 'x'){
          str[i] = 1;
      }
      else {str[i] = 0;}
    }
  }
  //convert from binary to decimal
  int sum = 0;
  for(int i = 0; i < 9; i ++){
    int scale = pow(2, 8-i);
    sum = sum + scale * (str [i] - '0');
  }
  //printf("%d\n", sum);
  return sum;
}

int main(void){
  char arr[] = {'0', '0', '0', '0', '0', '0', '0', '0', '\0'};
  char arr0[] = {'0', '0', '0', '0', '0', '0', '1', '1', '\0'};
  char arr1[] = {'0', '0', '1', '1', '1', '0', '0', '0', '\0'};
  char arr2[] = {'f', 'f', '\0'};
  char arr3[] = {'1', '1','\0'};
  char arr4 [9];
  char arr5[] = {'r', 'w', 'x','r','-','x','r','-','x'};
  //binaryStringtoValue(arr0);
  //binaryStringtoValue(arr1);
  //writeValueAsBinaryString(56, arr);
  //writeValueAsBinaryString(127, arr);
  //printf("%s\n", arr);
  //hexStringToValue(arr2);
  //hexStringToValue(arr3);
  //writeValueAsHexString(161, arr2);
  //writeValueAsHexString(172, arr2);
  writePermissionString(0755, arr4); 
  //generatePermissionBits(arr5);
  return 0;
}
