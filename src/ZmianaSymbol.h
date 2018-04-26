#pragma once
#pragma warning( disable : 4251 )
#pragma warning( disable : 4275 )
#ifdef _WIN32
#   define ZMIANA_API __declspec(dllexport)
#else
#	define ZMIANA_API
#endif
