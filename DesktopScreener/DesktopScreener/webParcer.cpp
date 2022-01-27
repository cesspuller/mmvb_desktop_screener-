#include "webParcer.hpp"
#include <iostream>
#include <string>

using namespace std;

namespace WebParcer
{
   size_t TWebParcer::WriteCallback( void* contents, size_t size, size_t nmemb, void* userp )
   {
      ( ( string* )userp )->append( ( char* )contents, size * nmemb );
      return size * nmemb;
   }

   string& TWebParcer::parcingWebPage( string input )
   {
      curl = curl_easy_init();

      if ( curl )
      {
         curl_easy_setopt( curl, CURLOPT_URL, input );
         curl_easy_setopt( curl, CURLOPT_WRITEFUNCTION, WriteCallback );
         curl_easy_setopt( curl, CURLOPT_WRITEDATA, &readBuffer );
         res = curl_easy_perform( curl );
         curl_easy_cleanup( curl );

         return readBuffer;
      }
   };
}