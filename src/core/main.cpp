#include "stdafx.h"

int main(int argc, char** argv) {
#if defined(_DEBUG)
 ::_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
 //::_CrtSetBreakAlloc(3709);
#endif
 local::__gpGlobal = new local::Global();
 if (!local::Global::Ready())
 {
  LOGERROR("Global class init error.");
  return -1;
 }

 LOGINFO("Project ready.");

 shared::Win::MainProcess(
  [&](const std::string& input, bool& exit) {
   if (input == "q") {
    exit = true;
   }
   else {

   }
  });



 SK_DELETE_PTR(local::__gpGlobal);
 return 0;
}
