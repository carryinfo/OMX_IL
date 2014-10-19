#include <OMX_Core.h>
#include "ComponentLoader.h"
#include "Log.h"

static ComponentLoader componentLoader;

OMX_API OMX_ERRORTYPE OMX_APIENTRY OMX_Init(void){
	FUNCTION_IN();
	OMX_ERRORTYPE err=OMX_ErrorNone;
	err=componentLoader.Init();
	FUNCTION_OUT();
	return err;
}

OMX_API OMX_ERRORTYPE OMX_APIENTRY OMX_Deinit(void){
	FUNCTION_IN();
	OMX_ERRORTYPE err=OMX_ErrorNone;
	err=componentLoader.DeInit();
	FUNCTION_OUT();
	return err;
}

OMX_API OMX_ERRORTYPE OMX_APIENTRY OMX_ComponentNameEnum(
    OMX_OUT OMX_STRING cComponentName,
    OMX_IN  OMX_U32 nNameLength,
    OMX_IN  OMX_U32 nIndex){
	FUNCTION_IN();
    OMX_ERRORTYPE err;
    err=componentLoader.ComponentNameEnum(cComponentName,nNameLength,nIndex);
	if (err == OMX_ErrorNone) {
		FUNCTION_OUT();
		return OMX_ErrorNone;
	}
	FUNCTION_OUT();
    return OMX_ErrorComponentNotFound;
}

OMX_API OMX_ERRORTYPE OMX_APIENTRY OMX_GetHandle(
    OMX_OUT OMX_HANDLETYPE* pHandle,
    OMX_IN  OMX_STRING cComponentName,
    OMX_IN  OMX_PTR pAppData,
    OMX_IN  OMX_CALLBACKTYPE* pCallBacks){
	FUNCTION_IN();
	OMX_ERRORTYPE err = OMX_ErrorNone;
	err=componentLoader.CreateComponent(pHandle,cComponentName,pAppData,pCallBacks);
	if (err == OMX_ErrorNone) {
		FUNCTION_OUT();
		return OMX_ErrorNone;
	}

	if (err == OMX_ErrorInsufficientResources) {
		FUNCTION_OUT();
		return OMX_ErrorInsufficientResources;
	}
	FUNCTION_OUT();
	return OMX_ErrorComponentNotFound;
}

OMX_API OMX_ERRORTYPE OMX_APIENTRY OMX_FreeHandle(
    OMX_IN  OMX_HANDLETYPE hComponent){
	FUNCTION_IN();
    OMX_ERRORTYPE err;

    err=componentLoader.DestroyComponent(hComponent);
	if (err == OMX_ErrorNone) {
		FUNCTION_OUT();
		return OMX_ErrorNone;
	}
	FUNCTION_OUT();
    return OMX_ErrorComponentNotFound;
}

OMX_API OMX_ERRORTYPE OMX_APIENTRY OMX_SetupTunnel(
    OMX_IN  OMX_HANDLETYPE hOutput,
    OMX_IN  OMX_U32 nPortOutput,
    OMX_IN  OMX_HANDLETYPE hInput,
    OMX_IN  OMX_U32 nPortInput){
	FUNCTION_IN();
	FUNCTION_OUT();
	return OMX_ErrorNone;
}


OMX_API OMX_ERRORTYPE   OMX_GetContentPipe(
    OMX_OUT OMX_HANDLETYPE *hPipe,
    OMX_IN OMX_STRING szURI){
	FUNCTION_IN();
	FUNCTION_OUT();
	return OMX_ErrorNone;
}

OMX_API OMX_ERRORTYPE OMX_GetComponentsOfRole (
	OMX_IN      OMX_STRING role,
    OMX_INOUT   OMX_U32 *pNumComps,
    OMX_INOUT   OMX_U8  **compNames){
	FUNCTION_IN();
    OMX_ERRORTYPE err;
    vector<string> comps;
    err=componentLoader.GetComponentOfRole(role,comps);
	if (err == OMX_ErrorNone) {
		*pNumComps=comps.size();
		for(int i=0;i<comps.size();i++){
			strcpy((char*)(*compNames+i),comps[i].c_str());
		}
		FUNCTION_OUT();
		return OMX_ErrorNone;
	}
	FUNCTION_OUT();
    return OMX_ErrorComponentNotFound;
}

OMX_API OMX_ERRORTYPE OMX_GetRolesOfComponent (
	OMX_IN      OMX_STRING compName,
    OMX_INOUT   OMX_U32 *pNumRoles,
    OMX_OUT     OMX_U8 **roles){
	FUNCTION_IN();
    OMX_ERRORTYPE err;
    vector<string> vRoles;
    err=componentLoader.GetRolesOfComponent(compName,vRoles);
	if (err == OMX_ErrorNone) {
		*pNumRoles=vRoles.size();
		for(int i=0;i<vRoles.size();i++){
			strcpy((char*)(*roles+i),vRoles[i].c_str());
		}
		FUNCTION_OUT();
		return OMX_ErrorNone;
	}
	FUNCTION_OUT();
    return OMX_ErrorComponentNotFound;
}

