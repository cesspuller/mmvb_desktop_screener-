#include "webParser.hpp"
#include <string>

using namespace std;

namespace WebParser
{
   string TWebDownloader::getReadBuffer() const
   {
      return readBuffer;
   };

   size_t TWebDownloader::writeCallback( void* contents, size_t size, size_t nmemb, void* userp )
   {
      ( ( string* )userp )->append( ( char* )contents, size * nmemb );
      return size * nmemb;
   };

   string& TWebDownloader::parsingWebPage( string input )
   {
      curl = curl_easy_init();

      if ( curl )
      {
         curl_easy_setopt( curl, CURLOPT_URL, input.c_str() );
         curl_easy_setopt( curl, CURLOPT_WRITEFUNCTION, writeCallback );
         curl_easy_setopt( curl, CURLOPT_WRITEDATA, &readBuffer );
         res = curl_easy_perform( curl );
         curl_easy_cleanup( curl );

         return readBuffer;
      }
   };
}