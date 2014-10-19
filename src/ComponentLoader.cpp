#include "ComponentLoader.h"
#include <dlfcn.h>
#include <sys/types.h>
#include <dirent.h>
#include "Log.h"
#include <string.h>

OMX_ERRORTYPE ComponentLoader::Init(){
	FUNCTION_IN();
	OMX_ERRORTYPE err=m_addPlugins();
	if(err!=OMX_ErrorNone){
		FUNCTION_OUT();
		return err;
	}
	FUNCTION_OUT();
	return OMX_ErrorNone;
}

OMX_ERRORTYPE ComponentLoader::DeInit(){
	FUNCTION_IN();
	OMX_ERRORTYPE err;
	for(vector<void*>::const_iterator iter=m_vHandleList.begin();
			iter!=m_vHandleList.end();iter++){
		if(dlclose(*iter)!=0) {
			FATAL_PRINT("Error %d in dlclose\n",err);
		}
	}
	FUNCTION_OUT();
	return OMX_ErrorNone;
}

OMX_ERRORTYPE ComponentLoader::CreateComponent(OMX_HANDLETYPE* handle,
		OMX_STRING componentName,OMX_PTR appData,
		OMX_CALLBACKTYPE* callback){
	int pos=-1;
	for(unsigned int i=0;i<m_vComponentInfo.size();i++){
		if(!strcmp(m_vComponentInfo[i].strName.c_str(),componentName)){
			pos=i;
		}
	}
	if(pos==-1){
		FATAL_PRINT("OMX_ErrorInvalidComponentName\n");
		return OMX_ErrorInvalidComponentName;
	}
	OMX_COMPONENTTYPE* comp=NULL;
	m_vComponentInfo[pos].constructor(comp,componentName);
	*handle=comp;
	((OMX_COMPONENTTYPE*)*handle)->SetCallbacks(*handle, callback, appData);

	return OMX_ErrorNone;
}

OMX_ERRORTYPE ComponentLoader::DestroyComponent(OMX_HANDLETYPE hComponent){
	return OMX_ErrorNone;
}


OMX_ERRORTYPE ComponentLoader::ComponentNameEnum(OMX_STRING componentName,
		OMX_U32 nNameLength,OMX_U32 nIndex){
	return OMX_ErrorNone;
}

OMX_ERRORTYPE ComponentLoader::GetRolesOfComponent(OMX_STRING compName,vector<string>& roles){
	return OMX_ErrorNone;
}

OMX_ERRORTYPE ComponentLoader::GetComponentOfRole(OMX_STRING role,vector<string>& vComps){
	return OMX_ErrorNone;
}

OMX_ERRORTYPE ComponentLoader::m_addPlugin(const string& strPath){
	FUNCTION_IN();
	void* handle;
	typedef int (*F_PTR)(stComponentInfo& stComponents);
	F_PTR fptr;
	if((handle = dlopen(strPath.c_str(), RTLD_NOW)) == NULL) {
		FATAL_PRINT("could not load %s: %s\n", strPath.c_str(), dlerror());
	} else {
		m_vHandleList.push_back(handle);
		if ((fptr = (F_PTR)dlsym(handle, "create_plugin")) == NULL) {
			FATAL_PRINT("FAIL: %s  - %s\n", strPath.c_str(), dlerror());
		} else {
			stComponentInfo compInfo;
			(*fptr)(compInfo);
			m_vComponentInfo.push_back(compInfo);
		}
	}
	FUNCTION_OUT();
	return OMX_ErrorNone;
}

OMX_ERRORTYPE ComponentLoader::m_addPlugins(){
	FUNCTION_IN();
	DIR *dirp;
	struct dirent *dp;

	dirp = opendir(OMX_PLUGINS_PATH);
	if(dirp == NULL){
		FATAL_PRINT("Failed to open directory %s\n", OMX_PLUGINS_PATH);
		FUNCTION_OUT();
		return OMX_ErrorUndefined;
	}

	while((dp = readdir(dirp)) != NULL) {
		int len = strlen(dp->d_name);
		if(len <= 3)
			continue;

		if(strncmp(dp->d_name+len-3, ".so", 3) == 0) {
			string path(OMX_PLUGINS_PATH);
			path.append(dp->d_name);
			m_addPlugin(path);
		}
	}
	FUNCTION_OUT();
	return OMX_ErrorNone;
}
