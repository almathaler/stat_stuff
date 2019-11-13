#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

void print_file_size(char *path, struct stat *StaT);
void print_mode(char *path, struct stat *StaT);
void print_atime(char *path, struct stat *StaT);

int main(){
  struct stat *StaT;
  printf("welcome to alma's work 05, stating files:\n\n");
  print_file_size("makefile", StaT);
  print_mode("makefile", StaT);
  print_atime("makefile", StaT);
  printf("\nthank you for viewing!\n\n");
  return 0;
}
void print_file_size(char *path, struct stat *StaT){
  stat(path, StaT);
  int size = StaT->st_size;
  printf("size of the file: %d\n", size);
}
void print_mode(char *path, struct stat *StaT){
//  return 0;
}
void print_atime(char *path, struct stat *StaT){
//  return 0;
}
