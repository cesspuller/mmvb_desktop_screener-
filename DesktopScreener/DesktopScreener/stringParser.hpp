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

            //! Конструктор по умолчанию 
            TStringParser() = default;

            //! Деструктор по умолчанию
            ~TStringParser() = default;

            //! Функция устанавливающая значение для writeBuffer
            void setReadBuffer( const TWebDownloader &buffer );

            //! Функция парсящая тикер акции
            string tickerParser( string writeBuffer );

            //! Функция парсящая цену акции
            string priceParser( string writeBuffer );

            //! Функция парсящая ценовое изменение акции в процентах
            string percentParser( string writeBuffer );

            //! Функция парсящая временной промежуток 
            string frameParser( string writeBuffer );

            //!< Полученный код запрашиваемой страницы
            string writeBuffer;            

         private:
            
            //!
            string ticker;                        //!< Строка содержащая тикер акции
            string price;                         //!< Строка содержащая цену акции

   };
}
#endif // !T_STRING_PARSER_HPP_

