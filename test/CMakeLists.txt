find_package(Boost 1.53.0
    COMPONENTS
        program_options
        unit_test_framework
    REQUIRED)

add_executable(test-strong-type
    main.cc
    test_skills.cc)

add_executable(LibStrong::test ALIAS test-strong-type)

#Set target properties
target_include_directories(test-strong-type
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_features(test-strong-type PRIVATE cxx_decltype_auto)
target_link_libraries(test-strong-type PRIVATE
    LibStrong::library
    Boost::program_options
    Boost::unit_test_framework)
