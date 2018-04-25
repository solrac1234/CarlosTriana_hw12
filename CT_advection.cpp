#include <iostream>
#include <math.h>

using namespace std;

//SE DEFINEN CONSTANTES Y ARREGLOS PARA LOS SNAPSHOTS 

float dt = 0.001; float dx = 0.001 ; int movx = 4/dx; int num_it = 700; float c = 1;

 float* A = new float[movx]; float* B = new float[movx];float* C = new float[movx];float* D = new float[movx];float* E = new float[movx]; float* F = new float[movx];


int main()
{
 	
  
float ymax = 0.5; float ymin = 0;

  //SE INICIALIZAN LAS FUNCIONES 
   for (int i=0; i < movx; i++){
	float coef = i*dx-2;
	float ymax = 0.5;
	float ymin = 0;
		if (pow( (coef)*(coef)  , ymax)  > ymax){
	  		B[i] = ymin; C[i] = ymin;}

      			else{
	   			B[i] = ymax; C[i] = ymax;}
    }

float ratioN = num_it/4.0 ;
float lim = 0.01;
//SE INICIALIZA UN SNAPCHOT PARA CADA FUNCION 
   for (int j = 0; j < num_it; j++){
       for ( int i = 1; i < movx-1; i++){
	   
           float deltaB = B[i]-B[i-1];
	   A[i] = B[i] - c*dt*( deltaB)/dx;}
     
      
       for (int i = 0; i < movx; i++){
	   B[i] = A[i]; }
     
       if ( pow(j*j, ymax) - ratioN  < lim){
	   for (int i = 0; i < movx; i++){
	       D[i] = B[i];}
	   }
       else if ( pow(j*j, ymax) - 2*ratioN  < lim){
	   for (int i = 0; i < movx; i++){
	      E[i] = B[i]; }
	 }
       else if ( pow(j*j, ymax) - 3*ratioN  < lim)
	 {
	   for (int i = 0; i < movx; i++)
	     { 
	       F[i] = B[i];
	     }
	 }
       
     }
   
       
   //SE IMPRIMEN LOS DATOS DE LOS SNAPSHOTS
   for (int i = 0; i < movx; i++)
     {
       cout << " " << C[i] << " " << D[i] << " " << E[i] << " " << F[i] << " " << A[i] <<  endl;
     }

   return 0;
}
