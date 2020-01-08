package main

import (
	"fmt"
)

var gg int

func t_const() {
	// 显式类型调用
	const a int = 1
	const b int = 2
	// 隐藏式类型调用
	const c = 3

	const LENGTH int = 10
	const WIDTH int = 20
	var area int
	const a2, b2, c2 = 1, false, "str" // 多重赋值
	area = LENGTH * WIDTH
	fmt.Println("面积为：%d", area)
	println()
	println(a2, b2, c2)
	const (
		Unkonw = 0
		Female = 1
		Male   = 2
		HAH    = iota
	)
	println(Male)
	println(HAH)

}

func t_operator() {
	var a int = 43219
	var ptr *int
	ptr = &a
	fmt.Println(*ptr)
}

func t_sentence() {
	// 语句
	var a int = 30
	if a < 20 {
		fmt.Println("a ligth 20")
	} else {
		fmt.Println("a big 20")
	}

	var grade string
	var marks int = 90
	switch marks {
	case 90:
		grade = "A"
	case 80:
		grade = "B"
	default:
		grade = "C"
	}
	fmt.Println(grade)
	switch {
	case grade == "A":
		fmt.Printf("优秀!\n")
		fallthrough
	case grade == "B", grade == "C":
		fmt.Printf("良好\n")
		fallthrough
	case grade == "D":
		fmt.Printf("及格\n")
	case grade == "F":
		fmt.Printf("不及格\n")
	default:
		fmt.Printf("差\n")
	}

	var c1, c2, c3 chan int
	var i1, i2 int
	select {
	case i1 = <-c1:
		fmt.Printf("received ", i1, "from c1\n")
	case i2 = <-c2:
		fmt.Printf("received ", i2, "from c2\n")
	case i3, ok := (<-c3):
		if ok {
			fmt.Printf("received ", i3, " from c3\n")
		} else {
			fmt.Printf("c3 is closed\n")
		}
	default:
		fmt.Printf("no communication\n")

	}
}

func t_sentence2() {
	// 循环
	sum := 0
	for i := 0; i <= 10; i++ {
		sum += i
	}
	fmt.Println("sum:", sum)

	strings := []string{"google", "runobb"}
	for i, s := range strings {
		fmt.Println(i, s)
	}

	numbers := [6]int{1, 2, 3, 4}
	for i, n := range numbers {
		fmt.Println(i, n)
	}
	// 无限循环
	// for true{
	// }

}

func max(num1, num2 int) int {
	var result int
	if num1 > num2 {
		result = num1
	} else {
		result = num2
	}
	return result
}

func swap(x, y string) (string, string) {
	return y, x

}

// 值传递

// 引用传递

// 闭包
func getSequence() func() int {
	i := 0
	return func() int {
		i += 1
		return i
	}
}

// 带参数的闭包
func add_bb(x1, x2 int) func(x3 int, x4 int) (int, int, int) {
	i := 0
	return func(x3 int, x4 int) (int, int, int) {
		i++
		return i, x1 + x2, x3 + x4
	}
}

func t_bibao() {
	fmt.Println("----------- bi bao ---------")
	nextNumber := getSequence()
	fmt.Println(nextNumber())
	fmt.Println(nextNumber())
	fmt.Println(nextNumber())
	nextNumber1 := getSequence()
	fmt.Println(nextNumber1())
	fmt.Println(nextNumber1())
	fmt.Println("----------- bi bao  canshu ---------")
	add_func := add_bb(1, 2)
	fmt.Println(add_func(1, 1))
	fmt.Println(add_func(0, 0))
	fmt.Println(add_func(2, 2))
	gg = 100
	fmt.Println("gg:", gg)
}

// 函数方法
type Circle struct {
	radius float64
}

func (c Circle) getArea() float64 {
	return 3.14 * c.radius * c.radius
}

func t_Area() {
	var c1 Circle
	c1.radius = 10.00
	fmt.Println("圆的面积是:", c1.getArea())
	gg = 200
	fmt.Println("gg:", gg)
}

func main() {

	fmt.Println("hello world")
	var b bool = true
	fmt.Println(b)
	var i int = 10
	var j, k int = 1, 2
	fmt.Println(i, j, k)
	var s1 string = "runoob"
	s2 := "kdfifdks"
	fmt.Println(s1, s2)

	var xx, yy int
	var s3 string
	s3 = "i"
	xx, yy = 1, 2
	xx, yy, s3 = 3, 4, "idi"
	fmt.Println(xx, yy, s3)
	t_const()
	t_operator()

	t_sentence()
	t_sentence2()
	t_bibao()
	t_Area()
	fmt.Println("gg:", gg)
}
