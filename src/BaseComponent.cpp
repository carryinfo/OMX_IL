#include "BaseComponent.h"
#include <stddef.h>


BaseComponent::BaseComponent(){
	t_compHandle->nSize = sizeof(OMX_COMPONENTTYPE);
	t_compHandle->pApplicationPrivate = NULL;
	t_compHandle->GetComponentVersion = BaseGetComponentVersion;
	t_compHandle->SendCommand = BaseSendCommand;
	t_compHandle->GetParameter = BaseGetParameter;
	t_compHandle->SetParameter = BaseSetParameter;
	t_compHandle->GetConfig = BaseGetConfig;
	t_compHandle->SetConfig = BaseSetConfig;
	t_compHandle->GetExtensionIndex = BaseGetExtensionIndex;
	t_compHandle->GetState = BaseGetState;
	t_compHandle->SetCallbacks = BaseSetCallbacks;
	t_compHandle->ComponentDeInit = BaseComponentDeInit;
	t_compHandle->ComponentRoleEnum = BaseComponentRoleEnum;
	t_compHandle->ComponentTunnelRequest =BaseComponentTunnelRequest;

	t_compHandle->AllocateBuffer = BaseAllocateBuffer;
	t_compHandle->UseBuffer = BaseUseBuffer;
	t_compHandle->UseEGLImage = BaseUseEGLImage;
	t_compHandle->FreeBuffer = BaseFreeBuffer;
	t_compHandle->EmptyThisBuffer = BaseEmptyThisBuffer;
	t_compHandle->FillThisBuffer = BaseFillThisBuffer;

	t_compHandle->nVersion.s.nVersionMajor = OMX_VERSION_MAJOR;
	t_compHandle->nVersion.s.nVersionMinor = OMX_VERSION_MINOR;
	t_compHandle->nVersion.s.nRevision = OMX_VERSION_REVISION;
	t_compHandle->nVersion.s.nStep = OMX_VERSION_STEP;
}

OMX_ERRORTYPE BaseComponent::BaseGetComponentVersion(
	OMX_IN  OMX_HANDLETYPE hComponent,
	OMX_OUT OMX_STRING pComponentName,
	OMX_OUT OMX_VERSIONTYPE* pComponentVersion,
	OMX_OUT OMX_VERSIONTYPE* pSpecVersion,
	OMX_OUT OMX_UUIDTYPE* pComponentUUID){
	return OMX_ErrorNone;
}

OMX_ERRORTYPE BaseComponent::BaseSendCommand(
	OMX_IN  OMX_HANDLETYPE hComponent,
	OMX_IN  OMX_COMMANDTYPE Cmd,
	OMX_IN  OMX_U32 nParam1,
	OMX_IN  OMX_PTR pCmdData){
	return OMX_ErrorNone;
}

OMX_ERRORTYPE BaseComponent::BaseGetParameter(
	OMX_IN  OMX_HANDLETYPE hComponent,
	OMX_IN  OMX_INDEXTYPE nParamIndex,
	OMX_INOUT OMX_PTR pComponentParameterStructure){
	return OMX_ErrorNone;
}

OMX_ERRORTYPE BaseComponent::BaseSetParameter(
	OMX_IN  OMX_HANDLETYPE hComponent,
	OMX_IN  OMX_INDEXTYPE nIndex,
	OMX_IN  OMX_PTR pComponentParameterStructure){
	return OMX_ErrorNone;
}

OMX_ERRORTYPE BaseComponent::BaseGetConfig(
	OMX_IN  OMX_HANDLETYPE hComponent,
	OMX_IN  OMX_INDEXTYPE nIndex,
	OMX_INOUT OMX_PTR pComponentConfigStructure){
	return OMX_ErrorNone;
}

OMX_ERRORTYPE BaseComponent::BaseSetConfig(
	OMX_IN  OMX_HANDLETYPE hComponent,
	OMX_IN  OMX_INDEXTYPE nIndex,
	OMX_IN  OMX_PTR pComponentConfigStructure){
	return OMX_ErrorNone;
}

OMX_ERRORTYPE BaseComponent::BaseGetExtensionIndex(
	OMX_IN  OMX_HANDLETYPE hComponent,
	OMX_IN  OMX_STRING cParameterName,
	OMX_OUT OMX_INDEXTYPE* pIndexType){
	return OMX_ErrorNone;
}

OMX_ERRORTYPE BaseComponent::BaseGetState(
	OMX_IN  OMX_HANDLETYPE hComponent,
	OMX_OUT OMX_STATETYPE* pState){
	return OMX_ErrorNone;
}

OMX_ERRORTYPE BaseComponent::BaseComponentTunnelRequest(
OMX_IN  OMX_HANDLETYPE hComp,
OMX_IN  OMX_U32 nPort,
OMX_IN  OMX_HANDLETYPE hTunneledComp,
OMX_IN  OMX_U32 nTunneledPort,
OMX_INOUT  OMX_TUNNELSETUPTYPE* pTunnelSetup){
	return OMX_ErrorNone;
}

OMX_ERRORTYPE BaseComponent::BaseUseBuffer(
	OMX_IN OMX_HANDLETYPE hComponent,
	OMX_INOUT OMX_BUFFERHEADERTYPE** ppBufferHdr,
	OMX_IN OMX_U32 nPortIndex,
	OMX_IN OMX_PTR pAppPrivate,
	OMX_IN OMX_U32 nSizeBytes,
	OMX_IN OMX_U8* pBuffer){
	return OMX_ErrorNone;
}

OMX_ERRORTYPE BaseComponent::BaseAllocateBuffer(
	OMX_IN OMX_HANDLETYPE hComponent,
	OMX_INOUT OMX_BUFFERHEADERTYPE** ppBuffer,
	OMX_IN OMX_U32 nPortIndex,
	OMX_IN OMX_PTR pAppPrivate,
	OMX_IN OMX_U32 nSizeBytes){
	return OMX_ErrorNone;
}

OMX_ERRORTYPE BaseComponent::BaseFreeBuffer(
	OMX_IN  OMX_HANDLETYPE hComponent,
	OMX_IN  OMX_U32 nPortIndex,
	OMX_IN  OMX_BUFFERHEADERTYPE* pBuffer){
	return OMX_ErrorNone;
}

OMX_ERRORTYPE BaseComponent::BaseEmptyThisBuffer(
	OMX_IN  OMX_HANDLETYPE hComponent,
	OMX_IN  OMX_BUFFERHEADERTYPE* pBuffer){
	return OMX_ErrorNone;
}

OMX_ERRORTYPE BaseComponent::BaseFillThisBuffer(
	OMX_IN  OMX_HANDLETYPE hComponent,
	OMX_IN  OMX_BUFFERHEADERTYPE* pBuffer){
	return OMX_ErrorNone;
}

OMX_ERRORTYPE BaseComponent::BaseSetCallbacks(
	OMX_IN  OMX_HANDLETYPE hComponent,
	OMX_IN  OMX_CALLBACKTYPE* pCallbacks,
	OMX_IN  OMX_PTR pAppData){
	return OMX_ErrorNone;
}

OMX_ERRORTYPE BaseComponent::BaseComponentDeInit(
	OMX_IN  OMX_HANDLETYPE hComponent){
	return OMX_ErrorNone;
}

OMX_ERRORTYPE BaseComponent::BaseUseEGLImage(
	OMX_IN OMX_HANDLETYPE hComponent,
	OMX_INOUT OMX_BUFFERHEADERTYPE** ppBufferHdr,
	OMX_IN OMX_U32 nPortIndex,
	OMX_IN OMX_PTR pAppPrivate,
	OMX_IN void* eglImage){
	return OMX_ErrorNone;
}

OMX_ERRORTYPE BaseComponent::BaseComponentRoleEnum(
OMX_IN OMX_HANDLETYPE hComponent,
OMX_OUT OMX_U8 *cRole,
OMX_IN OMX_U32 nIndex){
	return OMX_ErrorNone;
}

