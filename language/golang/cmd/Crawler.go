package main

import (
	"bytes"
	"flag"
	"fmt"
	"github.com/PuerkitoBio/goquery"
	"log"
	"net/http"
)

func get_web_page(url string) (resp_leg int64, body string) {
	resp, err := http.Get(url)
	if err != nil {
		fmt.Println("err:", err)
		return 0, ""
	}

	if resp.StatusCode != 200 {
		fmt.Println("statucode:", resp.StatusCode)
		return 0, ""
	}

	buf := new(bytes.Buffer)
	buf.ReadFrom(resp.Body)
	s := buf.String()
	fmt.Printf("%s", s)

	return resp.ContentLength, s
}

func get_web_page_res(url string) (resp_leg int64, res http.Response) {
	resp, err := http.Get(url)
	if err != nil {
		fmt.Println("err:", err)
		return
	}

	// defer resp.Body.Close()
	if resp.StatusCode != 200 {
		fmt.Println("statucode:", resp.StatusCode)
		return
	}

	// buf := new(bytes.Buffer)
	// buf.ReadFrom(resp.Body)
	// s := buf.String()
	// fmt.Printf("here:%s", s)

	return resp.ContentLength, *resp
}

func parse_html_page(res *http.Response) {
	// buf := new(bytes.Buffer)
	// buf.ReadFrom(res.Body)
	// s := buf.String()
	// fmt.Printf("parse body: %s", s)

	// doc, err := goquery.NewDocumentFromResponse(res)
	// doc, err := goquery.NewDocument(s)
	// if err != nil {
	// 	fmt.Println("failed.", err)
	// 	log.Fatal(err)
	// 	return
	// }
	doc, err := goquery.NewDocumentFromReader(res.Body)
	if err != nil {
		log.Fatal("goquery err:", err)
	}
	// selector := "#p"

	fmt.Println("find #p")
	// doc.Find(selector).Each(func(i int,s *goquery.Selection){
	// 	text:=s.Find(selector).Text()
	// 	fmt.Println(text)
	// })
	// Find the review items
	doc.Find(".sidebar-reviews article .content-block").Each(func(i int, s *goquery.Selection) {
		// For each item found, get the band and title
		band := s.Find("a").Text()
		title := s.Find("i").Text()
		fmt.Printf("Review %d: %s - %s\n", i, band, title)
	})
}

var gopherType string
var url string

func parse_flag() {
	const (
		defaultGopher = "pocket"
		usage         = "the variety of gopher"
	)
	flag.StringVar(&gopherType, "gopher_type", defaultGopher, usage)
	flag.StringVar(&gopherType, "g", defaultGopher, usage+" (shorthand)")
	flag.StringVar(&url, "url", "", "crawler url to parse")
	flag.Parse()
	fmt.Println("flag.Arg:", flag.Arg(1))
}

func init() {
	parse_flag()
	fmt.Println("parse url:", url)
}

func main() {
	// 解析命令行

	// l, h := get_web_page(url)
	l, res := get_web_page_res(url)

	// buf := new(bytes.Buffer)
	// buf.ReadFrom(res.Body)
	// s := buf.String()
	// fmt.Printf("res>>>>>:[%s]\n", s)

	parse_html_page(&res)

	fmt.Println("length:%s", l)
	fmt.Println("end:", gopherType)
}
