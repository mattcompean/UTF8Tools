#include <cstdio>
#include "ConvertToUtf8.h"
#include <iostream>
using namespace std;

int main()
{
    printf("hello from %s!\n", "UTF8Conversion");

    ConvertToUtf8 converter("/home/mcompean/ISO 8859-1 Encoding.txt", "Latin1");
    converter.convert();
    cout << "Converted text: " << converter.getConvertedText() << endl;

    return 0;
}