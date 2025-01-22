package file

import (
	"bufio"
	"fmt"
	"log"
	"os"
)

type Op struct {
	Nome string
	Func func(string) error
	Arg  string
}

type File struct {
	file   *os.File
	writer *bufio.Writer

	ops chan Op

	Caminho string
}

func NewFile(nome string) (a File, err error) {

	a.Caminho = fmt.Sprintf("/tmp/%s", nome)

	f, err := os.OpenFile(a.Caminho, os.O_APPEND|os.O_CREATE|os.O_WRONLY, 0755)

	if err != nil {

		return
	}

	a.file = f

	w := bufio.NewWriter(f)
	a.writer = w

	return
}

func (a *File) Observe() {

	a.ops = make(chan Op)

	for op := range a.ops {
		err := op.Func(op.Arg)

		if err != nil {

			log.Println(err)
		}
	}
}

func (a *File) Insert(content string) {

	a.ops <- Op{
		"Insert",
		a.insert,
		content,
	}
}

func (a *File) Upload(dest string) {

	a.ops <- Op{
		"Upload",
		a.upload,
		dest,
	}
}

func (a *File) insert(content string) (err error) {

	_, err = a.writer.WriteString(fmt.Sprint(content + "\n"))

	return
}

func (a *File) upload(dest string /* placeholder */) (err error) {

	err = a.writer.Flush()

	if err != nil {

		return
	}

	err = a.file.Truncate(0)
	_, err = a.file.Seek(0, 0)

	copyFile(a.Caminho, dest)

	return
}
