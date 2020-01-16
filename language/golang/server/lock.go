package server 

import "sync"

import "time"

var lock sync.Mutex

func MutexStudy() {
	lock.Lock()
	time.Sleep(1 * time.Second)
	lock.Unlock()
}
