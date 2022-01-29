#ifndef _T_WEB_PARSER_HPP_
#define _T_WEB_PARSER_HPP_

#include "../CurlHPP/curl.h"
#include <string>

using namespace std;

namespace WebParser
{
   //! ����� ����������� ������� http/https �������� � �������� ���������� ���������� 
   class __declspec( dllexport ) TWebDownloader
   {
      public:

         //! ����������� �� ��������� 
         TWebDownloader() = default;

         //! ���������� �� ��������� 
         ~TWebDownloader() = default;

         //! ������� ����������� ������ ��� �������� � ������������ �� � readBuffer
         //! input - ������ ������ ����������� ��� �������� 
         //! return - ��� �������� 
         string& parsingWebPage( const string& input );

      private:

         //! ������� ����������� �������� �����
         static size_t WriteCallback( void* contents, size_t size, size_t nmemb, void* userp );

         //! ���������� ��� ������ � �������� ���� ��� ��������
         CURL* curl = nullptr;                           //!< ��������� �� ���������� �����������
         CURLcode res;                         //!< ������������, ���������� ��������� ������ ������� ���������� CURL 
         string readBuffer;                    //!< ���������� ��� ������������� �������� 
   };
}

#endif // !_T_WEB_PARSER_HPP_