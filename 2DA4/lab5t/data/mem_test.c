#include "system.h"
#include <stdio.h>

#define BASE  SRAM_CONTROLLER_0_BASE

#define MAXNUM_WORDS   262144 
	//the SRAM is 512K, ie. 512*1024byte, ie. 524288byte. each words has 16bits, so MAX_words: 262144
	//if want to test 32K, change this number accordingly.
int main()
{

  //for unsigned char(1 byte): range: 0--255
  //for char the range is (-128---127)
  //for unsigned short (2 byte): range:  0--65535
  //for int(4 byte): range: 0---4,294,967,295  (?? 2 power of 32  ?)

   int i;
   int char_err_num=0, short_err_num=0, int_err_num=0;

   char * char_ptr; 
   char aChar;

   short *short_ptr;
   short aShort;

   int *int_ptr;
   int aInt;

   int charsize, shortsize, intsize;


  /*******************************************************************************
  *   when debug, it is better to use letters....(such as A....ASCII code 65..)  *
  *   to debug. because  we can use printf to check. if use chars that are not   *
  *   printable, run time error may occur if try to use printf to check          *
  * *****************************************************************************/


   charsize=sizeof(aChar);
   shortsize=sizeof(aShort);
   intsize=sizeof(aInt);
   printf("the sizeof char, short, int are: %d, %d, %d\n", charsize, shortsize, intsize);
/*

 //===============version, use pointers=============================

        //----------test Char------------------
         char_ptr= BASE;
        // printf(" the char at base is  %d\n", *(char_ptr));
        for (i=0; i<MAXNUM_WORDS*2; i++) {  // since char only take one byte,  *2

            aChar=i%128;    // or achar=(char)i;
            //*(short*)(BASE+2*i)=aShort; // only 0 to 255, total 256 chars;
            *char_ptr=aChar;

           //printf( " the char is : %c\n", aChar);
            //printf( " the written char is : %c            ====the address: %x\n", *(char_ptr), char_ptr);
            char_ptr++;
        }

          //printf( "==================-===========\n\n");

        char_ptr=BASE;
        //printf(" the char at base is  %d\n", *short_ptr);
        for (i=0; i<MAXNUM_WORDS*2; i++) {   //
              if (*char_ptr!=i%128 )  {  //or if (*char_ptr!=(char)i)
                  //printf( " the written : %d\n", *char_ptr);
                  //printf( "the should-be: %d\n", i%256);
                  //printf( " the boolean:  %d\n\n", (*char_ptr==i%256));
                  char_err_num++;
              }
                //printf( " the written char is : %c            -----the address: %x\n", *char_ptr, char_ptr);
             char_ptr++;
         }
         printf("Testing  Char: the total numbers of error is : %i\n" ,char_err_num);





    //----------test short--------since the range of short is -32768 to 32767 if the MAXNUM_WORDS IS BIGER THAN 32767, WILL TEST ERROR
    //----------------------------SO NEED TO %32767------------------------
        short_ptr= BASE;
        for (i=0; i<MAXNUM_WORDS; i++) {  // since short takes two bytes, ie. one word,  *1

            aShort=i%32767;
            *short_ptr=aShort;
            short_ptr++;
        }

        short_ptr=BASE;
        for (i=0; i<MAXNUM_WORDS; i++) {   //
              if (*short_ptr!=i%32767 )  {
                  short_err_num++;
              }
             short_ptr++;
        }
        printf("Testing short: the total numbers of error is : %i\n" ,short_err_num);


    //-----------test int---------------
        int_ptr=BASE;
        for (i=0; i<MAXNUM_WORDS/2; i++) {  // since int  take four bytes,  /1

            aInt=i;
            *int_ptr=aInt;
            int_ptr++;
        }

        int_ptr=BASE;
        for (i=0; i<MAXNUM_WORDS/2; i++) {   //
              if (*int_ptr!=i )  {
                  int_err_num++;
              }
             int_ptr++;
        }
        printf("Testing int  : the total numbers of error is : %i\n" ,int_err_num);

//===========================================================================

*/



//===============version, do not use pointers==================================
    //----------------TEST CHAR-----------------------------------
        for (i=0; i<MAXNUM_WORDS*2; i++) {
            *(char*)(BASE+i)=i%128; // to be safe, use 128 rather than 256
                                    // since by default, the char type may be the UNSIGNED CHAR,
                                    // which is ranged from 0--127.
					// or *(char*)(BASE+i)=(char)i;
        }

        for (i=0; i<MAXNUM_WORDS*2; i++) {
            if (* (char*)(BASE+i)!=i%128){  // or .....(char)i,   if not i%128
                char_err_num++;
            }
        }
        printf("Testing  Char: the total numbers of error is : %i\n" ,char_err_num);

    //----------------TEST SHORT-----------------------------------
        for (i=0; i<MAXNUM_WORDS; i++) {
            *(short*)(BASE+i*2)=i%32767; // short, uses two bytes
        }
        for (i=0; i<MAXNUM_WORDS; i++) {
           // printf( " the written one: %d     should be----: %d   address   %x\n",*(short*)(BASE+i), i+15, BASE+i);
            if (* (short*)(BASE+i*2)!=i%32767){
                short_err_num++;
            }
        }
        printf("Testing Short: the total numbers of error is : %i\n" ,short_err_num);

    //----------------TEST INT    -----------------------------------
        for (i=0; i<MAXNUM_WORDS/2; i++) {
            *(int*)(BASE+i*4)=i; // int, use 4 bytes
        }
        for (i=0; i<MAXNUM_WORDS/2; i++) {
            if (* (int*)(BASE+i*4)!=i){
                int_err_num++;
            }
        }
        printf("Testing INT  : the total numbers of error is : %i\n" ,int_err_num);



  return 0;
}