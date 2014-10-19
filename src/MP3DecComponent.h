#ifndef __MP3_DEC_COMPONENT_H
#define __MP3_DEC_COMPONENT_H

#include "BaseComponent.h"
#include "ComponentLoader.h"

#ifdef __cplusplus
extern "C" {
#endif

int (*fptr)(stComponentInfo& stComponents);

extern int create_plugin(stComponentInfo& stComponents);

#ifdef __cplusplus
};
#endif

class MP3DecComponent:public BaseComponent{
public:
	static OMX_ERRORTYPE MP3DecComponent_Construct(OMX_COMPONENTTYPE* handle,OMX_STRING cComponentName);
};

#endif	//	__MP3_DEC_COMPONENT_H
