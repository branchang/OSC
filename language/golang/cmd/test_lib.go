package main
import (
	"io"
	"log"
	"net/http"

	"github.com/kataras/muxie"
	"github.com/gorilla/websocket"
)

func t_muxie_fileserver(){
	mux := muxie.NewMux()
	mux.Handle("/static/*file", http.StripPrefix("/static/", http.FileServer(http.Dir("./static"))))

	log.Println("Server started at http://localhost:8080\nGET: http://localhost:8080/static/\nGET: http://localhost:8080/static/js/empty.js")
	http.ListenAndServe(":8080", mux)
}

func hello(w http.ResponseWriter, r *http.Request){
	io.WriteString(w, "Hello GopherCon Israel 2019!")
}

func t_go_websockets(){
	http.HandleFunc("/", hello)
	http.ListenAndServe(":8000", nil)
}

func ws(w http.ResponseWriter, r *http.Request){
	upgrade := websocket.Upgrader{}
	conn, err := upgrade.Upgrade(w, r, nil)
	if err != nil{
		return 
	}

	for {
		_, msg, err := conn.ReadMessage()
		if err != nil {
			conn.Close()
			return 
		}
		log.Printf("msg: %s", string(msg))
	}
}

func t_one_m_go_websockets(){
	http.HandleFunc("/", ws)
	if err:= http.ListenAndServe(":8000", nil);  err!=nil{
		log.Fatal(err)
	}
} 

func main(){
	// t_muxie_fileserver()
	t_go_websockets()
}