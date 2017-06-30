## Chinese passphrase generator

A cross-platform Chinese passphrase generator written in C++, using [Qt](https://www.qt.io) and [libsodium](https://download.libsodium.org/doc/ "The Sodium crypto library").  
Windows binary can be downloaded on the [release](https://github.com/cfbao/chinese-diceware/releases) page.

阅读[中文版本](./README.md)

### Security

Randomness of this passphrase generator is provided through libsodium's [random data generator](https://download.libsodium.org/doc/generating_random_data/),
which is considered cryptographically secure.
However, the program itself is not designed with strong security in mind. Please only use it on secure personal computers.
For important, high security passphrases, please use physical dice to generate.

### Build from source

Source code posted here is written and tested on Windows 7 in [Qt Creator](https://www.qt.io/ide/),
using MSVC 2015, Qt 5.9 and libsodium-1.0.12. 
Some variables in [ZhPwdGen.pro](./ZhPwdGen.pro) might need modification for a successful compilation under other environments.