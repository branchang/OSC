// 获取所有未映射的海外酒店信息，国家是马来西亚、日本、韩国、泰国、新加坡
var mysql = require('mysql');
var xlsx = require('node-xlsx');
var fs = require('fs');
const util = require('util');
var async2 = require('async');


var connection = mysql.createConnection({
    host:'localhost',
    port:10010,
    user:'ota',
    password:'Js03H7z#K',
    database:'ota'
});

connection.connect();
var mapping_hotels = new Array();

function f1() {
    console.log('f1 start')
    connection.query("select hotel_id from `ctrip_qmapping.20180403` group by hotel_id;",
    function(error, results, fields){
        if (error){
            console.log(error.message);
            return 
        }
        for (var i=0; i < results.length; i++){
                hotel_id = results[i]['hotel_id'];
                // console.log(hotel_id);
                mapping_hotels.push(hotel_id);
        }
        console.log('f1 end')
    });
}

// connection.query('select hotel_id, count(*) as cc from `ctrip_qmapping.20180403` where ctrip_room_id="" group by hotel_id;',
// 判断是独家产品，暂不支持接入
// 判断是独家酒店，暂不支持接入
// 接口无房型详情
// 接口无酒店详情
// 酒店无匹配,Code：3
// 生成子酒店失败：该母酒店下已经存在此供应商下对应的子酒店！
// select hotel_id from `ctrip_qmapping.20180403`  where failed_reason='' and ctrip_room_id='';
var no_mapping_hotels = new Array();
function f2() {
    console.log('f2 start.');
    connection.query("select * from `ctrip_qmapping.20180403`  where  (failed_reason='' and ctrip_room_id='') or (failed_reason='判断是独家酒店，暂不支持接入') or (failed_reason='接口无酒店详情') or (failed_reason='酒店无匹配,Code：3');",
    function(error, results, fields){
        if (error){
            console.log(error.message);
            return 
        }
        for (var i=0; i < results.length; i++){
                // console.log(results[i]['hotel_id']);
                no_mapping_hotels.push(results[i]['hotel_id']);
        }
        console.log('f2 end');
    });
}

// 获取ctrip_hotel_detail中的酒店信息

var results_array = new Array()
function f3() {
        connection.query("select hotel_id from ctrip_hotel_detail where  country in (102,103,108,109,110);",
        function (error,results, fields){
            if (error) {
                console.log(error.message);
                return 
            }
            for (var i=0;i<results.length; i++){
                hotel_id = results[i]['hotel_id'];
                if (mapping_hotels.indexOf(hotel_id) == -1){
                    // console.log('no result:', hotel_id)
                    results_array.push(hotel_id);
                    continue
                }
                if (no_mapping_hotels.indexOf(hotel_id) >= 0){
                    // console.log('no mapping:', hotel_id)
                    results_array.push(hotel_id);
                }
            }
            console.log('f3');
        });
}

var text_results = new Array();
// var sql = "select country,city_id,hotel_name,hotel_id from ctrip_hotel_detail where hotel_id in ({0});".format();
function f4() {

    var sql = util.format("select country,city_id,hotel_name,hotel_id from ctrip_hotel_detail where hotel_id in (%s);", results_array.join());
    console.log('results array lenght:', results_array.length)
    console.log(sql)

    // connection.query(sql, function(error,results, fields){
    //     if (error){
    //         console.log(error.message);
    //     }
    //     for (var i = 0;i< results.length; i++){
    //         text_results.push([results[i]['country'],
    //                            results[i]['city_id'],
    //                            results[i]['hotel_name'],
    //                             results[i]['hotel_id']]);
    //     }
    // });
}

function f5 (){
    console.log('end f5')
}

function f6 (){
    console.log('end f6')
}


function starts() {
    async2.series([
        function (callback){
            f6();
            callback(null,'one');
        },
        function (callback){
            f5();
            callback(null,'two');
        },
        function (callback){
            f1();
            callback(null,'three');
        },
        function (callback){
            f2();
            callback(null,'fort');
        },
        function (callback){
            f3();
            callback(null,'five');
        },
        function (callback){
            f4();
            callback(null,'six');
        }], function(error, result){
        if (error){
            console.log('error', error.message);
        }
        console.log(result);
    });
}
// connection.end()
// var buffer = xlsx.build([{name: "mySheetName", data: text_results}]);
// fs.writeFileSync('./test2.xlsx', buffer);

starts();
console.log('end');