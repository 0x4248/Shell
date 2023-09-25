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
> The makefile will be changed and should not be put into version control our .gitignore file will ignore it for you.

## 📖 Usage
To run the shell, run the following command:
```bash
./shell
```

## ✅ OS Support

Linux is fully supported. MacOS and Windows may work but are not fully tested. 

## 📝 Licence

This project is licensed under the GNU General Public License v3.0 - see the [LICENCE](LICENCE) file for details.
