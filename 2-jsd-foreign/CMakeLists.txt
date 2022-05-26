cmake_minimum_required( VERSION 3.16.3 )

project( jsd-foreign )


JSD_SHOW_PROJECT_GROUP_HEADER()


add_subdirectory( 0-tpg-autotesting/0-tpc-googletestmock )
add_subdirectory( 0-tpg-autotesting/0-tpa-gtm )
add_subdirectory( 0-tpg-autotesting/1-tpc-cppunit )
add_subdirectory( 0-tpg-autotesting/1-tpa-cppunit )


JSD_SHOW_PROJECT_GROUP_FOOTER()
