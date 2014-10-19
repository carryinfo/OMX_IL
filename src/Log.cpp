#include "Log.h"

std::tr1::shared_ptr<Log>	Log::m_ptrInstance;

std::tr1::shared_ptr<Log> Log::GetInstance()
{
	if(m_ptrInstance==NULL)
	{
		m_ptrInstance=std::tr1::shared_ptr<Log>(new Log());
	}
	return m_ptrInstance;
}

void Log::m_LogV(const char *pszFmt,va_list argp)
{
	struct tm *now;
	struct timeb tb;

	if (NULL==pszFmt||0==pszFmt[0]){
		return;
	}

	if (-1==vsnprintf(logstr,ARRSIZE(logstr),pszFmt,argp)){
		logstr[ARRSIZE(logstr)-1]=0;
	}

	ftime(&tb);
	now=localtime(&tb.time);
	sprintf(datestr,"%04d-%02d-%02d",now->tm_year+1900,now->tm_mon+1,now->tm_mday);
	sprintf(timestr,"%02d:%02d:%02d",now->tm_hour     ,now->tm_min  ,now->tm_sec );
	sprintf(mss,"%03d",tb.millitm);
	printf("[%s %s.%s] %s",datestr,timestr,mss,logstr);
}



void Log::LOG(PRINT_LEVEL ePrintLevel,const char *pszFmt,...)
{
	pthread_mutex_lock(&m_mutex);
	va_list argp;

	va_start(argp,pszFmt);
	if(ePrintLevel<=m_ePrintLevel){
		m_LogV(pszFmt,argp);
	}

	va_end(argp);

	pthread_mutex_unlock(&m_mutex);
}
