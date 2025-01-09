package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	r := bufio.NewReader(os.Stdin)
	w := bufio.NewWriter(os.Stdout)
	defer w.Flush()

	var n int
	fmt.Fscan(r, &n)

	count := 0
	for i := 5; i <= n; i *= 5 {
		count += n / i
	}
	fmt.Fprintln(w, count)
}
