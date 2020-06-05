#ifndef _LINP_EXPORTS_H__
#define _LINP_EXPORTS_H__

#ifdef _WIN32
	#ifdef linp_EXPORTS
		#define LINP_EXPORT __declspec(dllexport)
	#else
		#define LINP_EXPORT __declspec(dllimport)
	#endif
#else
	#define LINP_EXPORT
#endif

#endif