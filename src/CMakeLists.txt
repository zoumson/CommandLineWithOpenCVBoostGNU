function (make_exe name Custom_LIB)

    #Bring the sources
    file(GLOB SOURCES_DEMO ${PROJECT_SOURCE_DIR}/src/${name}/*.cpp)

    #Build the executable
    add_executable(${name} ${SOURCES_DEMO})

    #Link the libraries 
    target_link_libraries(${name} ${Custom_LIB})
    #target_link_libraries(${name} ${Custom_LIB} ${Boost_LIBRARIES})

endfunction()


make_exe(gnu "")
make_exe(opencv "${OpenCV_LIBS}")
make_exe(boost "${Boost_LIBRARIES}")
#set(demo3_libs  lib1 lib2)
#make_exe(demo3 "${demo3_libs}")

#set(demo4_libs  lib1 lib2 ${Boost_LIBRARIES}))
#make_exe(demo3 "${demo4_libs}")