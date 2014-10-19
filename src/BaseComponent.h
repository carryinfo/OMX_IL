#ifndef __BASE_COMPONENT_H
#define __BASE_COMPONENT_H

#include <OMX_Component.h>

typedef enum{
	INPUT_PORT_INDEX,
	OUTPUT_PORT_INDEX,
	PORT_INDEX_MAX,
};

class BaseComponent{
public:
	BaseComponent();

	static OMX_ERRORTYPE BaseGetComponentVersion(
			OMX_IN  OMX_HANDLETYPE hComponent,
			OMX_OUT OMX_STRING pComponentName,
			OMX_OUT OMX_VERSIONTYPE* pComponentVersion,
			OMX_OUT OMX_VERSIONTYPE* pSpecVersion,
			OMX_OUT OMX_UUIDTYPE* pComponentUUID);
	static OMX_ERRORTYPE BaseSendCommand(
			OMX_IN  OMX_HANDLETYPE hComponent,
			OMX_IN  OMX_COMMANDTYPE Cmd,
			OMX_IN  OMX_U32 nParam1,
			OMX_IN  OMX_PTR pCmdData);
	static OMX_ERRORTYPE BaseGetParameter(
			OMX_IN  OMX_HANDLETYPE hComponent,
			OMX_IN  OMX_INDEXTYPE nParamIndex,
			OMX_INOUT OMX_PTR pComponentParameterStructure);
	static OMX_ERRORTYPE BaseSetParameter(
			OMX_IN  OMX_HANDLETYPE hComponent,
			OMX_IN  OMX_INDEXTYPE nIndex,
			OMX_IN  OMX_PTR pComponentParameterStructure);
	static OMX_ERRORTYPE BaseGetConfig(
			OMX_IN  OMX_HANDLETYPE hComponent,
			OMX_IN  OMX_INDEXTYPE nIndex,
			OMX_INOUT OMX_PTR pComponentConfigStructure);
	static OMX_ERRORTYPE BaseSetConfig(
			OMX_IN  OMX_HANDLETYPE hComponent,
			OMX_IN  OMX_INDEXTYPE nIndex,
			OMX_IN  OMX_PTR pComponentConfigStructure);
	static OMX_ERRORTYPE BaseGetExtensionIndex(
			OMX_IN  OMX_HANDLETYPE hComponent,
			OMX_IN  OMX_STRING cParameterName,
			OMX_OUT OMX_INDEXTYPE* pIndexType);
	static OMX_ERRORTYPE BaseGetState(
			OMX_IN  OMX_HANDLETYPE hComponent,
			OMX_OUT OMX_STATETYPE* pState);
	static OMX_ERRORTYPE BaseComponentTunnelRequest(
		OMX_IN  OMX_HANDLETYPE hComp,
		OMX_IN  OMX_U32 nPort,
		OMX_IN  OMX_HANDLETYPE hTunneledComp,
		OMX_IN  OMX_U32 nTunneledPort,
		OMX_INOUT  OMX_TUNNELSETUPTYPE* pTunnelSetup);
	static OMX_ERRORTYPE BaseUseBuffer(
			OMX_IN OMX_HANDLETYPE hComponent,
			OMX_INOUT OMX_BUFFERHEADERTYPE** ppBufferHdr,
			OMX_IN OMX_U32 nPortIndex,
			OMX_IN OMX_PTR pAppPrivate,
			OMX_IN OMX_U32 nSizeBytes,
			OMX_IN OMX_U8* pBuffer);
	static OMX_ERRORTYPE BaseAllocateBuffer(
			OMX_IN OMX_HANDLETYPE hComponent,
			OMX_INOUT OMX_BUFFERHEADERTYPE** ppBuffer,
			OMX_IN OMX_U32 nPortIndex,
			OMX_IN OMX_PTR pAppPrivate,
			OMX_IN OMX_U32 nSizeBytes);
	static OMX_ERRORTYPE BaseFreeBuffer(
			OMX_IN  OMX_HANDLETYPE hComponent,
			OMX_IN  OMX_U32 nPortIndex,
			OMX_IN  OMX_BUFFERHEADERTYPE* pBuffer);
	static OMX_ERRORTYPE BaseEmptyThisBuffer(
			OMX_IN  OMX_HANDLETYPE hComponent,
			OMX_IN  OMX_BUFFERHEADERTYPE* pBuffer);
	static OMX_ERRORTYPE BaseFillThisBuffer(
			OMX_IN  OMX_HANDLETYPE hComponent,
			OMX_IN  OMX_BUFFERHEADERTYPE* pBuffer);
	static OMX_ERRORTYPE BaseSetCallbacks(
			OMX_IN  OMX_HANDLETYPE hComponent,
			OMX_IN  OMX_CALLBACKTYPE* pCallbacks,
			OMX_IN  OMX_PTR pAppData);
	static OMX_ERRORTYPE BaseComponentDeInit(
			OMX_IN  OMX_HANDLETYPE hComponent);
	static OMX_ERRORTYPE BaseUseEGLImage(
			OMX_IN OMX_HANDLETYPE hComponent,
			OMX_INOUT OMX_BUFFERHEADERTYPE** ppBufferHdr,
			OMX_IN OMX_U32 nPortIndex,
			OMX_IN OMX_PTR pAppPrivate,
			OMX_IN void* eglImage);
	static OMX_ERRORTYPE BaseComponentRoleEnum(
		OMX_IN OMX_HANDLETYPE hComponent,
		OMX_OUT OMX_U8 *cRole,
		OMX_IN OMX_U32 nIndex);

protected:
	OMX_COMPONENTTYPE *  t_compHandle;
	BasePort* t_ports[PORT_INDEX_MAX];

private:
	pthread_t m_MsgThreadID;
	pthread_t m_MainThreadID;

};

#endif	//	__BASE_COMPONENT_H
