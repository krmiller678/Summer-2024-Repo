#include "TGA.h"
#include <string>
#include <iostream>
using namespace std;

TGA::TGA(short width, short height, unsigned char idLength, unsigned char colorMapType, unsigned char dataTypeCode,
	short colorMapOrigin, short colorMapLength, char colorMapDepth, short xOrigin, short yOrigin, char bitsPerPixel,
	char imageDescriptor)
	: _width(width), _height(height)
{
	_arrayOfPixels = new unsigned char[(width * height * 3)];
	_idLength = idLength;
	_colorMapType = colorMapType;
	_dataTypeCode = dataTypeCode;
	_colorMapOrigin = colorMapOrigin;
	_colorMapLength = colorMapLength;
	_colorMapDepth = colorMapDepth;
	_xOrigin = xOrigin;
	_yOrigin = yOrigin;
	_bitsPerPixel = bitsPerPixel;
	_imageDescriptor = imageDescriptor;

}

TGA::TGA(const TGA& rhs)
{
	_width = rhs._width;
	_height = rhs._height;
	_arrayOfPixels = new unsigned char[(_width * _height * 3)];
	for (unsigned int i = 0; i < (_width * _height * 3); i++)
	{
		_arrayOfPixels[i] = rhs._arrayOfPixels[i];
	}
	_idLength = rhs._idLength;
	_colorMapType = rhs._colorMapType;
	_dataTypeCode = rhs._dataTypeCode;
	_colorMapOrigin = rhs._colorMapOrigin;
	_colorMapLength = rhs._colorMapLength;
	_colorMapDepth = rhs._colorMapDepth;
	_xOrigin = rhs._xOrigin;
	_yOrigin = rhs._yOrigin;
	_bitsPerPixel = rhs._bitsPerPixel;
	_imageDescriptor = rhs._imageDescriptor;
}

TGA::~TGA()
{
	delete[] _arrayOfPixels;
}

void TGA::SetPixels(std::ifstream& inFile)
{
	inFile.read(reinterpret_cast<char*>(&_arrayOfPixels[0]), (_width * _height * 3));
}

void TGA::WriteTo(ofstream& outFile)
{
	outFile.write(reinterpret_cast<char*>(&_idLength), sizeof(_idLength));
	outFile.write(reinterpret_cast<char*>(&_colorMapType), sizeof(_colorMapType));
	outFile.write(reinterpret_cast<char*>(&_dataTypeCode), sizeof(_dataTypeCode));
	outFile.write(reinterpret_cast<char*>(&_colorMapOrigin), sizeof(_colorMapOrigin));
	outFile.write(reinterpret_cast<char*>(&_colorMapLength), sizeof(_colorMapLength));
	outFile.write(reinterpret_cast<char*>(&_colorMapDepth), sizeof(_colorMapDepth));
	outFile.write(reinterpret_cast<char*>(&_xOrigin), sizeof(_xOrigin));
	outFile.write(reinterpret_cast<char*>(&_yOrigin), sizeof(_yOrigin));
	outFile.write(reinterpret_cast<char*>(&_width), sizeof(_width));
	outFile.write(reinterpret_cast<char*>(&_height), sizeof(_height));
	outFile.write(reinterpret_cast<char*>(&_bitsPerPixel), sizeof(_bitsPerPixel));
	outFile.write(reinterpret_cast<char*>(&_imageDescriptor), sizeof(_imageDescriptor));
	outFile.write(reinterpret_cast<char*>(&_arrayOfPixels[0]), (_width * _height * 3));
}

short TGA::GetWidth() const { return _width; }

TGA& TGA::operator=(const TGA& rhs)
{
	_width = rhs._width;
	_height = rhs._height;
	delete[] _arrayOfPixels;
	_arrayOfPixels = new unsigned char[(_width * _height * 3)];
	for (unsigned int i = 0; i < (_width * _height * 3); i++)
	{
		_arrayOfPixels[i] = rhs._arrayOfPixels[i];
	}
	_idLength = rhs._idLength;
	_colorMapType = rhs._colorMapType;
	_dataTypeCode = rhs._dataTypeCode;
	_colorMapOrigin = rhs._colorMapOrigin;
	_colorMapLength = rhs._colorMapLength;
	_colorMapDepth = rhs._colorMapDepth;
	_xOrigin = rhs._xOrigin;
	_yOrigin = rhs._yOrigin;
	_bitsPerPixel = rhs._bitsPerPixel;
	_imageDescriptor = rhs._imageDescriptor;

	return *this;
}

void TGA::Multiply(const TGA* lhs, const TGA* rhs)
{
	// uninteresting variables - invoking obj is default initialized
	_width = rhs->_width;
	_height = rhs->_height;
	_idLength = rhs->_idLength;
	_colorMapType = rhs->_colorMapType;
	_dataTypeCode = rhs->_dataTypeCode;
	_colorMapOrigin = rhs->_colorMapOrigin;
	_colorMapLength = rhs->_colorMapLength;
	_colorMapDepth = rhs->_colorMapDepth;
	_xOrigin = rhs->_xOrigin;
	_yOrigin = rhs->_yOrigin;
	_bitsPerPixel = rhs->_bitsPerPixel;
	_imageDescriptor = rhs->_imageDescriptor;

	// Operation
	_arrayOfPixels = new unsigned char[(_width * _height * 3)];
	for (unsigned int i = 0; i < (_width * _height * 3); i++)
	{
		_arrayOfPixels[i] = static_cast<unsigned char>((static_cast<float>(rhs->_arrayOfPixels[i]) / 255) *
			(static_cast<float>(lhs->_arrayOfPixels[i])) + .5f);
	}
}

void TGA::Subtract(const TGA* lhs, const TGA* rhs)
{
	// uninteresting variables - invoking obj is default initialized
	_width = rhs->_width;
	_height = rhs->_height;
	_idLength = rhs->_idLength;
	_colorMapType = rhs->_colorMapType;
	_dataTypeCode = rhs->_dataTypeCode;
	_colorMapOrigin = rhs->_colorMapOrigin;
	_colorMapLength = rhs->_colorMapLength;
	_colorMapDepth = rhs->_colorMapDepth;
	_xOrigin = rhs->_xOrigin;
	_yOrigin = rhs->_yOrigin;
	_bitsPerPixel = rhs->_bitsPerPixel;
	_imageDescriptor = rhs->_imageDescriptor;

	// Operation
	_arrayOfPixels = new unsigned char[(_width * _height * 3)];
	for (unsigned int i = 0; i < (_width * _height * 3); i++)
	{
		if (static_cast<int>(lhs->_arrayOfPixels[i]) - static_cast<int>(rhs->_arrayOfPixels[i]) > 0)
		{
			_arrayOfPixels[i] = static_cast<unsigned char>(static_cast<int>(lhs->_arrayOfPixels[i]) 
				- static_cast<int>(rhs->_arrayOfPixels[i]));
		}
		else
			_arrayOfPixels[i] = static_cast<unsigned char>(0);
	}
}

void TGA::Screen(const TGA* lhs, const TGA* rhs)
{
	// uninteresting variables - invoking obj is default initialized
	_width = rhs->_width;
	_height = rhs->_height;
	_idLength = rhs->_idLength;
	_colorMapType = rhs->_colorMapType;
	_dataTypeCode = rhs->_dataTypeCode;
	_colorMapOrigin = rhs->_colorMapOrigin;
	_colorMapLength = rhs->_colorMapLength;
	_colorMapDepth = rhs->_colorMapDepth;
	_xOrigin = rhs->_xOrigin;
	_yOrigin = rhs->_yOrigin;
	_bitsPerPixel = rhs->_bitsPerPixel;
	_imageDescriptor = rhs->_imageDescriptor;

	// Operation
	_arrayOfPixels = new unsigned char[(_width * _height * 3)];
	for (unsigned int i = 0; i < (_width * _height * 3); i++)
	{
		_arrayOfPixels[i] = static_cast<unsigned char>((1 -(1 - static_cast<float>(rhs->_arrayOfPixels[i]) / 255) *
			(1 - static_cast<float>(lhs->_arrayOfPixels[i]) / 255))*255 + .5f);
	}
}

void TGA::Overlay(const TGA* lhs, const TGA* rhs)
{
	// uninteresting variables - invoking obj is default initialized
	_width = rhs->_width;
	_height = rhs->_height;
	_idLength = rhs->_idLength;
	_colorMapType = rhs->_colorMapType;
	_dataTypeCode = rhs->_dataTypeCode;
	_colorMapOrigin = rhs->_colorMapOrigin;
	_colorMapLength = rhs->_colorMapLength;
	_colorMapDepth = rhs->_colorMapDepth;
	_xOrigin = rhs->_xOrigin;
	_yOrigin = rhs->_yOrigin;
	_bitsPerPixel = rhs->_bitsPerPixel;
	_imageDescriptor = rhs->_imageDescriptor;

	// Operation
	_arrayOfPixels = new unsigned char[(_width * _height * 3)];
	for (unsigned int i = 0; i < (_width * _height * 3); i++)
	{
		if ((static_cast<float>(lhs->_arrayOfPixels[i]) / 255) <= 0.5)
		{
			_arrayOfPixels[i] = static_cast<unsigned char>(2 * (static_cast<float>(rhs->_arrayOfPixels[i]) / 255) *
				(static_cast<float>(lhs->_arrayOfPixels[i])) + .5f);
		}
		else
		{
			_arrayOfPixels[i] = static_cast<unsigned char>((1 - 2 * (1 - static_cast<float>(rhs->_arrayOfPixels[i]) / 255) *
				(1 - static_cast<float>(lhs->_arrayOfPixels[i]) / 255)) * 255 + .5f);
		}
	}
}

void TGA::AddToChannel(unsigned int channel, int amountToAdd, const TGA* rhs)
{
	// uninteresting variables - invoking obj is default initialized
	_width = rhs->_width;
	_height = rhs->_height;
	_idLength = rhs->_idLength;
	_colorMapType = rhs->_colorMapType;
	_dataTypeCode = rhs->_dataTypeCode;
	_colorMapOrigin = rhs->_colorMapOrigin;
	_colorMapLength = rhs->_colorMapLength;
	_colorMapDepth = rhs->_colorMapDepth;
	_xOrigin = rhs->_xOrigin;
	_yOrigin = rhs->_yOrigin;
	_bitsPerPixel = rhs->_bitsPerPixel;
	_imageDescriptor = rhs->_imageDescriptor;

	// Operation
	_arrayOfPixels = new unsigned char[(_width * _height * 3)];
	for (unsigned int i = 0; i < (_width * _height * 3); i++)
	{
		_arrayOfPixels[i] = rhs->_arrayOfPixels[i];
	}
	for (unsigned int i = channel; i < (_width * _height * 3); i+=3)
	{
		if ((static_cast<int>(rhs->_arrayOfPixels[i]) + amountToAdd < 255))
		{
			_arrayOfPixels[i] = static_cast<unsigned char>(static_cast<int>(rhs->_arrayOfPixels[i]) + amountToAdd);
		}
		else
			_arrayOfPixels[i] = static_cast<unsigned char>(255);
	}
}

void TGA::MultiplyChannel(unsigned int channel, int amountToMult)
{
	for (unsigned int i = channel; i < (_width * _height * 3); i += 3)
	{
		if ((static_cast<int>(_arrayOfPixels[i]) * amountToMult < 255))
		{
			_arrayOfPixels[i] = static_cast<unsigned char>(static_cast<int>(_arrayOfPixels[i]) * amountToMult);
		}
		else
			_arrayOfPixels[i] = static_cast<unsigned char>(255);
	}
}

void TGA::SeparateChannel(unsigned int channel)
{
	for (unsigned int i = 0; i < (_width * _height); i++)
	{
		unsigned char valueToSet = _arrayOfPixels[channel + 3 * i];
		_arrayOfPixels[0 + 3 * i] = valueToSet;
		_arrayOfPixels[1 + 3 * i] = valueToSet;
		_arrayOfPixels[2 + 3 * i] = valueToSet;
	}
}

void TGA::SetChannel(unsigned int channel, const TGA* rhs)
{
	for (unsigned int i = 0; i < (_width * _height); i++)
	{
		_arrayOfPixels[channel + 3*i] = rhs->_arrayOfPixels[channel + 3 * i];
	}
}

void TGA::Flip(const TGA* rhs)
{
	// uninteresting variables - invoking obj is default initialized
	_width = rhs->_width;
	_height = rhs->_height;
	_idLength = rhs->_idLength;
	_colorMapType = rhs->_colorMapType;
	_dataTypeCode = rhs->_dataTypeCode;
	_colorMapOrigin = rhs->_colorMapOrigin;
	_colorMapLength = rhs->_colorMapLength;
	_colorMapDepth = rhs->_colorMapDepth;
	_xOrigin = rhs->_xOrigin;
	_yOrigin = rhs->_yOrigin;
	_bitsPerPixel = rhs->_bitsPerPixel;
	_imageDescriptor = rhs->_imageDescriptor;

	// Operation
	_arrayOfPixels = new unsigned char[(_width * _height * 3)];
	unsigned int size = _width * _height * 3;
	for (unsigned int i = 0; i < (_width * _height); i++)
	{
		_arrayOfPixels[i*3] = rhs->_arrayOfPixels[size - 3 - i * 3];
		_arrayOfPixels[1 + i * 3] = rhs->_arrayOfPixels[size - 2 - i * 3];
		_arrayOfPixels[2 + i * 3] = rhs->_arrayOfPixels[size - 1 - i * 3];

	}
}

bool TGA::operator==(const TGA& rhs)
{
	
	if (_width != rhs._width)
		return false;
	if (_height != rhs._height)
		return false;
	if (_idLength != rhs._idLength)
		return false;
	if (_colorMapType != rhs._colorMapType)
		return false;
	if (_dataTypeCode != rhs._dataTypeCode)
		return false;
	if (_colorMapOrigin != rhs._colorMapOrigin)
		return false;
	if (_colorMapLength != rhs._colorMapLength)
		return false;
	if (_colorMapDepth != rhs._colorMapDepth)
		return false;
	if (_xOrigin != rhs._xOrigin)
		return false;
	if (_yOrigin != rhs._yOrigin)
		return false;
	if (_bitsPerPixel != rhs._bitsPerPixel)
		return false;
	if (_imageDescriptor != rhs._imageDescriptor)
		return false;

	for (unsigned int i = 0; i < (_width * _height) * 3; i++)
	{
		if (_arrayOfPixels[i] != rhs._arrayOfPixels[i])
			return false;
	}
	return true;
}

void TGA::Combine4(const TGA* lowLeft, const TGA* lowRight, const TGA* upLeft, const TGA* upRight)
{
	_width = lowLeft->_width*2;
	_height = lowLeft->_height*2;
	_idLength = lowLeft->_idLength;
	_colorMapType = lowLeft->_colorMapType;
	_dataTypeCode = lowLeft->_dataTypeCode;
	_colorMapOrigin = lowLeft->_colorMapOrigin;
	_colorMapLength = lowLeft->_colorMapLength;
	_colorMapDepth = lowLeft->_colorMapDepth;
	_xOrigin = lowLeft->_xOrigin;
	_yOrigin = lowLeft->_yOrigin;
	_bitsPerPixel = lowLeft->_bitsPerPixel;
	_imageDescriptor = lowLeft->_imageDescriptor;

	// Operation
	_arrayOfPixels = new unsigned char[(_width * _height * 3)];
	for (unsigned int i = 0; i < _height / 2 ; i++)
	{
		for (unsigned int j = 0; j < _width * 3; j++)
		{
			if (j < (_width * 3 / 2))
			{
				_arrayOfPixels[(_width * 3 * i) + j] = lowLeft->_arrayOfPixels[((lowLeft->_width) * 3 * i) + j];
			}
			else
			{
				_arrayOfPixels[(_width * 3 * i) + j] = lowRight->_arrayOfPixels[((lowRight->_width) * 3 * i) + j - _width * 3 / 2];
			}
		}
	}
	for (unsigned int i = 0; i < _height / 2; i++)
	{
		for (unsigned int j = 0; j < _width * 3; j++)
		{
			if (j < (_width * 3 / 2))
			{
				_arrayOfPixels[(_width * 3 * (_height / 2 + i)) + j] = upLeft->_arrayOfPixels[((lowLeft->_width) * 3 * i) + j];
			}
			else
			{
				_arrayOfPixels[(_width * 3 * (_height / 2 + i)) + j] = upRight->_arrayOfPixels[((upRight->_width) * 3 * i) + j - _width * 3 / 2];
			}
		}
	}
}
