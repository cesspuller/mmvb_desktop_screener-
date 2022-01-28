#include "webParser.hpp"
#include "stringParser.hpp"
#include <iostream>

using namespace WebParser;

int main()
{
   string input = "https://bcs-express.ru/kotirovki-i-grafiki/lkoh";
   TWebDownloader webDownloader;
   TStringParser stringParser;

   webDownloader.parsingWebPage( input );
   string pageCode  = webDownloader.getReadBuffer();

   stringParser.tickerParser( pageCode );
   
   return 0;
};
