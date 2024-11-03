set(CMAKE_GENERATOR_PLATFORM "x64" CACHE STRING "" FORCE)
PROJECT(dinput8)
ENABLE_LANGUAGE(C CXX ASM_MASM)
ADD_LIBRARY(
    dinput8
    SHARED
    dinput8_asm.asm
    dinput8.cpp
    dinput8.def
    MinHook/include/MinHook.h
    MinHook/src/hde/hde32.c
    MinHook/src/hde/hde32.h
    MinHook/src/hde/hde64.c
    MinHook/src/hde/hde64.h
    MinHook/src/hde/pstdint.h
    MinHook/src/hde/table32.h
    MinHook/src/hde/table64.h
    MinHook/src/buffer.c
    MinHook/src/buffer.h
    MinHook/src/hook.c
    MinHook/src/trampoline.c
    MinHook/src/trampoline.h
)
