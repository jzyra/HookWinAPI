# HookWinAPI

This library allows the implementation of interception functions to intercept calls to Windows system functions.  
It enables developers to alter the behavior of system functions by injecting custom code.

# Build

To compile this library, you must have MinGW installed and have the gcc.exe and ar.exe binaries in the PATH environment variable.  
You must then run the following command:

    make.bat

# Functions

## hook\_init

> **Description :** Allows initializing the hook on the Windows system function without activating it.

### Prototype

```c
struct hook_t * hook_init(const char * moduleName, const char * funcname, PVOID funcHook);
```

### Arguments

* `moduleName` (`const char *`): The name of the module (dll file) associated with the Windows system function that will be hooked.
* `funcname` (`const char *`): The name of the Windows system function that will be hooked.
* `funcHook` (`PVOID`): The pointer to the function that will be called instead of the Windows system function.

### Return value

* `struct hook_t *`: A pointer that represents the hook and that will allow the hook to be activated or deactivated.

## hook\_enable

> **Description :** Enables the hook to be activated and the funcHook function (specified in hook_init) to be called instead of the funcname function (specified in hook_init).

### Prototype

```c
void hook_enable(struct hook_t *hook);
```

### Arguments

* `hook` (`struct hook_t *`): The structure returned during the initialization of the hook (hook_init).

## hook\_disable

> **Description :** Disable the hook and call the funcname function (specified in hook_init) instead of the funcHook function (specified in hook_init).

### Prototype

```c
void hook_disable(struct hook_t *hook);
```

### Arguments

* `hook` (`struct hook_t *`): The structure returned during the initialization of the hook (hook_init).

## hook\_free

> **Description :** Frees the memory allocated for the structure returned by the hook_init function.

### Prototype

```c
void hook_free(struct hook_t *hook);
```

### Arguments

* `hook` (`struct hook_t *`): The structure returned during the initialization of the hook (hook_init).
