#ifndef __LOG_H
#define __LOG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tr1/memory>

#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <time.h>
#include <sys/timeb.h>
#include <stdarg.h>

#define MAXLOGSIZE 	20000000
#define ARRSIZE(x) 	(sizeof(x)/sizeof(x[0]))

typedef enum PRINT_LEVEL
{
	FATAL,
	MAJOR,
	WARN,
	DEBUG,
	INFO,
}PRINT_LEVEL;

class Log
{
public:
	static std::tr1::shared_ptr<Log> GetInstance();
	Log():m_ePrintLevel(FATAL)
	{
		pthread_mutex_init(&m_mutex,NULL);
	}

	~Log(){pthread_mutex_destroy(&m_mutex);}

	void SetDebugLevel(PRINT_LEVEL ePrintLevel)
	{
		m_ePrintLevel=ePrintLevel;
	}

	void LOG(PRINT_LEVEL ePrintLevel,const char *pszFmt,...);

private:
	void m_LogV(const char *pszFmt,va_list argp);

private:
	static std::tr1::shared_ptr<Log>	m_ptrInstance;
	char 			logstr[16000];
	char 			datestr[16];
	char 			timestr[16];
	char 			mss[4];
	PRINT_LEVEL 	m_ePrintLevel;
	pthread_mutex_t	m_mutex;
};


//	MACORS
#define FATAL_PRINT(fmt, ...)																			\
	Log::GetInstance()->LOG(FATAL,"[%s Line %d]:	"fmt, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#define ERROR_PRINT(fmt, ...)																			\
	Log::GetInstance()->LOG(WARN,"[%s Line %d]:	"fmt, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#define DEBUG_PRINT(fmt, ...)																			\
	Log::GetInstance()->LOG(DEBUG,"[%s Line %d]:	"fmt, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#define INFO_PRINT(fmt, ...)																			\
	Log::GetInstance()->LOG(INFO,"[%s Line %d]:	"fmt, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#define MAJOR_PRINT(fmt, ...)																			\
	Log::GetInstance()->LOG(MAJOR,"[%s Line %d]:	"fmt, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);

#define FUNCTION_IN() FATAL_PRINT("[IN]\n")
#define FUNCTION_OUT() FATAL_PRINT("[OUT]\n")

#endif
