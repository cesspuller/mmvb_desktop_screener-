#ifndef _T_WEB_PARSER_HPP_
#define _T_WEB_PARSER_HPP_

#include "../CurlHPP/curl.h"
#include <string>

using namespace std;

namespace WebParser
{
   //! Класс реализующий парсинг http/https страницы и хранение полученной информации 
   class __declspec( dllexport ) TWebDownloader
   {
      public:

         //! Конструктор по умолчанию 
         TWebDownloader() = default;

         //! Деструктор по умолчанию 
         ~TWebDownloader() = default;

         //! Функция выполняющая запись вэб страницы и записывающая ее в readBuffer
         //! input - Адресс откуда скачивается код страницы 
         //! return :
         //! true - Успешный результат работы
         //! false - В процессе работы возникли проблемы  
         bool parsingWebPage( const string& input );

         //! Функция доступа к резулитирующей строке 
         string& getPage() const;

      private:

         //! Функция выполняющая обратный вызов
         static size_t WriteCallback( void* contents, size_t size, size_t nmemb, void* userp );

         //! Функция проверки промежуточных результатов работы функции parsingWebPage
         //! FIXME : НУЖНА ДЛЯ ЭТАПА РАЗРОБОТКИ -> УДАЛИТЬ ПРИ ПОДГОТОВКЕ РЕЛИЗА 
         void checkingResult( CURLcode result);

         //! Конструктор копирования
         //! Запрещён для реализации синхронных процессов в многопотоке
         TWebDownloader( const TWebDownloader& T ) = delete;

         //! Переменные для записи и хранения кода вэб страницы
         CURL* curl = nullptr;                        //!< Указатель на дескриптор уйстройства CURL
         CURLcode resultCURLFunc;                     //!< Перечисление, содержащие результат работы функций фреймворка CURL 
         string readBuffer;                           //!< Полученный код запрашиваемой страницы 
   };
}

#endif // !_T_WEB_PARSER_HPP_