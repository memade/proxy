#include "stdafx.h"

namespace local {

 Server::Server() {
  Init();
 }

 Server::~Server() {
  UnInit();
 }

 void Server::Init() {
  do {
#if _DEBUG
   m_pLibuv = libuvpp::ILibuv::CreateInterface(R"(D:\__Github__\Windows\projects\libuvpp\bin\x64\Debug\libuvpp.dll)");
#else

#endif
   if (!m_pLibuv)
    break;
   m_pLibuvServer = m_pLibuv->CreateProxyTcp();
   if (!m_pLibuvServer)
    break;
   m_pLibuvServer->OnConnect(
    [&](libuvpp::ISession* session) {
     OnConnect(session);
    });
   m_pLibuvServer->OnDisconnect(
    [&](libuvpp::ISession* session) {
     OnDisconnect(session);
    });
   m_pLibuvServer->OnMessage(
    [&](libuvpp::ISession* session, const std::string& message) {
     OnMessage(session, message);
    });
   auto config = m_pLibuvServer->ConfigGet();
   config->IPAddr(R"(0.0.0.0:8800)");
   config->IPV(libuvpp::EnIPV::IPV4);
   config->SocketType(libuvpp::EnSocketType::TCP);
   if (!m_pLibuvServer->Start())
    break;
   m_IsOpen.store(true);
  } while (0);
 }

 void Server::UnInit() {
  if (m_pLibuvServer) {
   m_pLibuvServer->Stop();
   /*m_pLibuvServer->Release();*/
  }
  libuvpp::ILibuv::DestoryInterface(m_pLibuv);
  m_IsOpen.store(false);
 }

 bool Server::Ready() const {
  return m_IsOpen.load();
 }

 void Server::OnMessage(libuvpp::ISession* session, const std::string& message) {
  //std::cout << __FUNCTION__ << std::endl;
  std::cout << message << std::endl;
 }
 void Server::OnConnect(libuvpp::ISession* session) {
  session->Read([](const auto& read) {
   std::cout << read << std::endl;
   });
  auto sk = 0;
  std::cout << __FUNCTION__ << std::endl;
 }
 void Server::OnDisconnect(libuvpp::ISession* session) {
  std::cout << __FUNCTION__ << std::endl;
  //session->Read([](const auto& read) {
  // std::cout << read << std::endl;
  // });
  auto sk = 0;
 }
}///namespace local