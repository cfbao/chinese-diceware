### Experimental passphrase generator

This is another Chinese passphrase generator app,
written in Go using [andlabs/ui](https://github.com/andlabs/ui "Platform-native GUI library for Go").
Cryptographically secure randomness is provided through [go pkg crypto/rand](https://golang.org/pkg/crypto/rand).
However, limitations and problems in andlabs/ui mean that this app is still mostly experimental.