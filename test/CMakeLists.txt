include(GoogleTest)
add_executable(mosti_test
  mosti_test.cpp
)

target_link_libraries(mosti_test
  PRIVATE
    Mosti
    ${CONAN_LIBS}
    ${GTest_LIBRARIES}
    GTest::gtest
    GTest::gtest_main
)

gtest_discover_tests(mosti_test)