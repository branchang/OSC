package com.make.happen;

import com.make.happen.thirdlib.ThirdLibTest;
import com.make.happen.thirdlib.ThirdLibTest.*;
import com.make.happen.CollectionCase;

import java.lang.StringBuilder;
import  java.lang.Thread;

class BasicType {

    public void char_type() {
        char c1 = 'A';
        char c2 = '中';
        char c3 = '\u0041';
        char c4 = '\u4e2d';
        System.out.println(c1);
        System.out.println(c2);
        System.out.println(c3);
        System.out.println(c4);
    }

    public int string_test() {
        String s = "";
        String s1 = "A";
        String s2 = "ABC";
        String s3 = "中文  ABC";
        String ss = "hello";

        System.out.println(ss);
        ss = "world";

        System.out.println(ss);
        String s4 = "hello";
        String cs1 = s4;
        s4 = "world";
        System.out.println(cs1);
        return 0;
    }

    public int array_test() {
        int[] ns = new int[5];
        ns[0] = 68;
        ns[1] = 79;
        ns[2] = 91;
        ns[3] = 85;
        ns[4] = 62;
        System.out.println(ns.length);

        int[] ns2 = new int[] {68, 79, 91, 85, 62};
        int[] ns3 = {68, 79, 91, 85, 62};


        String[] names = {
                "ABC", "XYZ", "zoo"
        };

        String s = names[1];
        names[1] = "cat";
        System.out.println(s);
        return 0;
    }
}


public class Hello {

    public static void main(String[] args){
        System.out.println("Here! 2021-0606");
        int x = 100;
        System.out.println(x);
        final double PI = 3.14;

        StringBuilder sb = new StringBuilder();

        int sum = ((1+x) * 100)/2;
        System.out.println(sum);
        boolean isGreater = 5 > 3;
        int age = 12;
        boolean isZero = age == 0;
        boolean isNonZero = !isZero;
        boolean isTeenager = age > 6 && age < 18;

        int n = -100;
        x = n >= 0 ? n: -n;
        BasicType bt = new BasicType();
        bt.char_type();
        bt.string_test();
        bt.array_test();

        ThirdLibTest tlt = new ThirdLibTest();
        tlt.exCommonLog();
        tlt.exLombokData();

        ThreadTest tt = new ThreadTest();
        tt.start();
        System.out.println("start while true!!!!!");
        double i = 10.111111;
        while (true) {
            double j = 3.33333;
            i = i / j;
            i+=1;
        }

//        try{
//            Thread.sleep(1000000);
//        }catch (InterruptedException e) {
//           e.printStackTrace();
//        }
    }
}
