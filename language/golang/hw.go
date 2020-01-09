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

func t_array() {
	var a1 [10]int
	a1[0] = 1
	var a2 = [2]int{2, 3}
	fmt.Println("a2[1]:", a2[1])
	var balance = [5]float32{500.0, 2.0, 30.0, 3.293, 4.98}
	var balance2 = [...]float32{500.0, 2.0, 30.0, 3.293, 4.98}
	fmt.Println("blance[3]:", balance[3], "balance2[4]:", balance2[4])

}

// 多维数组
func t_mult_array() {
	var a1 [2][3]int
	a1[1][1] = 1
	// 初始化二维数组
	var a2 = [3][4]int{
		{0, 1, 2, 3},
		{4, 5, 6, 7},
		{8, 9, 19, 11},
	}
	a3 := a2[1][3]
	fmt.Println("a3:", a3)
}

func getAverage(arr [5]int, size int) float32 {
	var i int
	var avg, sum float32
	for i = 0; i < size; i++ {
		sum += float32(arr[i])
	}
	avg = sum / float32(size)
	return avg
}

func t_getaverage() {
	/* 数组长度为 5 */
	var balance = [5]int{1000, 2, 3, 17, 50}
	var avg float32

	/* 数组作为参数传递给函数 */
	avg = getAverage(balance, 5)

	/* 输出返回的平均值 */
	fmt.Printf("平均值为: %f ", avg)
}

func t_pointer() {
	var a int = 10
	fmt.Println("a address is %x", &a)
}

const MAX int = 3

// 指针数组
func t_point_array() {
	a := []int{10, 100, 200}
	var i int
	var ptr [MAX]*int
	for i = 0; i < MAX; i++ {
		fmt.Println("a[", i, "]:", a[i])
		ptr[i] = &a[i]
	}
	for i = 0; i < MAX; i++ {
		fmt.Println("Point:", ptr[i], "->", *ptr[i])
	}
	for i, x := range ptr {
		fmt.Println("I:", i, "X:", x, "x:", *x)
	}
}

// 指向指针的指针
func t_p_to_p() {
	var a int
	var ptr *int
	var pptr **int
	ptr = &a
	pptr = &ptr
	a = 938
	fmt.Println(a, *ptr, **pptr)
	var x int = 5
	var y int = 10
	t_point_swap(&x, &y)
	fmt.Println("x:", x, "y:", y)
}

func t_point_swap(x *int, y *int) {

	var temp int
	temp = *x
	*x = *y
	*y = temp
}

type Books struct {
	title   string
	author  string
	subject string
	book_id int
}

func t_struct() {
	s1 := Books{"GO lang", "www.runoob.com", "jiaocheng ", 8383883}
	s2 := Books{title: "Go 语言", author: "www.runoob.com", subject: "Go 语言教程", book_id: 6495407}
	s2.title = "java"
	s3 := Books{title: "Go 语言", author: "www.runoob.com"}
	s3.title = "python"

	fmt.Println(s1)
	fmt.Println(s2)
	fmt.Println(s3)

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
	t_array()
	t_getaverage()
	t_pointer()
	t_point_array()
	t_p_to_p()
	t_struct()
}
