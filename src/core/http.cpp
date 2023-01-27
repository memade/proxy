#include "stdafx.h"

namespace local {

 Http::Http() {
  Init();
 }

 Http::~Http() {
  UnInit();
 }

 void Http::Init() {
  do {
#if _DEBUG
   m_pLibcurl = libcurlpp::ILibcurlpp::CreateInterface(R"(D:\__Github__\Windows\projects\libcurlpp\bin\x64\Debug\libcurlpp.dll)");
#else

#endif

   if (!m_pLibcurl)
    break;

   m_IsOpen.store(true);
  } while (0);
 }

 void Http::UnInit() {
  libcurlpp::ILibcurlpp::DestoryInterface(m_pLibcurl);
  m_IsOpen.store(false);
 }

 bool Http::Ready() const {
  return m_IsOpen.load();
 }

}///namespace local