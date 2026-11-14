# Experiments C++

## Format code
```bash
git ls-files '*.cpp' '*.hpp' '*.cc' '*.cxx' | xargs clang-format -i
```
## Show deps versions
```bash
vcpkg list --x-install-root=build/vcpkg_installed
```
