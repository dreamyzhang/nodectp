#ifndef __COMM_H__
#define __COMM_H__

#ifdef WIN32
	#include <windows.h>
	#include <io.h>
	#include <process.h>
#else
	#include <unistd.h>
	#include <iconv.h>
#endif


#endif