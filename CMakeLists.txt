cmake_minimum_required(VERSION 3.20)
project(myler2 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

set(SRC_LIST
        main.c
        myler.c
        myler_cmdline.c
        myler_list.c
        myler_lyrics.c
        myler_search.c
        myler_ui.c
        myler_utils.c
        mystring.c)

if (UNIX)
    set(SRC_LIST ${SRC_LIST}
            linux/console.c
            linux/httpclient.c
            linux/music.c
            linux/system.c)
elseif (WIN32)
    set(SRC_LIST ${SRC_LIST}
            windows/console.c
            windows/httpclient.c
            windows/music.c
            windows/system.c)
endif ()

if(MSVC)
    add_compile_options("$<$<C_COMPILER_ID:MSVC>:/source-charset:UTF-8>")
elseif (WIN32)
    add_compile_options("-fexec-charset=GBK")
endif()

add_executable(myler2 ${SRC_LIST})
if(WIN32)
    target_link_libraries(myler2 PRIVATE winmm ws2_32)
endif ()