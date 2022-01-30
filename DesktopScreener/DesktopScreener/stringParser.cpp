#include "stringParser.hpp"
#include <string>
#include <algorithm>

using namespace std;

namespace WebParser
{
   void TStringParser::setReadBuffer( const TWebDownloader &buffer )
   {
      writeBuffer = buffer.getReadBuffer();
   };

   string TStringParser::tickerParser( string writeBuffer )
   {
      size_t firstFound = writeBuffer.find( "grafiki/" );
      string firstEq = writeBuffer.substr( firstFound + 8 );
      string ticker = firstEq.substr( 0, 4 );

      transform( ticker.begin(), ticker.end(), ticker.begin(), toupper );

      return ticker;
   };

   string TStringParser::priceParser( string writeBuffer )
   {
      size_t firstFound = writeBuffer.find( "price js-price-close" );
      string firstEq = writeBuffer.substr( firstFound + 22);

      size_t secondFound = firstEq.find_first_of("<");
      string price = firstEq.substr( 0 , secondFound );

      size_t space = price.find( "&" );

      if ( space != string::npos )
      {
         const int k = price.find_first_of( "&");
         price.erase( k, 6 );
      }
     
      return price;
   };

   string TStringParser::percentParser( string writeBuffer )
   {
      size_t firstFound = writeBuffer.find( "change js-profit-percent" );
      string firstEq = writeBuffer.substr( firstFound + 26 );

      
      size_t secondFound = firstEq.find_first_of( "<" );
      string percent = firstEq.substr( 0, secondFound );

      size_t space = percent.find( "&" );

      if ( space != string::npos )
      {
         percent.erase( 0, 6 );
         percent.insert( percent.begin(), '+' );
      }

      return percent;
   };

   string TStringParser::frameParser( string writeBuffer )
   {
      return writeBuffer;
   };
}