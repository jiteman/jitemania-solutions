#pragma once


#include "jsd/platform_support/common_shared_library_support.h"


#if defined( JSD_SSC_DERIVED_LIBRARY_TEMPLATE_SHARED_INTERFACE_INTERNAL )
	#define JSD_SSC_DERIVED_LIBRARY_TEMPLATE_SHARED_INTERFACE		JSD_SHARED_EXPORT_CONVENTION

#else
	#define JSD_SSC_DERIVED_LIBRARY_TEMPLATE_SHARED_INTERFACE		JSD_SHARED_IMPORT_CONVENTION

#endif