package com.make.happen.thirdlib;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import lombok.Data;


public class ThirdLibTest {

    public int exCommonLog(){

        Log log = LogFactory.getLog(ThirdLibTest.class);
        log.info("start...");
        log.warn("end");
        log.error("hahahahah 123321321312321");
        return 0;
    }

    public void exLombokData() {
        LombokData lbd = new LombokData();
        lbd.setId(123);
        lbd.setName("here is name!");
        System.out.println(lbd.getId());
        System.out.println(lbd.getName());
    }
}

/**
 *
 */
@Data
class LombokData{
    private int id;

    private String name;
}

