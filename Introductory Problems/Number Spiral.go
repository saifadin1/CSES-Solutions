package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	f := bufio.NewReader(os.Stdin)
	w := bufio.NewWriter(os.Stdout)
	defer w.Flush()

	var t int
	fmt.Fscan(f, &t)

	for t > 0 {
		t--
		var x, y int
		fmt.Fscan(f, &x, &y)

		if x == 1 && y == 1 {
			fmt.Fprintln(w, 1)
			continue
		}

		layer := max(x, y)
		index := min(x, y)
		lower := (layer-1)*(layer-1) + 1
		upper := layer * layer

		if layer%2 == 1 {
			if y >= x {
				fmt.Fprintln(w, upper-index+1)
			} else {
				fmt.Fprintln(w, lower+index-1)
			}
		} else {
			if y >= x {
				fmt.Fprintln(w, lower+index-1)
			} else {
				fmt.Fprintln(w, upper-index+1)
			}
		}
	}
}
