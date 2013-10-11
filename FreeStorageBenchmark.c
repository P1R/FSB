/*
    Copyright 2013 Perez Negron Rocha David Eugenio (p1r0)
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    email: p1r0@insomnia247.nl
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

main()
{
int i, j, r, A[10000], B[10000];
clock_t start, end;
FILE *fp = NULL;
	start = clock(); //asignamos a start valor inicio de reloj
	if((fp=fopen("prueba", "wb"))==NULL)
		printf("No se puede abrir fichero\n");
	for(i = 0;i < 10000; i++){
		end = clock();
		//srand(time(NULL)); daba mismos numeros por alta velocidad de micro implemente la sig solucion
		srand(end-start);
		r = rand() % 100;
		A[i] = r;
		if(fwrite(A, sizeof(int),10000, fp) != 10000)
			printf("Error de escritura de fichero");
	}
	fclose(fp);

/*leer valores*/
		if((fp=fopen("prueba", "rb"))==NULL)
			printf("No se puede abrir fichero\n");
	for(i = 0; i < 10000; i++){
		if(fread(B, sizeof(int), 10000, fp) != 10000) {
			if(feof(fp))
				printf("final prematuro de fichero");
			else
				printf("Error de lectura de fichero");
		}
	}
	fclose(fp);

        for(i = 0;i < 10000; i++){
		printf("%d",A[i]-B[i]);
        }

	end = clock(); //asignamos a end valor de fin de reloj
	printf("\ntiempo del proceso: %f seg\n", (double)(end-start)/ CLOCKS_PER_SEC);//tiempo dado en segundos
    getchar();
}
