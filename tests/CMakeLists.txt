macro(package_add_test_with_libraries TESTNAME FILES LIBRARIES INCLUDE
      TEST_WORKING_DIRECTORY)
  add_executable(${TESTNAME} ${FILES})
  target_include_directories(${TESTNAME} PRIVATE ${INCLUDE})
  target_link_libraries(${TESTNAME} gtest gmock gtest_main ${LIBRARIES})
  gtest_discover_tests(
    ${TESTNAME}
    WORKING_DIRECTORY ${TEST_WORKING_DIRECTORY}
    PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${TEST_WORKING_DIRECTORY}")
  set_target_properties(
    ${TESTNAME} PROPERTIES BUILD_RPATH "/usr/local/lib/")
                            # INSTALL_RPATH "/so/should/this")
  set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
endmacro()

set(test_libraries client ${TWSAPI})

set(test_includes "/usr/local/include/twsapi/" "/usr/local/include/")

package_add_test_with_libraries(ContractBuilderTest ContractBuilderTest.cpp
                                "${test_libraries}" "${test_includes}" "")
package_add_test_with_libraries(SingleActionTest SingleActionTest.cpp
                                "${test_libraries}" "${test_includes}" "")
