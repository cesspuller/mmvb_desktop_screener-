#ifndef _T_WEB_PARCER_HPP_
#define _T_WEB_PARCER_HPP_

#include "../DesktopScreener/webParser.hpp"
#include <iostream>
#include "../packages/Microsoft.googletest.v140.windesktop.msvcstl.dyn.rt-dyn.1.8.1.4/build/native/include/gtest/gtest.h"
#include <iostream> 
#include <fstream>
#include <string>


using namespace WebParser;

//! Тест загрузчика веб страниц
TEST( web_parser_test, load_page )
{
   int numVal = 1612; //!< Колличество правильных символов до возврата корретки 

   TWebDownloader downloader;
   
   auto resultProb = downloader.parsingWebPage("https://www.cplusplus.com/reference/string/string/append/");
   EXPECT_TRUE( resultProb );

   auto strPage = downloader.getPage();
   ifstream file( "./DesktopScreenerTest/fileHtml.txt" );
   string line;
   string testPage;

   while(std::getline( file, line ))
   {
      testPage += line;
      testPage += "\n";
   }

   for ( int a = 0; a < numVal; ++a )
      EXPECT_EQ( testPage[a], strPage[a] );
};

#endif //! _T_WEB_PARCER_HPP_