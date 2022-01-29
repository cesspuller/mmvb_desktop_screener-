#ifndef _T_Web_Parcer_HPP_
#define _T_Web_Parcer_HPP_

#include "../CurlHPP/curl.h"
#include <string>

using namespace std;

namespace WebParser
{
   //! Класс реализующий парсинг http/https страницы и хранение полученной информации 
   class TWebDownloader
   {
      public:

         //! Конструктор по умолчанию 
         TWebDownloader() = default;

         //! Деструктор по умолчанию 
         ~TWebDownloader() = default;

         //! Функция выполняющая запись вэб страницы и записывающая ее в readBuffer
         string& parsingWebPage( string input );

      private:

         //! Функция выполняющая обратный вызов
         static size_t WriteCallback( void* contents, size_t size, size_t nmemb, void* userp );

         //! Переменные для записи и хранения кода вэб страницы
         CURL* curl;                           //!< Указатель на дескриптор уйстройства
         CURLcode res;                         //!< Перечисление, содержащие результат работы функций фреймворка CURL 
         string readBuffer;                    //!< Полученный код запрашиваемой страницы 
   };
}

#endif // !_T_Web_Parcer_HPP_

