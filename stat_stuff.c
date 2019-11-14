#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <sys/stat.h>

void print_file_size(char *path, struct stat *StaT);
void print_mode(char *path, struct stat *StaT);
void print_atime(char *path, struct stat *StaT);

int main(){
  struct stat StaT;
  printf("welcome to alma's work 05, stats of ./program:\n\n");
  print_file_size("program", &StaT);
  print_mode("program", &StaT);
  print_atime("program", &StaT);
  printf("\nthank you for viewing!\n\n");
  return 0;
}
void print_file_size(char *path, struct stat *StaT){
  stat(path, StaT);
  double size = StaT->st_size;
  size = size / 10;
  printf("size of the file: %fKB\n", size);
}
void print_mode(char *path, struct stat *StaT){
  stat(path, StaT);
  int mode = StaT->st_mode;
  int octalMode = mode%01000;
  mode = octalMode;
  printf("rwx mode: ");
  int i;
  int digit;
  char arr[3] = {'r', 'x', 'w'};
/*
  for (k=0; k<3; k++){
    for (i=0; i<3; i++){ //x, then w, then r
      digit = mode%0b10; //mod by 2 to cut off the last digit
      mode = mode / 0b10; //divide by 2 to continue on
      if (digit&0b1){ // one mod one is zero. so if it's on, print
        printf("%c", arr[i]);
      }else{
        printf("-");
      }
    }
  }
*/
  int bit_shifted;
  for (i = 9; i>0; i--){
    bit_shifted = mode>>(i-1);
    if (bit_shifted&1){
      printf("%c", arr[i%3]);
    }else{
      printf("-");
    }
  }
  printf("\noctal mode of the file: %o\n", octalMode);
}
void print_atime(char *path, struct stat *StaT){
  stat(path, StaT);
  const time_t *a_time = &(StaT->st_atime);
  char *our_time = ctime(a_time);
  printf("atime of the file: %s\n", our_time);
}
