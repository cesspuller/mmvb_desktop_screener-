#ifndef _T_Web_Parcer_HPP_
#define _T_Web_Parcer_HPP_

#include "../CurlHPP/curl.h"
#include <string>

using namespace std;

namespace WebParcer
{
   //! ����� ����������� ������� http/https �������� � �������� ���������� ���������� 
   class TWebParcer
   {
      public:

         //! ����������� �� ��������� 
         TWebParcer() = default;

         //! ���������� �� ��������� 
         ~TWebParcer() = default;

         //! ������� ����������� �������� �����
         static size_t WriteCallback( void* contents, size_t size, size_t nmemb, void* userp );

         //! ������� ����������� ������ ��� �������� � ������������ �� � readBuffer
         string& parcingWebPage( string input );

      private:

         //! ���������� ��� ������ � �������� ���� ��� ��������
         CURL* curl;                           //!< ��������� �� ���������� �����������
         CURLcode res;                         //!< ������������, ���������� ��������� ������ ������� ���������� CURL 
         string readBuffer;                    //!< ���������� ��� ������������� �������� 
   };
}

#endif // !_T_Web_Parcer_HPP_

