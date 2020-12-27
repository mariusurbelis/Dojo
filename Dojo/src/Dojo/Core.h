#pragma once

#ifdef DOJO_BUILD_DLL

#define DOJO_API _declspec(dllexport)

#else

#define DOJO_API _declspec(dllimport)

#endif // DOJO_BUILD_DLL
