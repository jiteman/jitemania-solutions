#pragma once


#include "jsd/platform_support/common_shared_library_support.h"


#if defined( JSD_base_library_template_SHARED_INTERFACE_INTERNAL ) // [JSD] change this name in copy (!)
	#define JSD_base_library_template_SHARED_INTERFACE		JSD_SHARED_EXPORT_CONVENTION

#else
	#define JSD_base_library_template_SHARED_INTERFACE		JSD_SHARED_IMPORT_CONVENTION

#endif
