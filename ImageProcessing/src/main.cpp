/* PROJECT 2 - IMAGE PROCESSING - KYLE MILLER */
// This program will serve to do the following:
// 1. Read in a number of .TGA files in a binary format
// 2. Process the image data stored within those files in a variety of ways
// 3. Write out new .TGA files in the same binary format
// NOTE - TGA files store data in BGR not RGB

#include <iostream>
#include <fstream>
#include <vector>
#include "TGA.h"
using namespace std;

// Read Helper Function
void ReadTGAFiles(vector<TGA*>& vecTGAs, ifstream& inFile);

// Loader Helper Function
void LoadEmUp(vector<TGA*>& vecTGAs);

// Problem Functions
void Part1(vector<TGA*>& vecTGAs);
void Part2(vector<TGA*>& vecTGAs);
void Part3(vector<TGA*>& vecTGAs);
void Part4(vector<TGA*>& vecTGAs);
void Part5(vector<TGA*>& vecTGAs);
void Part6(vector<TGA*>& vecTGAs);
void Part7(vector<TGA*>& vecTGAs);
void Part8(vector<TGA*>& vecTGAs);
void Part9(vector<TGA*>& vecTGAs);
void Part10(vector<TGA*>& vecTGAs);
void PartEC(vector<TGA*>& vecTGAs);

// Tester
void TesterFunc();


int main()
{
	// 1. Read in TGA files - Store in vector<TGA>
	vector<TGA*> vecTGAs;
	LoadEmUp(vecTGAs);

	// 2. Perform Manipulations
	// 3. Write out new .TGA files

	Part1(vecTGAs);
	Part2(vecTGAs);
	Part3(vecTGAs);
	Part4(vecTGAs);
	Part5(vecTGAs);
	Part6(vecTGAs);
	Part7(vecTGAs);
	Part8(vecTGAs);
	Part9(vecTGAs);
	Part10(vecTGAs);
	PartEC(vecTGAs);

	TesterFunc();

}

void ReadTGAFiles(vector<TGA*>& vecTGAs, ifstream& inFile)
{
	// 1. Read through the header to get width and height
	unsigned char idLength;
	unsigned char colorMapType;
	unsigned char dataTypeCode;
	short colorMapOrigin;
	short colorMapLength;
	char colorMapDepth;
	short xOrigin;
	short yOrigin;
	short width;
	short height;
	char bitsPerPixel;
	char imageDescriptor;
	inFile.read(reinterpret_cast<char*>(&idLength), sizeof(idLength));
	inFile.read(reinterpret_cast<char*>(&colorMapType), sizeof(colorMapType));
	inFile.read(reinterpret_cast<char*>(&dataTypeCode), sizeof(dataTypeCode));
	inFile.read(reinterpret_cast<char*>(&colorMapOrigin), sizeof(colorMapOrigin));
	inFile.read(reinterpret_cast<char*>(&colorMapLength), sizeof(colorMapLength));
	inFile.read(reinterpret_cast<char*>(&colorMapDepth), sizeof(colorMapDepth));
	inFile.read(reinterpret_cast<char*>(&xOrigin), sizeof(xOrigin));
	inFile.read(reinterpret_cast<char*>(&yOrigin), sizeof(yOrigin));
	inFile.read(reinterpret_cast<char*>(&width), sizeof(width));
	inFile.read(reinterpret_cast<char*>(&height), sizeof(height));
	inFile.read(reinterpret_cast<char*>(&bitsPerPixel), sizeof(bitsPerPixel));
	inFile.read(reinterpret_cast<char*>(&imageDescriptor), sizeof(imageDescriptor));

	// 2. Create an instance of TGA class
	TGA* imageToAdd = new TGA(width,height,idLength,colorMapType,dataTypeCode,
		 colorMapOrigin,colorMapLength,colorMapDepth,xOrigin,yOrigin,bitsPerPixel,
		 imageDescriptor);
	imageToAdd->SetPixels(inFile);

	// 3. Push Back to vecTGAs
	vecTGAs.push_back(imageToAdd);
}

void LoadEmUp(vector<TGA*>& vecTGAs)
{
	ifstream inFile("input/car.tga", ios_base::binary);
	ReadTGAFiles(vecTGAs, inFile);
	inFile.close();
	inFile.open("input/circles.tga", ios_base::binary);
	ReadTGAFiles(vecTGAs, inFile);
	inFile.close();
	inFile.open("input/layer_blue.tga", ios_base::binary);
	ReadTGAFiles(vecTGAs, inFile);
	inFile.close();
	inFile.open("input/layer_green.tga", ios_base::binary);
	ReadTGAFiles(vecTGAs, inFile);
	inFile.close();
	inFile.open("input/layer_red.tga", ios_base::binary);
	ReadTGAFiles(vecTGAs, inFile);
	inFile.close();
	inFile.open("input/layer1.tga", ios_base::binary);
	ReadTGAFiles(vecTGAs, inFile);
	inFile.close();
	inFile.open("input/layer2.tga", ios_base::binary);
	ReadTGAFiles(vecTGAs, inFile);
	inFile.close();
	inFile.open("input/pattern1.tga", ios_base::binary);
	ReadTGAFiles(vecTGAs, inFile);
	inFile.close();
	inFile.open("input/pattern2.tga", ios_base::binary);
	ReadTGAFiles(vecTGAs, inFile);
	inFile.close();
	inFile.open("input/text.tga", ios_base::binary);
	ReadTGAFiles(vecTGAs, inFile);
	inFile.close();
	inFile.open("input/text2.tga", ios_base::binary);
	ReadTGAFiles(vecTGAs, inFile);
	inFile.close();
}

void Part1(vector<TGA*>& vecTGAs)
{
	// 2. Perform Manipulations
	TGA temp;
	temp.Multiply(vecTGAs[5], vecTGAs[7]);

	// 3. Write out new .TGA files
	ofstream outFile("output/part1.tga", ios_base::binary);
	temp.WriteTo(outFile);
}
void Part2(vector<TGA*>& vecTGAs)
{
	// 2. Perform Manipulations
	TGA temp;
	temp.Subtract(vecTGAs[0], vecTGAs[6]);

	// 3. Write out new .TGA files
	ofstream outFile("output/part2.tga", ios_base::binary);
	temp.WriteTo(outFile);
}
void Part3(vector<TGA*>& vecTGAs)
{
	// 2. Perform Manipulations
	TGA temp;
	temp.Multiply(vecTGAs[5], vecTGAs[8]);
	TGA temp2;
	temp2.Screen(&temp, vecTGAs[9]);

	// 3. Write out new .TGA files
	ofstream outFile("output/part3.tga", ios_base::binary);
	temp2.WriteTo(outFile);
}
void Part4(vector<TGA*>& vecTGAs)
{
	// 2. Perform Manipulations
	TGA temp;
	temp.Multiply(vecTGAs[6], vecTGAs[1]);
	TGA temp2;
	temp2.Subtract(&temp, vecTGAs[8]);

	// 3. Write out new .TGA files
	ofstream outFile("output/part4.tga", ios_base::binary);
	temp2.WriteTo(outFile);
}
void Part5(vector<TGA*>& vecTGAs)
{
	// 2. Perform Manipulations
	TGA temp;
	temp.Overlay(vecTGAs[7], vecTGAs[5]);

	// 3. Write out new .TGA files
	ofstream outFile("output/part5.tga", ios_base::binary);
	temp.WriteTo(outFile);
}
void Part6(vector<TGA*>& vecTGAs)
{
	// 2. Perform Manipulations
	TGA temp;
	temp.AddToChannel(1,200,vecTGAs[0]);

	// 3. Write out new .TGA files
	ofstream outFile("output/part6.tga", ios_base::binary);
	temp.WriteTo(outFile);
}
void Part7(vector<TGA*>& vecTGAs) 
{
	// 2. Perform Manipulations
	TGA temp;
	temp = *(vecTGAs[0]);
	temp.MultiplyChannel(2, 4);
	temp.MultiplyChannel(0, 0);

	// 3. Write out new .TGA files
	ofstream outFile("output/part7.tga", ios_base::binary);
	temp.WriteTo(outFile);
}
void Part8(vector<TGA*>& vecTGAs)
{
	// 2. Perform Manipulations
	TGA tempRed;
	tempRed = *(vecTGAs[0]);
	tempRed.SeparateChannel(2);

	// 3. Write out new .TGA files
	ofstream outFile("output/part8_r.tga", ios_base::binary);
	tempRed.WriteTo(outFile);

	// 2. Perform Manipulations
	TGA tempGreen;
	tempGreen = *(vecTGAs[0]);
	tempGreen.SeparateChannel(1);

	// 3. Write out new .TGA files
	ofstream outFile1("output/part8_g.tga", ios_base::binary);
	tempGreen.WriteTo(outFile1);

	// 2. Perform Manipulations
	TGA tempBlue;
	tempBlue = *(vecTGAs[0]);
	tempBlue.SeparateChannel(0);

	// 3. Write out new .TGA files
	ofstream outFile2("output/part8_b.tga", ios_base::binary);
	tempBlue.WriteTo(outFile2);
}
void Part9(vector<TGA*>& vecTGAs)
{
	// 2. Perform Manipulations
	TGA temp;
	temp = *(vecTGAs[2]);
	temp.SetChannel(1, vecTGAs[3]);
	temp.SetChannel(2, vecTGAs[4]);

	// 3. Write out new .TGA files
	ofstream outFile("output/part9.tga", ios_base::binary);
	temp.WriteTo(outFile);
}
void Part10(vector<TGA*>& vecTGAs)
{
	// 2. Perform Manipulations
	TGA temp;
	temp.Flip(vecTGAs[10]);

	// 3. Write out new .TGA files
	ofstream outFile("output/part10.tga", ios_base::binary);
	temp.WriteTo(outFile);
}
void PartEC(vector<TGA*>& vecTGAs)
{
	// 2. Perform Manipulations
	TGA temp;
	// Combine4 == (Lower L, Lower R, Upper L, Upper R) image input
	temp.Combine4(vecTGAs[9], vecTGAs[7], vecTGAs[0], vecTGAs[1]);

	// 3. Write out new .TGA files
	ofstream outFile("output/extracredit.tga", ios_base::binary);
	temp.WriteTo(outFile);
}
void TesterFunc()
{
	vector<TGA*> testVec;
	ifstream inFile("examples/EXAMPLE_part1.tga", ios_base::binary);
	ReadTGAFiles(testVec, inFile);
	inFile.close();
	inFile.open("output/part1.tga", ios_base::binary);
	ReadTGAFiles(testVec, inFile);
	inFile.close();
	if (*(testVec[0]) == *(testVec[1]))
		cout << "TEST 1 SUCCESSFUL\n";
	else
		cout << "Test 1 FAILED\n";

	testVec.clear();
	inFile.open("examples/EXAMPLE_part2.tga", ios_base::binary);
	ReadTGAFiles(testVec, inFile);
	inFile.close();
	inFile.open("output/part2.tga", ios_base::binary);
	ReadTGAFiles(testVec, inFile);
	inFile.close();
	if (*(testVec[0]) == *(testVec[1]))
		cout << "TEST 2 SUCCESSFUL\n";
	else
		cout << "Test 2 FAILED\n";

	testVec.clear();
	inFile.open("examples/EXAMPLE_part3.tga", ios_base::binary);
	ReadTGAFiles(testVec, inFile);
	inFile.close();
	inFile.open("output/part3.tga", ios_base::binary);
	ReadTGAFiles(testVec, inFile);
	inFile.close();
	if (*(testVec[0]) == *(testVec[1]))
		cout << "TEST 3 SUCCESSFUL\n";
	else
		cout << "Test 3 FAILED\n";

	testVec.clear();
	inFile.open("examples/EXAMPLE_part4.tga", ios_base::binary);
	ReadTGAFiles(testVec, inFile);
	inFile.close();
	inFile.open("output/part4.tga", ios_base::binary);
	ReadTGAFiles(testVec, inFile);
	inFile.close();
	if (*(testVec[0]) == *(testVec[1]))
		cout << "TEST 4 SUCCESSFUL\n";
	else
		cout << "Test 4 FAILED\n";

	testVec.clear();
	inFile.open("examples/EXAMPLE_part5.tga", ios_base::binary);
	ReadTGAFiles(testVec, inFile);
	inFile.close();
	inFile.open("output/part5.tga", ios_base::binary);
	ReadTGAFiles(testVec, inFile);
	inFile.close();
	if (*(testVec[0]) == *(testVec[1]))
		cout << "TEST 5 SUCCESSFUL\n";
	else
		cout << "Test 5 FAILED\n";

	testVec.clear();
	inFile.open("examples/EXAMPLE_part6.tga", ios_base::binary);
	ReadTGAFiles(testVec, inFile);
	inFile.close();
	inFile.open("output/part6.tga", ios_base::binary);
	ReadTGAFiles(testVec, inFile);
	inFile.close();
	if (*(testVec[0]) == *(testVec[1]))
		cout << "TEST 6 SUCCESSFUL\n";
	else
		cout << "Test 6 FAILED\n";

	testVec.clear();
	inFile.open("examples/EXAMPLE_part7.tga", ios_base::binary);
	ReadTGAFiles(testVec, inFile);
	inFile.close();
	inFile.open("output/part7.tga", ios_base::binary);
	ReadTGAFiles(testVec, inFile);
	inFile.close();
	if (*(testVec[0]) == *(testVec[1]))
		cout << "TEST 7 SUCCESSFUL\n";
	else
		cout << "Test 7 FAILED\n";

	testVec.clear();
	inFile.open("examples/EXAMPLE_part8_b.tga", ios_base::binary);
	ReadTGAFiles(testVec, inFile);
	inFile.close();
	inFile.open("output/part8_b.tga", ios_base::binary);
	ReadTGAFiles(testVec, inFile);
	inFile.close();
	if (*(testVec[0]) == *(testVec[1]))
		cout << "TEST 8b SUCCESSFUL\n";
	else
		cout << "Test 8b FAILED\n";

	testVec.clear();
	inFile.open("examples/EXAMPLE_part8_g.tga", ios_base::binary);
	ReadTGAFiles(testVec, inFile);
	inFile.close();
	inFile.open("output/part8_g.tga", ios_base::binary);
	ReadTGAFiles(testVec, inFile);
	inFile.close();
	if (*(testVec[0]) == *(testVec[1]))
		cout << "TEST 8g SUCCESSFUL\n";
	else
		cout << "Test 8g FAILED\n";

	testVec.clear();
	inFile.open("examples/EXAMPLE_part8_r.tga", ios_base::binary);
	ReadTGAFiles(testVec, inFile);
	inFile.close();
	inFile.open("output/part8_r.tga", ios_base::binary);
	ReadTGAFiles(testVec, inFile);
	inFile.close();
	if (*(testVec[0]) == *(testVec[1]))
		cout << "TEST 8r SUCCESSFUL\n";
	else
		cout << "Test 8r FAILED\n";

	testVec.clear();
	inFile.open("examples/EXAMPLE_part9.tga", ios_base::binary);
	ReadTGAFiles(testVec, inFile);
	inFile.close();
	inFile.open("output/part9.tga", ios_base::binary);
	ReadTGAFiles(testVec, inFile);
	inFile.close();
	if (*(testVec[0]) == *(testVec[1]))
		cout << "TEST 9 SUCCESSFUL\n";
	else
		cout << "Test 9 FAILED\n";

	testVec.clear();
	inFile.open("examples/EXAMPLE_part10.tga", ios_base::binary);
	ReadTGAFiles(testVec, inFile);
	inFile.close();
	inFile.open("output/part10.tga", ios_base::binary);
	ReadTGAFiles(testVec, inFile);
	inFile.close();
	if (*(testVec[0]) == *(testVec[1]))
		cout << "TEST 10 SUCCESSFUL\n";
	else
		cout << "Test 10 FAILED\n";

	testVec.clear();
	inFile.open("examples/EXAMPLE_extracredit.tga", ios_base::binary);
	ReadTGAFiles(testVec, inFile);
	inFile.close();
	inFile.open("output/extracredit.tga", ios_base::binary);
	ReadTGAFiles(testVec, inFile);
	inFile.close();
	if (*(testVec[0]) == *(testVec[1]))
		cout << "TEST 11 SUCCESSFUL\n";
	else
		cout << "Test 11 FAILED\n";
}