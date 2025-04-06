#define _CRT_SECURE_NO_WARNINGS

//  Project Title: 2x2x2 Neural Network Calculator

#include <iostream>
#include <fstream>
#include <string>
#include <io.h>
#include <dos.h>
#include <conio.h>
#include <stdlib.h>
#include <sstream>
#include <stdio.h>
#include <iomanip>
#include <istream>
#include <math.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char* argv[]) {

	char outputFile[128] = "net2025v3.log";

	FILE* savedata;

	if (argc < 7) {
		std::cout << endl;
		std::cout << "Please type the image file name - Class 1: Make sure it is a 2x1 file" << endl;
		std::cout << "Please type the image file name - Class 2: Make sure it is a 2x1 file" << endl;
		std::cout << "Please make sure that the Data format is 'double': 64 bits real" << endl;
		std::cout << "Please enter the learning rate (double) in ]0, 0.99]" << endl;
		std::cout << "Please enter the number of iterations (integer): 1000 maximum" << endl;
		std::cout << "Please enter the smoothing factor (double) in ]0, 0.99]" << endl;
		std::cout << "Please enter the random value of the initial wighting connections " << endl;
		std::cout << endl;
		exit(0);
	}

	else { // run the program (begin)


		if ((savedata = fopen(outputFile, "w")) == NULL)
		{

			std::cout << "Cannot open output file, Now Exit..." << endl;
			exit(0);

		}
		else { // processing (begin)

			int n1 = 2;
			int n2 = 2;

			char fileNameX1[328];
			char fileNameX2[328];

			double learningRate = atof(argv[3]);
			int nofIterations = atoi(argv[4]);
			double smoothingFactor = atof(argv[5]);

			double randomValue = atof(argv[6]);

			sprintf(fileNameX1, "%s", argv[1]);
			sprintf(fileNameX2, "%s", argv[2]);

			
			std::cout << endl;
			std::cout << "The File name of Class 1 is: " << fileNameX1 << endl;
			std::cout << "The File name of Class 2 is: " << fileNameX2 << endl;
			std::cout << "The learning rate is: " << learningRate << endl;
			std::cout << "The number of iterations is: " << nofIterations << endl;
			std::cout << "The smoothing factor is: " << smoothingFactor << endl;
			std::cout << "The random value of the initial wighting connections is: " << randomValue << endl;
		
			fprintf(savedata, "%s%s\n", "The File name of Class 1 is: ", fileNameX1);
			fprintf(savedata, "%s%s\n", "TThe File name of Class 2 is: ", fileNameX2);
			fprintf(savedata, "%s%lf\n", "The learning rate is: ", learningRate);
			fprintf(savedata, "%s%d\n", "The number of iterations is: ", nofIterations);
			fprintf(savedata, "%s%lf\n", "The smoothing factor is: ", smoothingFactor);
			fprintf(savedata, "%s%lf\n", "The random value of the initial wighting connections is: ", randomValue);

			if ((double)learningRate <= 0.0 || (double)learningRate > 0.99)
			{

				std::cout << "Please enter the learning rate (double) in ]0, 0.99]" << endl;
				exit(0);

			}

			if ((double)nofIterations <= 0 || (double)nofIterations > 1000)
			{

				std::cout << "Please enter the number of iterations (integer): 1000 maximum" << endl;
				exit(0);

			}

			if ((double)smoothingFactor <= 0.0 || (double)smoothingFactor > 0.99)
			{

				std::cout << "Please enter the smoothing factor (double) in ]0, 0.99]" << endl;
				exit(0);

			}

			double i11 = 0.0, i12 = 0.0, i21 = 0.0, i22 = 0.0;

			/// read image file (begin)
			FILE* pf;

			if ((pf = fopen(fileNameX1, "rb+")) == NULL)
			{

				std::cout << "Cannot open file: " << fileNameX1 << endl;
				fprintf(savedata, "%s%s\n", "Cannot open file: ", fileNameX1);
				
				exit(0);

			}
			else { // else

						fread(&i11, sizeof(double), 1, pf);
						fread(&i12, sizeof(double), 1, pf);
				
				fclose(pf);


			} // else 
			/// read file (end)

			if ((pf = fopen(fileNameX2, "rb+")) == NULL)
			{

				std::cout << "Cannot open file: " << fileNameX2 << endl;
				fprintf(savedata, "%s%s\n", "Cannot open file: ", fileNameX2);
				
				exit(0);

			}
			else { // else

						fread(&i21, sizeof(double), 1, pf);
						fread(&i22, sizeof(double), 1, pf);

			     fclose(pf);

			} // else 
			/// read file (end)

			std::cout << "Data loaded" << endl;


			// initialize threshold logic units
			double b1 = 0.0;
			double b2 = 0.0;
			double b3 = 0.0;
			double b4 = 0.0;
			double pb1 = 0.0;
			double pb2 = 0.0;
			double pb3 = 0.0;
			double pb4 = 0.0;

			// initialize to zeros
			double H11 = 0.0, H12 = 0.0;
			double H21 = 0.0, H22 = 0.0;

			double O11 = 0.0, O12 = 0.0;
			double O21 = 0.0, O22 = 0.0;
			
			double EofFit = (double)0.0;

			double sum1 = (double)0.0;
			double sum2 = (double)0.0;

			double w1 = randomValue, w2 = randomValue, w3 = randomValue, w4 = randomValue; 
			double w5 = randomValue, w6 = randomValue, w7 = randomValue, w8 = randomValue; 
			double pw1 = randomValue, pw2 = randomValue, pw3 = randomValue, pw4 = randomValue; 
            double pw5 = randomValue, pw6 = randomValue, pw7 = randomValue, pw8 = randomValue; 

			// learning process (begin)
			for (int counter = 1; counter <= nofIterations; counter++)
			{

				EofFit = 0;

				// compute the Network input-output - Image 1 - (begin)
				double h11 = (double)0.0;
				double h12 = (double)0.0;

				
						h11  = (double)i11 * (double)w1 +
							   (double)i12 * (double)w2;

						h12  = (double)i11 * (double)w3 +
						 	   (double)i12 * (double)w4;
				

				h11 = h11 + b1;
				h12 = h12 + b2;

				H11 = (double)1.0 / ((double)1.0 + (double)exp(-(double)h11));
				H12 = (double)1.0 / ((double)1.0 + (double)exp(-(double)h12));


				if ((_isnan((double)H11)) == 0) {}
				else {

					std::cout << "Please run again the program using less number of iterations " << endl;
					exit(0);

				}

				if ((_isnan((double)H12)) == 0) {}
				else {

					std::cout << "Please run again the program using less number of iterations " << endl;
					exit(0);

				}
				
				double net11 = (double)0.0;
				double net12 = (double)0.0;


				net11 = (double)H11 * (double)w5 +
					    (double)H12 * (double)w6;

				net12 = (double)H11 * (double)w7 +
					    (double)H12 * (double)w8;

				net11 += b3;
				net12 += b4;

				O11 = (double)1.0 / ((double)1.0 + (double)exp(-(double)net11));
				O12 = (double)1.0 / ((double)1.0 + (double)exp(-(double)net12));


				if ((_isnan((double)O11)) == 0) {}
				else {

					std::cout << "Please run again the program using less number of iterations " << endl;
					exit(0);

				}

				if ((_isnan((double)O12)) == 0) {}
				else {

					std::cout << "Please run again the program using less number of iterations " << endl;
					exit(0);

				}	
				// compute the Network input-output - Image 1 - (end)

				// compute the Network input-output - Image 2 - (begin)
				double h21 = (double)0.0;
				double h22 = (double)0.0;

				h21  =   (double)i21 * (double)w1 +
						 (double)i22 * (double)w2;

				h22  =   (double)i21 * (double)w3 +
						 (double)i22 * (double)w4;

				h21 = h21 + b1;
				h22 = h22 + b2;

				O21 = (double)1.0 / ((double)1.0 + (double)exp(-(double)h21));
				O22 = (double)1.0 / ((double)1.0 + (double)exp(-(double)h22));


				if ((_isnan((double)O21)) == 0) {}
				else {

					std::cout << "Please run again the program using less number of iterations " << endl;
					exit(0);

				}

				if ((_isnan((double)O22)) == 0) {}
				else {

					std::cout << "Please run again the program using less number of iterations " << endl;
					exit(0);

				}
				
				double net21 = (double)0.0;
				double net22 = (double)0.0;

				net21 = (double)H21 * (double)w5 +
					    (double)H22 * (double)w6;

				net22 = (double)H21 * (double)w7 +
					    (double)H22 * (double)w8;


				net21 += b3;
				net22 += b4;

				O21 = (double)1.0 / ((double)1.0 + (double)exp(-(double)net21));
				O22 = (double)1.0 / ((double)1.0 + (double)exp(-(double)net22));

				if ((_isnan((double)O21)) == 0) {}
				else {

					std::cout << "Please run again the program using less number of iterations " << endl;
					exit(0);

				}

				if ((_isnan((double)O22)) == 0) {}
				else {

					std::cout << "Please run again the program using less number of iterations " << endl;
					exit(0);

				}
				// compute the Network input-output - Image 2 - (begin)


				// compute the Network output (begin)		
				std::cout << "O11 = " << O11 << endl;
				std::cout << "O21 = " << O21 << endl;
				std::cout << "O12 = " << O12 << endl;
				std::cout << "O22 = " << O22 << endl;
				// compute the Network output (end)

				double target11 = (double)1.0;
				double target21 = (double)0.0;
				double target12 = (double)0.0;
				double target22 = (double)1.0;

				// calculate the error of fit (begin)
				EofFit = ((double)O11 - target11) * ((double)O11 - target11) +
					     ((double)O21 - target21) * ((double)O21 - target21) +
					     ((double)O12 - target12) * ((double)O12 - target12) +
					     ((double)O22 - target22) * ((double)O22 - target22);

				EofFit /= (double)0.5;

				std::cout << "EofFit = " << EofFit << endl;
				// calculate the error of fit (end)

				// save data into log file (begin)
				fprintf(savedata, "%s%lf\n", "EofFit = ", EofFit);
				fprintf(savedata, "%s%lf\n", "O11 = ", O11);
				fprintf(savedata, "%s%lf\n", "O21 = ", O21);
				fprintf(savedata, "%s%lf\n", "O12 = ", O12);
				fprintf(savedata, "%s%lf\n", "O22 = ", O22);
				// save data into log file (end)


				// adjust weigths (begin)
				double derivativeTerm_X1;
				double derivativeTerm_X2;
				double derivativeTerm_X1_X2;

		
				        // w5
						derivativeTerm_X1 = (double)0.0;
						derivativeTerm_X2 = (double)0.0;
						derivativeTerm_X1_X2 = (double)0.0;

						derivativeTerm_X1 = ((double)O11 * ((double)1.0 - O11) * ((double)O11 - target11));

						derivativeTerm_X1 *= (double)i11;

		
						derivativeTerm_X2 = ((double)O21 * ((double)1.0 - O21) * ((double)O21 - target21));

						derivativeTerm_X2 *= (double)i21;


						derivativeTerm_X1_X2 = (double)derivativeTerm_X1 + (double)derivativeTerm_X2;


						w5 += (-(double)learningRate * (double)derivativeTerm_X1_X2);

						w5 += ((double)smoothingFactor * (double)pw5);

						pw5 = (double)w5;

						
						if ( (_isnan((double)w5)) == 0 ) { } else {
				
							std::cout << "Please run again the program using less number of iterations " << endl;
							exit(0);
				
						} 

				        // w6
						derivativeTerm_X1 = (double)0.0;
						derivativeTerm_X2 = (double)0.0;
						derivativeTerm_X1_X2 = (double)0.0;

						derivativeTerm_X1 = ((double)O11 * ((double)1.0 - O11) * ((double)O11 - target11));

						derivativeTerm_X1 *= (double)i12;


						derivativeTerm_X2 = ((double)O21 * ((double)1.0 - O21) * ((double)O21 - target21));

						derivativeTerm_X2 *= (double)i22;


						derivativeTerm_X1_X2 = (double)derivativeTerm_X1 + (double)derivativeTerm_X2;


						w6 += (-(double)learningRate * (double)derivativeTerm_X1_X2);

						w6 += ((double)smoothingFactor * (double)pw6);

						pw6 = (double)w6;

						
						if ((_isnan((double)w6)) == 0) {}
						else {

							std::cout << "Please run again the program using less number of iterations " << endl;
							exit(0);

						}

						derivativeTerm_X1 = (double)0.0;
						derivativeTerm_X2 = (double)0.0;
						derivativeTerm_X1_X2 = (double)0.0;

						derivativeTerm_X1 = ((double)O12 * ((double)1.0 - O12) * ((double)O12 - target12));

						derivativeTerm_X1 *= (double)i11;


						derivativeTerm_X2 = ((double)O22 * ((double)1.0 - O22) * ((double)O22 - target22));

						derivativeTerm_X2 *= (double)i21;


						derivativeTerm_X1_X2 = (double)derivativeTerm_X1 + (double)derivativeTerm_X2;

						w7 += (-(double)learningRate * (double)derivativeTerm_X1_X2);

						w7 += ((double)smoothingFactor * (double)pw7);

						pw7 = (double)w7;

						
						if ((_isnan((double)w7)) == 0) {}
						else {

							std::cout << "Please run again the program using less number of iterations " << endl;
							exit(0);

						}

						derivativeTerm_X1 = (double)0.0;
						derivativeTerm_X2 = (double)0.0;
						derivativeTerm_X1_X2 = (double)0.0;

						derivativeTerm_X1 = ((double)O12 * ((double)1.0 - O12) * ((double)O12 - target12));

						derivativeTerm_X1 *= (double)i12;


						derivativeTerm_X2 = ((double)O22 * ((double)1.0 - O22) * ((double)O22 - target22));

						derivativeTerm_X2 *= (double)i22;


						derivativeTerm_X1_X2 = (double)derivativeTerm_X1 + (double)derivativeTerm_X2;

						w8 += (-(double)learningRate * (double)derivativeTerm_X1_X2);

						w8 += ((double)smoothingFactor * (double)pw8);

						pw8 = (double)w8;

						
						if ((_isnan((double)w8)) == 0) {}
						else {

							std::cout << "Please run again the program using less number of iterations " << endl;
							exit(0);

						}

						// adjust threshold logic unit
						derivativeTerm_X1 = ((double)O11 * ((double)1.0 - O11) * ((double)O11 - target11));

						derivativeTerm_X1 *= (double)1.0;


						derivativeTerm_X2 = ((double)O21 * ((double)1.0 - O21) * ((double)O21 - target21));

						derivativeTerm_X2 *= (double)1.0;


						derivativeTerm_X1_X2 = (double)derivativeTerm_X1 + (double)derivativeTerm_X2;


						b3 += (-(double)learningRate * derivativeTerm_X1_X2);

						b3 += ((double)smoothingFactor * pb3);

						pb3 = (double)b3;

						

						if ( (_isnan((double)b3)) == 0 ) { } else {
				
							std::cout << "Please run again the program using less number of iterations " << endl;
							exit(0);
				
						} 


						// adjust threshold logic unit
						derivativeTerm_X1 = ((double)O12 * ((double)1.0 - O12) * ((double)O12 - target12));

						derivativeTerm_X1 *= (double)1.0;


						derivativeTerm_X2 = ((double)O22 * ((double)1.0 - O22) * ((double)O22 - target22));

						derivativeTerm_X2 *= (double)1.0;


						derivativeTerm_X1_X2 = (double)derivativeTerm_X1 + (double)derivativeTerm_X2;

						b4 += (-(double)learningRate * derivativeTerm_X1_X2);

						b4 += ((double)smoothingFactor * pb4);

						pb4 = (double)b4;


						if ( (_isnan((double)b4)) == 0 ) { } else {
				
							std::cout << "Please run again the program using less number of iterations " << endl;
							exit(0);
				
						} 
						// adjust weigths (end)
			
						
						// backpropagation to hidden layer (begin)
						double deEtotal_o1 = (double)0.0;
						double deEtotal_o2 = (double)0.0;

        				// w1 -
						deEtotal_o1 = (((double)O11 - target11) * O11 * (1.0 - O11) * w5 * H11 * (1.0 - H11) * (double)i11) + 
                        // -
							          (((double)O12 - target12) * O12 * (1.0 - O12) * w7 * H11 * (1.0 - H11) * (double)i11);
													   
						// w1 -
						deEtotal_o2 = (((double)O21 - target21) * O21 * (1.0 - O21) * w5 * H21 * (1.0 - H21) *(double)i21) + 
						// -	
							          (((double)O22 - target22) * O22 * (1.0 - O22) * w7 * H21 * (1.0 - H21) * (double)i21);

						// calculation of the delta rule
						w1 += -(double)learningRate * ((double)deEtotal_o1 + deEtotal_o2);

						w1 += ((double)smoothingFactor * (double)pw1);

						pw1 = ((double)w1);

						if ( (_isnan((double)w1)) == 0 ) { } else {
				
							std::cout << "Please run again the program using less number of iterations " << endl;
							exit(0);
				
						} 

						// w2 -
						deEtotal_o1 = (((double)O11 - target11) * O11 * (1.0 - O11) * w5 * H11 * (1.0 - H11) * (double)i12) + 
						// - 
							          (((double)O22 - target22) * O22 * (1.0 - O22) * w7 * H21 * (1.0 - H21) * (double)i22);
													   
						// w2 -							  
						deEtotal_o2 = (((double)O12 - target12) * O12 * (1.0 - O12) * w7 * H11 * (1.0 - H11) * (double)i12) + 
						// -
							          (((double)O21 - target21) * O21 * (1.0 - O21) * w5 * H21 * (1.0 - H21) * (double)i22);

					    // calculation of the delta rule
						w2 += -(double)learningRate * ((double)deEtotal_o1 + deEtotal_o2);

						w2 += ((double)smoothingFactor * (double)pw2);

						pw2 = ((double)w2);


						if ( (_isnan((double)w2)) == 0 ) { } else {
				
							std::cout << "Please run again the program using less number of iterations " << endl;
							exit(0);
				
						}  

						// w3 -
						deEtotal_o1 = (((double)O12 - target12) * O12 * (1.0 - O12) * w8 * H12 * (1.0 - H12) * (double)i11)  +
						// -	
							          (((double)O22 - target22) * O22 * (1.0 - O22) * w8 * H22 * (1.0 - H22) * (double)i21);
													   

						//							  
						deEtotal_o2 = (((double)O21 - target21) * O21 * (1.0 - O21) * w6 * H22 * (1.0 - H22) * (double)i21) +
						
						// - 
						  	          (((double)O11 - target11) * O11 * (1.0 - O11) * w6 * H12 * (1.0 - H12) * (double)i11);

						// calculation of the delta rule
						w3 += -(double)learningRate * ((double)deEtotal_o1 + deEtotal_o2);

						w3 += ((double)smoothingFactor * (double)pw3);

						pw3 = ((double)w3);


						if ( (_isnan((double)w3)) == 0 ) { } else {
				
							std::cout << "Please run again the program using less number of iterations " << endl;
							exit(0);
				
						} 

						// w4 - 
						deEtotal_o1 = (((double)O12 - target12) * O12 * (1.0 - O12) * w8 * H12 * (1.0 - H12) * (double)i12) + 
						// -	          
							          (((double)O22 - target22) * O22 * (1.0 - O22) *  w8 * H22 * (1.0 - H22) * (double)i22);

						
						deEtotal_o2 = (((double)O21 - target21) * O21 * (1.0 - O21) * w6 * H12 * (1.0 - H22) * (double)i22) +
                        // -
							          (((double)O11 - target11) * O11 * (1.0 - O11) * w6 * H12 * (1.0 - H12) * (double)i12);

						// calculation of the delta rule
						w4 += -(double)learningRate * ((double)deEtotal_o1 + deEtotal_o2);

						w4 += ((double)smoothingFactor * (double)pw4);

						pw4 = ((double)w4);


				        if ( (_isnan((double)w4)) == 0 ) { } else {
				
							std::cout << "Please run again the program using less number of iterations " << endl;
							exit(0);
				
						} 

						// calculation of the chain rule b1
						// -
						deEtotal_o1 = (((double)O11 - target11) * O11 * (1.0 - O11) * w5 * H11 * (1.0 - H11) * (double)1.0) +
						// -	       
							          (((double)O21 - target21) * O21 * (1.0 - O21) * w5 * H21 * (1.0 - H21) * (double)1.0);
				
						// calculation of the delta rule
						// -
						deEtotal_o2 = (((double)O12 - target12) * O12 * (1.0 - O12) * w7 * H11 * (1.0 - H11) * (double)1.0) +
                        // -
						              (((double)O22 - target22) * O22 * (1.0 - O22) * w7 * H21 * (1.0 - H21) * (double)1.0);


						b1 += -(double)learningRate * ((double)deEtotal_o1 + deEtotal_o2);

						b1 += ((double)smoothingFactor * (double)pb1);

						pb1 = ((double)b1);


						if ( (_isnan((double)b1)) == 0 ) { } else {
				
							std::cout << "Please run again the program using less number of iterations " << endl;
							exit(0);
				
						} 

						// calculation of the chain rule b2
						//// -
						deEtotal_o1 = (((double)O11 - target11) * O11 * (1.0 - O11) * w6 * H12 * (1.0 - H12) * (double)1.0) +
                        //// -
							          (((double)O21 - target21) * O21 * (1.0 - O21) * w6 * H22 * (1.0 - H22) * (double)1.0);
					

						deEtotal_o2 = (((double)O12 - target12) * O12 * (1.0 - O12) * w8 * H11 * (1.0 - H11) * (double)1.0) +
                        //// - 
							          (((double)O22 - target22) * O22 * (1.0 - O22) * w8 * H22 * (1.0 - H22) * (double)1.0);

                       // calculation of the delta rule
						b2 += -(double)learningRate * ((double)deEtotal_o1 + deEtotal_o2);

						b2 += ((double)smoothingFactor * (double)pb2);

						pb2 = ((double)b2);


						if ( (_isnan((double)b2)) == 0 ) { } else {
				
							std::cout << "Please run again the program using less number of iterations " << endl;
							exit(0);
				
						} 
     					// backpropagation to hidden layer (end)
			    
			}// learning process (end)


	FILE * saveWeights;
	char output[300];
	
	sprintf(output, "%s", "Weights.img");

	if ((saveWeights = fopen(output, "wb+")) == NULL)
	{

		std::cout << "Cannot open output file, Now Exit..." << endl;
	    exit(0);

	}
	else { // (save)

			fwrite(&w1, sizeof(double), 1, saveWeights);
			fwrite(&w2, sizeof(double), 1, saveWeights);
			fwrite(&w3, sizeof(double), 1, saveWeights);
			fwrite(&w4, sizeof(double), 1, saveWeights);
	
		fclose(saveWeights);

	} // (save)


	sprintf(output, "%s", "HL_Weights.img");
	if ((saveWeights = fopen(output, "wb+")) == NULL)
	{

		std::cout << "Cannot open output file, Now Exit..." << endl;
	    exit(0);

	}
	else { // (save)

			fwrite(&w5, sizeof(double), 1, saveWeights);
			fwrite(&w6, sizeof(double), 1, saveWeights);
			fwrite(&w7, sizeof(double), 1, saveWeights);
			fwrite(&w8, sizeof(double), 1, saveWeights);

		fclose(saveWeights);

	} // (save)

			
			std::cout << "End of Computation..." << endl;
			std::cout << endl;

			fprintf(savedata, "%s\n", "End of Computation...");
			fprintf(savedata, "\n");

			fclose(savedata);
	        
			} // processing (ends)

	} // run the program (end)

	return 0;
} // end of main 