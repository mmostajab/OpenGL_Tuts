#include "application.h"

#include <iostream>

//#define  DEBUG_MEM_LEAKS
#ifdef   DEBUG_MEM_LEAKS
# define _CRTDBG_MAP_ALLOC
# include <stdlib.h>
# include <crtdbg.h>
#endif //DEBUG_MEM_LEAKS



int main(int argc, char** argv) {
#ifdef DEBUG_MEM_LEAKS
  _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
  //_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);
#endif

  int nArgs = argc > 7 ? 7 : argc;
  // 17.0 ---> 17.2
  std::string arguments[7] = {  "vel.rvf", "0.0", "0.1", "0.2", "0.6", "0.001", "0.001" };

  for (int i = 1; i < nArgs; i++)
    arguments[i-1] = argv[i];

  Application app(arguments[0], atof(arguments[1].c_str()), atof(arguments[2].c_str()), atof(arguments[3].c_str()), atof(arguments[4].c_str()), atof(arguments[5].c_str()), atof(arguments[6].c_str()));

  std::cout << "W/S Increases / Decreases minimum range value\n";
  std::cout << "D/A Increases / Decreases maximum range value\n";

  app.init(800, 600);

  app.run();

  app.shutdown();

#ifdef DEBUG_MEM_LEAKS
  _CrtDumpMemoryLeaks();
#endif

  return 0;
}