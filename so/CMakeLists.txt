add_library(so SHARED so.cpp)

target_compile_definitions(so PRIVATE SO_EXPORTS=1)

