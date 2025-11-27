#include "include/hook.h"

struct hook_t *hook_init(const char *moduleName, const char *funcName, PVOID funcHook) {
  DWORD protect = PAGE_EXECUTE_READWRITE;
  struct hook_t *res = (struct hook_t *) malloc(sizeof(struct hook_t));
  res->func = (PVOID) GetProcAddress(GetModuleHandle(moduleName), funcName);
  res->hook = funcHook;
  memset(res->backupBytes, 0, sizeof(BYTE) * SIZE_CODE);

  VirtualProtect((PVOID) res->func, SIZE_CODE, PAGE_EXECUTE_READWRITE, &protect);
  memcpy(res->backupBytes, res->func, SIZE_CODE);
  return res;
}

void hook_enable(struct hook_t *hook) {
#if defined(__x86_64__) || defined(_M_X64)
  BYTE tmp[SIZE_CODE] = {0x49, 0xba, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0xff, 0xe2};
#else
  BYTE tmp[SIZE_CODE] = {0xb8, 0x00, 0x00, 0x00, 0x00, 0xff, 0xe0};
#endif
  memcpy(&tmp[IDX_PTR], &(hook->hook), SIZE_ADDR);
  memcpy(hook->func, tmp, SIZE_CODE);
}

void hook_free(struct hook_t *hook) {
  free(hook);
}

void hook_disable(struct hook_t *hook) {
  memcpy(hook->func, hook->backupBytes, SIZE_CODE);
}
