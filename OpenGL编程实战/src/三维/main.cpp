#include "3ddemo.h"

#include <Windows.h>



int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                      LPSTR lpCmdLine, int nShowCmd) {
  // SampleCube instance;
  ColorCube instance;
  instance.main(800, 600);

  return 0;
}