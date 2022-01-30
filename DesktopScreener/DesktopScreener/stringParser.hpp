#ifndef T_STRING_PARSER_HPP_
#define T_STRING_PARSER_HPP_

#include "webParser.hpp"
#include "../CurlHPP/curl.h"
#include <string>

using namespace std;

namespace WebParser
{
   class TStringParser
   {
         public:

            //! ����������� �� ��������� 
            TStringParser() = default;

            //! ���������� �� ���������
            ~TStringParser() = default;

            //! ������� ��������������� �������� ��� writeBuffer
            void setReadBuffer( const TWebDownloader &buffer );

            //! ������� �������� ����� �����
            string tickerParser( string writeBuffer );

            //! ������� �������� ���� �����
            string priceParser( string writeBuffer );

            //! ������� �������� ������� ��������� ����� � ���������
            string percentParser( string writeBuffer );

            //! ������� �������� ��������� ���������� 
            string frameParser( string writeBuffer );

            //!< ���������� ��� ������������� ��������
            string writeBuffer;            

         private:
            
            //!
            string ticker;                        //!< ������ ���������� ����� �����
            string price;                         //!< ������ ���������� ���� �����

   };
}
#endif // !T_STRING_PARSER_HPP_

