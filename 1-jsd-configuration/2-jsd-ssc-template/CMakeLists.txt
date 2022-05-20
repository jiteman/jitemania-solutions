cmake_minimum_required( VERSION 3.16.3 )

project( jsd_ssc_template ) # separate source component


JSD_SHOW_PROJECT_GROUP_HEADER()


set( JSD_SSC_CMAKE_PATH ${PROJECT_SOURCE_DIR}/0-ssc-cmake )
set( JSD_SSC_SOURCE_PATH ${PROJECT_SOURCE_DIR}/1-ssc-repository/source-repository )


add_subdirectory( 2-ssc-base-library )
add_subdirectory( 3-ssc-derived-library )
add_subdirectory( 4-ssc-executable )


JSD_SHOW_PROJECT_GROUP_FOOTER()
