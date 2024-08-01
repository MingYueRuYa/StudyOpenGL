#include "spline_editor.h"

#include <Windows.h>



int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                      LPSTR lpCmdLine, int nShowCmd) {
  SplineEditor instance;
  instance.main(800, 600);

  return 0;
}