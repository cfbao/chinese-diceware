# Diceware Chinese wordlists

Diceware [Wubi wordlist](./wubi.wordlist) and [Pinyin wordlist](./pinyin.wordlist) consist of words from
[*Common Vacabulary in Modern Chinese*](https://zh.wikipedia.org/wiki/%E7%8E%B0%E4%BB%A3%E6%B1%89%E8%AF%AD%E5%B8%B8%E7%94%A8%E8%AF%8D%E8%A1%A8) encoded/transliterated to English alphabet using Wubi and Pinyin respectively. They can be used to generate complex, memorable Diceware passphrases.

阅读[中文版本](./README.md)

## Introduction to Diceware

[Diceware](http://www.diceware.com "Diceware Passphrase Home"), created by Arnold Reinhold, is a method to generate passphrases.
To use Diceware, you need a wordlist and at least one dice.
The wordlist should consist of 7776 (=6<sup>5</sup>) distinct words, 
each corresponding to a unique five-digit "dice index" (e.g. "46134").
Every five dice throws can then randomly choose a word. Every 30 dice throws can generate a complex six-word passphrase.
Such passphrases are typically more memorable than passwords (built from random characters) of equivalent complexity.

The [original Diceware wordlist](http://world.std.com/~reinhold/diceware.wordlist.asc) is in English, and contains many obscure words,
making it unsuitable for most native Chinese speakers.
Since then, many other versions of Diceware wordlist have been compiled and in various languages,
but no complete Chinese wordlist can be found on the Internet as of June 2017. So I decided to compile one (or two) myself.

## Details of Chinese wordlists

* Diceware Chinese wordlists consist of three columns, namely `dice index` - `Wubi/Pinyin encoding` - `Chinese characters`, separated from each other by a tab. This is one column more than wordlists for most other languages.
* When using Diceware Chinese wordlist, use the Wubi/Pinyin encoding to build your passphrase. Chinese characters are effectively only mnemonics.
* Wubi wordlist consists of only two-character words, all encoded with only 4 English letters.
* Pinyin wordlist consists of words encoded in 3 to 6 English letters. Average encoding length is 5.54.
* Encodings of both wordlists form [prefix codes](https://en.wikipedia.org/wiki/Prefix_code), so there's no need to add a space or special character in between words.
* All Chinese wordlist files are encoded in UTF-8.

## 8k wordlists and passphrase generator

Important, high-security passphrases should be generated with physical dice,
but regular passphrases for average users may be generated on safe computers using appropriate apps without serious problems.
However, to ensure uniform distribution of word choices, it's best to modify wordlists to have lengths of a power of 2.
[Wubi8k wordlist](./wubi8k.wordlist) and [Pinyin8k wordlist](./pinyin8k.wordlist) are designed with this purpose in mind.

Based on these two 8k wordlists, I wrote a cross-platform [Chinese passphrase generator](./gui-qt) in C++, 
using [Qt](https://www.qt.io/) and [libsodium](https://download.libsodium.org/doc/ "The Sodium crypto library"). Randomness of word choices are provided through libsodium's [random data generator](https://download.libsodium.org/doc/generating_random_data/ "Generating random data · libsodium").

## Sources

* Common Vacabulary in Modern Chinese: [gist.github.com/indiejoseph](https://gist.github.com/indiejoseph/eae09c673460aa0b56db)，[华宇拼音输入法论坛](http://bbs.unispim.com/forum.php?mod=viewthread&tid=31393)
* Wubi encoding: [rime/rime-wubi](https://github.com/rime/rime-wubi)
