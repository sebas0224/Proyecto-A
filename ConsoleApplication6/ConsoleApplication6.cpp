// ConsoleApplication6.cpp : Defines the entry point for the console application.
//
#include <stdio.h>
#include "stdafx.h"

FILE *stream, *stream2;

int main( void )
{ 
	char caracter;
	char resul[15], matriz [4][3];
	int i = 0,j=0,k=0;
   errno_t err;

   
   err  = fopen_s( &stream, "nombre.txt", "r" );
   if( err == 0 )
   {
      printf( "El archivo 'nombre.txt_' fue abierto\n" );
   }
   else
   {
      printf( "El archivo 'nombre.txt_' no fue abierto\n" );
   }

   printf("\nEl contenido del archivo de prueba es \n\n");

  /* while (feof(stream) == 0)
   {
	   caracter = fgetc(stream);
	   resul[i] = caracter;
	   printf("%c", caracter);
	   i++;
   }*/
   while (feof(stream) == 0)
   {


	   caracter = fgetc(stream);
	   printf("%c", caracter);
	   if (caracter != 5 || caracter != 10 || caracter != 15)
	   {
		   matriz[i][j] = caracter;
		   j++;
	   }
	   if (j == 3)
	   {
		   i++;
		   j = 0;
	   }


   }

   for (i = 0; i++; i < 4)
   {
	   for (j = 0; j++; j < 4)
	   {
		   printf("resultado: %c\n", matriz[i][j]);
	   }
	   printf("\n\n");

   }

   //printf("\nEl contenido del archivo de prueba es: %s \n\n",resul);
   // Open for write 
   

   // Close stream if it is not NULL 
   if( stream )
   {
      err = fclose( stream );
      if ( err == 0 )
      {
         printf( "El archivo 'nombre.txt_' fue cerrado\n" );
      }
      else
      {
         printf( "El archivo 'nombre.txt_' no fue cerrado\n" );
      }
   }

   // All other files are closed:
   int numclosed = _fcloseall( );
   printf( "Number of files closed by _fcloseall: %u\n", numclosed );
}

