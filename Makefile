## DEV BUILD
b:
	cmake --build build
gen-build: # generate build
	cmake -S . -B build
gen-fresh-build: # generate fresh build
	cmake -S . -B build --fresh
clean-build: # clean build
	cmake --build build --clean-first
run-build: # run dev build
	build/app/main


## Debug build
gen-debug: # generate debug
	cmake -S . -B debug -DCMAKE_BUILD_TYPE=Debug
gen-fresh-debug: # generate fresh debug
	cmake -S . -B debug -DCMAKE_BUILD_TYPE=Debug --fresh
d:
	cmake --build debug
clean-debug: # clean debug
	cmake --build debug --clean-first
run-debug: # run debug
	debug/app/main


## TESTING BUILDS
gen-test: # generate testing build
	cmake -S . -B build_tests -DPACKAGE_TESTS=On
gen-fresh-test: # generate fresh testing build
	cmake -S . -B build_tests -DPACKAGE_TESTS=On --fresh
test:
	cmake --build build_tests
clean-test:
	cmake --build build_tests --clean-first
run-test: # run all test
	ctest --test-dir build_tests


## TESTING DEBUG BUILD
gen-test-debug: # generate testing debug build
	cmake -S . -B debug_tests -DPACKAGE_TESTS=On -DCMAKE_BUILD_TYPE=Debug
test-debug:
	cmake --build debug_tests
run-test-debug: # run all test
	ctest --test-dir debug_tests


# clean symlinks
clean-sym:
	rm compile_commands.json
	@echo cleaned symlinks

