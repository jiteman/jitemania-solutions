cmake_minimum_required( VERSION 3.16.3 )

project( jsd-ssc-template ) # separate source component


JSD_SHOW_PROJECT_GROUP_HEADER()


set( JSD_SSC_CMAKE_PATH ${PROJECT_SOURCE_DIR}/0-ssc-cmake )
set( JSD_SSC_SOURCE_PATH ${PROJECT_SOURCE_DIR}/1-ssc-repository )


add_subdirectory( 2-ssc-base-library )
add_subdirectory( 3-ssc-derived-library )
add_subdirectory( 4-ssc-executable )


JSD_SHOW_PROJECT_GROUP_FOOTER()
