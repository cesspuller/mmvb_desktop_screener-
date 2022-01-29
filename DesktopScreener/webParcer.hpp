#ifndef _T_Web_Parcer_HPP_
#define _T_Web_Parcer_HPP_

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

         //! ������� ����������� ������ ��� �������� � ������������ �� � readBuffer
         string& parsingWebPage( string input );

      private:

         //! ������� ����������� �������� �����
         static size_t WriteCallback( void* contents, size_t size, size_t nmemb, void* userp );

         //! ���������� ��� ������ � �������� ���� ��� ��������
         CURL* curl;                           //!< ��������� �� ���������� �����������
         CURLcode res;                         //!< ������������, ���������� ��������� ������ ������� ���������� CURL 
         string readBuffer;                    //!< ���������� ��� ������������� �������� 
   };
}

#endif // !_T_Web_Parcer_HPP_

