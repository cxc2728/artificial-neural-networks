	   #define _CRT_SECURE_NO_WARNINGS
       // Three Layer Perceptron with Growing Architecture
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
       #include <math.h>
       #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
       #include "iostream.h"

	   #include <istream>
	  
		int returnValue = 0;

		using namespace std;

	   // 2024
       #define   LOWEST       DBL_MIN
       #define   HIGHEST      DBL_MAX
       #define   PATH         1000
	   #define   CLASSES      10
	   // 2024


			/// 2024
		class ANN2024 {
		
			unsigned int n1; 
			unsigned int n2; 

		public:

			// declare a structure ' data ' that defines the
			// pointers to pointers to the image
			struct data {

				double* wekk;

				double* sery;

			}*pointer; // pointer to the element of the structure 'data'
			// the pointer points to the memory address of the
			// pointers to pointers 

		public:

			// constructor of the class 
			ANN2024(unsigned int x, unsigned int y) : n1(x), n2(y) { pointer = 0; };

			// declare the prototype of the 
			// function 'allocateData'
			// the function belongs to the 
			// sets of methods of the class 
			void allocateData();

			// destructor 
			~ANN2024() { }

		};
		/// 2024

void ANN2024::allocateData() { // allocate data

			pointer = new data;

			pointer->wekk = new double [this->n1];

			// (2) initialize (begin)
			for (unsigned int v = 0; v < this->n1; v++) { // (1)


				pointer->wekk[v] = (double)0.0;


			} // (1) allocate struct 'data' (end)
			// (2) initialize (end)


			pointer->sery = new double[this->n1];

			// (2) initialize (begin)
			for (unsigned int v = 0; v < this->n1; v++) { // (1)


				pointer->sery[v] = (double)0.0;


			} // (1) allocate struct 'data' (end)
			// (2) initialize (end)

		} // allocate data

		struct learning_set
		{

			unsigned int  T;
			unsigned int INP;
		    unsigned int OUT_T;
			double RATE;
			double SMOOF;
			double TOLL;
			unsigned int ITE;
			unsigned int CONV;

		}set;

        char buff[PATH][CLASSES];

		unsigned int HID;


      // 2024
     double  * pattern_handler(char filename[PATH],unsigned int x);
	 // 2024

     double  * make_desidered_output(int q, int  * op);

     double     normalise(double value, double min, double max);

     double  * first_layer_random_weigth_generator(unsigned int r,unsigned int v);

     double  * second_layer_random_weigth_generator(unsigned int v,unsigned int q);

     double  * first_layer_weigth_change(unsigned int r,unsigned int v);

     double  * second_layer_weigth_change(unsigned int v,unsigned int q);

     // 2024
     double  * pattern_normaliser(char filename[], double *p1 ,double * p2 , unsigned int x);
	 // 2024

     double multiplier(double m);

     double sigmoid(double input);

     double  * F_net (double  * l3 ,unsigned int q);

     unsigned int index(double  * l7, unsigned int c);

     double  * delta2 ( double  * l4 , double  * l5 ,  double  * l6 ,
				      unsigned int q ,unsigned int b);

     double  * correction_allocator(unsigned int r , unsigned int q);

     double  * second_layer_correction_calculator( double  * l7,
			      double  * l8, unsigned int r ,unsigned int q);

     double  * first_layer_correction_calculator( double  * l12,
			     double  * l13, unsigned int q ,unsigned int p);


     double  * delta1 ( double  * l9 , double  * l10 ,
			    double  * l11 , unsigned int q ,unsigned int b);

     double error_calculator(double  * a1 , double  * a2, unsigned int q ,unsigned int b);


     double  * second_layer_weight_adjustment( double  * b1,
		       double  * b2, double r1, double s1 ,unsigned int p ,unsigned int q );

     double  * first_layer_weight_adjustment( double  * b4,
			double  * b5, double r1, double s1, unsigned int p ,unsigned int r);


     unsigned int  first_layer_connections_saver(double  * x1, unsigned int p, unsigned int q);

     unsigned int  second_layer_connections_saver( double  * x2, unsigned int r, unsigned int v );

     char * take_a_filename(char selector[], char current_dir[],
				      unsigned int r, unsigned int p);

	 // 2024
     int * set_learning_variables(char path_store[80]);
	 // 2024

     unsigned int    find_requested_files(char selector[10], char current_dir[80]);

     unsigned int range_saver(double * f1 , double * f2 , unsigned int r );

     double  * new_second_layer_weight_adjustment(double  * b1,
	       double  * b2,double r1,double s1,unsigned int f,unsigned int p,unsigned int q );

     double  * new_first_layer_weight_adjustment(double  * b4,
	       double  * b5, double r1, double s1 ,unsigned int f, unsigned int p,unsigned int r);

	 double  * output_nodes_producer( double  * l1 , double  * l2 ,
				       unsigned int p ,unsigned int r);

     void main (void)
     {

	  // 2025
      unsigned int ju,acc;
      unsigned int k1,k2,k3,k4,k6,alt,re_learn;
      double erro;
      unsigned int j,gt;
      unsigned int counter,count;
      unsigned int inde;
      double ru, su;  /// .RATE .SMOOF  //
      unsigned int select;
	  char ch, string[300];
	  // 2025
      char what_to_do = 'A';
      char * name;
		 // 2024
		 char filename[PATH];
		 char* theName;
		 char theMismatchFilename[PATH];
		 // 2024
      unsigned int i;



      double   * pattern_pointing = 0;
      double   * output = 0;


      double   * first_layer_connections = 0;
      double   * second_layer_connections = 0;


      double   * first_layer_change = 0;
      double   * second_layer_change = 0;


      double    * pattern_user = 0;
      double    * pattern_detector = 0;

      double    * transfer_hidden = 0;
      double    * transfer_output = 0;

      double    * function_net1 = 0;
      double    * function_net2 = 0;

      double    * delta2_store = 0;
      double    * delta1_store = 0;

      double   * corr1 = 0;
      double   * corr2 = 0;

      double   * transit1 = 0;
      double   * transit2 = 0;

      double   * def1 = 0;
      double   * def2 = 0;

      double  * transit3 = 0;
      double  * transit4 = 0;

      double * smallest = 0;
      double * biggest = 0;

      double  * inout = 0;


      counter=0;
      erro=0;
      count=0;

	  
		// 2025
        int * dim = 0;
		// 2025

		 // 2024
		 unsigned int MAX_PATH_LENGTH = 300;
		 printf("\n");
		 cout << ("INSERT CURRENT LEARN DIRECTORY: drive: ") << "back-slash " << ("directory") << endl;
		 cin.getline(string, MAX_PATH_LENGTH);

		 // 2025
		 cout << "Path: " << string << endl;
		 // 2025

		 dim = set_learning_variables(string);

		 // 2024
		 for (unsigned int theIndex = 1; theIndex <= set.OUT_T; theIndex++)
			 printf("Dimensions = %d\n", *(dim + theIndex));
		 // 2024

		 
		 // 2024
		 ANN2024 ANN_Binary(set.INP, CLASSES);

		 ANN_Binary.allocateData();
		 // 2024

     printf("\n");
     printf("DIGIT Y to SET THE NETWORK or N to quit\n");
     ch = _getche();
     ch=toupper(ch);
     printf("\n");

		 // 2024
		 char makeRangeforNormalization = ' ';
		 // 2024

     switch(ch){

	  case 'N':
	  free(dim);
	  exit(0);

	  case 'Y':
	  printf("\n");
	  printf("LEARNING SET STORED\n");
	  printf("\n");
	  printf("press enter to MAKE A RANGE FOR NORMALISATION\n");
	  while (!_kbhit());
	  // 2024
	  makeRangeforNormalization = _getche();
	  // 2024

     }


		 // 2024
		 for (unsigned int theIndex = 1; theIndex <= set.OUT_T; theIndex++)
			 printf("Dimensions = %d\n", *(dim + theIndex));
		 // 2024

		 output = make_desidered_output(set.OUT_T, dim);

		 // 2024
		 unsigned int k5 = 0;

		 for (k2 = 0; k2 < set.OUT_T; k2++) {

			 k5++;

			 for (k1 = 0; k1 < set.OUT_T; k1++) {


				 unsigned int as = (set.OUT_T + 1) + k1 + (k2 * set.OUT_T);

				 printf("Desired Output = %lf\n", *(output + as));

			 }

		 }
		 // 2024



		free(dim);

	    for (j = 0; j < (set.T); j++) {


	    inde=index(output,j);

	    select=(unsigned int)(*(output+inde));

	    name=take_a_filename(buff[inde+1],string,select,j);


	    strcpy(filename,name);

	    acc = set.INP;

	    pattern_pointing = pattern_handler(filename,acc);

	    for (k1 = 0; k1 < ((set.INP) + 1); k1++) {

	    printf("IO[%u][%u]=%lf\n",j,k1, *(pattern_pointing+k1) );
				
		}


	    free( pattern_pointing );

			    
		}

		

	    for (k2 = 1; k2 < ((set.INP) + 1); k2++) {

			 ANN_Binary.pointer->wekk[k2] = -HIGHEST;

			 ANN_Binary.pointer->sery[k2] = HIGHEST;
			
		 }
		

	    for (j = 0; j < (set.T); j++) {

	    inde=index(output,j);

	    select=(unsigned int)(*(output+inde));

	    name=take_a_filename(buff[inde+1],string,select,j);

	    strcpy(filename,name);

	    acc = set.INP;

	    pattern_pointing = pattern_handler(filename,acc);
		
		for (k2 = 1; k2 < ((set.INP) + 1); k2++) {
			
			
				 if ((*(pattern_pointing + k2)) >= ANN_Binary.pointer->wekk[k2]) {

					 ANN_Binary.pointer->wekk[k2] = *(pattern_pointing + k2);
					
				 }

				 if ((*(pattern_pointing + k2)) < ANN_Binary.pointer->sery[k2]) {

					 ANN_Binary.pointer->sery[k2] = *(pattern_pointing + k2);
					 
				 }
				
			 }//1 for

	   free( pattern_pointing );

			  } //2 for

	   printf("\n");
	   printf("RANGE FOR NORMALISATION\n");
	   printf("\n");

	   // 2025
	   for (k2 = 1; k2 < ((set.INP) + 1); k2++) { // for loop

				
				cout << "smallest[" << k2 << "] = " << ANN_Binary.pointer->sery[k2] << "\t" <<
				         "biggest[" << k2 << "] = " << ANN_Binary.pointer->wekk[k2] << endl;
				
			 } // for loop
	   // 2025

	  
		 printf("\n");
		 printf("press enter to NORMALISE ALL PATTERNS\n");
		 while (!_kbhit());
		 // 2024
		 char normalizeAllPatterns = _getch();
		 // 2024


		if (!(biggest = new double[(set.INP + 1) * sizeof(double)]))
		 {
			 printf("Not enough memory to allocate biggest\n");
			 exit(1);
		 }
		 else

		 if (!(smallest = new double[(set.INP + 1) * sizeof(double)]))
		 {
			 printf("Not enough memory to allocate smallest\n");
			 exit(1);
		 }
		 else 

				 for (k2 = 1; k2 < ((set.INP) + 1); k2++) {

					 // 2025
					 *(biggest + k2) = ANN_Binary.pointer->wekk[k2];

					 *(smallest + k2) = ANN_Binary.pointer->sery[k2];
					 // 2025
				 }

			
	    for (j = 0; j < (set.T); j++) {

	    inde=index(output,j);

	    select=(unsigned int)(*(output+inde));

	    name=take_a_filename(buff[inde+1],string,select,j);

	    strcpy(filename,name);

	    acc = set.INP;

    pattern_user = pattern_normaliser(filename,smallest,biggest,acc);

    for (k2 = 0; k2 < ((set.INP) + 1); k2++) {

				 printf("IO[%u][%u]=%lf\n", j, k2, *(pattern_user + k2));


			 }

			 printf("\n");
			 free(pattern_user);

		 }


        alt=0;

	    for(j=0;j<(set.T);j++){


	    inde=index(output,j);

	    select=(unsigned int)(*(output+inde));

	    name=take_a_filename(buff[inde+1],string,select,j);


	    strcpy(filename,name);

	    acc=set.INP;

        pattern_user = pattern_normaliser(filename,smallest,biggest,acc);

	   for(k2=1;k2<((set.INP)+1);k2++){

       if( ( *(pattern_user+k2) )>1){

       printf("WARNING IO[%u][%u]=%lf\n",j,k2,*(pattern_user+k2) );
       printf("Came from file %s\n",filename);
       alt++;
				    
	   } //if

				
	}  //for k2

       free( pattern_user );

	}//for j

       if(alt!=0){

      printf("press enter to quit\n");
       while(!_kbhit());
       
	   // 2024
	   char QuitTheProgram = _getch();
       // 2024

	   exit(0);
		  } else printf("All inputs correctly normalised\n");

       printf("press enter to SEARCH FOR MISMATCHING CASES\n");
       while(!_kbhit());
       
	   // 2024
	   char searchMismatchingCases = _getch();
       // 2024
	   
	   printf("please WAIT...\n");


       for(gt=0;gt<(set.T);gt++){


	    inde=index(output,gt);

	    select=(unsigned int)(*(output+inde));

	    name=take_a_filename(buff[inde+1],string,select,gt);

	    strcpy(filename,name);

	    acc=set.INP;

        pattern_user = pattern_normaliser(filename,smallest,biggest,acc);

        // 2024
		for (j = gt+1; j < (set.T); j++) {
        // 2024

	    inde=index(output,j);

	    select=(unsigned int)(*(output+inde));
		
	    // 2024
		theName = take_a_filename(buff[inde + 1], string, select, j);
		
		strcpy(theMismatchFilename, theName);
		// 2024
		
	    acc=set.INP;

        pattern_detector = pattern_normaliser(theMismatchFilename, smallest, biggest, acc);


	   if(gt!=j){

		  
	   k2=-1;
	   alt=-1;

       do{

	   k2++;

       if( k2<((set.INP)+1) ){

       if( (*(pattern_user+k2) ) == (*(pattern_detector+k2) ) ){

       alt=alt+1;
							       
	   }  //if
		
	   }   //if

	 }while(k2<((set.INP)+1));

	if(alt==(set.INP)){

    // 2024	
	printf("WARNING!! %s is MISMATCHING  %s \n", filename, theMismatchFilename);
	// 2024

	for(k2=0;k2<((set.INP)+1);k2++){

	printf("IO=%lf   IO=%lf\n",*(pattern_user+k2), *(pattern_detector+k2));
				}
	printf("press enter to quit\n");
	
	while (!_kbhit());
	// 2024
	char QuitProgram = _getch();
	// 2024
	
	// 2025
	free(pattern_user);
	free(pattern_detector);
	// 2025

	exit(0);

	}  //if alt==inp

	}  //if gt!=j

	} //for j

	} // for gt

	

	printf("No mismatching cases found\n");
	printf("press enter to START THE LEARNING PROCESS\n");
	while (!_kbhit());
	// 2024
	char startLearningProcess = _getch();
	// 2024


	    acc=set.INP;
	    ju=set.OUT_T;
	    ru=set.RATE;
	    su=set.SMOOF;

     ///////////////One hidden layer network//////////////

	first_layer_connections =
	first_layer_random_weigth_generator(acc,HID);

	second_layer_connections =
	second_layer_random_weigth_generator(HID,ju);

	first_layer_change = first_layer_weigth_change(acc,HID);

	second_layer_change = second_layer_weigth_change(HID,ju);


	def1 = correction_allocator(HID,acc);

	def2 = correction_allocator(HID,ju);

	do{

		gt=0;
		erro=0.0;


	transit1 = correction_allocator(HID,acc);

	transit2 = correction_allocator(HID,ju);

	do{


	inde=index(output,gt);

	select=(unsigned int)(*(output+inde));

	name=take_a_filename(buff[inde+1],string,select,gt);

	strcpy(filename,name);

	pattern_user = pattern_normaliser(filename,smallest,biggest,acc);

	transfer_hidden = output_nodes_producer(first_layer_connections,
	pattern_user,HID, acc);

	*(transfer_hidden)= 1.0 ;

	function_net1 = F_net (transfer_hidden,HID);

	transfer_output =
	output_nodes_producer(second_layer_connections,
	transfer_hidden,ju, HID);


	function_net2 = F_net (transfer_output, ju);

	delta2_store = delta2(output,transfer_output,function_net2,ju,inde);

	corr2 = second_layer_correction_calculator(delta2_store,
		transfer_hidden,HID,ju);


	for(k4=0;k4<((HID)+1);k4++){

		  for(k6=1;k6<((set.OUT_T)+1);k6++){

			   k1 = ((k4*(set.OUT_T))+k6);

      *(transit2 + k1) =( ( *(transit2 +k1) ) + ( *(corr2 + k1) ) );

						  }

						}
	     free(corr2);

	delta1_store = delta1(delta2_store,second_layer_connections,
			      function_net1,HID,ju);

	corr1 =  first_layer_correction_calculator(delta1_store,
		 pattern_user,HID,acc);

	for(k4=1;k4<((HID)+1);k4++){

		   for(k6=0;k6<((set.INP)+1);k6++){

		    k1 = ( ((k4-1)*((set.INP)+1)) + k6 );

	  *(transit1 + k1) =( ( *(transit1 +k1) ) + ( *(corr1 + k1) ) );

						    }

					     }
	      free(corr1);


       erro = erro + error_calculator(transfer_output,output,ju,inde);


	free (pattern_user);
	free (transfer_hidden);
	free (transfer_output);
	free (function_net1);
	free (function_net2);
	free (delta2_store);
	free (delta1_store);


	gt++;

	}while(gt<(set.T)) ;


	     counter++;

	  if(counter>(set.ITE))
	  {

		  printf("ERROR=%lf\n",(erro*0.5));
		  counter=0;
		  count++;
	  }


		for(k4=1;k4<((HID)+1);k4++){

		   for(k1=0;k1<((set.INP)+1);k1++){


			 k6=(k1 +(((set.INP)+1)*(k4-1)) );

		*(def1 + k6) = *(first_layer_connections + k6);

						   }

					    }



	   for(k1=0;k1<((HID)+1);k1++){

		 for(k4=1;k4<((set.OUT_T)+1);k4++){

		     k6=( (k4-1) + (k1*(set.OUT_T)) );

	      *(def2 + k6) = *(second_layer_connections + k6);

						 }

					   }

  if(HID==1){

       transit3 = second_layer_weight_adjustment(transit2,
		  second_layer_change,ru,su,HID,ju);

	   for (k1 = 0; k1 < ((HID)+1); k1++) {

		   for (k6 = 1; k6 < ((set.OUT_T) + 1); k6++) {

			   k4 = ((k6 - 1) + (k1 * (set.OUT_T)));


			   *(second_layer_connections + k4) = ((*(def2 + k4)) + (*(transit3 + k4)));

		   }

	   }
	   free(transit3);
	
  }

  if(HID>1){

       transit3 = new_second_layer_weight_adjustment(transit2,
		  second_layer_change,ru,su,re_learn,HID,ju);

	   for (k1 = 0; k1 < ((HID)+1); k1++) {

		   for (k6 = 1; k6 < ((set.OUT_T) + 1); k6++) {

			   k4 = ((k6 - 1) + (k1 * (set.OUT_T)));


			   *(second_layer_connections + k4) = ((*(def2 + k4)) + (*(transit3 + k4)));

		   }

	   }
	   free(transit3);

	}



		


      if(HID==1){

      transit4 =  first_layer_weight_adjustment(transit1,
		  first_layer_change,ru,su,HID,acc);

	  for (k6 = 1; k6 < ((HID)+1); k6++) {

		  for (k1 = 0; k1 < ((set.INP) + 1); k1++) {


			  k4 = (k1 + (((set.INP) + 1) * (k6 - 1)));


			  *(first_layer_connections + k4) = ((*(def1 + k4)) + (*(transit4 + k4)));

		  }

	  }

	  free(transit4);

	  }

      if(HID>1){

      transit4 =  new_first_layer_weight_adjustment(transit1,
		  first_layer_change,ru,su,re_learn,HID,acc);
		
	  for (k6 = 1; k6 < ((HID)+1); k6++) {

		  for (k1 = 0; k1 < ((set.INP) + 1); k1++) {


			  k4 = (k1 + (((set.INP) + 1) * (k6 - 1)));


			  *(first_layer_connections + k4) = ((*(def1 + k4)) + (*(transit4 + k4)));

		  }

	  }

	  free(transit4);

	  }



	   for(k1=0;k1<((HID)+1);k1++){

		 for(k3=1;k3<((set.OUT_T)+1);k3++){

			     k2=((k1*(set.OUT_T))+k3);

			    *(second_layer_change+k2) = *(transit2+k2);


						 }

		}

	free(transit2);


	      for(k3=1;k3<((HID)+1);k3++){

		       for(k1=0;k1<((set.INP)+1);k1++){

		 
				   k6=(k1 +(((set.INP)+1)*(k3-1)) );

	     
				   *(first_layer_change + k6) = *(transit1 + k6);

						       }

		   }
	   
		  free(transit1);

	     if(  (count>=set.CONV)
		)
	     {
	     count=0;


	     if(//1

	HID < ( (unsigned int)(2*sqrt( (double) (set.INP)+(set.OUT_T) ) ) )

	       )//1
	      {  //if

     do{

	printf("\n");
	printf("YOU CAN INTERACT with the LEARNING PROCESS\n");
	printf("DIGIT Y to ADD a NEURON to the NETWORK\n");
	printf("DIGIT N to NOT CHANGE the NETWORK ARCHITECTURE\n");
	printf("DIGIT S to STOP The LEARNING PROCESS\n");

	what_to_do = _getche();
	what_to_do = toupper(what_to_do);

	printf("\n");

       }while( (what_to_do!='Y')&&(what_to_do!='N')&&(what_to_do!='S') );


     switch(what_to_do){

	  case 'Y':
	  printf("\n");


	HID = HID+1;

	printf("A NEURON IS ADDED TO THE HIDDEN LAYER\n");
	printf("%u neurones are in the HIDDEN LAYER\n",HID);

	printf("How many previous neurones want you relearn?\n");
	
	printf("Please select between %u and %u neurones\n", 0, (HID-1) );

	returnValue = scanf("%u",&k1);
	
	if ( k1 >= 0 && k1 <= (HID-1) ) re_learn = unsigned int(HID-k1);
	
	else
	{

		printf("The number of neurones you have selected to re-learn is not acceptable\n");

		free(second_layer_change);
		free(first_layer_change);
		free(def1);
		free(first_layer_connections);
		free(def2);
		free(second_layer_connections);

		delete biggest;
	    delete smallest;

		printf("Please press enter to Exit\n");
	    while (!_kbhit());
	    // 2024
		char endLearningProcess = _getch();
		// 2024

	    exit(0);
		
	}


	 if ((inout = (double  *) calloc( ((acc+1)*(HID+2)),sizeof(double)) ) == NULL)
	{
   
		printf("Not enough memory to allocate buffer first_layer\n");
		
		exit(1);

	} 
	 
	 for(j=1;j<HID;j++){

		   for(i=0;i<acc+1;i++){

		   k6=( i+ ((acc+1)*(j-1)) );

		*(inout + k6) = 	*(first_layer_connections + k6);
				     
		   }
			
	 }
	
	 free(first_layer_connections);


 if ((first_layer_connections = (double  *) calloc( ((acc+1)*(HID+2)),sizeof(double)) ) == NULL)
 {
   printf("Not enough memory to allocate buffer first_layer\n");

   exit(1);
 }     
 
		for(j=1;j<HID;j++){

		   for(i=0;i<acc+1;i++){

		   k6=( i+ ((acc+1)*(j-1)) );

		*(first_layer_connections + k6) = *(inout + k6);
				     
		   }
			
		}

	    for(j=re_learn;j<=HID;j++){

		   for(i=0;i<acc+1;i++){

		   k6=( i+ ((acc+1)*(j-1)) );

		   *(first_layer_connections + k6)= 0;

				     }
		
		}

		 for(j=1;j<HID;j++){

		   for(i=0;i<acc+1;i++){

		   k6=( i+ ((acc+1)*(j-1)) );

		 *(inout + k6) = *(first_layer_change + k6);

				       }
		
		 }

		
		 free(first_layer_change);


 if ((first_layer_change = (double  *) calloc( ((acc+1)*(HID+2)), sizeof(double)) ) == NULL)
 {
   printf("Not enough memory to allocate buffer first_layer_change\n");

   exit(1);

 }                  
 
 
      for(j=1;j<HID;j++){

	   for(i=0;i<acc+1;i++){

		   k6=( i+ ((acc+1)*(j-1)) );

		   *(first_layer_change + k6) = *(inout + k6);

				       }
				       
      }

		for(j=re_learn;j<=HID;j++){

		  for(i=0;i<acc+1;i++){

		  k6=( i+ ((acc+1)*(j-1)) );

		  *(first_layer_change+k6) = 0.0;

				       }
					     
		}


		for(j=1;j<HID;j++){

		   for(i=0;i<acc+1;i++){

		   k6=( i + ((acc+1)*(j-1)) );

		   *(inout + k6)= *(def1 + k6);
			
		   }
			
		}
			  
		free(def1);


  if ((def1 = (double  *) calloc((acc+1)*(HID+2), sizeof(double)) ) == NULL)
  {
   printf("Not enough memory to allocate buffer corrections\n");

	exit(1);
   
  }
		    
  for(j=1;j<HID;j++){

	   for(i=0;i<acc+1;i++){

		   k6=( i+ ((acc+1)*(j-1)) );

		*(def1+k6) = *(inout + k6);
				     
	   }
		
  }


  for(j=re_learn;j<=HID;j++){

	  for(i=0;i<acc+1;i++){

		   k6=( i+ ((acc+1)*(j-1)) );

		  *(def1+k6)= 0.0;
				     
	  }
		
  }
	
  free(inout);

  if ((inout = (double  *) calloc( ((ju+1)*(HID+2)),sizeof(double)) ) == NULL)
  {
   printf("Not enough memory to allocate buffer second_layer\n");

   exit(1);

  }

  for(i=0;i<HID;i++){

	   for(j=1;j<ju+1;j++){

		   k6=( (j-1) + (i*ju) );

		   *(inout + k6)=
		   *(second_layer_connections + k6);

	
	   }
		
  }
	
  free(second_layer_connections);


 if ((second_layer_connections = (double  *) calloc( ((ju+1)*(HID+2)),sizeof(double)) ) == NULL)
 {
   printf("Not enough memory to allocate buffer second_layer\n");

   exit(1);
 }

 for(i=0;i<HID;i++){

	for(j=1;j<ju+1;j++){

		   k6=( (j-1) + (i*ju) );

		   *(second_layer_connections + k6)=
		   *(inout + k6);
	}
	
 }

     for(i=re_learn;i<=HID;i++){

	   for(j=1;j<ju+1;j++){

		       k6=( (j-1) + (i*ju) );

		   *(second_layer_connections + k6)=0;

				    }
	
	 }


	 for(i=0;i<HID;i++){

		   for(j=1;j<ju+1;j++){

		   k6=( j + (i*ju) );

		   *(inout + k6)=*(second_layer_change + k6);

				       }
				     
	 }
	
	 free(second_layer_change);



 if ((second_layer_change = (double  *) calloc( ((ju+1)*(HID+2)), sizeof(double)) ) == NULL)
 {
   printf("Not enough memory to allocate buffer second_layer_change \n");

	exit(1);
 }       
 
 for(i=0;i<HID;i++){

	 for(j=1;j<ju+1;j++){

		   k6=( j + (i*ju) );

		   *(second_layer_change + k6)=
		   *(inout + k6);
			       
	 }
				       
 }

 for(i=re_learn;i<=HID;i++){

		 for(j=1;j<ju+1;j++){

		     k6=( j + (i*ju) );

		     *(second_layer_change+k6)=0.0;
				      
		 }
		
 }


  for(i=0;i<HID;i++){

	for(j=1;j<ju+1;j++){

	   k6=( (j-1) + (i*ju) );

		*(inout + k6)=
		*(def2 + k6);
	
	}
	
  }
	
  free(def2);

  if ((def2 = (double  *) calloc((ju+1)*(HID+2), sizeof(double)) ) == NULL)
   {
   
	   printf("Not enough memory to allocate buffer corrections\n");

	   exit(1);
   
  }
	for(i=0;i<HID;i++){

		for(j=1;j<ju+1;j++){

		   k6=( (j-1) + (i*ju) );

		*(def2 + k6)=
		*(inout + k6);
				     
		}
		
	}


    for(i=re_learn;i<=HID;i++){

	   for(j=1;j<ju+1;j++){

		     k6=( (j-1) + (i*ju) );

		  *(def2 + k6)= 0.0;
	
	   }
		
	}

	
	free(inout);

	  case 'N':
	  continue;

	  case 'S':
	  continue;


     }  //switch

	   }  //if  <


	     if(//1

	HID >=( (unsigned int)(2*sqrt( (double) (set.INP)+(set.OUT_T) ) ) )

	       )//1
	      {  //if

     do{

     printf("\n");
     printf("YOU CAN INTERACT with the LEARNING PROCESS\n");
     printf("DIGIT Y to continue the learning process\n");
     printf("DIGIT S to STOP The LEARNING PROCESS\n");
     what_to_do = _getche();
     what_to_do = toupper(what_to_do);
     printf("\n");

       }while( (what_to_do!='Y')&&(what_to_do!='S') );


     switch(what_to_do){

	  case 'Y':
	  continue;

	  case 'S':
	  continue;

		       }  //switch

	   }  //if >=

	 }  //if  count


	 }while( (what_to_do!='S') && ((erro*0.5)>=(set.TOLL))

		); //while


	printf("THE NETWORK REACHED THE REQUESTED MINIMUM\n");
	printf("THE HIDDEN LAYER HAS %u NEURONES\n",HID);
	printf("press enter to save RESULTS\n");
	while(!_kbhit());
	// 2024
	char saveData = _getch();
	// 2024


	free( output );

	free( first_layer_connections );
	free( second_layer_connections);
	free( first_layer_change );
	free( second_layer_change);


    if( (first_layer_connections_saver(def1,HID,acc) ) == 1 ){

    printf("FIRST LAYER WEIGHT SAVED\n");

					 }  else    {

    printf(" WARNING FIRST LAYER WEIGHT NOT SAVED \n");

						     }

    if( (second_layer_connections_saver(def2,HID,ju) ) == 1 ){

    printf("SECOND LAYER WEIGHT SAVED\n");

					 }  else     {

    printf(" WARNING SECOND LAYER WEIGHT NOT SAVED \n");

						     }

    if( ( range_saver(biggest,smallest,acc) ) == 2 ){

    printf("RANGE FOR NORMALISATION SAVED\n");

					 }  else     {

    printf("WARNING RANGE FOR NORMALISATION NOT SAVED \n");

						      }

	printf("press enter to quit\n");
	// 2024
	char ExitTheProgram = _getch();
	// 2024


	free(def1);
	free(def2);
	// 2024
	delete [] biggest;
	delete [] smallest;
	// 2024

} //end of main//



double  *  pattern_handler(char filename[PATH],unsigned int x)
{

     FILE *pf;
     unsigned int k2;
     double number;
     double   *pointer;

    if ((pointer = (double  *) calloc( (x+1),sizeof(double)) ) == NULL)
	{
  
		printf("Not enough memory to allocate buffer pattern\n");
		exit(1);
	}



	if ((pf = fopen(filename,"rb"))==NULL)
	{
	 printf("Cannot open file %s\n",filename);
	 free(pointer);
	 exit(1);

	}


	 *(pointer) = 1.0;

	 for(k2=1;k2<x+1;k2++){

	 fread(&number, 1,sizeof(double), pf);

	 *(pointer+k2)=number;

			      }
	 fclose (pf);

	 return pointer;
       
}  //end of func


double  * make_desidered_output(int q, int  * op)
{

      double  * y_output;
      int k5,k1,as;
      int k2;



 if ((y_output = (double  *) calloc( (q*q)+(q+1),sizeof(double)) ) == NULL)
 {
   printf("Not enough memory to allocate buffer y_output\n");

   exit(1);
  }

	*(y_output)=*(op);


	 for(k5=1;k5<=q;k5++){

	 *(y_output+k5) = ( (*(op+k5)) + (*(y_output+k5-1)) );

			     }

	 k5=0;

	 for(k2=0;k2<q;k2++){

	 k5++;

	 for(k1=0;k1<q;k1++){


	 as=(q+1)+k1+(k2*q);

	 if( k1==(k5-1) ) {

	 *(y_output+as)=1.0;

				   } else  *(y_output+as)=0.0;

			     }

			     }


	return  y_output;
 }//end of func


double     normalise(double value, double min, double max)
{
	// 2025
	if( ((double)max-min) != 0.0 )
	
		return (value - min)/(max - min);
	
	else return (double)0.0;
	// 2025
}


 double  * first_layer_random_weigth_generator(unsigned int r,unsigned int v)
 {

	double  * first_layer;
	double s;
	unsigned int k6,i,j;

 if ((first_layer = (double  *) calloc( ((r+1)*(v+1)),sizeof(double)) ) == NULL)
 {
    printf("Not enough memory to allocate buffer first_layer\n");
	exit(1);
 
 }

 	  int randomNumber = rand();

		   for(j=1;j<v+1;j++){
		   for(i=0;i<r+1;i++){

		   s=rand() %10;

		   k6=( i+ ((r+1)*(j-1)) );

		   *(first_layer+k6)=s*0.01;

				       }
				       }
       return  first_layer;

 }//end of funct



double  * second_layer_random_weigth_generator(unsigned int v,unsigned int q)
{

	  double  * second_layer;
	  double s;
	  unsigned int k6,i,j;

if ((second_layer = (double  *) calloc( ((q+1)*(v+1)),sizeof(double)) ) == NULL)
{
   printf("Not enough memory to allocate buffer second_layer\n");

   exit(1);
}

	  int randomNumber = rand();

		   for(i=0;i<v+1;i++){
		   for(j=1;j<q+1;j++){

		   s=rand() %10;

		   k6=( (j-1) + (i*q) );

		   *(second_layer+k6)=s*0.01;

				       }
				       }
       return  second_layer;

 }//end of funct

double  * first_layer_weigth_change(unsigned int r,unsigned int v)
{

	 double  * first_layer_change;
	 unsigned int k6,i,j;

 if ((first_layer_change = (double  *) calloc( ((r+1)*(v+1)), sizeof(double)) ) == NULL)
 {
   printf("Not enough memory to allocate buffer first_layer_change\n");

   exit(1);
 }

	for(j=1;j<v+1;j++){
	
		for(i=0;i<r+1;i++){

		   k6=( i+ ((r+1)*(j-1)) );

		   *(first_layer_change+k6)=0.0;
		
		}

		
	}
       return  first_layer_change;

 }//end of funct


double  * second_layer_weigth_change(unsigned int v,unsigned int q)
{

	double  * second_layer_change;
	unsigned int k6,i,j;

 if ((second_layer_change = (double  *) calloc( ((q+1)*(v+1)), sizeof(double)) ) == NULL)
 {
   printf("Not enough memory to allocate buffer second_layer_change \n");
   exit(1);
 }
		   for(i=0;i<v+1;i++){
		   for(j=1;j<q+1;j++){

		   k6=( j + (i*q) );

		   *(second_layer_change+k6)=0.0;

				       }
				       }
       return  second_layer_change;

 }//end of funct

double  * pattern_normaliser(char filename[], double *p1 ,double *p2 , unsigned int x)
   {
     FILE *pf;
     unsigned int k2;
     double number;
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

	    *(pattern_normalisation) = 1.0;

	    for(k2=1;k2<x+1;k2++){

	    // 2024
		returnValue = fread(&number, sizeof(double), 1, pf);
		// 2024

        *(pattern_normalisation+k2)=normalise( number,*(p1+k2),*(p2+k2) );
			
		}
       
		fclose (pf);

	    return pattern_normalisation;

  }  //end of func


double multiplier(double m)
{

    return  ( m * (1-m) );

}

double sigmoid(double input)
{

    double activate;


    activate = (double)( 1 / (1 + exp((double)-input)) );


    return activate;

}


double  * output_nodes_producer(double  * l1 , double  * l2 , unsigned int p ,unsigned int r)
{

	double  * y ;
    double top ;
    unsigned int i,j,k6;

   if ((y = (double  *) calloc( (p+1), sizeof(double)) ) == NULL)
   {
   
	   printf("Not enough memory to allocate buffer OUTPUT NODES\n");
   
	   exit(1);

   }
	   for(j=1;j<p+1;j++){

			       top=0;
	   
				   for(i=0;i<r+1;i++){
			       
					   k6=(i+((r+1)*(j-1)));
	   
					   top  = top + ( (*(l1+k6) ) * ( *(l2+i) ) );

			      }

	   *(y+j) = sigmoid( top );
			      
	   }

      return y;

   }


double  * F_net (double  * l3 ,unsigned int q)
{

    double  * f1;
    double net ;
    unsigned int j ;


   if ((f1 = (double  *) calloc( (q+1), sizeof(double)) ) == NULL)
   {
   
	   printf("Not enough memory to allocate buffer F_net\n");
	   
	   exit(1);

   }

	 for(j=1;j<q+1;j++){

	 net= *(l3+j);
	 *(f1+j) = multiplier ( net );

			   }
    return f1;

}

unsigned int index(double  * l7, unsigned int c)
{

  unsigned int i,k2;

   k2=0 ;

  for(i=0;((unsigned int)(*(l7+i)))<=c;i++){

  k2++;
				  }

   return k2-1;
   
}

double  * delta2 (double  * l4 , double  * l5 ,  double  * l6 , unsigned int q ,unsigned int b)
{

   double  *d;
   unsigned int a ,j ;

   if ((d = (double  *) calloc( (q+1), sizeof(double)) ) == NULL)
   {
   printf("Not enough memory to allocate buffer delta2\n");

   exit(1);

   }

	 for(j=1;j<q+1;j++){

			    a=(q+j+(q*b));

	*(d+j) = ( (*(l4+a)) - (*(l5+j)) ) * ( *(l6+j) );

			    }
	return d;

}

double  * correction_allocator(unsigned int r , unsigned int q)
{

	   double  * g;
	   unsigned int i;


  if ((g = (double  *) calloc((r+1)*(q+1), sizeof(double)) ) == NULL)
  {

	  printf("Not enough memory to allocate buffer corrections\n");
	  exit(1);
   
  }


   for(i=0;i<(r+1)*(q+1);i++){

   *(g+i)=0.0;
		
   }
   
   return g;   
}

double  * second_layer_correction_calculator(double  * l7, double  * l8, unsigned int r ,unsigned int q)
{
     double  * h;
     unsigned int n,i,j;

    if ((h = (double  *) calloc((r+1)*(q+1), sizeof(double)) ) == NULL)
    {
   
		printf("Not enough memory to allocate buffer corrections\n");

		exit(1);
   
	}

     for(i=0;i<r+1;i++){

	     for(j=1;j<q+1;j++){

     n = ((i*q)+j);
     
	 *(h+n) =  ( (*(l7+j) ) * ( *(l8+i) ) );
	 	
		 }

	}

    return h;

}

double  * first_layer_correction_calculator( double  * l12, double  * l13, unsigned int q ,unsigned int p)
{
     double  * k;
     unsigned int n,i,j;

   if ((k = (double  *) calloc((p+1)*(q+1), sizeof(double)) ) == NULL)
   {

   printf("Not enough memory to allocate buffer corrections\n");

   exit(1);
   
   }


     for(j=1;j<q+1;j++){

	     for(i=0;i<p+1;i++){

	 n = ( ((j-1)*(p+1)) + i );
     *(k+n) =   ( (*(l12 +j) ) * ( *(l13 +i) ) );

				}

			}

     return k;

}

double  * delta1 (double  * l9 , double  * l10 ,  double  * l11 , unsigned int q , unsigned int b)
{

   double  * e;
   unsigned int i, j, n ;
   double sop;

   if ((e = (double  *) calloc( (q+1), sizeof(double)) ) == NULL)
   {
   
	   printf("Not enough memory to allocate buffer delta1\n");
	   exit(1);
   
   }

	 for(j=1;j<q+1;j++){

			    sop=0;

	 for(i=1;i<b+1;i++){

	 n=( i + (q*(i-1)) + j - 1 );
	 sop = sop + ( ( (*(l9 + i)) * (*(l10 + n)) ) );

			    }

	  *(e+j) = sop * ( *(l11 + j) ) ;

			     }
	return e;

}

double error_calculator(double  * a1 , double  * a2, unsigned int q , unsigned int b)
{

     unsigned int i,w;
     double fog;

     fog=0;

	 for(i=1;i<q+1;i++){

	 w=(q+i+(q*b));


	 fog = fog + (   ( ( *(a1 + i) ) - ( *(a2 + w) ) )  *
			
		             ( ( *(a1 + i) ) - ( *(a2 + w) ) )   );

			   }

     return fog;

}

double  * second_layer_weight_adjustment(double  * b1, double  *b2, double r1, double s1 , unsigned int p , unsigned int q)
{
     double  * step1;

     unsigned int k1,k6,i,j;

     if ((step1 = (double  *) calloc((p+1)*(q+1), sizeof(double)) ) == NULL)
	 {
		 printf("Not enough memory to allocate buffer second adjustments\n");

		 exit(1);
   
	 }

     for(i=0;i<p+1;i++){

	     for(j=1;j<q+1;j++){
	
			 k1=((i*q)+j);
			 k6= k1-1;

			  *(step1+k6) =  ( (r1 * (*(b1+k1) ) )  +   (s1 * (*(b2+k1) ) ) );

					}

			}

return step1;

}

double  * new_second_layer_weight_adjustment( double  * b1,	double  * b2, double r1, double s1 ,unsigned int f, unsigned int p ,unsigned int q )
{
     double  * step1;

     unsigned int k1,k6,i,j;

     if ((step1 = (double  *) calloc((p+1)*(q+1), sizeof(double)) ) == NULL)
	 {
   
		 printf("Not enough memory to allocate buffer second adjustments\n");
		  exit(1);
   
	 }

     for(i=0;i<p;i++){

	     for(j=1;j<q+1;j++){

			 k1=((i*q)+j);
				 
			 k6= k1-1;

			*(step1+k6) =0.0;
			
		 }

		
	 }
	
	 for(i=f;i<=p;i++){

		 for(j=1;j<q+1;j++){

				 k1=((i*q)+j);
				 k6= k1-1;

				 *(step1+k6) =  ( (r1 * (*(b1+k1) ) )  +   (s1 * (*(b2+k1) ) ) );
				
		 }
		
	 }


return step1;

}


double  * first_layer_weight_adjustment(double  * b4, double  *b5, double r1, double s1 , unsigned int p ,unsigned int r)
{
     double  * step2;

     unsigned int k6,i,j;

     if ((step2 = (double  *) calloc((r+1)*(p+1), sizeof(double)) ) == NULL)
     {
   
		 printf("Not enough memory to allocate buffer first adjustments\n");
		 exit(1);
   
	 }


	     for(j=1;j<p+1;j++){

		 for(i=0;i<r+1;i++){

				    k6=(i + ((r+1)*(j-1)) );

	*(step2+k6) =  ( (r1 * (*(b4+k6) ) ) +

				   (s1 * (*(b5+k6) ) ) );

				    }


				}

     return step2;

}


double  * new_first_layer_weight_adjustment( double  * b4, double  *b5, double r1, double s1 ,unsigned int f,unsigned int p ,unsigned int r)
{
     double  * step2;

     unsigned int k6,i,j;

     if ((step2 = (double  *) calloc((r+1)*(p+1), sizeof(double)) ) == NULL)
     {
   
		 printf("Not enough memory to allocate buffer first adjustments\n");
		 exit(1);
   
	 }
	
	 for(j=1;j<p;j++){

		 for(i=0;i<r+1;i++){

		     k6=(i + ((r+1)*(j-1)) );

			 *(step2+k6) = 0.0;

			 
		 }

	 }

		  for(j=f;j<=p;j++){

		    for(i=0;i<r+1;i++){

		    k6=(i + ((r+1)*(j-1)) );

   *(step2+k6) =  ( (r1 * (*(b4+k6) ) ) +  (s1 * (*(b5+k6) ) ) );

				       }
				    }
	return step2;

}


unsigned int  first_layer_connections_saver( double  * x1, unsigned int p, unsigned int q )
{

	unsigned int j , k1, ok, k6;
	FILE * sl;

	if ((sl = fopen("WEIGHT1.txt","w+"))==NULL)

	{

	ok = 0 ;

	}
	else {

		ok = 1;

		for (j = 1; j < p + 1; j++) {

			for (k1 = 0; k1 < q + 1; k1++) {

				k6 = (k1 + ((q + 1) * (j - 1)));

				if (sl != NULL) int returnValue = fprintf(sl, "%lf\n", *(x1 + k6));

			}

		}
	
		if (sl != NULL) int returnValue = fclose(sl);

	}
    return ok;

}

unsigned int  second_layer_connections_saver( double  * x2, unsigned int r, unsigned int v )
{

	unsigned int j , k1, ok, k6;
	FILE * sl;


	if ((sl = fopen("WEIGHT2.txt","w+"))==NULL)

	{

	ok = 0 ;

	}
	else {

		ok = 1;


		for (k1 = 0; k1 < r + 1; k1++) {

			for (j = 1; j < v + 1; j++) {


				k6 = ((j - 1) + (k1 * v));

				if (sl != NULL) int returnValue = fprintf(sl, "%lf\n", *(x2 + k6));

			}

		}
	
		if (sl != NULL) int returnValue = fclose(sl);

	}

    return ok;

}

char * take_a_filename(char selector[], char current_dir[], unsigned int r, unsigned int p)
{

     char klf[80];
    
	 char s1[5]="\\";
     char * a;
     char * b;
     unsigned int stop=0,stop1;
     
	
	 // 2024
	 char * TheNameOfTheFile = 0;

	 TheNameOfTheFile = (char*)calloc(80, sizeof(char));
	 
	 
	 if ( TheNameOfTheFile == NULL )
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

	   b = selector;

	   while (stop == 0) {

		   if ((ent = readdir(dir)) != NULL)
		   {

			   a = ent->d_name;

			   if ((strstr(a, b)) != NULL)
			   {

				   stop = 1;


			   }
		   }
	   }


	   stop1 = 1;


	   while (stop1 <= (p - r)) {

		   if ((ent = readdir(dir)) != NULL)
		   {

			   a = ent->d_name;

			   if ((strstr(a, b)) != NULL)
			   {

				   stop1++;

			   }


		   }


	   }


	   // 2024
	   if (ent != NULL)
	   {
		   strcat(klf, ent->d_name);

		   sprintf(TheNameOfTheFile, "%s", klf);
	   }
	   // 2024

	  if (closedir(dir) != 0)
	  {

			perror("Unable to close directory");

	  }

		return TheNameOfTheFile;
		// 2024
  
   } // else

  }

int * set_learning_variables(char path_store[80])
 {

    FILE* sc;

	  char first_file[80];
	  unsigned int k1 = 0, l;
	  double cs;
	  unsigned int  k2 = 0;
	  char s1[5] = "\\";
	  

	  DIR* dir;
	  struct dirent* ent;

	
	  if ((dir = opendir(path_store)) == NULL)
	  {

		  perror("Unable to open directory");

		  exit(1);

	  }

	  for (l = 1; l <= 3; l++) {


		  if ((ent = readdir(dir)) != NULL)
		  {


			  if (l == 3) {

				  cout << "\n" << endl;

				  cout << "FIRST FILE OF THE LIST: " << ent->d_name << endl;

				  k2++;
			  }

		  }
		  else {

			  cout << "cannot find FIRST FILE of the list " << endl;
			  exit(1);

		  }
	  }

	  strcpy(first_file, path_store);

	  strcat(first_file, s1);

	  strcat(first_file, ent->d_name);

	  cout << "entry: " << first_file << endl;


	  if ((sc = fopen(first_file, "rb")) == NULL) {

		  cout << "cannot open first file of the list" << endl;

		  exit(1);

	  }
	  else { // 2024

		  
		  int ReadTheValue = 1;

		  while ( ReadTheValue != 0 ) {

			  ReadTheValue = fread(&cs, sizeof(double), 1, sc);

			  if ( ReadTheValue != 0 ) k1++;		  

		  }

	  } // 2024

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

   cout << "LEARNING PATTERNS = " << k2 << endl;

   set.T=k2;

   // 2024
   cout << "INSERT number of classes to discriminate (OUTPUT NEURONS)" << endl;
   // 2024

   cin >> k1;

   set.OUT_T=k1;

   // 2025
   int * dimension = 0;
   if (!(dimension= new int[(k1+1)*sizeof(int)]))
   {
   cout << "Not enough memory to allocate output limits" << endl;
   exit(1);
   }

   *(dimension)=0;
   // 2025

    for(l=1;l<=k1;l++){

   printf("\n");

   printf("INSERT file extention of %d class [ . ,letter, number]\n",l);

   returnValue = scanf("%s",&buff[l][0]);

   *(dimension+l) = find_requested_files(buff[l],path_store);

   printf("\n");
   printf("%d FILES FOUND\n",(int)(*(dimension+l)));
   printf("\n");

		     }


  HID=1;

  cout << "INSERT LEARNING RATE [0...1]" << endl;
  cin >> cs;
  set.RATE=cs;

  cout << "INSERT SMOOTHING FACTOR [0...1]" << endl;
  cin >> cs;
  set.SMOOF=cs;

  cout << "INSERT LEARNING PROCESS TOLERANCE"  << endl;
  cin >> cs;
  set.TOLL=cs;

  cout << "INSERT ITERATION COUNTER VALUE (integer)" << endl;
  cin >> k1;
  set.ITE=k1;

  cout << "INSERT LEARNING PROCESS CONVERGENCE CHECK VALUE (integer)" << endl;
  cin >> k1;
  set.CONV=k1;


  printf("CHECK if the learning set is currently correct\n");
  printf("\n");

  printf("T=%u\n",set.T);
  printf("INP=%u\n",set.INP);
  printf("HID=%u\n",HID);
  printf("OUT=%u\n",set.OUT_T);
  printf("RATE=%lf\n",set.RATE);
  printf("SMOOF=%lf\n",set.SMOOF);
  printf("TOLL=%lf\n",set.TOLL);
  printf("ITE=%u\n",set.ITE);
  printf("CONV=%u\n",set.CONV);
  printf("\n");

  return dimension;

 }

unsigned int find_requested_files(char selector[10], char current_dir[80])
{

     unsigned int  k3=0;
     const char * a;
     const char * b;

     DIR *dir;
     struct dirent *ent;



	   if ((dir = opendir(current_dir)) == NULL)
	   {

	    perror("Unable to open directory");
	    exit(1);

	   }else{

		b=selector;

		while ((ent = readdir(dir)) != NULL)
		{

		a=ent->d_name;

		if( (strstr(a,b))!=NULL ){


		k3++;
		cout << "" << ent->d_name << endl;

					    }
		}

		}

   if (closedir(dir) != 0)
   {

   perror("Unable to close directory");

   }
     cout << " \n" << endl;
     cout <<"FILES FOUND: " << k3 << endl;

     return k3;

 }

unsigned int range_saver(double * f1 , double * f2 , unsigned int r)
{

	unsigned int ok = 0, j;
	FILE * sl = NULL, * ls = NULL;

	sl = fopen("BIGGEST.txt", "w+");

	if (sl != NULL)
	{

	ok += 1;


	for (j = 1; j < r + 1; j++) {

		if (sl != NULL) {
			if ((returnValue = fprintf(sl, "%lf\n", *(f1 + j))) == 0) {}
	}

		}

	if (sl != NULL) {
		if ((returnValue = fclose(sl)) == 0) {}
	}

	}

	ls = fopen("SMALLEST.txt", "w+");

	if (ls != NULL)
	{

		ok += 1;


		for (j = 1; j < r + 1; j++) {

			if (ls != NULL) {
				if ((returnValue = fprintf(ls, "%lf\n", *(f2 + j))) == 0) {}
			}

		}

		if (ls != NULL) {
			if ((returnValue = fclose(ls)) == 0) {}
		}

	}

    return ok;

  }