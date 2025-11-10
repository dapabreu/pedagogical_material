#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/stat.h>
// relevant include
#include <sys/mman.h> 

int fdsrc, fddst; // FD for src and dst files
char *src, *dst; // pointers to the MMap files
struct stat statbuf; // struct for file info

void cleanup(){
   // unmap src region..
   if( munmap(src, statbuf.st_size) < 0)
   {
      fprintf(stderr,"src munmap error: %s\n",strerror(errno));
      exit(1);
   }

   // unmap dst region..
   if( munmap(dst, statbuf.st_size) < 0)
   {
      fprintf(stderr,"dst munmap error: %s\n",strerror(errno));
      exit(1);
   }

   // close fds
   close(fdsrc);
   close(fddst);
}

int main (int argc, char *argv[])
{
   if(argc != 3)
   {
      printf("usage: ./mycp <src> <dst> \n");
      exit(1);
   }

   /////////// Prepare files ////////////
   // open src file  (get FD of src)
   if((fdsrc = open (argv[1], O_RDONLY)) < 0)
   {
      fprintf(stderr,"src open error: %s\n",strerror(errno));
      exit(1);
   }
   // get the size of src file 
   if(fstat (fdsrc, &statbuf) < 0)
   {
      fprintf(stderr,"src fstat error: %s\n",strerror(errno));
      exit(1);
   }

   // create the destiny file
   if ((fddst = open (argv[2], O_RDWR | O_CREAT , 0600)) < 0)
   {
      fprintf(stderr,"dst open error: %s\n",strerror(errno));
      exit(1);
   }

   // expand dst size by seeking to the last byte 
   lseek(fddst, statbuf.st_size - 1, SEEK_SET);
   // put something there
   write(fddst, "" , 1);

   ///////////////// MMAP usage //////////////////

   // memory map the src file
   if((src = mmap (0, statbuf.st_size, PROT_READ, MAP_SHARED, fdsrc, 0)) == MAP_FAILED)
   {
      fprintf(stderr,"src mmap error: %s\n",strerror(errno));
      exit(1);
   }

   // memory map the dst file 
   if((dst = mmap (0, statbuf.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fddst, 0)) == (caddr_t) -1)
   {
      fprintf(stderr,"dst mmap error: %s\n",strerror(errno));
      exit(1);
   }

   // with both files in memory we can use mem copy to
   // copy the bytes from the src mmap to the dest mmap (and file)
   memcpy (dst, src, statbuf.st_size);

   ////////////////  cleanup ! ///////////////
   cleanup();

   exit(0);
}