#include <stdio.h>
#include <dirent.h>

int main(){
   struct dirent *files;
   DIR *dir = opendir("/");

   if (dir == NULL){
      printf("Error while opening the directory");
      return 0;
   }

   while ((files = readdir(dir)) != NULL)
   printf("%s\n", files->d_name);
   closedir(dir);
   return 0;
}
