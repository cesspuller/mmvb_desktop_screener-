#ifndef _T_WEB_PARSER_HPP_
#define _T_WEB_PARSER_HPP_

#include "../CurlHPP/curl.h"
#include <string>

using namespace std;

namespace WebParser
{
   //! ����� ����������� ������� http/https �������� � �������� ���������� ���������� 
   class TWebDownloader
   {
      public:

         //! ����������� �� ��������� 
         TWebDownloader() = default;

         //! ���������� �� ��������� 
         ~TWebDownloader() = default;

         string getReadBuffer() const;

         //! ������� ����������� ������ ��� �������� � ������������ �� � readBuffer
         string& parsingWebPage( string input );

      private:

         //! ������� ����������� �������� �����
         static size_t writeCallback( void* contents, size_t size, size_t nmemb, void* userp );

         //! ���������� ��� ������ � �������� ���� ��� ��������
         CURL* curl;                           //!< ��������� �� ���������� �����������
         CURLcode res;                         //!< ������������, ���������� ��������� ������ ������� ���������� CURL 
         string readBuffer;                    //!< ���������� ��� ������������� �������� 
   };
}

#endif // !_T_WEB_PARSER_HPP_
