#include "stringParser.hpp"
#include <string>

using namespace std;

namespace WebParser
{
   void TStringParser::setReadBuffer( const TWebDownloader &buffer )
   {
      writeBuffer = buffer.getReadBuffer();
   };

   string TStringParser::tickerParser( string writeBuffer )
   {
      return writeBuffer;
   };

   string TStringParser::priceParser( string writeBuffer )
   {
      return writeBuffer;
   };

   string TStringParser::percentParser( string writeBuffer )
   {
      return writeBuffer;
   };

   string TStringParser::frameParser( string writeBuffer )
   {
      return writeBuffer;
   };
}