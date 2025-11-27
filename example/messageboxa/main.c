#include <hook.h>

int WINAPI myMessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType);
struct hook_t *h;

int WINAPI myMessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType) {
    hook_disable(h);
    MessageBoxA(0, "HOOK DLL", "MESSAGE TEST", MB_OK | MB_ICONINFORMATION);
    int ret = MessageBoxA(hWnd, lpText, lpCaption, uType);
    hook_enable(h);
    return ret;
}

INT APIENTRY DllMain(HMODULE hDLL, DWORD Reason, PVOID Reserved) {
  switch(Reason) {
    case DLL_PROCESS_ATTACH:
      h = hook_init("User32", "MessageBoxA", (PVOID) myMessageBoxA);
      hook_enable(h);
      break;
  }
}
