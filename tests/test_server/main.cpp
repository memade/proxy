#include <win.h>
#include <libuvpp.hpp>

int main(int argc, char** argv) {
#if defined(_DEBUG)
 ::_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
 //::_CrtSetBreakAlloc(3709);
#endif

 libuvpp::ILibuv* gpLibuv = libuvpp::ILibuv::CreateInterface(R"(D:\__Github__\Windows\bin\x64\Debug\libuvpp.dll)");
 libuvpp::IServer* gpServer = nullptr;
 do {
  if (!gpLibuv)
   break;
  gpServer = gpLibuv->CreateServer();
  if (!gpServer)
   break;
  gpServer->OnSessionCreateAfterCb(
   [&](libuvpp::ISession* session) {

    auto sk = 0;
   });
  gpServer->OnSessionDestoryAfterCb([&](libuvpp::ISession* session) {

   auto sk = 0;
   });
  gpServer->OnSessionDestoryBeforeCb([&](libuvpp::ISession* session) {
   session->Read([](const auto& read){
    std::cout << read << std::endl;
    });

   });
  gpServer->OnServerMessage(
   [&](libuvpp::ISession* session, const std::string& message) {
    std::cout << message << std::endl;
   });

  auto config = gpServer->ConfigGet();
  config->IPAddr("0.0.0.0");
  config->Port(8800);
  if (!gpServer->Start())
   break;


  auto sk = 0;
 } while (0);





 shared::Win::MainProcess(
  [&](const std::string& input, bool& exit) {

   if (input == "q") {

    exit = true;
   }
  });

 return 0;
}
