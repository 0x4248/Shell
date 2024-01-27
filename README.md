# 🐚 Shell++
A simple shell written in C++.

## 🔨 Building
### 📝 Dependencies
- [GCC](https://gcc.gnu.org/)
- [Make](https://www.gnu.org/software/make/)

### 🛠️ Building using our Makefile

First install the dependencies, then clone the repository and cd into it:
```bash
apt install gcc make
```
To build the shell, run the following commands:
```bash
make
```

### 🛠️ Building using cmake

#### Manually

First install the dependencies, then clone the repository and cd into it:
```bash
apt install gcc make cmake
```

To build the shell, run the following commands:
```bash
mkdir build
cd build
cmake ..
make
```

Or run cmake in the root directory:

```bash
cmake .
make
```

> **Note**
>
> The makefile will be changed and should not be put into version control

#### Using the script

First install the dependencies, then clone the repository and cd into it:
```bash
apt install gcc make cmake
```

To build the shell, run the following commands:
```bash
sh tools/build_cmake.sh
```

You can also clean the repository using the following command:
```bash
sh tools/clean_cmake.sh
```

## ⚙️ Configuration

This project uses [Kconfig](https://www.kernel.org/doc/html/latest/kbuild/kconfig-language.html) to configure the shell. You will need to install kconfiglib to configure the shell.

To install kconfiglib, run the following command:
```bash
pip3 install kconfiglib
```

To configure the shell, run the following command:
```bash
make menuconfig
```

## 📖 Usage
To run the shell, run the following command:
```bash
./shell
```

## ✅ OS Support

Linux is fully supported. MacOS and Windows may work but are not fully tested. 

## 📝 Licence

This project is licensed under the GNU General Public License v3.0 - see the [LICENCE](LICENCE) file for details.
