package main

import (
	"fmt"
	"math"
)

func main() {
	var n, s int
	fmt.Scan(&n)
	ar := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&ar[i])
		s += ar[i]
	}
	ans := math.MaxInt64
	for k := 1; k < (1 << n); k++ {
		a := 0
		for i := 0; i < n; i++ {
			if (1<<i)&k > 0 {
				a += ar[i]
			}
		}
		diff := s - 2*a
		if diff < 0 {
			diff *= -1
		}
		ans = min(ans, diff)
	}
	fmt.Println(ans)
}

// full path: main_test.go
