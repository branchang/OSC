package com.make.happen;

import cn.hutool.core.collection.CollUtil;
import com.make.happen.datastruct.BasicHashMap;
import com.make.happen.thirdlib.*;
import com.make.happen.thirdlib.ThirdLibTest.*;
import com.make.happen.CollectionCase;
import com.make.happen.HttpServer.*;

import cn.hutool.crypto.digest.MD5;


import java.lang.StringBuilder;
import  java.lang.Thread;
import java.time.LocalDateTime;
import java.time.ZoneOffset;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.time.format.DateTimeFormatter;
import java.util.*;

import com.make.happen.works.ParseCuepoint;
import com.make.happen.zdemo.PokerDemo;
import org.apache.commons.lang3.StringUtils;




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

    public void testBasicHashMap(){
        BasicHashMap map = new BasicHashMap();
        for (int i = 0;i< 100; i++) {
            map.put("张哈" + i, "你这瓜保熟吗?" + i);
        }

        System.out.println(map.size());

        for (int i = 0;i< 100; i++) {
        	System.out.println(map.get("张哈" + i));
        }

        map.put("刘华强1","哥们，你这瓜保熟吗？");
        map.put("刘华强1","你这瓜熟我肯定要啊！");
        System.out.println(map.get("刘华强1"));
    }
}

class DateTimeTest {

    public void toUtcTime() {
        System.out.println(LocalDateTime.now());
        DateTimeFormatter pattern = DateTimeFormatter.ofPattern("yyyy-MM-dd'T'HH:mm:ss'Z'");

        LocalDateTime n = LocalDateTime.now(ZoneOffset.UTC).minusSeconds(60);
        System.out.println(n);
        System.out.println(n.format(pattern));
//        System.out.println(n.toEpochSecond(ZoneOffset.UTC));
        long utcN = n.toEpochSecond(ZoneOffset.UTC);
        Date d1 = new Date(utcN);
        System.out.println(d1);
        DateFormat format = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
//        System.out.println(format.format(new Date(n.toEpochSecond(ZoneOffset.UTC))));
    }
}


public class Hello {

    public static void main(String[] args){
        System.out.println("Here! 2021-0606");
        phpUniqid();
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
        bt.testBasicHashMap();

        DateTimeTest dtt = new DateTimeTest();
        dtt.toUtcTime();

        ThirdLibTest tlt = new ThirdLibTest();
        tlt.exCommonLog();
        tlt.exLombokData();

        StringTest();

//        ossUpload();
        lombokDemo();
        PokerDemo pokerDemo = new PokerDemo();
        pokerDemo.run();

        System.out.println(System.currentTimeMillis());
        System.out.println("---------------");
//        try {
////            TencentLivesRelay.createReqURL();
////            TencentLivesRelayDesc.createReqURL();
////            TencentLivesRelayDel.createReqURL();
//        } catch (Exception e) {
//        	System.out.println(e.toString());
//        }
//        TestCreateRoomID();

//        httpServerTest();
//        ThreadTest tt = new ThreadTest();
//        tt.start();
//        System.out.println("start while true!!!!!");
//        double i = 10.111111;
//        while (true) {
//            double j = 3.33333;
//            i = i / j;
//            i+=1;
//        }

//        try{
//            Thread.sleep(1000000);
//        }catch (InterruptedException e) {
//           e.printStackTrace();
//        }

//        String md5SecretKey = MD5.create().digestHex("2JS0tFo7ELmD9ERXqr6AeXY1k4FSzEPd");
//        String md5SecretKey = MD5.create().digestHex("2JS0tFo7ELmD9ERXqr6AeXY1k4FSzEPd");
        String md5SecretKey = MD5.create().digestHex("8316c9c04e9287df3f7be9a5e2e532b3");
        System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~~");
        System.out.println(md5SecretKey);

        List<String> l1 = new LinkedList<>();
        l1.add("1232321311");
        l1.add("1232321312");
        l1.add("1232321313");
        System.out.println(l1);

        Map<String, Object> sign_ctx = new HashMap<>(8);
//        sign_ctx.put("event", "lives/tell-stream-running");
//        sign_ctx.put("refer", "vhall");
//        sign_ctx.put("room_id", l1);
//        sign_ctx.put("time", 1639621806);
//        sign_ctx.put("app_id", "OlXR3OQ0");

        sign_ctx.put("status", 3);
        sign_ctx.put("config_id", "1147");
        sign_ctx.put("room_id", "lss_740cce74");
        sign_ctx.put("task_id", "185c8aac-1692-4f89-b8c5-08594865577b");
        sign_ctx.put("time", 1639634701);
        sign_ctx.put("errcode", "200");
        sign_ctx.put("app_id", "076dd680");
        sign_ctx.put("event", "lives/pull_stream_status");
        sign_ctx.put("errmsg", "拉流异常:{'status': 3, 'code': '317', 'input': u'rtmp://t-alrtmplive01.e.vhall.com/vhallyun/lss_414ce151?token=alibaba', 'msg': 'rtmp://t-alrtmplive01.e.vhall.com/vhallyun/lss_414ce151?token=alibaba: Invalid data found when processing input', 'output': u'rtmp://rs02.live.t.vhou.net:1935/vhallyun?vhost=relayVhost?token=alibaba/lss_740cce74', 'annotation': '\\xe6\\x8b\\x89\\xe6\\xb5\\x81\\xe5\\xa4\\xb1\\xe8\\xb4\\xa5'}");
        sign_ctx.put("refer", "vhall");
        sign_ctx.put("repeat_times", 3);

        sign_ctx = CollUtil.sort(sign_ctx, null);
        StringBuilder builder = new StringBuilder();
        sign_ctx.forEach((key, value) -> {
            if(value instanceof String[] || value instanceof List){
                value = "Array";
            }
            builder.append(key).append("|").append(md5SecretKey).append("|").append(value);

        });
        String sign = MD5.create().digestHex(builder.toString());
        System.out.println(sign);

//        ParseCuepoint parseCuepoint = new ParseCuepoint();
//        parseCuepoint.exce();

    }

    private static void httpServerTest() {

        try {
            HttpServer hs = new HttpServer();
            hs.start();
        }catch (Exception e) {
            System.out.println(e.toString());
        }
    }

    private static void StringTest() {
    	String str1 = null;
    	System.out.println("StringTest:" + StringUtils.isBlank(str1));
    	String[] sa1 = new String[]{};
    }

    private static String phpUniqid() {

        long usecond = System.currentTimeMillis() * 1000;
        // 微秒
        long microSecond = System.nanoTime()/1000;
        // 秒
        long second = microSecond/1000;
//        long microSecond = System.nanoTime()/1000;
        int sec = (int) second;
        int usec = (int) (microSecond - (second * 1000)) % 0x100000;

        String uniqid = String.format("%08x%05x", sec, usec);
        System.out.println(uniqid);
        return uniqid;
    }

    private static void TestCreateRoomID() {
        CreateId createId = new CreateId();
        try {
            createId.run();
        }catch (Exception e) {
        	System.out.println(e.toString());
        }
    }

    private static void ossUpload() {
    	AliOSSUpload aliOSSUpload = new AliOSSUpload();
    	aliOSSUpload.uploadFile();

    }

    private static void lombokDemo() {
        ForLombokTest forLombokTest = new ForLombokTest();
        forLombokTest.getAddress();
        forLombokTest.setFunny(true);
        ForLombokTest forLombokTest1 = new ForLombokTest("fdsafdsa", 1, "fdsaf ", "fdsaf ", "fdsaf", true);

    }

}
