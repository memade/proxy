#include "stdafx.h"

namespace local {

 Global::Global() {
  Init();
 }
 Global::~Global() {
  UnInit();
 }
 void Global::Init() {
  __gpSpdlog = shared::ISpdlog::CreateInterface(
   shared::Win::GetModuleNameA(true),
   shared::Win::GetModulePathA()
  );

  do {
   m_pHttp = new Http();
   m_pServer = new Server();
   if (!m_pHttp || !m_pHttp->Ready())
    break;
   if (!m_pServer || !m_pServer->Ready())
    break;
   m_Ready.store(true);
  } while (0);
 }
 void Global::UnInit() {
  do {
   SK_DELETE_PTR(m_pHttp);
   SK_DELETE_PTR(m_pServer);
   shared::ISpdlog::DestoryInterface();
   m_Ready.store(false);
  } while (0);
 }
 bool Global::Ready() {
  bool result = false;
  do {
   if (!__gpGlobal)
    break;
   result = __gpGlobal->m_Ready.load();
  } while (0);
  return result;
 }


 extern Global* __gpGlobal = nullptr;
}///namespace local
