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
         //! return :
         //! true - �������� ��������� ������
         //! false - � �������� ������ �������� ��������  
         bool parsingWebPage( const string& input );

         //! ������� ������� � �������������� ������ 
         string& getPage() const;

      private:

         //! ������� ����������� �������� �����
         static size_t WriteCallback( void* contents, size_t size, size_t nmemb, void* userp );

         //! ������� �������� ������������� ����������� ������ ������� parsingWebPage
         //! FIXME : ����� ��� ����� ���������� -> ������� ��� ���������� ������ 
         void checkingResult( CURLcode result);

         //! ����������� �����������
         //! �������� ��� ���������� ���������� ��������� � �����������
         TWebDownloader( const TWebDownloader& T ) = delete;

         //! ���������� ��� ������ � �������� ���� ��� ��������
         CURL* curl = nullptr;                        //!< ��������� �� ���������� ����������� CURL
         CURLcode resultCURLFunc;                     //!< ������������, ���������� ��������� ������ ������� ���������� CURL 
         string readBuffer;                           //!< ���������� ��� ������������� �������� 
   };
}

#endif // !_T_WEB_PARSER_HPP_