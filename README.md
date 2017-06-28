# Diceware 中文词表

Diceware [五笔词表](./wubi.wordlist) 与 [拼音词表](./pinyin.wordlist)，取词自[《现代汉语常用词表》](http://baike.baidu.com/item/%E7%8E%B0%E4%BB%A3%E6%B1%89%E8%AF%AD%E5%B8%B8%E7%94%A8%E8%AF%8D%E8%A1%A8)，分别使用五笔与拼音来编码汉字词语，可用于生成高强度、易记忆的 Diceware 密码。

## Diceware 简介

[Diceware](http://www.diceware.com "Diceware Passphrase Home") 是一种由 Arnold Reinhold 创造的构造密码短语的方法。使用 Diceware 需要一份词表和至少一个骰子。词表由7776 (=6<sup>5</sup>) 个不同的单词构成，每个单词对应一个5位“骰子序号”（如 "46134"），每掷5个/次骰子便可选中一个随机的单词。掷30个/次骰子就能生成一个高强度的6词密码短语。由于每个单词有明确的意思，这样的密码短语通常比相同强度的由随机字符组成的密码更容易记忆。

[最初的 Diceware 词表](http://world.std.com/~reinhold/diceware.wordlist.asc) 是英文的，且生僻词较多，不易于中文母语者使用。之后多种其他版本/语言的 Diceware 词表陆续出现，但至2017年6月尚未在网上发现完整的中文词表，我便动手自制了这两份。

## 中文词表详情

* Diceware 中文词表由三列构成，依次为 `骰子序号` - `五笔/拼音编码` - `汉字单词`，每列之间由 tab 隔开，相比拼音字的Diceware词表要多一列。
* 使用 Diceware 中文词表时，用 五笔/拼音 编码组成密码，中文汉字用于记忆。
* 五笔词表完全由双字词语构成，对应的五笔编码全部为4个字符。
* 拼音词表中的词语编码全部在3-6字符之间，平均编码长度5.54字符。
* 两个词表的编码都构成 [前缀码](http://baike.baidu.com/item/%E5%89%8D%E7%BC%80%E7%A0%81) ([prefix code](https://en.wikipedia.org/wiki/Prefix_code))，因而在使用时无须在单词中另加空格或特殊字符。

## Diceware中文密码生成器

高敏感度的重要密码应当用实物骰子生成，但普通用户的普通密码在计算机上用合适的工具生成也无伤大雅。不过，为确保计算机随机选词的均匀性，词表长度最好改为2的幂。 [五笔8k词表](./wubi8k.wordlist) 与 [拼音8k词表](./pinyin8k.wordlist) 就是为这个目的而制作的。

基于这两个8k词表，我写了两个有图形界面的中文密码生成器，功能一样，分别使用了 {Go, [andlabs/ui](https://github.com/andlabs/ui "Platform-native GUI library for Go")} 和 {C++, [Qt](https://www.qt.io/), [libsodium](https://download.libsodium.org/doc/ "The Sodium crypto library")}，选词随机性分别由 [Go crypto/rand](https://golang.org/pkg/crypto/rand/) 和 [libsodium](https://download.libsodium.org/doc/generating_random_data/) 保证。两个工具都应该可以跨平台编译使用。

## 文本来源
* 现代汉语常用词表：[gist.github.com/indiejoseph](https://gist.github.com/indiejoseph/eae09c673460aa0b56db)，[华宇拼音输入法论坛](http://bbs.unispim.com/forum.php?mod=viewthread&tid=31393)
* 五笔编码表：[rime/rime-wubi](https://github.com/rime/rime-wubi)
