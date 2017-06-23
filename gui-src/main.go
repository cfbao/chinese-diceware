package main

import (
	"crypto/rand"
	"github.com/andlabs/ui"
	"math/big"
	"strings"
)

func main() {
	const defaultNWord = 6
	const defaultList = 0
	err := ui.Main(func() {
		// set up gui
		window := ui.NewWindow("五笔/拼音 密码生成器", 450, 150, false)
		listLabel := ui.NewLabel("密码种类： ")
		listCombo := ui.NewCombobox()
		listCombo.Append("五笔")
		listCombo.Append("拼音")
		listCombo.SetSelected(defaultList)
		hbox0 := ui.NewHorizontalBox()
		hbox0.Append(listLabel, true)
		hbox0.Append(listCombo, false)
		nWordLabel := ui.NewLabel("词语个数： ")
		nWordSpinBox := ui.NewSpinbox(1, 10)
		nWordSpinBox.SetValue(defaultNWord)
		hbox1 := ui.NewHorizontalBox()
		hbox1.Append(nWordLabel, true)
		hbox1.Append(nWordSpinBox, false)
		genButton := ui.NewButton("生成新密码")
		pwdEntry := ui.NewEntry()
		hanEntry := ui.NewEntry()
		pwdEntry.SetReadOnly(true)
		hanEntry.SetReadOnly(true)
		vbox := ui.NewVerticalBox()
		vbox.Append(hbox0, false)
		vbox.Append(hbox1, false)
		vbox.Append(genButton, false)
		vbox.Append(pwdEntry, false)
		vbox.Append(hanEntry, false)
		window.SetMargined(true)
		window.SetChild(vbox)
		window.OnClosing(func(*ui.Window) bool {
			ui.Quit()
			return true
		})

		// set up functionality
		var genPwd = func() {
			nWord := nWordSpinBox.Value()
			chosenWords := make([]string, nWord)
			chosenCodes := make([]string, nWord)
			var idx *big.Int
			var list []listItem
			if listCombo.Selected() == 0 {
				list = wubi
			} else {
				list = pinyin
			}
			for i := 0; i < nWord; i++ {
				idx, _ = rand.Int(rand.Reader, big.NewInt(8192))
				chosenWords[i] = list[idx.Int64()].HanZi
				chosenCodes[i] = list[idx.Int64()].Code
			}
			pwdEntry.SetText(strings.Join(chosenCodes, "-"))
			hanEntry.SetText(strings.Join(chosenWords, "-"))
		}
		listCombo.OnSelected(func(*ui.Combobox) { genPwd() })
		nWordSpinBox.OnChanged(func(*ui.Spinbox) { genPwd() })
		genButton.OnClicked(func(*ui.Button) { genPwd() })

		// show window
		genPwd()
		window.Show()
	})
	if err != nil {
		panic(err)
	}
}
