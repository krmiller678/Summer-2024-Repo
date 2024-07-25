#pragma once
#include <fstream>

class TGA
{
private:
	unsigned char _idLength;
	unsigned char _colorMapType;
	unsigned char _dataTypeCode;
	short _colorMapOrigin;
	short _colorMapLength;
	char _colorMapDepth;
	short _xOrigin;
	short _yOrigin;
	short _width;
	short _height;
	char _bitsPerPixel;
	char _imageDescriptor;
	unsigned char* _arrayOfPixels;

public:
	// Constructors and Destructor
	TGA(short width = 0, short height = 0, unsigned char idLength = 0, unsigned char colorMapType = 0, unsigned char dataTypeCode = 0,
		short colorMapOrigin = 0, short colorMapLength = 0, char colorMapDepth = 0, short xOrigin = 0, short yOrigin = 0, char bitsPerPixel = 0,
		char imageDescriptor = 0);
	TGA(const TGA& rhs); // Copy-Constructor
	~TGA();

	// Mutators (Setters)
	void SetPixels(std::ifstream& inFile);
	void WriteTo(std::ofstream& outFile);

	// Accessors (Getters)
	short GetWidth() const;

	// Operators
	TGA& operator=(const TGA& rhs); // Copy Assignment
	bool operator==(const TGA& rhs);
	void Multiply(const TGA* lhs, const TGA* rhs);
	void Subtract(const TGA* lhs, const TGA* rhs);
	void Screen(const TGA* lhs, const TGA* rhs);
	void Overlay(const TGA* lhs, const TGA* rhs);
	
	void AddToChannel(unsigned int channel, int amountToAdd, const TGA* rhs);
	void MultiplyChannel(unsigned int channel, int amountToMult);
	void SeparateChannel(unsigned int channel);
	void SetChannel(unsigned int channel, const TGA* rhs);
	void Flip(const TGA* rhs);
	void Combine4(const TGA* lowLeft, const TGA* lowRight, const TGA* upLeft, const TGA* upRight);
};