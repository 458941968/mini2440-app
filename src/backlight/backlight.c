#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ioctl.h> 
#include <linux/fb.h>

int main(int argc, char** argv)
{
   if ( argc == 1 )
         {
   printf("Useage:backlight on\n");
   printf("       backlight off\n");
         return 1;

       }

   int fb = open("/dev/fb0", O_RDWR);
   if( fb < 0 )
       {
  printf("Cann't open /dev/fb0\n");
  return 1;
       }

 if( strcmp( argv[1], "on" ) == 0 )
     ioctl(fb, FBIOBLANK, 0 );
   else if( strcmp( argv[1], "off" ) == 0 )
   ioctl(fb, FBIOBLANK, 1 );
 else
 {
   printf("Useage Error ......\n");
   printf("Useage:backlight on\n");
   printf("       backlight off\n");
 }

   close(fb);

 return 0;

}
