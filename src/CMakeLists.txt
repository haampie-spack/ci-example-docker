set(MYPKG_SOURCE_FILES multiply_by_two.cpp)

add_library(mypkg ${MYPKG_LIBRARY_TYPE} ${MYPKG_SOURCE_FILES})

target_compile_definitions(mypkg PRIVATE
    $<$<BOOL:MYPKG_USE_CUDA>:MYPKG_USE_CUDA>
)

target_include_directories(mypkg PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

target_link_libraries(mypkg PRIVATE
    $<$<BOOL:MYPKG_USE_CUDA>:CUDA::cublas>
    $<$<BOOL:MYPKG_USE_CUDA>:CUDA::cudart>)