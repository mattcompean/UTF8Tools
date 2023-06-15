#include "ConvertToUtf8.h"
#include <iostream>
#include <fstream>
#include <streambuf>

ConvertToUtf8::ConvertToUtf8(std::string file, std::string locale)
{
	_file = file;
	_locale = locale;
	_convertedFile = "/home/mcompean/ConvertedText.txt";
	
	std::ifstream reader(_file);

	if (reader.is_open())
	{
		_originalText.assign((std::istreambuf_iterator<char>(reader)),std::istreambuf_iterator<char>());
	}

	reader.close();
}

void ConvertToUtf8::convert()
{
	std::cout << "Original Text: " << _originalText << std::endl;
	std::cout << "Size of Original Text: " << _originalText.length() << std::endl;
	std::cout << "Converting..." << std::endl;
	for (std::string::iterator it = _originalText.begin(); it != _originalText.end(); ++it)
	{
		uint8_t ch = *it;
		if (ch < 0x80) {
			_convertedText.push_back(ch);
		}
		else {
			_convertedText.push_back(0xc0 | (ch & 0xc0) >> 6);
			_convertedText.push_back(0x80 | (ch & 0x3f));
		}
	}

	std::cout << "Writing to file: " << _convertedFile << std::endl;

	writeFile();
}

void ConvertToUtf8::writeFile()
{
	std::ofstream writer(_convertedFile);
	
	if (writer.is_open())
	{
		writer << _convertedText;
	}

	writer.close();
}
