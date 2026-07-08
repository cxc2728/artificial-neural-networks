#define _CRT_SECURE_NO_WARNINGS

       #include <stdio.h>
      
       #include <string.h>
       #include <dos.h>
       #include <stdlib.h>
       #include <conio.h>
       #include <math.h>
       #include <ctype.h>

	   #include "dirent.h"
	   #include "useoldio.h"
	   #include <ctype.h>
	   #include <stdio.h>
       #include "math.h"
	   #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
       #include "iostream.h"

		#include <istream>
		#include <cfloat>

		struct learning_set
		{

			unsigned int  T ;   //unsigned  int//
			int INP ;
			int HID ;
			int OUT_T ;

		}set;

      

      char classNames[10][100];
 
      int    set_learning_variables(char path_store[80]);

      double  * first_layer_connections_taker( int p, int q );

      double  * second_layer_connections_taker( int r, int v);

      double  * biggest_range_taker( int r );

      double  * smallest_range_taker( int r );

      double  * pattern_normaliser(char filename[128], double  *p1 ,double  *p2 , int x);

      double     normalise(double value, double min, double max);

      char * take_a_filename( char current_dir[80],unsigned int p);

      double sigmoid(double input);

      double  * output_nodes_producer( double  * l1 , double  * l2 , int p ,int r);





	void main(void){


	int    k6;
	int j;
	unsigned int t;

	char string[80];
	char * name;
	char filename[128];

	FILE *stream;



	double  * input_layer;
	double  * hidden_layer;

	double   * upper;
	double   * lower;
	double   * pattern;

	double   *  hidden_activator;
	double   *  output_activator;


	   char *lena;
	   char *aigo;
	   char *goulp;

	   goulp="NETWORK RESPONSE:";


	 // 2024
	 int MAX_PATH_LENGTH = 300;
     cout << ("INSERT TEST DIRECTORY: drive: ") << "back-slash " << ("directory") << endl;
	 cin.getline(string, MAX_PATH_LENGTH);
	 // 2024

     if( (set_learning_variables(string))==1  ){

	   printf("TEST SET STORED\n");
      
	 }

	   printf("PLEASE WAIT LOADING...\n");


  input_layer = first_layer_connections_taker( (set.HID),(set.INP) );

  hidden_layer = second_layer_connections_taker( (set.HID),(set.OUT_T) );

  upper = biggest_range_taker( (set.INP) );

  lower = smallest_range_taker( (set.INP) );



	 for(j=1;j<((set.HID)+1);j++){

		  k6=( ((set.INP)+1)*(j-1) );

	*(input_layer+k6)=-(*(input_layer+k6) );

				      }


	  for(j=1;j<((set.OUT_T)+1);j++){

		  k6=( ((set.HID)+1)*(j-1) );

	*(hidden_layer+k6)=-(*(hidden_layer+k6) );


				       }


	 // 2024
	 char readyToClassify = ' ';
	 // 2024

	 printf("READY TO CLASSIFY press enter  \n");
	 printf("\n");
	 while(!_kbhit());
	 // 2024
	 readyToClassify = _getche();
	 // 2024
	 stream=fopen("RESPONSE.txt","w+");

	 fprintf(stream,"%s  \n",goulp);

	 // 2025
	 FILE * dimensionHID;
	 if ((dimensionHID = fopen("DimensionHID.txt","w"))==NULL)
	 {

	 printf("WARNING CANNOT OPEN DimensionHID FILE\n");
	 exit(0);

	 } else { }
	 // 2025

     t=0;
	     do{




	 name=take_a_filename(string,t);

	 strcpy(filename,name);


	 pattern = pattern_normaliser(filename,lower,upper,(set.INP) );

	 hidden_activator = output_nodes_producer(input_layer,pattern,(set.HID), (set.INP));

	 // 2025
	 fprintf(dimensionHID,"%s\t",name);

	 for (int d = 1; d <=set.HID; d++) {

		fprintf(dimensionHID,"%lf\t", *(hidden_activator+d));


	 }
	 fprintf(dimensionHID,"\n");
	 // 2025

     output_activator = output_nodes_producer(hidden_layer,hidden_activator, (set.OUT_T),(set.HID));


	 for(j=1;j<((set.OUT_T)+1);j++){



		 if(j==1){

			printf("%s=%f\n",classNames[j-1],(*(output_activator+j)) );
			aigo="CHARATERIZED AS:";
			fprintf(stream,"%s \n",aigo);
			fprintf(stream,"%s %f \n",classNames[j-1],(*(output_activator+j)) );

		 }

  
		 if(j==2){

	 
			 printf("%s=%f\n",classNames[j-1],(*(output_activator+j)) );
			 fprintf(stream,"%s %f \n",classNames[j-1],(*(output_activator+j)) );

	 	 }


		 if(j==3){

	 
			 printf("%s=%f\n",classNames[j-1],(*(output_activator+j)) );
			 fprintf(stream,"%s %f \n",classNames[j-1],(*(output_activator+j)) );

		 }
  
   
		 if(j==4){

	  
			 printf("%s=%f\n",classNames[j-1],(*(output_activator+j)) );	  
			 fprintf(stream,"%s %f \n",classNames[j-1],(*(output_activator+j)) );

	     }


	 }

	 printf("\n");
	 printf("SOURCE FILE: %s\n",filename);
	 lena="source file:";
	 fprintf(stream,"%s %s \n",lena,filename);

	 // 2024
	 char classify = ' ';
	 // 2024

	 printf("\n");
	 puts("PRESS ENTER to CLASSIFY a NEW INPUT\n");
	 while(!_kbhit());
	 // 2024
	 classify = _getche();
	 // 2024

	  free(pattern);
	  free(hidden_activator);
	  free(output_activator);


	 t++;


	} while( t < (set.T) );

     fclose(stream);
     printf("\n");
     printf("CLASSIFICATIONS CORRECTLY SAVED ON FILE \n");

	 // 2025
	 fclose(dimensionHID);
	 // 2025

	 // 2024
	 char enterKey = ' ';
	 // 2024

     puts("hit any key to quit");
     while(!_kbhit());
     enterKey = _getche();

     free(input_layer);
     free(hidden_layer);
     free(upper);
     free(lower);



}// END


int set_learning_variables(char path_store[80])
{

	 FILE * sc;


     char first_file[80];
     int k1=0,l;
     double cs;
     unsigned int  k2=0;
     char s1[5]="\\";

     DIR *dir;
     struct dirent *ent;


  if ((dir = opendir(path_store)) == NULL)
  {
    perror("Unable to open directory");
    exit(1);
  }

   for(l=1;l<=3;l++){

   if((ent = readdir(dir)) != NULL)
   {


    if(l==3){

    cout << "\n" << endl;

    cout << "FIRST FILE OF THE LIST: " << ent->d_name << endl;

    k2++;
	   }

   }  else {

  cout << "cannot find FIRST FILE of the list " << endl;
  exit(1);

       }
	 }

	   strcpy(first_file,path_store);

	   strcat(first_file,s1);

	   strcat(first_file,ent->d_name);

	   cout << "entry: " << first_file << endl;


  if((sc=fopen(first_file,"rb"))==NULL){

  cout << "cannot open first file of the list" << endl;

  exit(1);
				      }


  /// 2024
  int ReadTheValue = 1;

  while (ReadTheValue != 0) {

	  ReadTheValue = fread(&cs, sizeof(double), 1, sc);

	  if (ReadTheValue != 0) k1++;

  }
  /// 2024


    while ((ent = readdir(dir)) != NULL)
    {

    cout << "" << ent->d_name << endl;

    k2++;

    }

    if (closedir(dir) != 0)
    {

    perror("Unable to close directory");

    }

  cout << "INPUT NEURONS = " << k1 << endl;

  set.INP=k1;

  printf("NUMBER OF PATTERNS TO BE TESTED = %d\n",k2);

  set.T=k2;

  printf("INSERT number of classes to discriminate (OUTPUT NEURONS) for a Maximum of 4\n");
  // 2024
  int returnValueOfScan = scanf("%d",&k1);
  // 2024

  set.OUT_T=k1;

  for(int s=0; s<k1; s++)
  {
	 
  printf("Please Insert Name of the Class to Indentify\n");
  cin >> classNames[s];
  printf("Class to Identify: %s\n", classNames[s]);

  }

  printf("INSERT NUMBER of HIDDEN NEURONS\n");
  returnValueOfScan = scanf("%d",&k1);
  set.HID=k1;

  printf("CHECK if the TEST set is currently correct\n");

  printf("\n");

  printf("TEST PATTERNS=%d\n",set.T);
  printf("INP=%d\n",set.INP);
  printf("HID=%d\n",set.HID);
  printf("OUT=%d\n",set.OUT_T);

  printf("\n");

  printf("DIGIT Y to SET THE NETWORK or N to quit\n");
  char ch=_getche();
  ch=toupper(ch);
  printf("\n");

  switch(ch){

  case 'N':
  exit(0);

  case 'Y':
  break;

	    }

  return 1;

 }


double  *   first_layer_connections_taker( int p, int q )
{

	double  * first_layer;
	int j , k1, k6;
	FILE * sl;
	double boot;


	if ((first_layer = (double  *) calloc( ((p+1)*(q+1)),sizeof(double)) ) == NULL)
	{

	printf("Not enough memory to allocate buffer first_layer\n");
	exit(1);

	}



	if ((sl = fopen("WEIGHT1.txt","r"))==NULL)

	{

	printf("WARNING CANNOT OPEN FIRST LAYER CONNECTIONS FILE\n");
	exit(1);

	}



	    for(j=1;j<p+1;j++){

	      for(k1=0;k1<q+1;k1++){

		k6=(k1 +((q+1)*(j-1)) );

		// 2024
		int returnValue = fscanf(sl,"%lf\n",&boot);
		// 2024

		*(first_layer + k6)=boot;

				     }

			      }
	   fclose(sl);

    return first_layer;

 }


double  *  second_layer_connections_taker( int r, int v )
{

	 double  * second_layer;
	 int j , k1, k6;
	 FILE * sl;
	 double boot;

 
	 if ((second_layer = (double  *) calloc( ((r+1)*(v+1)),sizeof(double)) ) == NULL)
 	 {
  
	 printf("Not enough memory to allocate buffer second_layer\n");
   	 exit(1);
 
	 }

	if ((sl = fopen("WEIGHT2.txt","r"))==NULL)
	{

	printf("WARNING CANNOT OPEN SECOND LAYER CONNECTIONS FILE\n");
	exit(1);

	}


	 for(k1=0;k1<r+1;k1++){

		 for(j=1;j<v+1;j++){


		  k6=( (j-1)+(k1*v) );

		  // 2024
		  int returnValue = fscanf(sl,"%lf\n",&boot);
		  // 2024

		  *(second_layer + k6)=boot;

		 }

	 }

	 fclose(sl);

     return second_layer;

 }


double  * biggest_range_taker( int r )
{

	double  * biggest;
	int j ;
	FILE * sl;
	double boot;


    if ((biggest = (double  *) calloc((r+1),sizeof(double)) ) == NULL)
    {
		printf("Not enough memory to allocate buffer biggest\n");
   
		exit(1);
    }

	if ((sl = fopen("BIGGEST.txt","r"))==NULL)
	{

		printf("WARNING CANNOT OPEN FIRST NORMALISER FILE\n");
	
		exit(1);

	}


	  for(j=1;j<r+1;j++){

		// 2024
  	    int returnValue = fscanf(sl,"%lf\n",&boot);
		// 2024

		*(biggest + j)=boot;

			    }

	  fclose(sl);

      return biggest;

 }


double  * smallest_range_taker( int r )
{

	double  * smallest;
	int j ;
	FILE * sl;
	double boot;


	if ((smallest = (double  *) calloc((r+1),sizeof(double)) ) == NULL)
	{

     printf("Not enough memory to allocate buffer smallest\n");
     exit(1);

	}

	if ((sl = fopen("SMALLEST.txt","r"))==NULL)
	{

	printf("WARNING CANNOT OPEN SECOND NORMALISER FILE\n");
	exit(1);

	}


	  for(j=1;j<r+1;j++){

      // 2024
	  int returnValue = fscanf(sl,"%lf\n",&boot);
	  // 2024

	  *(smallest + j)=boot;

		
	  }
	  
	  fclose(sl);

      return smallest;

}

double  * pattern_normaliser(char filename[128], double  *p1 ,double  *p2 , int x)
{

	 FILE *pf;
     int k2;
     double boot,number;
     double   *pattern_normalisation;


   if ((pattern_normalisation = (double  *) calloc( (x+1), sizeof(double)) ) == NULL)
   {

	   printf("Not enough memory to allocate buffer pattern\n");
   
	   exit(1);

   }



	if ((pf = fopen(filename,"rb"))==NULL)
	{
	
		printf("Cannot open file %s\n",filename);
	 
		free(pattern_normalisation);
	 
		exit(1);

	}


	    for(k2=1;k2<x+1;k2++){

		  // 2024
		  int returnValue = fread(&number, sizeof(double), 1, pf);
		  // 2024

	      boot = normalise( number,*(p1+k2),*(p2+k2) );

	      if(boot<0.01)
		  {
			      
			  *(pattern_normalisation+k2)=0.0;

		  }

	      if(boot>0.99)
		  {

			  *(pattern_normalisation+k2)=1.0;

		  }

		if( (boot>=0.01) && (boot<=0.99) ){

			*(pattern_normalisation+k2)=boot;
	
		}

		}
   
		fclose (pf);

		return pattern_normalisation;

}

double normalise(double value, double min, double max)
{

	if ((_isnan((double)(value - min) / (max - min))) == 0) { return ((double)(value - min) / (max - min)); }

	else return (double)0.0;

}


char * take_a_filename( char current_dir[80], unsigned int p)
{

     char klf[80];
     char s1[5]="\\";
     const char * a;
     unsigned int stop=0;
     
	 // 2024
	 char* TheNameOfTheFile = 0;

	 TheNameOfTheFile = (char*)calloc(80, sizeof(char));


	 if (TheNameOfTheFile == NULL)
	 {
		 printf("Not Enough memory to allocate filename, Exit");
		 exit(0);
	 }
	 // 2024

     DIR *dir;
     struct dirent *ent;


	 strcpy(klf,current_dir);

	 strcat(klf,s1);

	 if ((dir = opendir(current_dir)) == NULL)
	 {

	    perror("Unable to open directory");
	    exit(1);

	 }
	 else {


		 while (stop != 2) {

			 if ((ent = readdir(dir)) != NULL)
			 {

				 a = ent->d_name;
				 stop++;

			 }

		 }


		 for (unsigned int x = 0; x <= p; x++) {

			 if ((ent = readdir(dir)) != NULL)
			 {

				 a = ent->d_name;

			 }

		 }

	 // 2024
	 if (ent != NULL)
	 {
		strcat(klf, ent->d_name);
	 }
	 // 2024

	 }

	// 2024
	sprintf(TheNameOfTheFile, "%s", klf);
	// 2024

    if (closedir(dir) != 0)
    {

    perror("Unable to close directory");

    }

	return TheNameOfTheFile;
}


double sigmoid(double input)
{

    double activate;
    activate=(double)(1/(1+exp((double)-input)));

	return activate;

}


double  * output_nodes_producer( double  * l1 , double  * l2 , int p ,int r)
{

    double  * y ;
    double top,THR;
    int i,j,k6,k5;

   if ((y = (double  *) calloc( (p+1), sizeof(double)) ) == NULL)
   {

   printf("Not enough memory to allocate buffer OUTPUT NODES\n");
   exit(1);

   }

	   for(j=1;j<p+1;j++){

			       top=0;

	   for(i=1;i<r+1;i++){


			       k6=(i+((r+1)*(j-1)));

	   top  = top + ( (*(l1+k6) ) * ( *(l2+i) ) );

			      }

			       k5=((r+1)*(j-1));

	   THR =( top - (*(l1+k5)) );

	   *(y+j) = sigmoid(THR);


			     }

	   return y;

}