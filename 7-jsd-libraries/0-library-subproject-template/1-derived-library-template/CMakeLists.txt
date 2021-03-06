cmake_minimum_required( VERSION 3.16.3 )

project( derived-library-template C CXX ) # [JSD] change this name in copy (!)


JSD_SHOW_PROJECT_HEADER()


## include dependencies
set( ${PROJECT_NAME}_DEPENDENCY_DIRS_VAR
	${JSD_PLATFORM_SOURCES}
	${base-library-template_DEPENDENCY_DIRS} # [JSD] change this name in copy (!)
	${PROJECT_SOURCE_DIR}/sources )
list( REMOVE_DUPLICATES ${PROJECT_NAME}_DEPENDENCY_DIRS_VAR )
include_directories( ${${PROJECT_NAME}_DEPENDENCY_DIRS_VAR} )


## this project headers and sources enumeration section
file( GLOB_RECURSE header_and_source_files ${PROJECT_SOURCE_DIR}/sources/*.h* ${PROJECT_SOURCE_DIR}/sources/*.c* )
add_library( ${PROJECT_NAME} SHARED ${header_and_source_files} )


## definition section
set( ${PROJECT_NAME}_BUILD_DEFINITIONS_VAR
	${base-library-template_LINK_DEFINITIONS} # [JSD] change this name in copy (!)
	-DJSD_derived_library_template_SHARED_INTERFACE_INTERNAL ) # [JSD] change this name in copy (!)
JSD_LIST_TO_STRING( ${PROJECT_NAME}_BUILD_DEFINITIONS_VAR )
JSD_STRING_REMOVE_DUPLICATES( ${PROJECT_NAME}_BUILD_DEFINITIONS_VAR )
set( ${PROJECT_NAME}_LINK_DEFINITIONS_VAR
	${base-library-template_LINK_DEFINITIONS} ) # [JSD] change this name in copy (!)
JSD_LIST_TO_STRING( ${PROJECT_NAME}_LINK_DEFINITIONS_VAR )
JSD_STRING_REMOVE_DUPLICATES( ${PROJECT_NAME}_LINK_DEFINITIONS_VAR )
add_definitions( "${${PROJECT_NAME}_BUILD_DEFINITIONS_VAR}" )


## required to be able to be linked into shared libraries.
set_target_properties( ${PROJECT_NAME} PROPERTIES POSITION_INDEPENDENT_CODE ON )
set_target_properties( ${PROJECT_NAME} PROPERTIES VERSION 0.1.0 )
set_target_properties( ${PROJECT_NAME} PROPERTIES SOVERSION 0.1 )


## project target section
set( ${PROJECT_NAME}_DEPENDENCY_LIBS_VAR
	${base-library-template_DEPENDENCY_LIBS} # [JSD] change this name in copy (!)
	base-library-template ) # [JSD] change in copy
list( REMOVE_DUPLICATES ${PROJECT_NAME}_DEPENDENCY_LIBS_VAR )
target_link_libraries( ${PROJECT_NAME} ${${PROJECT_NAME}_DEPENDENCY_LIBS_VAR} )


## Expose public includes to other subprojects through cache variable.
include( ${JSD_CMAKE_PATH}/set-expose-dependencies.cmake )
JSD_SHOW_PROJECT_FOOTER()
