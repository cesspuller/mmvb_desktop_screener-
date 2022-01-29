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
   TWebDownloader downloader;
   
   auto result = downloader.parsingWebPage("https://www.cplusplus.com/reference/string/string/append/");
   
};

#endif //! _T_WEB_PARCER_HPP_