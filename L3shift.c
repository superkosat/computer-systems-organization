#include <stdio.h>

main() {


   unsigned int a = 60;	/* 60 = 0011 1100 */  
   unsigned int b = 13;	/* 13 = 0000 1101 */
   int c = 0;           

   c = a & b;       /* 12 = 0000 1100 */ 
   printf("Line 1 - Value of c is %d\n", c );

   c = a | b;       /* 61 = 0011 1101 */
   printf("Line 2 - Value of c is %d\n", c );

   c = a ^ b;       /* 49 = 0011 0001 */
   printf("Line 3 - Value of c is %d\n", c );

   c = ~a;          /*-61 = 1100 0011 */
   printf("Line 4 - Value of c is %d\n", c );

   c = a << 2;     /* 240 = 0000 0010 */
   printf("Line 5 - Value of c is %d\n", c );

   c = a << 3;     /* 480 = 1110 0100 */
   printf("Line 5a - Value of c is %d\n", c );

   c = a >> 2;     /* 15 = 0000 1111 */
   printf("Line 6 - Value of c is %d\n", c );

   char c1 = 'A'; // 0100 0001  = 65
   int  shiftval = c1 << 1;  
   printf( "%d, %x \n",  shiftval,  shiftval );

   // c1 becomes a signed integer so can create issues with negatives

   c1 = 0xD2;// 1101 0010  = 210
   unsigned int ushiftval = c1 << 1;  
   printf( "%u, %x \n", ushiftval, ushiftval );

   c1 = 0xD2;// 1101 0010  = 210
   int sshiftval = c1 << 1;  
   printf( "%d, %x \n", sshiftval, sshiftval );
}