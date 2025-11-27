#ifndef HOOK_H_INCLUDED
#define HOOK_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <windows.h>

#if defined(__x86_64__) || defined(_M_X64)
#define SIZE_CODE 13
#define SIZE_ADDR 8
#define IDX_PTR   2
#else
#define SIZE_CODE 7
#define SIZE_ADDR 4
#define IDX_PTR   1
#endif

struct hook_t {
  BYTE backupBytes[SIZE_CODE];
  PVOID hook;
  PVOID func;
};

struct hook_t *hook_init(const char *moduleName, const char *funcName, PVOID funcHook);
void hook_enable(struct hook_t *hook);
void hook_free(struct hook_t *hook);
void hook_disable(struct hook_t *hook);

#ifdef __cplusplus
}
#endif

#endif
