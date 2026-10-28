# Copilot Instructions

C++23 playground of small standalone numeric examples (Boost uBLAS, Armadillo). Built with CMake + Ninja; dependencies come from vcpkg (`vcpkg.json`: cxxopts, boost, boost-stacktrace, armadillo, gtest). Requires `VCPKG_ROOT` to be set.

## Build, test, run

- `./build.sh <build|rebuild>` (argument required; no argument prints usage and exits 1):
  - `build`: clean build + test (wipes `build/`, `vcpkg install`, configure, build, `ctest --preset=vcpkg`).
  - `rebuild`: configure + build only (no wipe, no vcpkg install, no tests).
- Incremental: `cmake --preset=vcpkg && cmake --build --preset=vcpkg`
- Tests: `ctest --preset=vcpkg`; single test: `ctest --preset=vcpkg -R <name>`. The `test/` directory is only added when `-DBUILD_TESTS=ON` is passed and does not exist yet; `noTestsAction` is `ignore`.
- Run examples: `./run.sh` (executes `build/src/experiments/math/example{1,2,3}`), or a single one directly, e.g. `build/src/experiments/math/example1`.
- Format: `git ls-files '*.cpp' '*.hpp' '*.cc' '*.cxx' | xargs clang-format -i`
- Lint: `git ls-files '*.cpp' '*.hpp' '*.cc' '*.cxx' | xargs clang-tidy -p build` (needs `build/compile_commands.json` from configure).

CI (`.github/workflows/build.yaml`, on PRs) enforces `clang-format --dry-run --Werror`, clang-tidy over all sources, then the vcpkg preset build and tests. Keep code format- and tidy-clean (`.clang-tidy` enables bugprone, performance, readability, analyzer checks; function size limits 80 lines / 60 statements).

## Architecture

- Root `CMakeLists.txt` adds `src/experiments/<topic>` subdirectories; each topic has its own `CMakeLists.txt`.
- In `src/experiments/math/CMakeLists.txt`, the `add_example(<name>)` function builds `<name>.cpp` into an executable linked with Boost (system, filesystem) and Armadillo. To add an example, create the `.cpp` and add an `add_example(...)` line; also add it to `run_all` in `run.sh`.
- Shared helpers live in `src/constants.hpp` (index/row/column constants), included relatively, e.g. `#include "../../constants.hpp"`.
- `docs/templates/` holds Conan-based template files, not used by the main vcpkg build.
