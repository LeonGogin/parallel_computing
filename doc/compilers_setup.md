
**Note:** All libraries must be compiled using the same compiler. By default, macOS uses `clang`.

This guide provides instructions for compiling with `g++` instead.

---

### Installing `libomp`

To install `libomp` using Homebrew and force compilation with `g++`, run the following command:

```bash
brew install --cc=gcc-13 --build-from-source libomp
```

After installation, add the following environment variables to your shell configuration (e.g., `.bashrc` or `.zshrc`):

```bash
export LDFLAGS="-L/usr/local/opt/libomp/lib"
export CPPFLAGS="-I/usr/local/opt/libomp/include"
```

---

### Installing `Catch2`

To install `Catch2` from source, follow these steps (you can try installing via Homebrew, but additional environment variables might be needed):

1. Run `cmake` to configure the build with `g++` as the compiler:

   ```bash
   cmake -S . -B build -DCMAKE_CXX_COMPILER=/usr/local/bin/g++-13
   ```

2. Build and install `Catch2`:

   ```bash
   sudo cmake --build build/ --target install
   ```
