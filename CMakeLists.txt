cmake_minimum_required( VERSION 3.16.3 )

project( jitemania-solutions )


if ( NOT DEFINED JSD_CMAKE_PATH )
	set( JSD_CMAKE_PATH ${CMAKE_SOURCE_DIR}/1-jsd-configuration/0-jsd-cmake/cmake )
endif()

if ( NOT DEFINED JSD_PLATFORM_SOURCES )
	set( JSD_PLATFORM_SOURCES ${CMAKE_SOURCE_DIR}/1-jsd-configuration/1-jsd-platform/sources )
endif()

##if ( NOT DEFINED JSD_EXTERNAL_PREBUILT_DEPENDENCIES_PATH )
##	set( JSD_EXTERNAL_PREBUILT_DEPENDENCIES_PATH ${CMAKE_SOURCE_DIR}/../_external_prebuilt_dependencies )
##endif()

include( ${JSD_CMAKE_PATH}/set-all-settings.cmake )


JSD_SHOW_PROJECT_GROUP_HEADER()


add_subdirectory( 1-jsd-configuration/2-jsd-ssc-template )
add_subdirectory( 7-jsd-libraries/0-library-subproject-template )
add_subdirectory( 9-jsd-applications/0-executable-template )
add_subdirectory( 6-jsd-experimental/0-cpp-standard )
# foreign components
add_subdirectory( 2-jsd-foreign )
##add_subdirectory( _jsd_tpa_components )
#~foreign components

# old jitemania components
##add_subdirectory( _jsd_old_components )
#~jitemania components

# pre jitemania components
##add_subdirectory( _jsd_migration_components )
#~pre jitemania components

# jitemania components
##add_subdirectory( _jsd_layer_low_components )
####add_subdirectory( _jsd_layer_middle_components )
####add_subdirectory( _jsd_layer_high_components )

##add_subdirectory( _jsd_experimental )
#~jitemania components


JSD_SHOW_PROJECT_GROUP_FOOTER()
