#ifndef __COMPONENT_LOADER_H
#define __COMPONENT_LOADER_H

#include <OMX_Core.h>
#include <OMX_Component.h>
#include <string>
#include <vector>
using namespace std;

#define OMX_PLUGINS_PATH	""


typedef struct stComponentInfo{
  OMX_VERSIONTYPE componentVersion;
  string strName;
  vector<string> vNameSpec;
  vector<string> vRoleSpec;
  string strNameRequested;
  OMX_ERRORTYPE (*constructor)(OMX_COMPONENTTYPE*,OMX_STRING cComponentName);
  OMX_U32 nqualitylevels;
//  multiResourceDescriptor** multiResourceLevel;
} stComponentInfo;

class ComponentLoader{
public:
	OMX_ERRORTYPE Init();
	OMX_ERRORTYPE DeInit();

	OMX_ERRORTYPE CreateComponent(OMX_HANDLETYPE* handle,
			OMX_STRING componentName,OMX_PTR appData,
			OMX_CALLBACKTYPE* callback);
	OMX_ERRORTYPE DestroyComponent(OMX_HANDLETYPE hComponent);

	OMX_ERRORTYPE ComponentNameEnum(OMX_STRING componentName,
			OMX_U32 nNameLength,OMX_U32 nIndex);
	OMX_ERRORTYPE GetRolesOfComponent(OMX_STRING compName,vector<string>& roles);
	OMX_ERRORTYPE GetComponentOfRole(OMX_STRING role,vector<string>& vComps);

private:
	OMX_ERRORTYPE m_addPlugin(const string& strPath);
	OMX_ERRORTYPE m_addPlugins();

private:
	vector<stComponentInfo>		m_vComponentInfo;
	vector<void*>				m_vHandleList;
};

#endif	//	__COMPONENT_LOADER_H
