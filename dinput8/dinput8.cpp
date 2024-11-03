#include <windows.h>
#include <stdio.h>
#include "MinHook/include/MinHook.h"

HINSTANCE mHinst = 0, mHinstDLL = 0;

extern "C" UINT_PTR mProcs[6] = {0};

LPCSTR mImportNames[] = {
  "DirectInput8Create",
  "DllCanUnloadNow",
  "DllGetClassObject",
  "DllRegisterServer",
  "DllUnregisterServer",
  "GetdfDIJoystick",
};

#ifndef _DEBUG
inline void log_info(const char* info) {
}
#else
FILE* debug;
inline void log_info(const char* info) {
  fprintf(debug, "%s\n", info);
  fflush(debug);
}
#endif

typedef int (*display_t)(const char*);
display_t display = nullptr;

int display_hook(const char* text) {
    return display("Hello MinHook!");
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
  mHinst = hinstDLL;
  if (fdwReason == DLL_PROCESS_ATTACH) {
    mHinstDLL = LoadLibrary("C:/Windows/System32/dinput8.dll");
    if (!mHinstDLL) {
      return FALSE;
    }
    for (int i = 0; i < 6; ++i) {
      mProcs[i] = (UINT_PTR)GetProcAddress(mHinstDLL, mImportNames[i]);
    }

#ifdef _DEBUG
    debug = fopen("./debug.log", "a");
#endif


    MH_Initialize();

    MH_CreateHook((LPVOID)0x00007ff62fb51634, &display_hook, reinterpret_cast<LPVOID*>(&display));

    MH_EnableHook(nullptr);
  } else if (fdwReason == DLL_PROCESS_DETACH) {
#ifdef _DEBUG
    fclose(debug);
#endif
    FreeLibrary(mHinstDLL);
  }
  return TRUE;
}

extern "C" void DirectInput8Create_wrapper();
extern "C" void DllCanUnloadNow_wrapper();
extern "C" void DllGetClassObject_wrapper();
extern "C" void DllRegisterServer_wrapper();
extern "C" void DllUnregisterServer_wrapper();
extern "C" void GetdfDIJoystick_wrapper();
