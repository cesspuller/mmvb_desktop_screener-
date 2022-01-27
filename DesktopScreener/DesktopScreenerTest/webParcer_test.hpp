#ifndef _T_WEB_PARCER_HPP_
#define _T_WEB_PARCER_HPP_

#include "../DesktopScreener/webParcer.hpp"
#include <iostream>
#include "../packages/Microsoft.googletest.v140.windesktop.msvcstl.dyn.rt-dyn.1.8.1.4/build/native/include/gtest/gtest.h"


using namespace WebParcer;

//! Тест загрузчика веб страниц
TEST( web_parecer_test, load_page )
{
   TWebDownloader downloader;

   auto result = downloader.parcingWebPage("https://www.cplusplus.com/reference/string/string/append/");

   cout << result;

};

#endif //! _T_WEB_PARCER_HPP_