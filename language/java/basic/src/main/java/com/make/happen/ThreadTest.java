package com.make.happen;

import java.lang.Thread;

public class ThreadTest extends  Thread {

    @Override
    public void run() {

        System.out.println("start new thread");
        while(true){
            double i = 99999.99999 / 34.34343;
        }
    }
}
