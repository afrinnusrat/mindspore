file(GLOB_RECURSE TFLITE_SRC_LIST RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
        *.cc
        )
set_property(SOURCE ${TFLITE_SRC_LIST} PROPERTY COMPILE_DEFINITIONS SUBMODULE_ID=mindspore::SubModuleId::SM_LITE)
add_library(tflite_parser_mid OBJECT
        ${TFLITE_SRC_LIST}
        )
target_link_libraries(tflite_parser_mid mindspore::flatbuffers)
