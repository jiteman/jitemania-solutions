cmake_minimum_required( VERSION 3.16.3 )

project( library-subproject-template ) # [JSD] change this name in copy (!)


JSD_SHOW_PROJECT_GROUP_HEADER()


add_subdirectory( 0-base-library-template )
add_subdirectory( 1-derived-library-template )


JSD_SHOW_PROJECT_GROUP_FOOTER()
