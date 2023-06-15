#pragma once
#include <string>

class ConvertToUtf8
{
public:
	ConvertToUtf8(std::string file, std::string locale);

	void convert();
	std::string getConvertedText() { return _convertedText; }

private:
	void writeFile();

	std::string _file;
	std::string _locale;
	std::string _convertedFile;
	std::string _convertedText;
	std::string _originalText;
};

