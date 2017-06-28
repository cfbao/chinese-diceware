## 中文密码生成器

一个用 C++, [Qt](https://www.qt.io) 和 [libsodium](https://download.libsodium.org/doc/ "The Sodium crypto library") 写的跨平台的 Diceware 中文密码生成器。

Read this in [English](./README.en.md).

### 安全性

该密码生成器的选词随机性由 libsodium 的[随机数生成器](https://download.libsodium.org/doc/generating_random_data/)保证，一般来说可以用于加密。但程序本身的安全性并无保证，请只在安全的个人电脑上使用。特别敏感、重要的密码 请使用**实物**骰子和词表生成。

### 编译

这里发出来的源码是在 Windows 7 上 [Qt Creator](https://www.qt.io/ide/) 里用 MSVC 2015, Qt 5.9 和 libsodium-1.0.12 编写、测试的，在其他环境下可能需要修改 [ZhPwdGen.pro](./ZhPwdGen.pro) 中部分变量才能顺利编译。