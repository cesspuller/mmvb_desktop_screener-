#include "webParser.hpp"
#include "stringParser.hpp"
#include <iostream>

using namespace WebParser;

int main()
{
   string input = "https://bcs-express.ru/kotirovki-i-grafiki/msft";
   TWebDownloader webDownloader;
   TStringParser stringParser;

   webDownloader.parsingWebPage( input );
   string pageCode  = webDownloader.getReadBuffer();

   cout << stringParser.tickerParser( pageCode ) << endl;
   cout << stringParser.priceParser( pageCode ) << endl;
   cout << stringParser.percentParser( pageCode ) << endl;
   
   return 0;
};
