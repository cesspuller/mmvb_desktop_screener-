#include "webParser.hpp"
#include <iostream>
#include <string>

using namespace std;

namespace WebParser  
{ 
   size_t TWebDownloader::WriteCallback( void* contents, size_t size, size_t nmemb, void* userp )
   {
      ( ( string* )userp )->append( ( char* )contents, size * nmemb );
      return size * nmemb;
   };

   bool TWebDownloader::parsingWebPage( const string& input ) 
   {
      curl = curl_easy_init();

      if ( curl )
      {
         checkingResult( curl_easy_setopt( curl, CURLOPT_URL, input.c_str() ) );
         checkingResult( curl_easy_setopt( curl, CURLOPT_WRITEFUNCTION, WriteCallback ) ) ;
         checkingResult( curl_easy_setopt( curl, CURLOPT_WRITEDATA, &page ) );
         checkingResult( resultCURLFunc = curl_easy_perform( curl ) );
         curl_easy_cleanup( curl );

         if( resultCURLFunc == CURLE_OK )
            return true;
      }

      return false;
   };

   void TWebDownloader::checkingResult( CURLcode result )
   {
      if ( result != CURLE_OK )
      {
         resultCURLFunc = result;
         cout << endl << "! When loading the page, CURL worked freelance! " << endl;
      }
   };

   string& TWebDownloader::getPage() 
   {
      return page;
   };
}