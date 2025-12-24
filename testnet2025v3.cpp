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

	char outputFile[128] = "testnet2025v3.log";

	FILE* savedata;

	if (argc < 3) {
		std::cout << endl;
		std::cout << "Please type the image file name - Class 1: Make sure it is a 2x1 file" << endl;
		std::cout << "Please type the image file name - Class 2: Make sure it is a 2x1 file" << endl;
		std::cout << "Please make sure that the Data format is 'double': 64 bits real" << endl;
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

			sprintf(fileNameX1, "%s", argv[1]);
			sprintf(fileNameX2, "%s", argv[2]);


			std::cout << endl;
			std::cout << "The File name of Class 1 is: " << fileNameX1 << endl;
			std::cout << "The File name of Class 2 is: " << fileNameX2 << endl;
		

			fprintf(savedata, "%s%s\n", "The File name of Class 1 is: ", fileNameX1);
			fprintf(savedata, "%s%s\n", "TThe File name of Class 2 is: ", fileNameX2);
		

			
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

			double w1 = 0.0, w2 = 0.0, w3 = 0.0, w4 = 0.0;
			double w5 = 0.0, w6 = 0.0, w7 = 0.0, w8 = 0.0;
			double b1 = 0.0, b2 = 0.0, b3 = 0.0, b4 = 0.0;
			

			if ((pf = fopen("Weights.img", "rb+")) == NULL)
			{

				std::cout << "Cannot open file: " << "Weights.img" << endl;
				fprintf(savedata, "%s%s\n", "Cannot open file: ", "Weights.img");

				exit(0);

			}
			else { // else

				fread(&w1, sizeof(double), 1, pf);
				fread(&w2, sizeof(double), 1, pf);
				fread(&w3, sizeof(double), 1, pf);
				fread(&w4, sizeof(double), 1, pf);
				fread(&b3, sizeof(double), 1, pf);
				fread(&b4, sizeof(double), 1, pf);

				fclose(pf);


			} // else 
			/// read file (end)

			if ((pf = fopen("HL_Weights.img", "rb+")) == NULL)
			{

				std::cout << "Cannot open file: " << "HL_Weights.img" << endl;
				fprintf(savedata, "%s%s\n", "Cannot open file: ", "HL_Weights.img");

				exit(0);

			}
			else { // else

				fread(&w5, sizeof(double), 1, pf);
				fread(&w6, sizeof(double), 1, pf);
				fread(&w7, sizeof(double), 1, pf);
				fread(&w8, sizeof(double), 1, pf);
				fread(&b1, sizeof(double), 1, pf);
				fread(&b2, sizeof(double), 1, pf);

				fclose(pf);


			} // else 
			/// read file (end)
			std::cout << "Data loaded" << endl;

			// initialize to zeros
			double H11 = 0.0, H12 = 0.0;
			double H21 = 0.0, H22 = 0.0;

			double O11 = 0.0, O12 = 0.0;
			double O21 = 0.0, O22 = 0.0;

			
				// compute the Network input-output - Image 1 - (begin)
				double h11 = (double)0.0;
				double h12 = (double)0.0;


				h11 = (double)i11 * (double)w1 + (double)i12 * (double)w2;

				h12 = (double)i11 * (double)w3 + (double)i12 * (double)w4;


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


				net11 = (double)H11 * (double)w5 + (double)H12 * (double)w6;

				net12 = (double)H11 * (double)w7 + (double)H12 * (double)w8;

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

				h21 = (double)i21 * (double)w1 + (double)i22 * (double)w2;

				h22 = (double)i21 * (double)w3 + (double)i22 * (double)w4;

				h21 = h21 + b1;
				h22 = h22 + b2;

				H21 = (double)1.0 / ((double)1.0 + (double)exp(-(double)h21));
				H22 = (double)1.0 / ((double)1.0 + (double)exp(-(double)h22));


				if ((_isnan((double)H21)) == 0) {}
				else {

					std::cout << "Please run again the program using less number of iterations " << endl;
					exit(0);

				}

				if ((_isnan((double)H22)) == 0) {}
				else {

					std::cout << "Please run again the program using less number of iterations " << endl;
					exit(0);

				}

				double net21 = (double)0.0;
				double net22 = (double)0.0;

				net21 = (double)H21 * (double)w5 + (double)H22 * (double)w6;

				net22 = (double)H21 * (double)w7 + (double)H22 * (double)w8;


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

				
				// save data into log file (begin)
				fprintf(savedata, "%s%lf\n", "O11 = ", O11);
				fprintf(savedata, "%s%lf\n", "O21 = ", O21);
				fprintf(savedata, "%s%lf\n", "O12 = ", O12);
				fprintf(savedata, "%s%lf\n", "O22 = ", O22);
				// save data into log file (end)


				
			std::cout << "End of Computation..." << endl;
			std::cout << endl;

			fprintf(savedata, "%s\n", "End of Computation...");
			fprintf(savedata, "\n");

			fclose(savedata);

		} // processing (ends)

	} // run the program (end)

	return 0;
} // end of main 