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
  printf("welcome to alma's work 05, stating files:\n\n");
  print_file_size("makefile", &StaT);
  print_mode("makefile", &StaT);
  print_atime("makefile", &StaT);
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
  mode = mode%01000;
  printf("mode of the file: %o\n", mode);
}
void print_atime(char *path, struct stat *StaT){
  stat(path, StaT);
  const time_t *a_time = &(StaT->st_atime);
  char *our_time = ctime(a_time);
  printf("atime of the file: %s\n", our_time);
}
